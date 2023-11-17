#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

//DADOS PRO PRÉ-PROCESSADOR
#define MAX_STRING 50
#define MAX_DATA 100

            /*Variaveis Globais*/

int numData = 0;
int login = 0;

            /*Ponteiros Globais*/

char *nomePTR;
char *emailPTR;
char *senhaPTR;
int *cpfPTR;
int *idadePTR;

            /*Structs Globais*/

typedef struct DATA
{
    //DADOS
    char nome[MAX_STRING];
    int idade;
    char sexo[MAX_STRING]; 
    char email[MAX_STRING];
    char senha[MAX_STRING];
    char senha2[MAX_STRING];
    int telefone[MAX_STRING];
    int numCPF;

    //INGRESSOS
    int ingressoInteiro;
    int ingressoMeia;
    int ticketID;

    //SysADM;
    char sysLogin[MAX_STRING];
    char sysPassword[MAX_STRING];
}DADOS;

            /*FUNÇÕES*/

//Escrever arquivo .csv
void criarArquivo(void);

//Abrir arquivo .csv
void abrirArquivo(void);

// Gerenciar dados
void gerenciarDados (void);

//Registro de dados
void registrarDados(void);

//Mostrar dados
void mostrarDados(void);

//Importar dados
void importarDados(void);

//Editar dados
void editarDados(void);

//Deletar dados
void pesquisarDados(void);

//Compra e validação de ingressos
void vendaIngressos(void);

// Deletar dados
void deletarDados(void);

//  Administração de sistema
void sysAdmin(void);

//  Login dos usuarios
void loginDados(void);

// Sobre o Museu
void museuDados(void);

// Validar ID
void validarID(void);

int main (void)
{
    srand(time(NULL));
    int option;
    do 
    {
        system("clear");
        printf("\n @@@@@@@  @@@  @@@  @@@  @@@@@@@@   @@@@@@   @@@@@@@   @@@@@@@  \n@@@@@@@@  @@@  @@@@ @@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@  \n");
        printf("!@@       @@!  @@!@!@@@  @@!       @@!  @@@  @@!  @@@    @@!    \n!@!       !@!  !@!!@!@!  !@!       !@!  @!@  !@!  @!@    !@!    \n");
        printf("!@!       !!@  @!@ !!@!  @!!!:!    @!@!@!@!  @!@!!@!     @!!    \n!!!       !!!  !@!  !!!  !!!!!:    !!!@!!!!  !!@!@!      !!!    \n");
        printf(":!!       !!:  !!:  !!!  !!:       !!:  !!!  !!: :!!     !!:    \n:!:       :!:  :!:  !:!  :!:       :!:  !:!  :!:  !:!    :!:    \n");
        printf(" ::: :::   ::   ::   ::   :: ::::  ::   :::  ::   :::     ::    \n :: :: :  :    ::    :   : :: ::    :   : :   :   : :     :\n\n\n");

    
        printf("  ********************** Bem-Vindo! *********************\n");
        printf("  * 1.Fazer login                                       *\n");
        printf("  * 2.Registrar dados                                   *\n");
        printf("  * 3.Editar dados                                      *\n");
        printf("  * 4.Comprar ingressos                                 *\n");
        printf("  * 5.Sobre o museu                                     *\n");
        printf("  * 6.Administração                                     *\n");
        printf("  * 7.Sair                                              *\n");
        printf("  *******************************************************\n");
        printf("\nPor favor, escolha a opção de 1 a 7: \n");
        scanf(" %d", &option); 
        //Telas do menu
        switch(option)
        {
            case 1:
                system("clear");
                loginDados();
               break;

            case 2:
                system("clear");
                registrarDados();
                break;

            case 3:
                system("clear");
                gerenciarDados();
                break;

            case 4:
                system("clear");
                //vendaIngressos();
                break;
            
            case 5:
                system("clear");
                break;

            case 6:
                system("clear");
                break;

            case 7:
                system("clear");
                printf("Saindo do programa...");
                return 0;
                break;

            default:
            system("clear");
            printf("Opção invalida!, tente novamente.\n");
        }
    }  
    while (option);
}

