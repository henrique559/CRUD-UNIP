#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

#define MAX_STRING 50
#define MAX_DATA 100

int numData = 0;

//Struct para dados pessoais.
struct data
{
    //Dados
    char nome[MAX_STRING];
    char dataNascimento[MAX_STRING];
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    char email[MAX_STRING];
    char telefone[MAX_STRING];
    char cpf[MAX_STRING];
    //Ticket
    int tipoIngresso;
    float totalIngresso;
    int qntdIngresso;
    float precoIngresso;
    char metodoPagamento[MAX_STRING];
    int ticketID;    
}dados[MAX_DATA];

//Registro de dados
void registroDados (void);

//Mostrar dados
void mostrarDados (void);

//Compra e validação de ingressos
void vendaIngressos (void);

// INTERFACE
int main(void)
{
    //Função principal e menu do programa

    int option;

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
        //Telas do menu
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
                vendaIngressos();
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
        for(int i = 1; i <= X; i++)
        {
            printf("Cadastro [%d]: \n", i);
            printf("Digite aqui o seu nome: \n> ");
            fgets(dados[i].nome, MAX_STRING, stdin);
            dados[i].nome[strlen(dados[i].nome) - 1] = '\0';

            printf("\nDigite aqui sua data de nascimento: \n> ");
            fgets(dados[i].dataNascimento, MAX_STRING, stdin);
            dados[i].dataNascimento[strlen(dados[i].dataNascimento) - 1] = '\0';

            sscanf(dados[i].dataNascimento, "%d %d %d", &dados[i].diaNascimento, &dados[i].mesNascimento, &dados[i].anoNascimento);

            printf("\nDigite aqui o seu email: \n> ");
            fgets(dados[i].email, MAX_STRING, stdin);
            dados[i].email[strlen(dados[i].email) - 1] = '\0';

            printf("\nDigite aqui o seu numero de telefone: \n> ");
            fgets(dados[i].telefone, MAX_STRING, stdin);
            dados[i].telefone[strlen(dados[i].telefone) - 1] = '\0';

            printf("\nDigite aqui o seu CPF: \n> ");
            fgets(dados[i].cpf, MAX_STRING, stdin);
            dados[i].cpf[strlen(dados[i].cpf) - 1] = '\0';
            printf("\n---<Cadastro [%d] realizado com sucesso>---\n\n", i);

            numData++;
        }
    }
    else
    {
        printf("Limite de registros atingido.\n");
    }
    printf("Aperte [ENTER] continuar\n");
    while (getchar() != '\n');
    system("clear");
    //Animação de encerramento.
    printf("Voltando ao menu...\n");
    sleep(1);
}


void mostrarDados (void)
{
    system("clear");
    if(numData >= 1)
    {
        for(int i = 1; i <= numData; i++)
        {
            printf("-------------------------------------------------\n");
            printf("REGISTRO - [%d]\n", i+1);
            printf("Nome: %10s\n", dados[i].nome);
            printf("Data de nascimento: %d/%d/%d\n", dados[i].diaNascimento, dados[i].mesNascimento, dados[i].anoNascimento);
            printf("Email: %10s\n", dados[i].email);
            printf("Telefone: %10.11s\n", dados[i].telefone);
            printf("CPF: %10.11s\n", dados[i].cpf);
        }
    }
    else
    {
        system("clear");
        printf("Nenhum registro encontrado.\nFaça seu cadastro na opção (1)\n");
        sleep(3);
        return;
    }
    printf("-------------------------------------------------\n");
    while (getchar() != '\n');
    printf("Pressione [ENTER] para continuar\n");
    scanf("%c");
    system("clear");
    printf("Voltando ao menu...\n");
    sleep(1);
    system("clear");
}

void vendaIngressos (void)
{  
    if(numData >= 1)
    {
        int qntd;
        float precoIngresso = 30.00;
        printf("Qual a quantidade de ingressos desejados?\n");
        scanf("%d", &qntd);
        //Limpar Buffer
        while (getchar() != '\n');

        for(int j = 1; j <= qntd; j++)
        {
            printf("Escolha o tipo de ingresso\n1 - Inteiro = R$30,00\n2 - Meia entrada = R$15,00\n3 - Isento = R$00,00\n(OBS: Ingresso isento apenas para crianças menores de 6 anos e idosos maiores de 60 anos.)\n> ");
            scanf("%d", &dados[j].tipoIngresso);
        
            switch(dados[j].tipoIngresso)
            {
                case 1:
                    dados[j].precoIngresso = 30.00;
                    printf("\nIngresso selecionado: Inteiro\n");
                    printf("Valor: R$%.2f\n", dados[j].precoIngresso);
                    dados[j].precoIngresso++;
                    sleep(2);
                    break;

                case 2:
                    dados[j].precoIngresso = 15.00;
                    printf("\n Ingresso selecionado: Meia entrada\n");
                    printf("Valor: R$%.2f\n", dados[j].precoIngresso);
                    dados[j].precoIngresso++;
                    sleep(2);
                    break;

                case 3:
                    if(dados[j].anoNascimento <= 1960 || dados[j].anoNascimento >= 2017)
                    {
                        precoIngresso == 00.00;
                        printf("Ingresso selecionado: Isento\n");
                        printf("Valor: R$%.2f", (precoIngresso = 0) );
                    }
                    else
                    {
                        printf("Você nao está apto para comprar ingresso isento.\n");
                        sleep(2);
                    }
                    break;

            }
        while (getchar() != '\n');
        printf("\nQual o metodo de pagamento?\n(Aceitamos PIX, Crédito e Débito)\n> ");
        fgets(dados[j].metodoPagamento, MAX_STRING, stdin);
        dados[j].metodoPagamento[strlen(dados[j].metodoPagamento) - 1] = '\0';
        
        dados[j].ticketID = rand() % 100 + 1;
        printf("-------------------------------------------------\n");
        printf("INGRESSO - [%d]\n", j);
        printf("Nome: %10s\n", dados[j].nome);
        printf("CPF: %10.11s\n", dados[j].cpf);
        printf("Valor do ingresso: R$%5.2f\n", precoIngresso);
        printf("Método de pagamento: %s\n", dados[j].metodoPagamento);
        printf("ID do Ingresso: 000%d\n", dados[j].ticketID);
        printf("-------------------------------------------------\n");
        }
    }
    else
    {   
        printf("Nenhum registro encontrado.\nFaça seu cadastro na opção (1).\n");
        sleep(3);
    }
    printf("Pressione [ENTER] para voltar ao menu");
    while (getchar() != '\n');
}
   
