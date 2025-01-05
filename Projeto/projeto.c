//bibliotecas
#include<stdlib.h>  
// 1 Permite usar o  system("cls"); (limpar o ecrã)   fflush(stdin);  (para limpar o buffer do teclado) 
//nota:(" %c") != fflush(stdin), 
//o primeiro não limpa todo o buffer apenas uma parte, enquanto o segundo limpa todo o buffer, 
//uma solução elegante e simples para problemas onde caracteres como o 
//(~)til e a bolinha de numero (nº) podem criar problemas em inputs e menus.
#include<stdio.h>   
// 2 Biblioteca standart de input e output
#include<locale.h>  
// 3 Para poder por uma lingua de um local permitindo a utilização de certos tipos de carcteres como por exemplo "�" mesma situação do de baixo
#include<ctype.h>   
// 4 Permite fazer certos simbolos corretamente (por algum motivo não está a funcionar se antes da entrega ele não estiver a funcionar eu removo esta biblioteca)
#include<math.h>    
// 5 Para calcular expoentes com a função pow(b,e) e mais algumas funções matematicas
#include<time.h>    
// 6 Para usar o srand(time(NULL)); e outras funções relacionadas a horarios e datas
#include<windows.h> 
// 7 Para poder utilizar o SYSTEMTIME
#include<conio.h>   
// 8 Permite usar o getch(); (substitui parcialmente o getchar e permite pedir ao utilizador por inputs sem os guardar utilizado recorrentemente como metodo de "parar" um codigo para apresentar informação até ao utilizador escolher continuar, recorrente-mente utilizado no fim de menus de saida para informar o utlizador de saida do programa sem o mesmo fechar de forma abrupta)

//constantes
#define TAMANHO_STRING 100
#define MAXIMO_ALUNOS 100
#define MAXIMO_FICHAS 10
#define MAXIMO_EXE 10
#define MAXIMO_SUBMISSOES 10000
#define NOTA_MAX 100
#define NOTA_MIN 0

//constantes para o caminho de cada ficheiro, por questão de praticidade vamos criar 1 ficheiro para cada coisa
//um ficheiro para estudantes, um para fichas, um para exercicio, e um para submissoes
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
int ler_ficheiro_binario(t_estudante vetor_estudantes[]);

void mostrar_estatisticas(t_estudante vetor_estudantes[], int numero_alunos);

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
int verificar_limite_exercicios_ficha(t_exercicio vetor_exercicios[], int numero_exercicios, int id_ficha_procurar, t_ficha vetor_fichas[], int numero_fichas);
void le_string_para_vetor(char vetor[], char mensagem[]);
t_data ler_data(t_data data);

//mostrar
void mostrar_dados_estudante(t_estudante vetor_estudantes[],int numero_alunos);
void mostrar_dados_ficha(t_ficha vetor_fichas[],int numero_fichas);
void mostrar_dados_exercicios(t_exercicio vetor_exercicios[],int numero_exercicios,t_ficha vetor_fichas[],int numero_fichas);

void print_detalhes_estudante(t_estudante vetor_estudantes[], int indice);
void print_detalhes_ficha(t_ficha vetor_fichas[], int indice);
void print_detalhes_exercicio(t_exercicio vetor_exercicios[], int indice);

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
        printf("* (2) Menu Dados Fichas         *\n");
        printf("* (3) Menu Dados Exercicio      *\n");
        printf("* (4) Menu Dados Submissoes     *\n");
        printf("* (5) Menu Estatisticas         *\n");
        printf("* (6) Gravar dados em Ficheiro! *\n");
        printf("* (7) Ler dados de um Ficheiro! *\n");
        printf("* (0) Sair                      *\n");
        printf("********* Menu de Opcoes ********\n");
        printf("Valores nao numericos vao ser interpretados\ncomo a ultima opçcao apresentada\n");
        printf("OPCAO:");
        scanf("%d",&opcao);
        fflush(stdin);
        if (opcao < 0 || opcao > 7){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao < 0 || opcao > 7);
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
        printf("Valores nao numericos vao ser interpretados\ncomo a ultima opçcao apresentada\n");
        printf("OPCAO:");
        scanf("%d",&opcao);
        fflush(stdin);
        if (opcao < 0 || opcao > 2){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao < 0 || opcao > 2);
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
        printf("Valores nao numericos vao ser interpretados\ncomo a ultima opçcao apresentada\n");
        printf("OPCAO:");
        scanf("%d",&opcao);
        fflush(stdin);
        if (opcao < 0 || opcao > 2){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao < 0 || opcao > 2);
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
        printf("Valores nao numericos vao ser interpretados\ncomo a ultima opçcao apresentada\n");
        printf("OPCAO:");
        scanf("%d",&opcao);
        fflush(stdin);
        if (opcao < 0 || opcao > 2){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao < 0 || opcao > 2);
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
        printf("Valores nao numericos vao ser interpretados\ncomo a ultima opçcao apresentada\n");
        printf("OPCAO:");
        scanf("%d",&opcao);
        fflush(stdin);
        if (opcao < 0 || opcao > 2){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao < 0 || opcao > 2);
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
        printf("Valores nao numericos vao ser interpretados\ncomo a ultima opçcao apresentada\n");
        printf("OPCAO:");
        scanf("%d",&opcao);
        fflush(stdin);
        if (opcao < 0 || opcao > 2){
            system("cls");
            printf("\nO valor inserido nao se encontr na lista de opcoes,\nporfavor insira uma das opcoes indicadas\n");
        }
    } while (opcao < 0 || opcao > 2);
    return opcao;
}