void registrarDados(void)
{
    int qntd;
    DADOS cadastro[MAX_DATA];
    static int i;

    if(numData < MAX_DATA)
    {
        for(i = 0; i < MAX_DATA; i++)
        {
            system("clear");
            printf("\t  *********************\n");
            printf("\t  * REGISTRO DE DADOS *\n");
            printf("\t  *********************\n");
            while (getchar() != '\n');
            printf("\nPor favor, preencha as informações: \n");

            printf("\nDigite seu nome completo: \n");
            fgets(cadastro[i].nome, MAX_STRING, stdin);
            cadastro[i].nome[strlen(cadastro[i].nome) - 1] = '\0';

            printf("\nDigite sua idade: \n");
            scanf("%d", &cadastro[i].idade);
            while (getchar() != '\n');

            printf("\nDigite aqui o seu gênero: \n");
            fgets(cadastro[i].sexo, MAX_STRING, stdin);
            cadastro[i].sexo[strlen(cadastro[i].sexo) - 1] = '\0';

            printf("\nDigite seu CPF: \n");
            scanf("%d", &cadastro[i].numCPF);
            while (getchar() != '\n');

            printf("\nDigite aqui o seu telefone: \n");
            scanf("%d", &cadastro[i].telefone);
            while (getchar() != '\n');

            printf("\nDigite seu email: \n");
            fgets(cadastro[i].email, MAX_STRING, stdin);
            cadastro[i].email[strlen(cadastro[i].email) - 1] = '\0';

            printf("\nDigite sua senha: \n");
            fgets(cadastro[i].senha, MAX_STRING, stdin);
            cadastro[i].senha[strlen(cadastro[i].senha) - 1] = '\0';

            printf("\nPor favor, digite novamente sua senha: \n");
            fgets(cadastro[i].senha2, MAX_STRING, stdin);
            cadastro[i].senha2[strlen(cadastro[i].senha2) - 1] = '\0';

            int PasswordCheck =(strcmp(cadastro[i].senha, cadastro[i].senha2));
            if(PasswordCheck == 0)
            {
                int opt;
                system("clear");
                printf("Cadastro realizado com sucesso!\n");
                numData++;
                sleep(1);

                printf("Deseja salvar os dados?\n1- Sim\n2- Nao");
                scanf("%d", &opt);
                if(opt == 1)
                {
                    criarArquivo();
                    printf("Aperte [ENTER] continuar\n");
                    while (getchar() != '\n');
                }
                else
                {
                    printf("Voltando ao menu...");
                    return;
                }
            }
            else
            {
                //Recursão
                printf("Senha incorreta, tente novamente.\n");
                registrarDados();
            }
        }
    }
    else
    {
        printf("Limite atingido\n");
    }
}

void mostrarDados (void)
{
    system("clear");

    DADOS cadastro[MAX_DATA];
    if(numData >= 1)
    {
        for(int i = 0; i <= numData; i++)
        {
            printf("-------------------------------------------------\n");
            printf("REGISTRO - [%d]\n", (i+1));
            printf("Nome: %10s\n", cadastro[i].nome);
            printf("Idade: %10d\n", cadastro[i].idade);
            printf("Email: %10s\n", cadastro[i].email);
            printf("Telefone: %10d\n", cadastro[i].telefone);
            printf("CPF: %10d\n", cadastro[i].numCPF);
        }
    }
    else
    {
        system("clear");
        printf("Nenhum registro encontrado.\nFaça seu cadastro na opção (1)\n");
        sleep(2);
        return;
    }
    printf("-------------------------------------------------\n");
    while (getchar() != '\n');
    printf("Pressione [ENTER] para continuar\n");
    scanf("%c");
    system("clear");
}

void editarDados (void)
{
    DADOS cadastro[MAX_DATA];
    int editar;
    
    printf("Qual registro você gostaria de mudar?");
    scanf("%d", &editar);
    while (getchar() != '\n');
    for(int i = editar; i == editar; i++)
    {
        printf("\nDigite seu nome completo: \n");
        fgets(cadastro[i].nome, MAX_STRING, stdin);
        cadastro[i].nome[strlen(cadastro[i].nome) - 1] = '\0';

        printf("\nDigite sua idade: \n");
        scanf("%d", &cadastro[i].idade);
        while (getchar() != '\n');

        printf("\nDigite aqui o seu gênero: \n");
        fgets(cadastro[i].sexo, MAX_STRING, stdin);
        cadastro[i].sexo[strlen(cadastro[i].sexo) - 1] = '\0';

        printf("\nDigite seu CPF: \n");
        scanf("%d", &cadastro[i].numCPF);
        while (getchar() != '\n');

        printf("\nDigite aqui o seu telefone: \n");
        scanf("%d", &cadastro[i].telefone);
        while (getchar() != '\n');

        printf("\nDigite seu email: \n");
        fgets(cadastro[i].email, MAX_STRING, stdin);
        cadastro[i].email[strlen(cadastro[i].email) - 1] = '\0';

        printf("\nDigite sua senha: \n");
        (cadastro[i].senha, MAX_STRING, stdin);
        cadastro[i].senha[strlen(cadastro[i].senha) - 1] = '\0';

        printf("\nPor favor, digite novamente sua senha: \n");
        fgets(cadastro[i].senha2, MAX_STRING, stdin);
        cadastro[i].senha2[strlen(cadastro[i].senha2) - 1] = '\0';

        int PasswordCheck =(strcmp(cadastro[i].senha, cadastro[i].senha2));
        if(PasswordCheck == 0)
        {
            int opt;
            system("clear");
            printf("Cadastro atualizado com sucesso!\n");
        }
        else
        {
            //Recursão
            printf("Senha incorreta, tente novamente.\n");
            editarDados();
        }
    }
}

