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
    char e_mail[TAMANHO_STRING];
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






//prototipos de funções

//  antigos 
//    |
//   \/
void gravar_ficheiro_binario(t_estudante vetor_estudantes[],int numero_alunos);

void alterar_nota_final_estudante(t_estudante vetor_estudantes[], int numero_alunos);
void mostrar_estatisticas(t_estudante vetor_estudantes[], int numero_alunos);
int ler_ficheiro_binario(t_estudante vetor_estudantes[]);
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
int procurar_estudante(t_estudante vetor_estudantes[], int numero_alunos ,int numero_estudante_procurar);
int procurar_exercicio(t_exercicio vetor_exercicios[], int numero_exercicios ,int numero_exercicio_procurar, t_ficha vetor_fichas[], int numero_fichas,int numero_fichas_procurar);
int procurar_ficha(t_ficha vetor_fichas[], int numero_fichas ,int numero_ficha_procurar);
int procurar_submissao(t_submissao vetor_submissoes[], int numero_submissoes ,int numero_submissao_procurar);   

//leitura de dados
int ler_dados_estudante(t_estudante vetor_estudantes[],int numero_alunos);
int ler_dados_ficha(t_ficha vetor_fichas[],int numero_fichas);
int ler_dados_exercicios(t_exercicio vetor_exercicios[],int numero_exercicios,t_ficha vetor_fichas[],int numero_fichas);

//funções genéricas
void ler_entre_2_opcoes(char vetor[],char mensagem[],char opcao1[],char opcao2[]);
void ler_entre_3_opcoes(char vetor[],char mensagem[],char opcao1[],char opcao2[],char opcao3[]);
int ler_numero_inteiro(char[],int, int);
int confirmar_Sim_ou_Nao(char[], char[], char[]);

//mostrar
void mostrar_dados_estudante(t_estudante vetor_estudantes[],int numero_alunos);
void mostrar_dados_ficha(t_ficha vetor_fichas[],int numero_fichas);
void mostrar_dados_exercicios(t_exercicio vetor_exercicios[],int numero_exercicios,t_ficha vetor_fichas[],int numero_fichas);