//  processamento de dados
//   ___________|___________
//  |                      |
// \/                     \/

//    funções genericas
//          |
//         \/

//atribui a data aos valores enviados aos arrays
t_data ler_data(t_data data){
    SYSTEMTIME t; // Declara a strutura SYSTEMTIME mas com o nome t
    GetLocalTime(&t); //recebe o tempo local do sistema
    data.dia = t.wDay; //data - dia
    data.mes = t.wMonth; //data - mes
    data.ano = t.wYear; //data - ano
    return data;
}
//ler ler entre 2 opcoes dadas pelo programador e atibuir ao vetor enviado
void ler_entre_2_opcoes(char vetor[],char mensagem[],char opcao1[],char opcao2[]) {
    int opcao = 0;
    do{
        system("cls");
        printf("\n(1) - %s\n(2) - %s\n%s: ",opcao1,opcao2,mensagem);
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
        printf("\n(1) - %s\n(2) - %s\n(3) - %s\n%s: ",opcao1,opcao2,opcao3,mensagem);
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

//le string e altera a mesma diretamente no vetor
void le_string_para_vetor(char vetor[], char mensagem[]) {
    char string_a_guaradar[TAMANHO_STRING]; //declara um "buffer" de string onde vamos guardar a resposta do utilizador e manipular a mesma e dps vamos utilizar o resultado final deste para por no vetor enviado
    printf("\n%s: ",mensagem); //apresenta a mensagem envaida pelo utilizador
    fgets(string_a_guaradar, TAMANHO_STRING, stdin); //apanha a resposta em string e insere a mesma no vetor 
    string_a_guaradar[strcspn(string_a_guaradar, "\n")] = '\0'; //remove os caracteres de troca de linha e mete ed fim de string
    strcpy(vetor, string_a_guaradar); //copia a string acabadinha de montar para dentro do vetor enviado
    fflush(stdin); //limpa o buffer de entrada TOTAL (pode ser trocado por um do-while muito especifico que faz o mesmo mas não é tão facil de ler se me der vontade faço o do while em formato de fução e "crio" um novo metodo so para limpar o teclado)
}

//le numero inteiro
int ler_numero_inteiro(char texto[],int min, int max){
    int num = 0;
    do{
        printf("%s: ",texto, min-1);
        scanf("%d",&num);
        fflush(stdin);
        if (num < min || num > max){
            system("cls"); 
            printf("O valor introduzido nao segue as regras indicadas\n(prima qualquer tecla para continuar)\n");
            getch();
        }
        fflush(stdin);
    } while (num < min || num > max);
    return num;
}

//confirmar sim ou não
int confirmar_Sim_ou_Nao(char texto[], char texto_cancelado[], char texto_confirmado[]) {
    char opcao;
    int sair;
    do{
        printf("%s",texto);
        scanf(" %c", &opcao);
        fflush(stdin);
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

//  Leitura de dados
//        |
//       \/

//ler dados estudantes
int ler_dados_estudante(t_estudante vetor_estudantes[],int numero_alunos) {
    int  contador = numero_alunos + 1, numero_aluno_procurar = 0, flag_estudante_procurado = 0, min_aluno = 2230001,max_aluno = 2249999;
    char e_email_estudante_completo[TAMANHO_STRING];
    vetor_estudantes[numero_alunos].id = contador; //id
    do { //numero do estudante
        numero_aluno_procurar = ler_numero_inteiro("\nInsira o numero do estudante (deve estar compreendido entre 2230001 e 2249999)",min_aluno,max_aluno); //pede e devolve o numero de aluno
        flag_estudante_procurado = procurar_estudante(vetor_estudantes,numero_alunos, numero_aluno_procurar); //manda para a função
        if (flag_estudante_procurado == -1) {
            vetor_estudantes[numero_alunos].numero = numero_aluno_procurar; //guarda o valor inserido no array se não existir
        } else {
            system("cls");
            printf("\nO aluno com o numero indicado ja se encontra registado escolha outro numero\n"); //mensagem de erro
        }  
    } while (flag_estudante_procurado != -1);
    le_string_para_vetor(vetor_estudantes[numero_alunos].nome, "Insira o nome do estudante"); //guarda o nome do estudantenome do estudante
    sprintf(e_email_estudante_completo, "%d@my.ipleiria.pt", numero_aluno_procurar); //atrbui o resultado de um suposto printf a um vetor de caracteres (desta maneira podemos utilizar variveis de ints em situações com chars)
    strcpy(vetor_estudantes[numero_alunos].e_mail, e_email_estudante_completo); // copia o valor dentro do vetor de caracteres com o e-mail completo para o e_mail do estudante dentro do vetor (podia ter feito os dois juntos mas para ficar mais legivel separei contudo uma verção mais compacta destas duas linhas é possivel e essa mesma verção não utiliza o vetor de caracteres extra) 
    return contador;
}

//ler dados fichas 
int ler_dados_ficha(t_ficha vetor_fichas[],int numero_fichas) {
    int contador = numero_fichas + 1, numero_ficha_procurar = 0, flag_ficha_procurado = 0;
    char nome_ficha[TAMANHO_STRING]; 
    vetor_fichas[numero_fichas].id = contador; //id
    do { //nome da ficha
        numero_ficha_procurar = ler_numero_inteiro("\nInsira o numero da ficha (este deve estar compreendido entre 1 e 10)",1,MAXIMO_FICHAS); //pede e devolve o numero da ficha
        flag_ficha_procurado = procurar_ficha(vetor_fichas,numero_fichas, numero_ficha_procurar); //manda para a função
        if (flag_ficha_procurado == -1) {
            sprintf(nome_ficha, "Ficha %d", numero_ficha_procurar); 
            strcpy(vetor_fichas[numero_fichas].nome, nome_ficha); 
        } else {
            system("cls");
            printf("\nA Ficha com o numero indicada ja se encontra registada escolha outro numero para a sua ficha\n"); //mensagem de erro
        }
    } while (flag_ficha_procurado != -1);
    vetor_fichas[numero_fichas].total_exe = ler_numero_inteiro("\nInsira o numero de exercicios da ficha (este deve estar compreendido entre 1 e 10)",1,MAXIMO_EXE);
    vetor_fichas[numero_fichas].data_publi = ler_data(vetor_fichas[numero_fichas].data_publi);
    return contador;
}

//ler dados exercicios
int ler_dados_exercicios(t_exercicio vetor_exercicios[], int numero_exercicios, t_ficha vetor_fichas[], int numero_fichas) {
    int numero_ficha_procurar = 0, flag_exercicio_procurado = 0, numero_exercicio_procurar = 0, id_ficha_encontrada = -1, limite_atingido = 0, sair = 0, contador = numero_exercicios + 1;
    vetor_exercicios[numero_exercicios].id = contador;
    do {      
        numero_ficha_procurar = ler_numero_inteiro("\nInsira o numero da ficha a que este exercicio vai estar ligado (entre 1 e 10)", 1, MAXIMO_FICHAS);
        id_ficha_encontrada = procurar_ficha(vetor_fichas, numero_fichas, numero_ficha_procurar);
        if (id_ficha_encontrada == -1) {
            printf("\nFicha nao encontrada. Insira um numero de ficha valido.\n");
        } else {
            limite_atingido = verificar_limite_exercicios_ficha(vetor_exercicios, numero_exercicios, numero_ficha_procurar, vetor_fichas, numero_fichas);
            if (limite_atingido == 0) { //ainda tem espaço no vetor
                numero_exercicio_procurar = ler_numero_inteiro("\nInsira o numero do exercicio (entre 1 e 10)", 1, MAXIMO_EXE);
                flag_exercicio_procurado = procurar_exercicio(vetor_exercicios, numero_exercicios, numero_exercicio_procurar, vetor_fichas, numero_fichas, numero_ficha_procurar);
                if (flag_exercicio_procurado != -1) {
                    printf("\nJa existe um exercicio com o numero indicado nesta ficha.\n");
                } else {
                    vetor_exercicios[numero_exercicios].id_ficha = id_ficha_encontrada + 1;
                    le_string_para_vetor(vetor_exercicios[numero_exercicios].nome, "Insira o nome do exercicio");
                    ler_entre_2_opcoes(vetor_exercicios[numero_exercicios].tipo_solucao,"Insira o tipo de solucao do exercicio", "Algoritmo", "Codigo");
                    ler_entre_3_opcoes(vetor_exercicios[numero_exercicios].dificuldade,"Insira a dificuldade do exercicio", "Elevada", "Media", "Baixa");
                }   
            }
        }
        if (id_ficha_encontrada == -1 || flag_exercicio_procurado != -1 || limite_atingido == -1) { //mensagem de erro para inserção por excesso de exercicios
                sair = confirmar_Sim_ou_Nao("Quer abortar a inserção de dados ? (S/N)","OK! A abortar a inserção de dados","Compreendido, a continuar a inserção de dados!");
    	}
    } while (id_ficha_encontrada == -1 || flag_exercicio_procurado != -1 || limite_atingido == -1);
    if (sair == 1) {
        contador = contador - 1;
    }
    return contador;
}



//  procura de dados
//         |
//        \/

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
    char nome_ficha[TAMANHO_STRING]; //Mesmo metodo utilizado anteriormente no codigo
    sprintf(nome_ficha, "Ficha %d", numero_fichas_procurar); //Mesmo metodo utilizado anteriormente no codigo
    fflush(stdin);
    for (indice = 0; indice < numero_fichas; indice++){
        if (strcmp(vetor_fichas[indice].nome, nome_ficha) == 0) { // Mesmo metodo utilizado anteriormente no codigo
            indice_ficha = indice;
        }
    }
    
    return indice_ficha;
}

//procurar exericio
int procurar_exercicio(t_exercicio vetor_exercicios[],int numero_exercicios,int numero_exercicio_procurar,t_ficha vetor_fichas[],int numero_fichas,int id_ficha_procurar){
    int indice_numero_fichas,indice_numero_exericios,indice_ficha=-1,indice_exercicio=-1;
    indice_ficha = procurar_ficha(vetor_fichas, numero_fichas, id_ficha_procurar);
    if(indice_ficha == -1){
        // system("cls");
        indice_exercicio = -2;
        //Se der return de -2 ele vai dar return desse -2 e vai indicar que este exercicio não existe
    } else {
        //O vetor percorre o array de exercicios e vai verificar se existe a ficha 
        for(indice_numero_exericios=0;indice_numero_exericios<numero_exercicios;indice_numero_exericios++){
            if(vetor_exercicios[indice_numero_exericios].id==numero_exercicio_procurar && vetor_exercicios[indice_numero_exericios].id_ficha==id_ficha_procurar){
                indice_exercicio=indice_numero_exericios;
            }
                
        }
    }
    // -1 para quando o exercicio não existe na ficha
    // -2 para quando não existe ficha
    return indice_exercicio;
}

//  Verificações
//       |
//      \/

//verificara o limie de exercicios por ficha
int verificar_limite_exercicios_ficha(t_exercicio vetor_exercicios[], int numero_exercicios, int id_ficha_procurar, t_ficha vetor_fichas[], int numero_fichas) {
    int flag = 0,total_exercicios_ficha = 0, index = 0;
    id_ficha_procurar -=1; 
    for (index = 0; index <= numero_exercicios; index++) {
        if (vetor_exercicios[index].id_ficha == id_ficha_procurar); {
            total_exercicios_ficha++;
        }
    }
    if (total_exercicios_ficha > vetor_fichas[id_ficha_procurar].total_exe) {
        printf("\nJa foi atingido o limite maximo de %d exercicios para esta ficha.\n", vetor_fichas[id_ficha_procurar].total_exe);
        flag = -1;
    }
    return flag;
}

// apresentação de dados    
//        |
//       \/

//mostrar o vetor estudante
void mostrar_dados_estudante(t_estudante vetor_estudantes[],int numero_alunos){
    int indice = 0,numero_aluno_procurar;
    char escolha[TAMANHO_STRING];
    if (vetor_estudantes[0].id == 0) {
        printf("Nao existem dados a apresentar, carregue os dados do ficheiro ou insira dados novos!!!\nPrima qualquer tecla para continuar...");
        getch();
        system("cls");
    } else {
        ler_entre_2_opcoes(escolha, "Escolha se quer apresentar todos os estudantes ou um em especifico","Todos","Especifico");
        if (strcmp(escolha,"Especifico")  == 0) {
            numero_aluno_procurar = ler_numero_inteiro("\nInsira o numero do estudante a procurar (deve estar compreendido entre 2230001 e 2249999)",2230001,2249999);
            indice = procurar_estudante(vetor_estudantes, numero_alunos,numero_aluno_procurar);
            if (indice != -1) {
                print_detalhes_estudante(vetor_estudantes, indice);
            } else {
                printf("O numero inserido não foi encontrado nos registos, carregue os dados dos ficheiros ou insira estudantes!");
            }
        } else {
            for (indice = 0; indice < numero_alunos; indice++){
                system("cls");
                print_detalhes_estudante(vetor_estudantes, indice);
            } 
        }
    }
}
void print_detalhes_estudante(t_estudante vetor_estudantes[], int indice) {
    printf("\nId do Estudante: %d\n", vetor_estudantes[indice].id);
    printf("Numero do Estudante: %d\n", vetor_estudantes[indice].numero);
    printf("Nome do Estudante: %s\n", vetor_estudantes[indice].nome);
    printf("E-mail do Estudante: %s\n", vetor_estudantes[indice].e_mail);
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
        ler_entre_2_opcoes(escolha, "Escolha se quer apresentar todas as fichas ou uma em especifico","Todas","Especifica");
        if (strcmp(escolha,"Especifica")  == 0) {
            numero_ficha_procurar = ler_numero_inteiro("\nInsira o numero da ficha a procurar (este deve estar compreendido entre 1 e 10)",1,MAXIMO_EXE);
            indice = procurar_ficha(vetor_ficha, numero_ficha, numero_ficha_procurar);
            if (indice != -1) {
                print_detalhes_ficha(vetor_ficha,indice);
            } else {
                printf("O numero inserido nao foi encontrado nos registos, carregue os dados dos ficheiros ou insira uma ou mais fichas!");
            }
        } else {
            for (indice = 0; indice < numero_ficha; indice++){
                print_detalhes_ficha(vetor_ficha,indice);
            } 
        }
    }
}
void print_detalhes_ficha(t_ficha vetor_fichas[], int indice) {
    printf("\nId da ficha: %d\n", vetor_fichas[indice].id);
    printf("Nome da ficha: %s\n", vetor_fichas[indice].nome);
    printf("Total de Exercicios: %d\n", vetor_fichas[indice].total_exe);
    printf("Data de Publicacao: %d\\%d\\%d\n", vetor_fichas[indice].data_publi.dia, vetor_fichas[indice].data_publi.mes,vetor_fichas[indice].data_publi.ano);
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
        ler_entre_2_opcoes(escolha, "Escolha se quer apresentar todas as fichas ou uma em especifico","Todas","Especifica");
        if (strcmp(escolha,"Especifica")  == 0) {
            numero_exercicio_procurar = ler_numero_inteiro("\nInsira o numero do exercicio a procurar (este deve estar compreendido entre 1 e 10)",1,MAXIMO_EXE);
            numero_ficha_procurar = ler_numero_inteiro("\nInsira o numero da ficha do exercicio a procurar (este deve estar compreendido entre 1 e 10)",1,MAXIMO_FICHAS);
            indice = procurar_exercicio(vetor_exercicios, numero_exercicios, numero_exercicio_procurar, vetor_fichas, numero_fichas, numero_ficha_procurar);
            if (indice != -1) {
                print_detalhes_exercicio(vetor_exercicios, indice);
            } else {
                printf("O numero inserido nao foi encontrado nos registos, carregue os dados dos ficheiros ou insira uma ou mais fichas!");
            }
        } else {
            for (indice = 0; indice < numero_exercicios; indice++){
                print_detalhes_exercicio(vetor_exercicios, indice);
            } 
        }
    }
}
void print_detalhes_exercicio(t_exercicio vetor_exercicios[], int indice) {
    printf("\nID do Exercicio: %d\n", vetor_exercicios[indice].id);
    printf("ID da Ficha: %d\n", vetor_exercicios[indice].id_ficha);
    printf("Nome do Exercicio: %s\n", vetor_exercicios[indice].nome);
    printf("Dificuldade: %s\n", vetor_exercicios[indice].dificuldade);
    printf("Tipo de Solucao: %s\n", vetor_exercicios[indice].tipo_solucao);
}





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

/*
 █████╗  ██████╗ █████╗ ██████╗ ███████╗██╗    ██╗
██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝██║    ██║
███████║██║     ███████║██████╔╝█████╗  ██║    ██║
██╔══██║██║     ██╔══██║██╔══██╗██╔══╝  ██║    ╚═╝
██║  ██║╚██████╗██║  ██║██████╔╝███████╗██║    ██╗
╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝    ╚═╝
*/