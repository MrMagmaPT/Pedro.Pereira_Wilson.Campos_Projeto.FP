/*[sumario]*/

//bibliotecas
#include<stdlib.h> // 1 Permite usar o  system("cls"); (limpar o ecrã)   fflush(stdin);  (para limpar o buffer do teclado)
#include<stdio.h>  // 2 Biblioteca standart de input e output
#include<unistd.h> // 3 sleep (1) (para o programa pelo tempo determinado pode ou não vir a ser utilizado se for vai estar aqui se não for vou retirar);
#include<conio.h>  // 4 Coloquei este aqui por causa do getch() (é um função par aobter caracter mas que tambem pode ser usado como um stopper a espera de a inserção de qualquer simbolo ou caracter do teclado, utilizado correntemente assguir a mensagem "prima qualquer tecla para continuar") 
#include<locale.h> // 5 Para poder por uma lingua de um local permitindo a utilização de certos tipos de carcteres como por exemplo "�"
#include<ctype.h>  // 6 Permite fazer certos simbolos corretamente
#include<math.h>   // 7 Para calcular expoentes com a função pow(b,e) e mais algumas funções matematicas
#include<time.h>   // 8 Para usar o srand(time(NULL)); 
#include<windows.h>// 9 Para poder utilizar o system("color 0a"); trocar 0a para a cor desejada utiliza o formato do CMD cor do texto � o segundo digito("a") cor do background � o primeiro("0")
#include<string.h> // 10 Manipulação de strings
#include<stdbool.h>// 11 Para poder usar files boolean (true/false)

//constantes
#define TAMANHO_STRING 100
#define MAXIMO_ALUNOS 30
#define FILE_PATH_ALUNOS "SecFiles/InfoAlunos.txt"


//strucks
typedef struct 
{
    int dia;
    int mes;
    int ano;
} t_data;

typedef struct 
{
    int id;
    int numero;
    char nome[TAMANHO_STRING];
    char regime[TAMANHO_STRING];
    int nota_final;
    t_data data_lancamento;
} t_aluno;

//funções
int ler_dados_estudante(t_aluno vetor_estudantes[],int numero_alunos);
int mostrar_dados_estudante(t_aluno vetor_estudantes[],int numero_alunos);
char ler_numero_inteiro(char[],int, int);
void gravar_ficheiro_binario(t_aluno vetor_estudantes[],int numero_alunos);
int ler_ficheiro_binario(t_aluno vetor_estudantes[]);

int menu_opcoes(void);
int confirmar_saida(void);

//função main
int main() {
    t_aluno vetor_alunos[MAXIMO_ALUNOS] = {0};
    int sair = 0, escolha = 0, numero_alunos = 0;
    do {
        escolha = menu_opcoes();
        switch (escolha)
        {
        case 1:
            system("cls");
            numero_alunos = ler_dados_estudante(vetor_alunos, numero_alunos);
            break;
        case 2:
            system("cls");
            mostrar_dados_estudante(vetor_alunos, numero_alunos);
            break;
        case 3:
            system("cls");

            break;
        case 4:
            system("cls");

            break;
        case 5:
            system("cls");
            gravar_ficheiro_binario(vetor_alunos, numero_alunos); //Escreve alunos no ficheiro
            break;
        case 6:
            system("cls");
            numero_alunos = ler_ficheiro_binario(vetor_alunos); // Lê alunos do ficheiro
            break;
        case 0:
            system("cls");
            sair = confirmar_saida();
            break;
        default:
            system("cls");
            printf("Erro, Opção Não Permitida!");
            break;
        }
    } while (sair != 1);
}

//le numero inteiro
char ler_numero_inteiro(char texto[],int min, int max){
    int num = 0;
    int tamanho_texto = strlen(texto);
    do{
        for (int i = 0; i < tamanho_texto; i++){
            printf("%c",texto[i]);
        }
        printf(": ");
        scanf("%d",&num);
        fflush(stdin);
        if (num < min || num > max){
            system("cls"); 
            printf("O valor introduzido não segue as regras indicadas\n(prima qualquer tecla para continuar)\n");
            getch();
        }
    } while (num < 1 || num > 100);
    return num;
}

//menu
int menu_opcoes(void){
    int opcao;
    do{
        printf("\n********* Menu de Opcoes *********\n");
        printf("* (1) Inserir Dados Estudante\t *\n");
        printf("* (2) Mostrar Dados Estudante\t *\n");
        printf("* (3) Alterar Nota Estudante\t *\n");
        printf("* (4) Stats Alunos\t\t *\n");
        printf("* (5) Gravar dados em Ficheiro!\t *\n");
        printf("* (6) Ler dados de um Ficheiro!\t *\n");
        printf("* (0) Sair\t\t\t *\n");
        printf("********* Menu de Opcoes *********\n");
        printf("OPCAO:");
        scanf("%d",&opcao); 
        if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 0){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 0);
    return opcao;
}

