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
#define MAXIMO_ALUNOS 100
#define MAXIMO_FICHAS 10
#define MAXIMO_EXE 10
#define MAXIMO_SUBMISSOES 10000
#define NOTA_MAX 100
#define NOTA_MIN 0

#define FILE_PATH_ESTUDANTE "SecFiles/ESTUDANTES.dat"
#define FILE_PATH_FICHA "SecFiles/FICHA.dat"
#define FILE_PATH_EXERCICIO "SecFiles/EXERCICIOS.dat"
#define FILE_PATH_SUBMISSOES "SecFiles/SUBMISSOES.dat"

//structs
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
    int e_mail;
} t_estudante;

typedef struct 
{
    int id;
    char nome[TAMANHO_STRING];
    int total_exe;
    t_data data_publi;
} t_ficha;

typedef struct 
{
    int id;
    int id_ficha;
    char nome[TAMANHO_STRING];
    char dificuldade[TAMANHO_STRING];
    char tipo_solucao[TAMANHO_STRING];
} t_exercicio;

typedef struct 
{
    int id;
    int id_estudante;
    int id_ficha;
    int id_exe;
    t_data data_submicao;
    int n_linhas_solucao;
    int nota;
} t_submissao;



//por remover 
//    |
//   \/
typedef struct 
{
    int id;
    int numero;
    char nome[TAMANHO_STRING];
    char regime[TAMANHO_STRING];
    int nota_final;
    t_data data_lancamento;
} t_aluno;
//     /\
//     |
// por remover


//prototipos de funções

//  antigos 
//    |
//   \/


void mostrar_dados_estudante(t_aluno vetor_estudantes[],int numero_alunos);
void gravar_ficheiro_binario(t_aluno vetor_estudantes[],int numero_alunos);

void alterar_nota_final_estudante(t_aluno vetor_estudantes[], int numero_alunos);
void mostrar_estatisticas(t_aluno vetor_estudantes[], int numero_alunos);
int ler_ficheiro_binario(t_aluno vetor_estudantes[]);
//     /\
//     |
//  antigos

//menus
int menu_opcoes(void);
int menu_opcoes_estudantes(void);
int menu_opcoes_exercicios(void);
int menu_opcoes_fichas(void);
int menu_opcoes_submicoes(void);
int menu_opcoes_estatisticas(void);

//procurar
int procurar_estudante(t_aluno vetor_estudantes[], int numero_alunos ,int numero_estudante_procurar);
int procurar_exercicio(t_exercicio vetor_exercicios[], int numero_exercicios ,int numero_exercicio_procurar);
int procurar_ficha(t_ficha vetor_fichas[], int numero_fichas ,int numero_ficha_procurar);
int procurar_submissao(t_submissao vetor_submissoes[], int numero_submissoes ,int numero_submissao_procurar);   

//leitura de dados
int ler_dados_estudante(t_estudante vetor_estudantes[],int numero_alunos);
int ler_dados_ficha(t_ficha vetor_fichas[],int numero_fichas);
int ler_dados_exercicios(t_exercicio vetor_exercicios[],int numero_exercicios, t_ficha vetor_fichas[],int numero_fichas);

//funções genéricas
void ler_entre_X_opcoes(char vetor[],char mensagem[],int quant_opcoes);
int ler_numero_inteiro(char[],int, int);
int confirmar_Sim_ou_Nao(char[], char[], char[]);

