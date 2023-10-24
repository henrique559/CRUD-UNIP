#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

#define MAX_STRING 50
#define MAX_DATA 100

//Variaveis globais

int numData = 0;

//Struct para dados pessoais.
struct data
{
    char nome[MAX_STRING];
    char dataNascimento[MAX_STRING];
    char email[MAX_STRING];
    char telefone[MAX_STRING];
    char cpf[MAX_STRING];
    char cep[MAX_STRING];
    char endereco[MAX_STRING];
    
}dados[MAX_DATA];

//Registro de dados
void registroDados (void);

//Mostrar dados
void mostrarDados (void);

// INTERFACE
int main(void)
{
    //Função principal e menu do programa
    int  option;

    do 
    {
        system("clear");
        printf("\n @@@@@@@  @@@  @@@  @@@  @@@@@@@@   @@@@@@   @@@@@@@   @@@@@@@  \n@@@@@@@@  @@@  @@@@ @@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@  \n");
        printf("!@@       @@!  @@!@!@@@  @@!       @@!  @@@  @@!  @@@    @@!    \n!@!       !@!  !@!!@!@!  !@!       !@!  @!@  !@!  @!@    !@!    \n");
        printf("!@!       !!@  @!@ !!@!  @!!!:!    @!@!@!@!  @!@!!@!     @!!    \n!!!       !!!  !@!  !!!  !!!!!:    !!!@!!!!  !!@!@!      !!!    \n");
        printf(":!!       !!:  !!:  !!!  !!:       !!:  !!!  !!: :!!     !!:    \n:!:       :!:  :!:  !:!  :!:       :!:  !:!  :!:  !:!    :!:    \n");
        printf(" ::: :::   ::   ::   ::   :: ::::  ::   :::  ::   :::     ::    \n :: :: :  :    ::    :   : :: ::    :   : :   :   : :     :\n\n\n");

    
        printf("1- Registrar dados\n2- Listar dados\n3- Comprar ingressos\n4- Sobre o museu\n5- Administração\n6- Sair\n");
        printf("DIGITE A OPÇÂO A SEGUIR: \n");
        scanf(" %d", &option); 

        switch(option)
        {
            case 1:
                system("clear");
                registroDados();
                break;

            case 2:
                system("clear");
                mostrarDados();
                break;

            case 3:
                system("clear");
                printf("EM CONSTRUÇÃO ");
                break;

            case 4:

            break;

            case 5:

            break;

            case 6:
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
    
void registroDados (void)
{
    int X;
    printf("Insira quantas pessoas vão se cadastrar: \n");
    scanf(" %d", &X);

    //Limpar buffer do scanf     
    while (getchar() != '\n');

    //Estrutura de repetição para pegar dados.
    if(numData < MAX_DATA)
    {
        //BUG DE INPUT!
        for(int i = 1; i <= X; i++)
        {
            printf("Cadastro [%d]: \n", i);
            printf("Digite aqui o seu nome: \n> ");
            fgets(dados[i].nome, MAX_STRING, stdin);
            dados[i].nome[strlen(dados[i].nome) - 1] = '\0';

            printf("\nDigite aqui sua data de nascimento: \n> ");
            fgets(dados[i].dataNascimento, MAX_STRING, stdin);
            dados[i].dataNascimento[strlen(dados[i].dataNascimento) - 1] = '\0';

            printf("\nDigite aqui o seu email: \n> ");
            fgets(dados[i].email, MAX_STRING, stdin);
            dados[i].email[strlen(dados[i].email) - 1] = '\0';

            printf("\nDigite aqui o seu numero de telefone: \n> ");
            fgets(dados[i].telefone, MAX_STRING, stdin);
            dados[i].telefone[strlen(dados[i].telefone) - 1] = '\0';

            printf("\nDigite aqui o seu CPF: \n> ");
            fgets(dados[i].cpf, MAX_STRING, stdin);
            dados[i].cpf[strlen(dados[i].cpf) - 1] = '\0';

            printf("\nDigite aqui seu Endereço: \n> ");
            fgets(dados[i].endereco, MAX_STRING, stdin);
            dados[i].endereco[strlen(dados[i].endereco) - 1] = '\0';

            printf("\nDigite aqui o seu CEP: \n> ");
            fgets(dados[i].cep, MAX_STRING, stdin);
            dados[i].cep[strlen(dados[i].cep) - 1] = '\0';
            numData++;

            printf("---<Cadastro [%d] realizado com sucesso>---\n", i);
            sleep(2);
            system("clear");
        }
    }
    else
    {
        printf("Limite de registros atingido.\n");
    }

    //Animação de encerramento.
    printf("Voltando ao menu.\n");
    sleep(1);
    system("clear");
    printf("Voltando ao menu..\n");
    sleep(1);
    system("clear");
    printf("Voltando ao menu...\n");
    sleep(1);
    system("clear");
}


void mostrarDados (void)
{
    system("clear");
    if(numData >= 1)
    {
        for(int i = 1; i <= numData; i++)
        {
            printf("-------------------------------------------------\n");
            printf("REGISTRO - [%d]\n", i);
            printf("Nome: %10s\n", dados[i].nome);
            printf("Data de nascimento: %10s\n", dados[i].dataNascimento);
            printf("Email: %10s\n", dados[i].email);
            printf("Telefone: %10s\n", dados[i].telefone);
            printf("CPF: %10s\n", dados[i].cpf);
            printf("CEP: %10s\n", dados[i].cep);
            printf("Endereço: %10s\n", dados[i].endereco);
            printf("-------------------------------------------------\n");
        }
    }
    else
    {
        system("clear");
        printf("[Nenhum registro encontrado]\n");
        sleep(3);
        system("clear");
        return;
    }
    char opt;
     while (getchar() != '\n');
    printf("Deseja continuar?\n> ");
    scanf("%c", &opt);
    system("clear");
}