//ler dados estudantes
int ler_dados_estudante(t_aluno vetor_estudantes[],int numero_alunos) {
    int regime = 0,contador = numero_alunos+1;
    SYSTEMTIME t; // Declara a strutura SYSTEMTIME
    GetLocalTime(&t); //recebe o tempo local do sistema
    vetor_estudantes[numero_alunos].id = contador; //id
    printf("\nInsira o numero do estudante: "); //numero do aluno
    scanf("%d",&vetor_estudantes[numero_alunos].numero);
    printf("\nInsira o nome do estudante: "); //nome do aluno
    scanf(" %s",&vetor_estudantes[numero_alunos].nome);
    do{
        printf("\n(1) - Diurno\n(2) - Pós Laboral\nInsira o regime do estudante: "); //regime do aluno
        scanf("%d",&regime);
        fflush(stdin);
        if  (regime != 1 && regime != 2) {
            printf("O valor inserido não se encontra de entre as opções apresentadas!!!\nPorfavor insira");
        }
    } while (regime != 1 && regime != 2);

    if (regime == 1) {
        strcpy(vetor_estudantes[numero_alunos].regime,"Diurno");
    } else {
        strcpy(vetor_estudantes[numero_alunos].regime,"Pós Laboral");
    }
    vetor_estudantes[numero_alunos].nota_final = ler_numero_inteiro("Insira a nota final (min 0 max 20) do estudante", 0, 20);
    vetor_estudantes[numero_alunos].data_lancamento.dia = t.wDay;
    vetor_estudantes[numero_alunos].data_lancamento.mes = t.wMonth;
    vetor_estudantes[numero_alunos].data_lancamento.ano = t.wYear;
    mostrar_dados_estudante(vetor_estudantes, contador); //debugging
    return contador;
}

//mostrar o vetor
int mostrar_dados_estudante(t_aluno vetor_estudantes[],int numero_alunos){
    int indice;
    for (indice = 0; indice < numero_alunos; indice++)
    {
        printf("\nId do Estudante: %d\n", vetor_estudantes[indice].id);
        printf("Nome do Estudante: %s\n", vetor_estudantes[indice].nome);
        printf("Numero do aluno: %d\n", vetor_estudantes[indice].numero);
        printf("Regime do curso: %s\n", vetor_estudantes[indice].regime);
        printf("Nota final do aluno: %d\n", vetor_estudantes[indice].nota_final);
        printf("Dia de lancamento: %d/%d/%d\n", vetor_estudantes[indice].data_lancamento.dia, vetor_estudantes[indice].data_lancamento.mes, vetor_estudantes[indice].data_lancamento.ano);
    } 
}

//inserir no fichero binario
void gravar_ficheiro_binario(t_aluno vetor_estudantes[], int numero_alunos) {
    FILE *file_alunos = fopen(FILE_PATH_ALUNOS, "wb");

    if (file_alunos == NULL) {
        printf("ERRO No gravamento de dados!");
    } else {
        fwrite(&numero_alunos, sizeof(int), 1, file_alunos); // Escreve a contagem para cada estudante
        fwrite(vetor_estudantes, sizeof(t_aluno), numero_alunos, file_alunos); // Escreve o array de estudantes
        printf("Dados Gravados com sucesso!!!");
    }
    fclose(file_alunos);
}

//ler do fitchero binario
int ler_ficheiro_binario(t_aluno vetor_estudantes[]) {
    int numero_estudantes = 0;
    FILE *file_alunos = fopen(FILE_PATH_ALUNOS, "rb");

    if (file_alunos == NULL) {
        printf("ERRO No carregamento de dados!");
    } else {
        fread(&numero_estudantes, sizeof(int), 1, file_alunos); // Lê o numero de estudantes
        fread(vetor_estudantes, sizeof(t_aluno), numero_estudantes, file_alunos); // Lê o array de estudantes
        printf("Dados carregados com sucesso!!!");
    }
    fclose(file_alunos);
    //faz eturn do numero de estudantes lido
    return numero_estudantes;
}

//confirmar saida
int confirmar_saida() {
    char opcao;
    int sair;
    do{
        printf("Deseja sair do programa ?(S\\N)\n");
        scanf(" %c", &opcao);
        if (opcao == 'N' || opcao == 'n')
        {
            printf("Entendido, a voltar ao programa\n");
            return 0;
        } else if (opcao == 'S' || opcao == 's') {
            printf("Entendido a sair do programa, prima qualquer tecla para terminar");
            getch();
            return 1;
        } else {
            printf("Esta opção nao foi apresentada, por favor responda com \"[S]\" ou \"[N]\"\n");
        }
    } while (opcao != 'N' && opcao != 'n' && opcao != 'S' && opcao != 's' );
}