//função main
int main() {
    t_aluno vetor_alunos[MAXIMO_ALUNOS] = {0};
    int sair = 0, escolha = 0, numero_alunos = 0;
    do {
        escolha = menu_opcoes();
        switch (escolha)
        {
        case 1: //estudantes
            system("cls");
            do{
                escolha = menu_opcoes_estudantes();
                switch (escolha)
                {
                case 1:
                    system("cls");
                    printf("1");
                    break;
                case 2:
                    system("cls");
                    printf("2");
                    break;
                case 0:
                    sair = confirmar_Sim_ou_Nao("Deseja voltar ao menu principal ?(S\\N)\n","Abortado o Regresso ao Menu Principal\n","A voltar para o Menu Principal (Prima qualquer tecla para voltar)!");
                    break;
                default:
                    system("cls");
                    printf("Erro, Opcao Nao Permitida!");
                    break;
                }
            } while (sair != 1);
            sair = 0;
            system("cls");
            break;
        case 2: //exercicios
            system("cls");
            do{
                escolha = menu_opcoes_estudantes();
                switch (escolha)
                {
                case 1:
                    system("cls");
                    printf("1");
                    break;
                case 2:
                    system("cls");
                    printf("2");
                    break;
                case 0:
                    sair = confirmar_Sim_ou_Nao("Deseja voltar ao menu principal ?(S\\N)\n","Abortado o Regresso ao Menu Principal\n","A voltar para o Menu Principal (Prima qualquer tecla para voltar)!");
                    break;
                default:
                    system("cls");
                    printf("Erro, Opcao Nao Permitida!");
                    break;
                }
            } while (sair != 1);
            sair = 0;
            system("cls");
            break;
        case 3: //fichas
            system("cls");
            do{
                escolha = menu_opcoes_estudantes();
                switch (escolha)
                {
                case 1:
                    system("cls");
                    printf("1");
                    break;
                case 2:
                    system("cls");
                    printf("2");
                    break;
                case 0:
                    sair = confirmar_Sim_ou_Nao("Deseja voltar ao menu principal ?(S\\N)\n","Abortado o Regresso ao Menu Principal\n","A voltar para o Menu Principal (Prima qualquer tecla para voltar)!");
                    break;
                default:
                    system("cls");
                    printf("Erro, Opcao Nao Permitida!");
                    break;
                }
            } while (sair != 1);
            sair = 0;
            system("cls");
            break;
        case 4: //submissoes
            system("cls");
            do{
                escolha = menu_opcoes_estudantes();
                switch (escolha)
                {
                case 1:
                    system("cls");
                    printf("1");
                    break;
                case 2:
                    system("cls");
                    printf("2");
                    break;
                case 0:
                    sair = confirmar_Sim_ou_Nao("Deseja voltar ao menu principal ?(S\\N)\n","Abortado o Regresso ao Menu Principal\n","A voltar para o Menu Principal (Prima qualquer tecla para voltar)!");
                    break;
                default:
                    system("cls");
                    printf("Erro, Opcao Nao Permitida!");
                    break;
                }
            } while (sair != 1);
            sair = 0;
            system("cls");
            break;
        case 5: //estastiticas
            system("cls");
            do{
                escolha = menu_opcoes_estudantes();
                switch (escolha)
                {
                case 1:
                    system("cls");
                    printf("1");
                    break;
                case 2:
                    system("cls");
                    printf("2");
                    break;
                case 3:
                    system("cls");
                    printf("3");
                    break;
                case 0:
                    sair = confirmar_Sim_ou_Nao("Deseja voltar ao menu principal ?(S\\N)\n","Abortado o Regresso ao Menu Principal\n","A voltar para o Menu Principal (Prima qualquer tecla para voltar)!");
                    break;
                default:
                    system("cls");
                    printf("Erro, Opcao Nao Permitida!");
                    break;
                }
            } while (sair != 1);
            sair = 0;
            system("cls");
            break;
        case 6: //gavar dados ficheiro
            system("cls");
            do{
                escolha = menu_opcoes_estudantes();
                switch (escolha)
                {
                case 1:
                    system("cls");
                    printf("1");
                    break;
                case 2:
                    system("cls");
                    printf("2");
                    break;
                case 0:
                    sair = confirmar_Sim_ou_Nao("Deseja voltar ao menu principal ?(S\\N)\n","Abortado o Regresso ao Menu Principal\n","A voltar para o Menu Principal (Prima qualquer tecla para voltar)!");
                    break;
                default:
                    system("cls");
                    printf("Erro, Opcao Nao Permitida!");
                    break;
                }
            } while (sair != 1);
            sair = 0;
            system("cls");
            break;
        case 7: //gavar dados ficheiro
            system("cls");
            do{
                escolha = menu_opcoes_estudantes();
                switch (escolha)
                {
                case 1:
                    system("cls");
                    printf("1");
                    break;
                case 2:
                    system("cls");
                    printf("2");
                    break;
                case 0:
                    sair = confirmar_Sim_ou_Nao("Deseja voltar ao menu principal ?(S\\N)\n","Abortado o Regresso ao Menu Principal\n","A voltar para o Menu Principal (Prima qualquer tecla para voltar)!");
                    break;
                default:
                    system("cls");
                    printf("Erro, Opcao Nao Permitida!");
                    break;
                }
            } while (sair != 1);
            sair = 0;
            system("cls");
            break;
        case 0: //sair
            system("cls");
            sair = confirmar_Sim_ou_Nao("Deseja sair do programa ?(S\\N)\n","Entendido, a voltar ao programa\n","Entendido a sair do programa, prima qualquer tecla para terminar!");
            break;
        default:
            system("cls");
            printf("Erro, Opcao Nao Permitida!");
            break;
        }
    } while (sair != 1);
}