//função main
int main() {
    t_estudante vetor_alunos[MAXIMO_ALUNOS] = {0};
    t_ficha vetor_fichas[MAXIMO_FICHAS] = {0};
    t_exercicio vetor_exercicios[MAXIMO_EXE] = {0};
    int numero_alunos = 0,numero_fichas = 0, numero_exercicios = 0;
    int sair = 0, escolha = 0;
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
                    numero_alunos = ler_dados_estudante(vetor_alunos, numero_alunos);
                    break;
                case 2:
                    system("cls");
                    mostrar_dados_estudante(vetor_alunos, numero_alunos);
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
        case 2: //fichas
            system("cls");
            do{
                escolha = menu_opcoes_fichas();
                switch (escolha)
                {
                case 1:
                    system("cls");
                    numero_fichas = ler_dados_ficha(vetor_fichas,numero_fichas);
                    break;
                case 2:
                    mostrar_dados_ficha(vetor_fichas,numero_fichas);
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
        case 3: //exercicios
            system("cls");
            do{
                escolha = menu_opcoes_exercicios();
                switch (escolha)
                {
                case 1:
                    system("cls");
                    numero_exercicios = ler_dados_exercicios(vetor_exercicios, numero_exercicios, vetor_fichas, numero_fichas);
                    break;
                case 2:
                    system("cls");
                    mostrar_dados_exercicios(vetor_exercicios, numero_exercicios,vetor_fichas, numero_fichas);
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
                escolha = menu_opcoes_submicoes();
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
                escolha = menu_opcoes_estatisticas();
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
            break;
        case 7: //ler dados ficheiro
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

//menu de menus
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

//  processamento de dados
//         |
//        \/

//ler ler entre 2 opcoes dadas pelo programador e atibuir ao vetor enviado
void ler_entre_2_opcoes(char vetor[],char mensagem[],char opcao1[],char opcao2[]) {
    int opcao = 0;
    do{
        system("cls");
        printf("\n(1) - %s\n(2) - %s\n%s",opcao1,opcao2,mensagem);
        scanf("%d",&opcao);
        fflush(stdin);
        if  (opcao != 1 && opcao != 2) {
            printf("O valor inserido não se encontra de entre as opcoes apresentadas!!!\nPorfavor Insira");
        } else { 
            if (opcao == 1) {
                strcpy(vetor,opcao1);
            } else {
                strcpy(vetor,opcao2);
            }
        }
    } while (opcao != 1 && opcao != 2);
}

//ler ler entre 3 opcoes dadas pelo programador e atibuir ao vetor enviado
void ler_entre_3_opcoes(char vetor[],char mensagem[],char opcao1[],char opcao2[], char opcao3[]) {
    int opcao = 0;
    do{
        printf("\n(1) - %s\n(2) - %s\n(3) - %s\n%s\n",opcao1,opcao2,opcao3,mensagem);
        scanf("%d",&opcao);
        fflush(stdin);
        if  (opcao != 1 && opcao != 2 && opcao != 3) {
            printf("O valor inserido não se encontra de entre as opcoes apresentadas!!!\nPorfavor Insira");
        } else { 
            if (opcao == 1) {
                strcpy(vetor,opcao1);
            } else if (opcao == 2){
                strcpy(vetor,opcao2);
            } else {
                strcpy(vetor,opcao3);
            }
        }
    } while (opcao != 1 && opcao != 2 && opcao != 3);
}

//le numero inteiro
int ler_numero_inteiro(char texto[],int min, int max){
    int num = 0;
    do{
        printf("%s: ",texto);
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

//confirmar saida
int confirmar_Sim_ou_Nao(char texto[], char texto_cancelado[], char texto_confirmado[]) {
    char opcao;
    int sair;
    do{
        printf("%s",texto);
        fflush(stdin);
        scanf(" %c", &opcao);
        if (opcao == 'N' || opcao == 'n')
        {
            printf("%s",texto_cancelado);
            sair = 0;
        } else if (opcao == 'S' || opcao == 's') {
            printf("%s",texto_confirmado);
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
    //char numero_aluno_str[20];
    vetor_estudantes[numero_alunos].id = contador; //id
    do {
        numero_aluno_procurar = ler_numero_inteiro("\nInsira o numero do estudante (deve estar compreendido entre 2230001 e 2249999)",2230001,2249999); //pede e devolve o numero de aluno
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
    //sprintf(vetor_estudantes[numero_alunos].e_mail, "%d@my.ipleiria.pt", numero_aluno_procurar);
    printf("\nInsira o e-mail do estudante: "); //email do estudant
    fgets(vetor_estudantes[numero_alunos].e_mail, TAMANHO_STRING, stdin);
    vetor_estudantes[numero_alunos].e_mail[strcspn(vetor_estudantes[numero_alunos].e_mail, "\n")] = '\0'; //Usamos o strcspn para tirar o Enter após colocar o nome
    return contador;
}

//ler dados fichas 
int ler_dados_ficha(t_ficha vetor_fichas[],int numero_fichas) {
    int contador = numero_fichas + 1;
    int numero_ficha_procurar = 0, flag_ficha_procurado = 0; //vai ser usado no futuro para procurar fichas para evitar que sejam repetidas
    char nome_ficha[50];  // TEMP - Até resposta do stor
    SYSTEMTIME t; // Declara a strutura SYSTEMTIME
    GetLocalTime(&t); //recebe o tempo local do sistema
    vetor_fichas[numero_fichas].id = contador; //id
    do { //nome da ficha
        numero_ficha_procurar = ler_numero_inteiro("\nInsira o numero da ficha (este deve estar compreendido entre 0 e 10)",0,MAXIMO_FICHAS); //pede e devolve o numero da ficha
        flag_ficha_procurado = procurar_ficha(vetor_fichas,numero_fichas, numero_ficha_procurar); //manda para a função
        if (flag_ficha_procurado == -1) {
            sprintf(nome_ficha, "Ficha %d", numero_ficha_procurar); // TEMP - Até resposta do stor
            strcpy(vetor_fichas[numero_fichas].nome, nome_ficha); // TEMP - Até resposta do stor
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

//ler dados exercicios
int ler_dados_exercicios(t_exercicio vetor_exercicios[],int numero_exercicios,t_ficha vetor_fichas[],int numero_fichas) {
    int  contador = numero_exercicios + 1;
    int numero_ficha_procurar = 0, flag_exercicio_procurado = 0, numero_exercicio_procurar = 0;
    vetor_exercicios[numero_exercicios].id = contador; //id
    do { //id_ficha
        numero_ficha_procurar = ler_numero_inteiro("\nInsira o numero da ficha a que este exercicio vai estar ligado(este deve estar compreendido entre 0 e 10)",0,MAXIMO_FICHAS); //pede e devolve o numero da ficha
        numero_exercicio_procurar = ler_numero_inteiro("\nInsira o numero do exercicio a procurar (este deve estar compreendido entre 0 e 10)",0,MAXIMO_EXE); //pede e devolve o numero do exercicios
        flag_exercicio_procurado = procurar_exercicio(vetor_exercicios, numero_exercicios, numero_exercicio_procurar, vetor_fichas, numero_fichas, numero_ficha_procurar); //manda para a função
        if (flag_exercicio_procurado == -2) {
            vetor_exercicios[numero_exercicios].id_ficha = flag_exercicio_procurado;
            printf("\nExercicio encontrada, exercicio associado à ficha selecionada!\n"); //mensagem de sucesso
        } else {
            system("cls");
            printf("\nJá existe um exercicio com numero indicado na ficha indicada,\n insira um exercicio ainda não previamente registado neste ficha\n"); //mensagem de erro
        }
    } while (flag_exercicio_procurado != -2 && flag_exercicio_procurado != -1);
    printf("\nInsira o nome do exercicio: "); //nome do exercicio
    fgets(vetor_exercicios[numero_exercicios].nome, TAMANHO_STRING, stdin);
    vetor_exercicios[numero_exercicios].nome[strcspn(vetor_exercicios[numero_exercicios].nome, "\n")] = '\0'; //Usamos o strcspn para tirar o Enter após colocar o nome
    ler_entre_2_opcoes(vetor_exercicios[numero_exercicios].tipo_solucao,"Insira o tipo de solução do exercicio: ","Algoritmo","Codigo");
    ler_entre_3_opcoes(vetor_exercicios[numero_exercicios].dificuldade,"Insira a dificuldade do exercicio: ","Elevada","Media","Baixa");
    return contador;
}

//procura estudante
int procurar_estudante(t_estudante vetor_estudantes[], int numero_alunos,int numero_estudante_procurar) {
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
    char nome_ficha[TAMANHO_STRING]; // TEMP - Até resposta do stor
    sprintf(nome_ficha, "Ficha %d", numero_fichas_procurar); // TEMP - Até resposta do stor
    for (indice = 0; indice < numero_fichas; indice++){
        if (strcmp(vetor_fichas[indice].nome, nome_ficha) == 0) { // TEMP - Até resposta do stor (o if aqui é o "problema")
            indice_ficha = indice;
        }
    }
    return indice_ficha;
}

//procurar exericio
int procurar_exercicio(t_exercicio vetor_exercicios[],int numero_exercicios,int numero_exercicio_procurar,t_ficha vetor_fichas[],int numero_fichas,int id_ficha_procurar){
    int indice_numero_fichas,indice_numero_exericios,indice_ficha=-1,indice_exercicio=-1;
    
    indice_ficha = procurar_ficha(vetor_fichas, numero_fichas, numero_exercicio_procurar);
    if(indice_ficha == -1){
        system("cls");
        printf("\nNão foram encontradas fichas com o numero indicado,\ninsira uma ficha já previamente registada\n");
        indice_exercicio = -2;
    } else {
        for(indice_numero_exericios=0;indice_numero_exericios<numero_exercicios;indice_numero_exericios++){
            if(vetor_exercicios[indice_numero_exericios].id==numero_exercicio_procurar && vetor_exercicios[indice_numero_exericios].id_ficha==id_ficha_procurar){
                indice_exercicio=indice_numero_exericios;
            }
        }
    }
    return indice_exercicio;
}

//mostrar o vetor estudante
void mostrar_dados_estudante(t_estudante vetor_estudantes[],int numero_alunos){
    int indice = 0,numero_aluno_procurar;
    char escolha[TAMANHO_STRING];
    if (vetor_estudantes[0].id == 0) {
        printf("Nao existem dados a apresentar, carregue os dados do ficheiro ou insira dados novos!!!\nPrima qualquer tecla para continuar...");
        getch();
        system("cls");
    } else {
        ler_entre_2_opcoes(escolha, "Escolha se quer apresentar todos os estudantes ou um em especifico: ","Todos","Especifico");
        if (strcmp(escolha,"Especifico")  == 0) {
            numero_aluno_procurar = ler_numero_inteiro("\nInsira o numero do estudante a procurar (deve estar compreendido entre 2230001 e 2249999)",2230001,2249999);
            indice = procurar_estudante(vetor_estudantes, numero_alunos,numero_aluno_procurar);
            if (indice != -1) {
                printf("\nId do Estudante: %d\n", vetor_estudantes[indice].id);
                printf("Numero do Estudante: %d\n", vetor_estudantes[indice].numero);
                printf("Nome do Estudante: %s\n", vetor_estudantes[indice].nome);
                printf("E-mail do Estudante: %s\n", vetor_estudantes[indice].e_mail);
            } else {
                printf("O numero inserido não foi encontrado nos registos, carregue os dados dos ficheiros ou insira estudantes!");
            }
        } else {
            for (indice = 0; indice < numero_alunos; indice++){
                printf("\nId do Estudante: %d\n", vetor_estudantes[indice].id);
                printf("Numero do Estudante: %d\n", vetor_estudantes[indice].numero);
                printf("Nome do Estudante: %s\n", vetor_estudantes[indice].nome);
                printf("E-mail do Estudante: %s\n", vetor_estudantes[indice].e_mail);
            } 
        }
    }
}

//mostrar o vetor ficha
void mostrar_dados_ficha(t_ficha vetor_ficha[],int numero_ficha){
    int indice = 0,numero_ficha_procurar;
    char escolha[TAMANHO_STRING];
    if (vetor_ficha[0].id == 0) {
        printf("Nao existem dados a apresentar, carregue os dados do ficheiro ou insira dados novos!!!\nPrima qualquer tecla para continuar...");
        getch();
        system("cls");
    } else {
        ler_entre_2_opcoes(escolha, "Escolha se quer apresentar todas as fichas ou uma em especifico:","Todas","Especifica");
        if (strcmp(escolha,"Especifica")  == 0) {
            numero_ficha_procurar = ler_numero_inteiro("\nInsira o numero da ficha a procurar (este deve estar compreendido entre 0 e 10)",0,MAXIMO_EXE);
            indice = procurar_ficha(vetor_ficha, numero_ficha, numero_ficha_procurar);
            if (indice != -1) {
                printf("\nId da ficha: %d\n", vetor_ficha[indice].id);
                printf("Nome da ficha: %s\n", vetor_ficha[indice].nome);
                printf("Total de Exercicios: %d\n", vetor_ficha[indice].total_exe);
                printf("Data de Publicacao: %d\\%d\\%d\n", vetor_ficha[indice].data_publi.dia, vetor_ficha[indice].data_publi.mes,vetor_ficha[indice].data_publi.ano);
            } else {
                printf("O numero inserido nao foi encontrado nos registos, carregue os dados dos ficheiros ou insira uma ou mais fichas!");
            }
        } else {
            for (indice = 0; indice < numero_ficha; indice++){
                printf("\nId da ficha: %d\n", vetor_ficha[indice].id);
                printf("Nome da ficha: %s\n", vetor_ficha[indice].nome);
                printf("Total de Exercicios: %d\n", vetor_ficha[indice].total_exe);
                printf("Data de Publicacao: %d\\%d\\%d\n", vetor_ficha[indice].data_publi.dia, vetor_ficha[indice].data_publi.mes,vetor_ficha[indice].data_publi.ano);
            } 
        }
    }
}

//mostrar o vetor exercicios
void mostrar_dados_exercicios(t_exercicio vetor_exercicios[], int numero_exercicios, t_ficha vetor_fichas[], int numero_fichas) {
    int indice = 0,numero_exercicio_procurar = 0, numero_ficha_procurar = 0;
    char escolha[TAMANHO_STRING];
    if (vetor_exercicios[0].id == 0) {
        printf("Nao existem dados a apresentar, carregue os dados do ficheiro ou insira dados novos!!!\nPrima qualquer tecla para continuar...");
        getch();
        system("cls");
    } else {
        ler_entre_2_opcoes(escolha, "Escolha se quer apresentar todas as fichas ou uma em especifico:","Todas","Especifica");
        if (strcmp(escolha,"Especifica")  == 0) {
            numero_exercicio_procurar = ler_numero_inteiro("\nInsira o numero do exercicio a procurar (este deve estar compreendido entre 0 e 10)",0,MAXIMO_EXE);
            numero_ficha_procurar = ler_numero_inteiro("\nInsira o numero da ficha do exercicio a procurar (este deve estar compreendido entre 0 e 10)",0,MAXIMO_FICHAS);
            indice = procurar_exercicio(vetor_exercicios, numero_exercicios, numero_exercicio_procurar, vetor_fichas, numero_fichas, numero_ficha_procurar);
            if (indice != -1) {
                printf("\nID do Exercicio: %d\n", vetor_exercicios[indice].id);
                printf("ID da Ficha: %d\n", vetor_exercicios[indice].id_ficha);
                printf("Nome do Exercicio: %s\n", vetor_exercicios[indice].nome);
                printf("Dificuldade: %s\n", vetor_exercicios[indice].dificuldade);
                printf("Tipo de Solucao: %s\n", vetor_exercicios[indice].tipo_solucao);
            } else {
                printf("O numero inserido nao foi encontrado nos registos, carregue os dados dos ficheiros ou insira uma ou mais fichas!");
            }
        } else {
            for (indice = 0; indice < numero_exercicios; indice++){
                printf("\nID do Exercicio: %d\n", vetor_exercicios[indice].id);
                printf("ID da Ficha: %d\n", vetor_exercicios[indice].id_ficha);
                printf("Nome do Exercicio: %s\n", vetor_exercicios[indice].nome);
                printf("Dificuldade: %s\n", vetor_exercicios[indice].dificuldade);
                printf("Tipo de Solucao: %s\n", vetor_exercicios[indice].tipo_solucao);
            } 
        }
    }
}









/*
   old bs 
      |   
     \/   
*/



/*


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
}*/