void deletarDados (void)
{
    DADOS cadastro[MAX_DATA];
    char emailLogin[MAX_DATA];
    char senhaLogin[MAX_DATA];
    int opt;
    int ID;

    printf("Deseja mesmo deletar sua conta?\n[1] - Sim\n[2] - Não");
    scanf("%d", &opt);

    if(opt == 1)
    {
        printf("Digite o N° da sua conta:\n");
        scanf("%d", &ID);

        for(int i = ID - 1; i < MAX_DATA - 1; i++)
        {
            cadastro[i] = cadastro[i + 1];
        }
        numData--;        
    }

    else
    {
        return;
    }
}

void criarArquivo (void)
{
    DADOS cadastro;
    FILE *dados;
    dados = fopen ("dados.csv", "a");

    if(dados == NULL)
    {
        printf("Erro ao criar o arquivo, tente novamente.\n");
        sleep(1);
        return;
    }
    fprintf(dados, "Nome: %s\nIdade: %d\nGenero: %s\nCPF: %d\n Telefone: %d\nEmail: %s\nSenha: %s\n", cadastro.nome, cadastro.idade, cadastro.sexo, cadastro.numCPF,
    cadastro.telefone, cadastro.email, cadastro.senha);

    printf("Arquivo criado com sucesso!");

    fclose(dados);
}

void loginDados(void)
{
    DADOS cadastro[MAX_DATA];
    char emailLogin[MAX_DATA];
    char senhaLogin[MAX_DATA];

    if (numData < 1)
    {
        system("clear");
        printf("Por favor, primeiro registre sua conta!\n");
        sleep(2);
        return;
    }
    else
    {
        system("clear");
        printf("Digite seu email: \n");
        fgets(emailLogin, MAX_STRING, stdin);
        emailLogin[strlen(emailLogin) - 1] = '\0';

        printf("Digite sua senha: \n");
        fgets(senhaLogin, MAX_STRING, stdin);
        senhaLogin[strlen(senhaLogin) - 1] = '\0';

        for(int i = 0; i < MAX_DATA; i++)
        {
            if(strcmp(cadastro[i].email, emailLogin) == 0 && strcmp(cadastro[i].senha, senhaLogin)==0)
            {
                printf("Login realizado com sucesso!\n");
                while (getchar() != '\n');
                login++;
                return;
            }
            else
            {
                printf("Dados incorretos, tente novamente.\n");
                loginDados();
            }
        }
    }   
}

void gerenciarDados (void)
{
    int options = 0;
    do
    {
        system("clear");
        printf("  ******************* Gerenciar dados *******************\n");
        printf("  * 1.Listar dados                                      *\n");
        printf("  * 2.Editar dados                                      *\n");
        printf("  * 3.Deletar dados                                     *\n");
        printf("  * 4.Exportar arquivo .CSV                             *\n");
        printf("  * 5.Importar arquivo .CSV                             *\n");
        printf("  * 6.Voltar ao menu principal                          *\n");
        printf("  *******************************************************\n");

        printf("Escolha uma opção: \n");
        scanf("%d", &options);

        switch (options)
        {
        case 1:
            mostrarDados();
            break;

        case 2:
            editarDados();
            break;

        case 3:
            deletarDados();
            break;
        
        case 4:
            criarArquivo();
            break;

        case 5:
            //importarDados();
            break;
        
        case 6:
            return;
            break;
        
        default:
        break;
        }
    }
    while (options);
}