//   menus
//    |
//   \/
//le numero inteiro
int ler_numero_inteiro(char texto[],int min, int max){
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
            printf("O valor introduzido nao segue as regras indicadas\n(prima qualquer tecla para continuar)\n");
            getch();
        }
    } while (num < min || num > max);
    return num;
}

//menu
int menu_opcoes(void){
    int opcao;
    do{
        printf("\n");
        printf("********* Menu de Opcoes ********\n");
        printf("* (1) Menu Dados Estudante      *\n");
        printf("* (2) Menu Dados Exercicio      *\n");
        printf("* (3) Menu Dados Fichas         *\n");
        printf("* (4) Menu Dados Submissoes     *\n");
        printf("* (5) Menu Estatisticas         *\n");
        printf("* (6) Gravar dados em Ficheiro! *\n");
        printf("* (7) Ler dados de um Ficheiro! *\n");
        printf("* (0) Sair                      *\n");
        printf("********* Menu de Opcoes ********\n");
        printf("OPCAO:");
        scanf("%d",&opcao); 
        if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 7 && opcao != 0){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 7 &&opcao != 0);
    return opcao;
}

//menu estudante
int menu_opcoes_estudantes(void){
    int opcao;
    do{
        printf("\n");
        printf("******* Menu de Estudante *******\n");
        printf("* (1) Inserir Dados Estudante   *\n");
        printf("* (2) Mostrar Dados Estudante   *\n");
        printf("* (0) Voltar                    *\n");
        printf("******* Menu de Estudante *******\n");
        printf("OPCAO:");
        scanf("%d",&opcao); 
        if (opcao != 1 && opcao != 2 && opcao != 0){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao != 1 && opcao != 2 && opcao != 0);
    return opcao;
}

//menu exercicios
int menu_opcoes_exercicios(void){
    int opcao;
    do{
        printf("\n");
        printf("***** Menu de Exercicios ********\n");
        printf("* (1) Inserir Dados Exercicios  *\n");
        printf("* (2) Mostrar Dados Exercicios  *\n");
        printf("* (0) Voltar                    *\n");
        printf("***** Menu de Exercicios ********\n");
        printf("OPCAO:");
        scanf("%d",&opcao); 
        if (opcao != 1 && opcao != 2 && opcao != 0){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao != 1 && opcao != 2 && opcao != 0);
    return opcao;
}

// menu fichas
int menu_opcoes_fichas(void){
    int opcao;
    do{
        printf("\n");
        printf("********* Menu de Fichas ********\n");
        printf("* (1) Inserir Dados Fichas      *\n");
        printf("* (2) Mostrar Dados Fichas      *\n");
        printf("* (0) Voltar                    *\n");
        printf("********* Menu de Fichas ********\n");
        printf("OPCAO:");
        scanf("%d",&opcao); 
        if (opcao != 1 && opcao != 2 && opcao != 0){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao != 1 && opcao != 2 && opcao != 0);
    return opcao;
}

//menu submisoes
int menu_opcoes_submicoes(void){
    int opcao;
    do{
        printf("\n");
        printf("****** Menu de Submicoes ********\n");
        printf("* (1) Inserir Dados Submissoes  *\n");
        printf("* (2) Mostrar Dados Submissoes  *\n");
        printf("* (0) Voltar                    *\n");
        printf("****** Menu de Submicoes ********\n");
        printf("OPCAO:");
        scanf("%d",&opcao); 
        if (opcao != 1 && opcao != 2 && opcao != 0){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao != 1 && opcao != 2 && opcao != 0);
    return opcao;
}

//menu submisoes
int menu_opcoes_estatisticas(void){
    int opcao;
    do{
        printf("\n");
        printf("******* Menu Estatisticas *******\n");
        printf("* (1) Total Submissoes Estudante*\n");
        printf("* (2) Média Nota Estudante      *\n");
        printf("* (3) %% Exercicio resolvido    *\n");
        printf("* (0) Voltar                    *\n");
        printf("******* Menu Estatisticas *******\n");
        printf("OPCAO:");
        scanf("%d",&opcao); 
        if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 0){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 0);
    return opcao;
}

// confirmar saida
//    |
//   \/

//confirmar saida
int confirmar_Sim_ou_Nao(char texto[], char texto_cancelado[], char texto_confirmado[]) {
    char opcao;
    int sair, tamanho_texto = strlen(texto),tamanho_texto_cancelado = strlen(texto_cancelado),tamanho_texto_confirmado = strlen(texto_confirmado);;
    do{
        for (int i = 0; i < tamanho_texto; i++){
            printf("%c",texto[i]);
        }
        fflush(stdin);
        scanf(" %c", &opcao);
        if (opcao == 'N' || opcao == 'n')
        {
            for (int i = 0; i < tamanho_texto_cancelado; i++){
                printf("%c",texto_cancelado[i]);
            }
            sair = 0;
        } else if (opcao == 'S' || opcao == 's') {
            for (int i = 0; i < tamanho_texto_confirmado; i++){
                printf("%c",texto_confirmado[i]);
            }
            getch();
            sair = 1;
        } else {
            printf("Esta opcao nao foi apresentada, por favor responda com \"[S]\" ou \"[N]\"\n");
        }
    } while (opcao != 'N' && opcao != 'n' && opcao != 'S' && opcao != 's' );
    return sair;
}

//ler dados estudantes
int ler_dados_estudante(t_estudante vetor_estudantes[],int numero_alunos) {
    int  contador = numero_alunos + 1, numero_aluno_procurar = 0, flag_estudante_procurado = 0;
    vetor_estudantes[numero_alunos].id = contador; //id
    do {
        numero_aluno_procurar = ler_numero_inteiro("\nInsira o numero do estudante (deve estar compreendido entre e 2249999)",2230001,2249999); //pede e devolve o numero de aluno
        flag_estudante_procurado = procurar_estudante(vetor_estudantes,numero_alunos, numero_aluno_procurar); //manda para a função
        if (flag_estudante_procurado == -1) {
            vetor_estudantes[numero_alunos].numero = numero_aluno_procurar; //guarda o valor inserido no array se não existir
        } else {
            system("cls");
            printf("\nO aluno com o numero indicado ja se encontra registado escolha outro numero\n"); //mensagem de erro
        }
    } while (flag_estudante_procurado != -1);
    printf("\nInsira o nome do estudante: "); //nome do aluno
    fgets(vetor_estudantes[numero_alunos].nome, TAMANHO_STRING, stdin);
    vetor_estudantes[numero_alunos].nome[strcspn(vetor_estudantes[numero_alunos].nome, "\n")] = '\0'; //Usamos o strcspn para tirar o Enter após colocar o nome
    vetor_estudantes[numero_alunos].e_mail = strcat(vetor_estudantes[numero_alunos].numero, "@my.ipleiria.pt");
    return contador;
}

//ler dados fichas
int ler_dados_ficha(t_ficha vetor_fichas[],int numero_fichas) {
    int  contador = numero_fichas + 1;
    int numero_ficha_procurar = 0, flag_ficha_procurado = 0; //vai ser usado no futuro para procurar fichas para evitar que sejam repetidas
    SYSTEMTIME t; // Declara a strutura SYSTEMTIME
    GetLocalTime(&t); //recebe o tempo local do sistema
    vetor_fichas[numero_fichas].id = contador; //id
    do { //nome da ficha
        numero_ficha_procurar = ler_numero_inteiro("\nInsira o numero da ficha (este deve estar compreendido entre 0 e 10)",0,MAXIMO_FICHAS); //pede e devolve o numero da ficha
        flag_ficha_procurado = procurar_ficha(vetor_fichas,numero_fichas, numero_ficha_procurar); //manda para a função
        if (flag_ficha_procurado == -1) {
            vetor_fichas[numero_fichas].nome == strcat("Ficha ",flag_ficha_procurado); //guarda o novo nome da ficha se não tiver sido encontrado
        } else {
            system("cls");
            printf("\nA Ficha com o numero indicada ja se encontra registada escolha outro numero para a sua ficha\n"); //mensagem de erro
        }
    } while (flag_ficha_procurado != -1);
    vetor_fichas[numero_fichas].total_exe = ler_numero_inteiro("\nInsira o numero de exercicios da ficha (este deve estar compreendido entre 0 e 10)",0,MAXIMO_EXE);
    vetor_fichas[numero_fichas].data_publi.dia = t.wDay; //data - dia
    vetor_fichas[numero_fichas].data_publi.mes = t.wMonth; //data - mes
    vetor_fichas[numero_fichas].data_publi.ano = t.wYear; //data - ano
    return contador;
}


/*
typedef struct 
{
    int id; DONE
    int id_ficha; DONE
    char nome[TAMANHO_STRING]; DONE
    char dificuldade[TAMANHO_STRING];
    char tipo_solucao[TAMANHO_STRING];
} t_exercicio;
*/

//ler dados exercicios
int ler_dados_exercicios(t_exercicio vetor_exercicios[],int numero_exercicios, t_ficha vetor_fichas[],int numero_fichas) {
    int  contador = numero_exercicios + 1;
    int numero_ficha_procurar = 0, flag_ficha_procurado = 0;
    vetor_exercicios[numero_exercicios].id = contador; //id
    do { //id_ficha
        numero_ficha_procurar = ler_numero_inteiro("\nInsira o numero da ficha a que este exercicio vai estar ligado(este deve estar compreendido entre 0 e 10)",0,MAXIMO_FICHAS); //pede e devolve o numero da ficha
        flag_ficha_procurado = procurar_ficha(vetor_fichas,numero_fichas, numero_ficha_procurar); //manda para a função
        if (flag_ficha_procurado == -1) {
            system("cls");
            printf("\nNão foram encontradas fichas com o numero indicado,\ninsira uma ficha já previamente registada\n"); //mensagem de erro
        } else {
            vetor_exercicios[numero_exercicios].id_ficha = flag_ficha_procurado;
            printf("\nFicha encontrada, exercicio associado à ficha selecionada!\n"); //mensagem de sucesso
        }
    } while (flag_ficha_procurado != -1);
    printf("\nInsira o nome do exercicio: "); //nome do exercicio
    ler_entre_X_opcoes(vetor_exercicios[numero_exercicios].dificuldade); //regime do estudante
    fgets(vetor_exercicios[numero_exercicios].nome, TAMANHO_STRING, stdin);
    vetor_fichas[numero_fichas].nome[strcspn(vetor_fichas[numero_fichas].nome, "\n")] = '\0'; //Usamos o strcspn para tirar o Enter após colocar o nome
    return contador;
}

//ler regime estudante
void ler_entre_2_opcoes(char vetor[],char mensagem[],int quant_opcoes) {
    int opcao;
    do{
        printf("\n(1) - Diurno\n(2) - Pos Laboral\nInsira o regime do estudante: "); //regime do aluno
        scanf("%d",&opcao);
        fflush(stdin);
        if  (opcao != 1 && opcao != 2) {
            printf("O valor inserido não se encontra de entre as opcoes apresentadas!!!\nPorfavor insira");
        } else {
            if (opcao == 1) {
                strcpy(regime,"Diurno");
            } else {
                strcpy(regime,"Pos Laboral");
            }
        }
    } while (opcao != 1 && opcao != 2);
}


//procura estudante
int procurar_estudante(t_aluno vetor_estudantes[], int numero_alunos,int numero_estudante_procurar) {
    int indice = 0, indice_aluno = -1;
    for (indice = 0; indice < numero_alunos; indice++){
        if (vetor_estudantes[indice].numero == numero_estudante_procurar) {
            indice_aluno = indice;
        }
    }
    return indice_aluno;
}

//procura ficha
int procurar_ficha(t_ficha vetor_fichas[], int numero_fichas,int numero_fichas_procurar) {
    int indice = 0, indice_ficha = -1;
    for (indice = 0; indice < numero_fichas; indice++){
        if (vetor_fichas[indice].nome == strcat("Ficha ",numero_fichas_procurar)) {
            indice_ficha = indice;
        }
    }
    return indice_ficha;
}





/*
   old bs 
      |   
     \/   
*/




//mostrar o vetor
void mostrar_dados_estudante(t_aluno vetor_estudantes[],int numero_alunos){
    int indice;
    if (vetor_estudantes[0].id == 0) {
        printf("Nao existem dados a apresentar, carregue os dados do ficheiro ou insira dados novos!!!\nPrima qualquer tecla para continuar...");
        getch();
        system("cls");
    }else {
        for (indice = 0; indice < numero_alunos; indice++){
            printf("\nId do Estudante: %d\n", vetor_estudantes[indice].id);
            printf("Nome do Estudante: %s\n", vetor_estudantes[indice].nome);
            printf("Numero do aluno: %d\n", vetor_estudantes[indice].numero);
            printf("Regime do curso: %s\n", vetor_estudantes[indice].regime);
            printf("Nota final do aluno: %d\n", vetor_estudantes[indice].nota_final);
            printf("Dia de lancamento: %d/%d/%d\n", vetor_estudantes[indice].data_lancamento.dia, vetor_estudantes[indice].data_lancamento.mes, vetor_estudantes[indice].data_lancamento.ano);
        } 
    }
}

//inserir no fichero binario
void gravar_ficheiro_binario(t_aluno vetor_estudantes[], int numero_alunos) {
    FILE *file_alunos = fopen(FILE_PATH_ESTUDANTE, "wb");

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
    FILE *file_alunos = fopen(FILE_PATH_ESTUDANTE, "rb");

    if (file_alunos == NULL) {
        printf("ERRO No carregamento de dados!");
    } else {
        fread(&numero_estudantes, sizeof(int), 1, file_alunos); // Lê o numero de estudantes
        fread(vetor_estudantes, sizeof(t_aluno), numero_estudantes, file_alunos); // Lê o array de estudantes
        printf("Dados carregados com sucesso!!!");
    }
    fclose(file_alunos);
    //faz return do numero de estudantes lido
    return numero_estudantes;
}



//alterar a nota final do estudante
void alterar_nota_final_estudante(t_aluno vetor_estudantes[], int numero_alunos) {
    int numero_aluno_procurar = 0, flag_estudante_procurado = 0;
    
    numero_aluno_procurar = ler_numero_inteiro("\nInsira o numero do estudante (deve estar compreendido entre 2230001 e 2249999)",2230001,2249999); //pede e devolve o numero de aluno
    flag_estudante_procurado = procurar_estudante(vetor_estudantes,numero_alunos, numero_aluno_procurar); //manda para a função

    if (flag_estudante_procurado != -1) {
        printf("A nota atual do aluno é: %d\n",vetor_estudantes[flag_estudante_procurado].nota_final);
        vetor_estudantes[flag_estudante_procurado].nota_final = ler_numero_inteiro("\nInsira a nova final (min 0 max 20) do estudante", 0, 20);
    }else{
        printf("\nO aluno nao foi encontrado");     
    }
}

// Estatísticas das avaliações - Wilson
void mostrar_estatisticas(t_aluno vetor_estudantes[], int numero_alunos) {
    int indice = 0, indice_aluno = -1, nota_mais_alta = 0, nota_mais_baixa = 20, soma = 0;
    float media = 0;
    char estudante_melhor_nota[TAMANHO_STRING], estudante_pior_nota[TAMANHO_STRING];
    for (indice = 0; indice < numero_alunos; indice++){
        if (vetor_estudantes[indice].nota_final > nota_mais_alta) {
            nota_mais_alta = vetor_estudantes[indice].nota_final;
            strcpy(estudante_melhor_nota,vetor_estudantes[indice].nome);
        }
        if (vetor_estudantes[indice].nota_final < nota_mais_baixa) {
            nota_mais_baixa = vetor_estudantes[indice].nota_final;
            strcpy(estudante_pior_nota,vetor_estudantes[indice].nome);
        }
        soma = soma + vetor_estudantes[indice].nota_final;
    }
    media = soma/indice;
    printf("A nota mais alta foi: %d - Que foi do aluno: %s\n", nota_mais_alta, estudante_melhor_nota);
    printf("A nota mais baixa foi: %d - Que foi do aluno: %s\n",nota_mais_baixa, estudante_pior_nota);
    printf("A media de todas as notas foi: %.2f\n",media);
}