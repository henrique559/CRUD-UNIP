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

char nome[MAX_STRING];
int idade;
char sexo[MAX_STRING]; 
char email[MAX_STRING];
char senha[MAX_STRING];
char senha2[MAX_STRING];
int telefone;
int numCPF;
int ingressoI = 0;
int ingressoM = 0;
int ingressoF = 0;
int qntd = 0;
char pix1[] = {"PIX"};
char cartao[] = {"Credito/Debito"};
int total = 0;
int TicketID = 0;
char horario[MAX_STRING];


    /*Ponteiros Globais*/

char *nomePTR;
char *emailPTR;
char *senhaPTR;
int *idadePTR;
int *cpfPTR;

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
    int ingressoI;
    int ingressoM;
    int ingressoF;
    int ticketID;
    char horario[MAX_STRING];

    //SysADM;
    char sysLogin[MAX_STRING];
    char sysPassword[MAX_STRING];

    //PESQUISA
    char resposta[256];
    int avaliacao;
}
cadastro;

    /*FUNÇÕES*/

//Menu Login
void loginMenu (void);

//Escrever arquivo .csv
void criarArquivo(void);

// Gerenciar dados
void gerenciarDados (void);

//Registro de dados
void registrarDados(void);

//Mostrar dados
void mostrarDados(void);

//Editar dados
void editarDados(void);

//Deletar dados
void pesquisarDados(void);

//Compra e validação de ingressos
void vendaIngressos(void);

// Deletar dados
void deletarDados(void);

//  Login da administração de sistema
void sysAdmin(void);

//  Login dos usuarios
void loginDados(void);

// Sobre o Museu
void museuDados(void);

// Validar ID
void validarID(void);

// Ticket Museu
void ticketMuseu (void);

// Menu do Administração
void sysMenu (void);

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
        printf("  * 2.Registrar cadastro                                *\n");
        printf("  * 3.Sobre o museu                                     *\n");
        printf("  * 4.Administração                                     *\n");
        printf("  * 5.Sair                                              *\n");
        printf("  *******************************************************\n");
        printf("\nPor favor, escolha a opção de 1 a 5: \n");
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
                museuDados();
                break;

            case 4:
                system("clear");
                sysAdmin();
                break;
            
            case 5:
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
    int i;

    if(numData < MAX_DATA)
    {
            system("clear");
            printf("\t  +-------------------+\n");
            printf("\t  | REGISTRO DE DADOS |\n");
            printf("\t  +-------------------+\n");

            while (getchar() != '\n');
            printf("\nPor favor, preencha as informações: \n");

            printf("Digite seu nome completo: \n");
            fgets(nome, MAX_STRING, stdin);
            nome[strlen(nome) - 1] = '\0';

            printf("\nDigite sua idade: \n");
            scanf("%d", &idade);
            while (getchar() != '\n');

            printf("\nDigite aqui o seu gênero: \n");
            fgets(sexo, MAX_STRING, stdin);
            sexo[strlen(sexo) - 1] = '\0';

            printf("\nDigite seu CPF: \n");
            scanf("%d", &numCPF);
            while (getchar() != '\n');

            printf("\nDigite aqui o seu telefone: \n");
            scanf("%d", &telefone);
            while (getchar() != '\n');

            printf("\nDigite seu email: \n");
            fgets(email, MAX_STRING, stdin);
            email[strlen(email) - 1] = '\0';

            printf("\nDigite sua senha: \n");
            fgets(senha, MAX_STRING, stdin);
            senha[strlen(senha) - 1] = '\0';

            printf("\nPor favor, digite novamente sua senha: \n");
            fgets(senha2, MAX_STRING, stdin);
            senha2[strlen(senha2) - 1] = '\0';

            int PasswordCheck =(strcmp(senha, senha2));
            if(PasswordCheck == 0)
            {
                nomePTR = nome;
                emailPTR = email;
                idadePTR = &idade;
                cpfPTR = &numCPF;
                senhaPTR = senha;
                numData++;
                
                criarArquivo();
                system("clear");
            }
            else
            {
                //Recursão
                printf("Senha incorreta, tente novamente.\n");
                registrarDados();
            }
    
    }
    else
    {
        printf("Limite atingido\n");
    }
}

void mostrarDados (void)
{
    cadastro dados[MAX_DATA];
    FILE *data;
    int read = 0;

        data = fopen("dados.csv", "r");
        if(data == NULL)
        {
        printf("Erro ao abrir arquivo\n");
        getchar();
        return;
        }

        do
        {
            fscanf(data,
            "%100[^,],%d,%d,%d,%100[^,],%100[^,],%100[^,]",
            dados[numData].nome,
            &dados[numData].idade,
            &dados[numData].numCPF,
            &dados[numData].telefone,
            dados[numData].sexo,
            dados[numData].email,
            dados[numData].senha);
            while (getchar() != '\n')
            
            printf("Nome: %s\nIdade: %d\nCPF: %d\nTelefone: %d\nGenero: %s\nEmail: %s\n", dados[numData].nome, dados[numData].idade, dados[numData].numCPF, dados[numData].telefone, dados[numData].sexo,
            dados[numData].email);
            while(getchar() != '\n');    

            if (!feof(data))
            {
                printf("erro.\n");
                return;
            }

            if (ferror(data))
            {
                printf("Erro ao ler arquivo.\n");
                return;
            }   
        
        }while (!feof(data));
       
    fclose(data);
}

void editarDados (void)
{
        system("clear");
        printf("\t  *********************\n");
        printf("\t  * REGISTRO DE DADOS *\n");
        printf("\t  *********************\n");
        while (getchar() != '\n');
        printf("\nPor favor, preencha as informações: \n");

        printf("\nDigite seu nome completo: \n");
        fgets(nome, MAX_STRING, stdin);
        nome[strlen(nome) - 1] = '\0';

        printf("\nDigite sua idade: \n");
        scanf("%d", &idade);
        while (getchar() != '\n');

        printf("\nDigite aqui o seu gênero: \n");
        fgets(sexo, MAX_STRING, stdin);
        sexo[strlen(sexo) - 1] = '\0';

        printf("\nDigite seu CPF: \n");
        scanf("%d", &numCPF);
        while (getchar() != '\n');

        printf("\nDigite aqui o seu telefone: \n");
        scanf("%d", &telefone);
        while (getchar() != '\n');

        printf("\nDigite seu email: \n");
        fgets(email, MAX_STRING, stdin);
        email[strlen(email) - 1] = '\0';

        printf("\nDigite sua senha: \n");
        fgets(senha, MAX_STRING, stdin);
        senha[strlen(senha) - 1] = '\0';

        printf("\nPor favor, digite novamente sua senha: \n");
        fgets(senha2, MAX_STRING, stdin);
        senha2[strlen(senha2) - 1] = '\0';

        int PasswordCheck =(strcmp(senha, senha2));
        if(PasswordCheck == 0)
        {
            int opt;
            system("clear");
            printf("Cadastro atualizado com sucesso!\n");
            criarArquivo();
        }
        else
        {
            //Recursão
            printf("Senha incorreta, tente novamente.\n");
            editarDados();
        }
    
}

void deletarDados (void)
{
    cadastro dados[MAX_DATA];
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
            dados[i] = dados[i + 1];
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
    FILE *dados;
    dados = fopen ("dados.csv", "a");

    if(dados == NULL)
    {
        printf("Erro ao criar o arquivo, tente novamente.\n");
        printf("Pressione [ENTER] para sair");
        while(getchar() != '\n');
        return;
    }
        
    fprintf(dados, "%s,%d,%d,%d,%s,%s,%s\n", nome, idade, numCPF, telefone,
    sexo, email, senha);

    system("clear");
    printf("Cadastro realizado com sucesso!\n");
    printf("Pressione [ENTER] para voltar ao menu");
    while(getchar() != '\n');
    fclose(dados);
}

void loginDados(void)
{
    while(getchar() != '\n');
    cadastro dados[MAX_DATA];
    FILE *data;
    char emailLogin[MAX_DATA];
    char senhaLogin[MAX_DATA];
    int read = 0;
    if (numData < 1)
    {
        system("clear");
        printf("Por favor, primeiro registre sua conta!\n");
        printf("Pressione [ENTER] para voltar\n");
        while(getchar() != '\n');
        return;
    }
    else
    {
        system("clear");
        printf("\t  +-------------------+\n");
        printf("\t  |       LOGIN       |\n");
        printf("\t  +-------------------+\n\n");

        printf("Digite seu email: \n");
        fgets(emailLogin, MAX_STRING, stdin);
        emailLogin[strlen(emailLogin) - 1] = '\0';

        printf("\nDigite sua senha: \n");
        fgets(senhaLogin, MAX_STRING, stdin);
        senhaLogin[strlen(senhaLogin) - 1] = '\0';

        data = fopen("dados.csv", "r");
        if(data == NULL)
        {
        printf("Erro ao abrir arquivo\n");
        getchar();
        return; 
        }

        do
        {
            fscanf(data,
            "%100[^\n],%d,%d,%d,%100[^\n],%100[^\n],%100[^\n]",
            dados[numData].nome,
            &dados[numData].idade,
            &dados[numData].numCPF,
            &dados[numData].telefone,
            dados[numData].sexo,
            dados[numData].email,
            dados[numData].senha);
            while (getchar() != '\n');

            if(strcmp(emailLogin, email) == 0 && strcmp(senhaLogin, senha)==0)
            {
                printf("Login realizado com sucesso!\n");
                printf("Pressione [ENTER] para continuar");

                while(getchar() != '\n');
                loginMenu();
            }
            else
            {
                system("clear");
                printf("Dados incorretos, tente novamente.\n");
                printf("Pressione [ENTER] para continuar");
                while(getchar() != '\n');
                loginDados();
                return;
            }

            if (!feof(data))
            {
                printf("erro.\n");
                return;
            }

            if (ferror(data))
            {
                printf("Erro ao ler arquivo.\n");
                return;
            }   
        } 
        while (!feof(data));
        fclose(data);
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
        printf("  * 5.Voltar                                            *\n");
        printf("  *******************************************************\n");

        printf("Por favor, escolha uma opção de 1 a 5: \n");
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
            system("clear");
            return;
            break;
        
        default:
        break;
        }
    }
    while (options);
}

void loginMenu()
{
    int optt;
    do
    {
        system("clear");
        printf("  ******************** Minha conta **********************\n");
        printf("  * 1.Comprar ingressos                                 *\n");
        printf("  * 2.Imprimir Ticket                                   *\n");
        printf("  * 3.Gerenciar dados                                   *\n");
        printf("  * 4.Pesquisa de avaliação                             *\n");
        printf("  * 5.Voltar ao menu principal                          *\n");
        printf("  *******************************************************\n");
        printf("\nPor favor, escolha a opção de 1 a 5: \n");
        scanf("%d", &optt);
        while(getchar() != '\n');
        switch(optt)
        {
            case 1:
                vendaIngressos();
                break;

            case 2:
                ticketMuseu();
                break;

            case 3:
                gerenciarDados();
                break;
            
            case 4:
                //Pesquisa();
                break;

            case 5:
                return;
                break;

            default:
                break;  
        }
    }
    while(optt);
}

void vendaIngressos (void)
{  
    int ticketopt;
    int opt = 0;
    char nomes[MAX_STRING];
    int pix;
    int cvc;
    int validade1, validade2;
    int numCartao;

    system("clear");
    printf("  ************************ Venda ************************\n");
    printf("  *                                                     *\n");
    printf("  *                    Seja bem-vindo(a)                *\n");
    printf("  *                                                     *\n"); //Descricao
    printf("  * [HORARIO]                                           *\n");
    printf("  * Entrada disponível: das 08:00h as 17:00h            *\n");
    printf("  * (A bilheteria abrirá as 07:00h)                     *\n");
    printf("  *                                                     *\n");
    printf("  * [INGRESSOS]                                         *\n");  //O que falta?:
    printf("  * Ingresso inteiro: R$30,00                           *\n");  //Endereço
    printf("  * Meia entrada:     R$15,00                           *\n");  //Obras /temas
    printf("  * Ingresso isento:  R$00,00                           *\n");
    printf("  *                                                     *\n");
    printf("  * [REGRAS]                                            *\n");
    printf("  *  > Meia entrada disponivel somente para alunos de   *\n");
    printf("  *  faculdades e escolas da rede publica               *\n");
    printf("  *                                                     *\n");
    printf("  *  > Ingresso isento disponivel somente para crianças *\n");
    printf("  * menores de 5 anos e idosos maiores de 60 anos       *\n");
    printf("  *                                                     *\n");
    printf("  *******************************************************\n");
    printf("\nApós ler, pressione [ENTER] para continuar\n");
    getchar();

    system("clear");
    printf("[VENDA DE INGRESSOS]\n\n");
    printf("Qual tipo de ingresso deseja comprar?:\n");
    printf("[1] - Ingresso inteiro\n[2] - Meia entrada\n[3] - Ingresso isento\n[4] - Ambos\n");
    scanf("%d", &ticketopt);
    while(getchar() != '\n');

    switch(ticketopt)
    {
        case 1:
            printf("\nSelecione a quantidade de ingressos desejados: \n");
            scanf(" %d", &ingressoI);
            while(getchar() != '\n');

            printf("\nSelecione o horário de visita: [MANHA/TARDE]\n");
            fgets(horario, MAX_STRING, stdin);
            horario[strlen(horario) - 1] = '\0';

            ingressoI *= 30;
            total = ingressoI;
            printf("\nValor total: R$%.2f\n", (float) total);
            printf("Qual o metodo de pagamento?\n");
            printf("[1] - Crédito/Débito\n[2] - PIX\n");
            scanf(" %d", &opt);
            while(getchar() != '\n');

            if(opt == 1)
            {
                printf("Tipo de pagamento selecionado: [%s]\n", cartao);
                printf("Digite o nome no cartão de crédito: \n");
                scanf("%s", nomes);
                while(getchar() != '\n');

                printf("\nDigite aqui a data de validade do cartao: \n");
                scanf("%d %d", &validade1, &validade2);
                while(getchar() != '\n');

                printf("\nDigite aqui o numero do cartão: \n");
                scanf("%d", &numCartao);
                while(getchar() != '\n');

                printf("\nDigite aqui o CVC do cartão: \n");
                scanf("%d", &cvc);
                while(getchar() != '\n');

                if(numCartao < 99999999999998)
                {
                    printf("Numero de cartão invalido!\n");
                    return;
                }
                else
                {
                    printf("Compra realizada com sucesso!\n");
                    printf("Pressione [ENTER] para continuar");
                    while(getchar() != '\n');
                    ticketMuseu();
                }
            }

            else if (opt == 2)
            {
                printf("\nTipo de pagamento selecionado: %s\n", pix1);
                printf("Leia o QR CODE pelo aplicativo de banco do seu celular: \n\n");
                printf("   [PROTOTIPO-QRCODE]\n");
                printf("  ▄▄▄▄▄▄▄ ▄ ▄▄▄ ▄▄▄▄▄▄▄\n");
                printf("  █ ▄▄▄ █ ▄▄▀█  █ ▄▄▄ █\n");
                printf("  █ ███ █ █▀ ▄▀ █ ███ █\n");
                printf("  █▄▄▄▄▄█ ▄▀█▀█ █▄▄▄▄▄█\n");
                printf("   ▄ ▀█▀▄▀█▄▄█▀▄ ▄▀▀▀▄█ \n");
                printf("    ██ ▄▄ █ █▀▄ ▄█▀█ █  \n");
                printf("  ▄▄▄▄▄▄▄ ▀▀▄█▄ █▄▄█▄▀▀ \n");
                printf("  █ ▄▄▄ █  ▄  ▄▀ ▀ ▀█▀▀ \n");
                printf("  █ ███ █ ██▀ ▄█▀▄ ▀▄▀  \n");
                printf("  █▄▄▄▄▄█ █▄▄ ▄███▄ ▄ ▀ \n\n");
                printf("Após realizar o pagamento, prossiga com a compra apertando [ENTER] no teclado\n");
                while(getchar() != '\n');

                printf("\nCompra realizada com sucesso\n");
                while(getchar() != '\n');
                ticketMuseu();
            }

            break;
        
        case 2:
            printf("Selecione a quantidade de ingressos desejados: \n");
            scanf(" %d", &ingressoM);
            while(getchar() != '\n');

            printf("\nSelecione o horário de visita: [MANHA/TARDE]\n");
            fgets(horario, MAX_STRING, stdin);
            horario[strlen(horario) - 1] = '\0';

            ingressoM *= 15;
            total = ingressoM;
            printf("\nValor total: R$%.2f\n", (float) total);
            printf("Qual o metodo de pagamento?\n");
            printf("[1] - Crédito/Débito\n[2] - PIX\n");
            scanf("%d", &opt);
            while(getchar() != '\n');

            if(opt == 1)
            {
                printf("Tipo de pagamento selecionado: %s\n", cartao);
                printf("Digite o nome no cartão de crédito: \n");
                scanf("%s", nomes);
                while(getchar() != '\n');

                printf("\nDigite aqui a data de validade do cartao: \n");
                scanf("%d %d", &validade1, &validade2);
                while(getchar() != '\n');

                printf("\nDigite aqui o numero do cartão: \n");
                scanf("%d", &numCartao);
                while(getchar() != '\n');

                printf("\nDigite aqui o CVC do cartão: \n");
                scanf("%d", &cvc);
                while(getchar() != '\n');


                if(numCartao < 999999999999998)
                {
                    printf("Numero de cartão invalido!\n");
                    return;
                }
                else
                {
                    printf("Compra realizada com sucesso!\n");
                    while(getchar() != '\n');
                    ticketMuseu();
                }
            }

            else if (opt == 2)
            {
                printf("Tipo de pagamento selecionado: %s\n", pix1);
                printf("Leia o QR CODE pelo aplicativo de banco do seu celular: \n\n");
                printf("   [PROTOTIPO-QRCODE]\n");
                printf("  ▄▄▄▄▄▄▄ ▄ ▄▄▄ ▄▄▄▄▄▄▄\n");
                printf("  █ ▄▄▄ █ ▄▄▀█  █ ▄▄▄ █\n");
                printf("  █ ███ █ █▀ ▄▀ █ ███ █\n");
                printf("  █▄▄▄▄▄█ ▄▀█▀█ █▄▄▄▄▄█\n");
                printf("   ▄ ▀█▀▄▀█▄▄█▀▄ ▄▀▀▀▄█ \n");
                printf("    ██ ▄▄ █ █▀▄ ▄█▀█ █  \n");
                printf("  ▄▄▄▄▄▄▄ ▀▀▄█▄ █▄▄█▄▀▀ \n");
                printf("  █ ▄▄▄ █  ▄  ▄▀ ▀ ▀█▀▀ \n");
                printf("  █ ███ █ ██▀ ▄█▀▄ ▀▄▀  \n");
                printf("  █▄▄▄▄▄█ █▄▄ ▄███▄ ▄ ▀ \n\n");
                printf("Após realizar o pagamento, prossiga com a compra apertando [ENTER] no teclado\n");
                while(getchar() != '\n');

                printf("Compra realizada com sucesso\n");
                ticketMuseu();
            }

            break;

        case 3:
            if(idade > 6 && idade < 60)
            {
                printf("Você não está apto para comprar ingressos isentos.\n");
            }
            else
            {
            printf("Selecione a quantidade de ingressos desejados: \n");
            scanf(" %d", &ingressoI);
            while(getchar() != '\n');

            printf("Selecione o horário de visita: [MANHA/TARDE]\n");
            fgets(horario, MAX_STRING, stdin);
            horario[strlen(horario) - 1] = '\0';

            ingressoI *= 0;
            total = ingressoI;
            printf("Valor total: R$%.2f\n", (float) total);
            printf("Qual o metodo de pagamento?\n");
            printf("[1] - Crédito/Débito\n[2] - PIX\n");
            scanf("%d", &opt);
            while(getchar() != '\n');

            if(opt == 1)
            {
                printf("\nTipo de pagamento selecionado: %s\n", cartao);
                printf("Digite o nome no cartão de crédito: \n");
                scanf("%s", nomes);
                while(getchar() != '\n');

                printf("\nDigite aqui a data de validade do cartao: \n");
                scanf("%d %d", &validade1, &validade2);
                while(getchar() != '\n');

                printf("\nDigite aqui o numero do cartão: \n");
                scanf("%d", &numCartao);
                while(getchar() != '\n');

                printf("\nDigite aqui o CVC do cartão: \n");
                scanf("%d", &cvc);
                while(getchar() != '\n');


                if(numCartao < 999999999999998)
                {
                    printf("Numero de cartão invalido!\n");
                    return;
                }
                else
                {
                    printf("Compra realizada com sucesso!\n");
                    while(getchar() != '\n');
                }
            }
            else if (opt == 2)
            {
                printf("Tipo de pagamento selecionado: %s\n", pix1);
                printf("Leia o QR CODE pelo aplicativo de banco do seu celular: \n\n");
                printf("   [PROTOTIPO-QRCODE]\n");
                printf("  ▄▄▄▄▄▄▄ ▄ ▄▄▄ ▄▄▄▄▄▄▄\n");
                printf("  █ ▄▄▄ █ ▄▄▀█  █ ▄▄▄ █\n");
                printf("  █ ███ █ █▀ ▄▀ █ ███ █\n");
                printf("  █▄▄▄▄▄█ ▄▀█▀█ █▄▄▄▄▄█\n");
                printf("   ▄ ▀█▀▄▀█▄▄█▀▄ ▄▀▀▀▄█ \n");
                printf("    ██ ▄▄ █ █▀▄ ▄█▀█ █  \n");
                printf("  ▄▄▄▄▄▄▄ ▀▀▄█▄ █▄▄█▄▀▀ \n");
                printf("  █ ▄▄▄ █  ▄  ▄▀ ▀ ▀█▀▀ \n");
                printf("  █ ███ █ ██▀ ▄█▀▄ ▀▄▀  \n");
                printf("  █▄▄▄▄▄█ █▄▄ ▄███▄ ▄ ▀ \n\n");
                printf("Após realizar o pagamento, prossiga com a compra apertando [ENTER] no teclado\n");
                while(getchar() != '\n');

                printf("Compra realizada com sucesso\n");
                ticketMuseu();
            }

            }
            break;

        case 4:
            printf("Selecione a quantidade de ingressos inteiros desejados: \n");
            scanf(" %d", &ingressoI);
            while(getchar() != '\n');

            printf("\nSelecione a quantidade de ingressos meia entrada desejados: \n");
            scanf(" %d", &ingressoM);
            while(getchar() != '\n');

            printf("Selecione o horário de visita: [MANHA/TARDE]\n");
            fgets(horario, MAX_STRING, stdin);
            horario[strlen(horario) - 1] = '\0';

            ingressoI *= 30;
            ingressoM *= 15;
            total = ingressoM + ingressoI;
            printf("Valor total: R$%.2f\n", (float) total);
            printf("Qual o metodo de pagamento?\n");
            printf("[1] - Crédito/Débito\n[2] - PIX\n");
            scanf("%d", &opt);
            while(getchar() != '\n');

            if(opt == 1)
            {
                printf("\nTipo de pagamento selecionado: %s\n", cartao);
                printf("Digite o nome no cartão de crédito: \n");
                scanf("%s", nomes);
                while(getchar() != '\n');

                printf("\nDigite aqui a data de validade do cartao: \n");
                scanf("%d %d", &validade1, &validade2);
                while(getchar() != '\n');

                printf("\nDigite aqui o numero do cartão: \n");
                scanf("%d", &numCartao);
                while(getchar() != '\n');

                printf("\nDigite aqui o CVC do cartão: \n");
                scanf("%d", &cvc);
                while(getchar() != '\n');


                if(numCartao < 999999999999998)
                {
                    printf("Numero de cartão invalido!\n");
                    return;
                }
                else
                {
                    printf("Compra realizada com sucesso!\n");
                    while(getchar() != '\n');
                    ticketMuseu();
                }
            }
            else if (opt == 2)
            {
                printf("Tipo de pagamento selecionado: %s\n", pix1);
                printf("Leia o QR CODE pelo aplicativo de banco do seu celular: \n\n");
                printf("   [PROTOTIPO-QRCODE]\n");
                printf("  ▄▄▄▄▄▄▄ ▄ ▄▄▄ ▄▄▄▄▄▄▄\n");
                printf("  █ ▄▄▄ █ ▄▄▀█  █ ▄▄▄ █\n");
                printf("  █ ███ █ █▀ ▄▀ █ ███ █\n");
                printf("  █▄▄▄▄▄█ ▄▀█▀█ █▄▄▄▄▄█\n");
                printf("   ▄ ▀█▀▄▀█▄▄█▀▄ ▄▀▀▀▄█ \n");
                printf("    ██ ▄▄ █ █▀▄ ▄█▀█ █  \n");
                printf("  ▄▄▄▄▄▄▄ ▀▀▄█▄ █▄▄█▄▀▀ \n");
                printf("  █ ▄▄▄ █  ▄  ▄▀ ▀ ▀█▀▀ \n");
                printf("  █ ███ █ ██▀ ▄█▀▄ ▀▄▀  \n");
                printf("  █▄▄▄▄▄█ █▄▄ ▄███▄ ▄ ▀ \n\n");
                printf("Após realizar o pagamento, prossiga com a compra apertando [ENTER] no teclado\n");
                while(getchar() != '\n');

                printf("Compra realizada com sucesso\n");
                ticketMuseu();
            }
            break;
    }

}

void ticketMuseu (void)
{
    char opttt;

    TicketID = rand() % 100 + 1;
    system("clear");

    if (total == 0)
    {
        printf("Nenhum ticket encontrado\n");
        printf("Pressione [ENTER] para continuar\n");
        while(getchar() != '\n');
        return;
    }
    else
    {
        for(int i = 0; i < qntd; i++)
        {
            printf("  +-------------------------------+\n");
            printf("                                 \n");
            printf("  [TICKET - %d]                   \n", i+1);
            printf("  Nome:  %7s                      \n", nome);
            printf("  Idade:  %7d                     \n", idade);
            printf("  CPF:  %7d                        \n", numCPF);
            printf("  Horario:  %7s               \n", horario);
            printf("  Preço do ingresso:  %7.2f   \n", total);
            printf("  ID do ingresso:  000%7d        \n", TicketID);
            printf("                                \n");
        }
    }

    printf("  +-------------------------------+\n");
    printf("Deseja exportar o seu ticket em .CSV? (S/N)\n");
    scanf("%c", &opttt);

    if(opttt == 's' || opttt == 'S')
    {
        FILE *ticketz;
        ticketz = fopen("tickets.csv", "a");

        if(ticketz == NULL)
        {
            printf("Erro não identificado, voltando...\n");
            return;
        }
        fprintf(ticketz, "Nome:%7s\nIdade:%7d\nCPF:%7d\nHorario:%7s\nPreço:%7.2f\nID:%0007d\n\n",nome,idade,numCPF,horario,total,TicketID);
        fclose(ticketz);

        printf("Arquivo criado com sucesso!\n");
        printf("Pressione [Enter para sair]");
        while(getchar() != '\n');
    }
    else
    {
        return;
    }
}

void pesquisaMuseu (void)
{
    cadastro pesquisa[MAX_DATA];
    char opt;
    int num_respostas = 0;

    for (int i = 0; i <= num_respostas; i++)
    {
        printf("Avaliacao do museu\n");
        printf("Feedback:\n");

        scanf("%[^\n]%s", pesquisa[i].resposta);
        printf("%s", pesquisa[i].resposta);
        printf("Avalie de 0 a 10\n");
        printf("0 - Totalmente insatisfeito\n10 - Totalmente satisfeito\n");
        printf(">");
        scanf("%d", &pesquisa[i].avaliacao);

        if(pesquisa[i].avaliacao < 0 || pesquisa[i].avaliacao > 10)
        {
            printf("Por fvor, insira um numero válido\n");
        }

        printf("Deseja continuar? (s\\n)\n ");
        scanf("%d", &opt);

        if(opt == 'n' || opt == 'N' || i > MAX_DATA);
        {
            return;
        }
        num_respostas++;
    }
    //Imprimir resultado

}

void sysAdmin (void)
{
    char sysLogin[MAX_STRING];
    char sysPassword[MAX_DATA];
    char log[] = "admin";
    char pas[] = "admin";
    
    system("clear");

    printf("\t  +-------------------+\n");
    printf("\t  |       ADMIN       |\n");
    printf("\t  +-------------------+\n\n");

    printf("Digite aqui o login do usuario administrador: \n");
    while(getchar() != '\n');
    fgets(sysLogin, MAX_STRING, stdin);
    sysLogin[strlen(sysLogin) - 1] = '\0';

    printf("\nDigite aqui a senha do usuario administrador: \n");
    fgets(sysPassword, MAX_STRING, stdin);
    sysPassword[strlen(sysPassword) - 1] = '\0';

    if(strcmp(sysLogin, log) == 0 && strcmp(sysPassword, pas) == 0)
    {
        sysMenu();
    }
    else
    {
        printf("\nLogin incorreto\n");
        while(getchar() != '\n');
        return;
    }
}

void sysMenu (void)
{
    system("clear");
    int option;
    do
    {
        printf("  ******************** Administração ********************\n");
        printf("  * 1.Validar tickets                                   *\n");
        printf("  * 2.Listar dados                                      *\n");
        printf("  * 3.Excluir dados                                     *\n");
        printf("  * 4.Voltar ao menu principal                          *\n");
        printf("  *******************************************************\n");
        printf("Por favor, escolha as opções de 1 a 4\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                validarID();
                break;

            case 2:
                mostrarDados();
                break;
            
            case 3:
                deletarDados();
                break;

            case 4:
                return;
                break;

            default:
                printf("Selecione a opção correta.");

        }
    }while(option);
}

void validarID (void)
{
    int optsys;
    FILE *validar;
    validar = fopen("validar.csv", "a");

    if(validar == NULL)
    {
        printf("Erro\n");
        return;
    }

    system("clear");
    if(TicketID == 0)
    {
        while(getchar() != '\n');
        system("clear");
        printf("Não foi possível validar o seu ticket\nERRO: Ticket não encontrado\n");
        printf("\nPressione [ENTER] para voltar ao menu\n");
        while(getchar() != '\n');
        system("clear");
    }
    else
    {
        printf("ID: 000%d", TicketID);
        printf("Deseja validar o ticket?\n[1] - Sim\n[2] - Não");
        scanf("%d", &optsys);
        while(getchar() != '\n');
        if(optsys == 1)
        {
            fprintf(validar,"ID VALIDADO: 000%d\n", TicketID);
            fclose(validar);

            printf("ID Validado com sucesso.\n");
            printf("Pressione [ENTER] para voltar ao menu");
            while(getchar() != '\n'); 
            return;
        }
        else
        {
            printf("Pressione [ENTER] para voltar ao menu");
            while(getchar() != '\n'); 
            return;
        }
    }
}

void museuDados (void)
{
    int optt;
    do
    {
        system("clear");
        printf("  ****************************************** CineArt ********************************************\n");
        printf("  *                                                                                             *\n");
        printf("  *                                     Seja bem-vindo(a)                                       *\n");
        printf("  *                                                                                             *\n"); //Descricao
        printf("  *      Bem-vindo ao Museu CineArte, um lugar que une a sétima arte com a expressão artística. *\n");
        printf("  * Neste museu, você encontrará uma fusão perfeita entre o cinema e arte, também encontrará    *\n");
        printf("  * a nostalgia de três décadas inesquecíveis 80, 90 e 2000.                                    *\n");
        printf("  *      Cada exposição é uma experiência cinematográfica única, onde você pode apreciar as     *\n");
        printf("  * belezas, as emoções dos momentos icônicos, personagens inesquecíveis e suas peculiaridades. *\n");
        printf("  * Uma jornada imperdível esperado por você, capturando a essência mágica que torna o cinema   *\n");
        printf("  * uma forma de arte eterna.                                                                   *\n");
        printf("  *                                                                                             *\n");
        printf("  * > Ficamos na Avenida Paulista, 157, São Paulo - SP de segunda a sábado das 08:00 às 17:00.  *\n");
        printf("  *                                                                                             *\n");
        printf("  *   Conheça as nossas exposições mais famosas:                                                *\n");
        printf("  *   [1] - O Exterminador do futuro.                                                           *\n");
        printf("  *   [2] - Pulp Fiction.                                                                       *\n");
        printf("  *   [3] - Senhor dos Aneis.                                                                   *\n");
        printf("  *                                                                                             *\n");
        printf("  *   [4] - Voltar ao menu                                                                      *\n");
        printf("  *                                                                                             *\n");
        printf("  ***********************************************************************************************\n");
        printf("\n\nSelecione uma opção de 1 a 4\n");
        scanf("%d", &optt);
        while(getchar() != '\n');

        switch(optt)
        {
            case 1:
                int sair1;
                system("clear");
                printf("                     +---------------------------------------------------+\n");
                printf("                     |             [O Exterminador do futuro]            |\n");
                printf("                     +---------------------------------------------------+\n\n");

                printf("     +--------------------------------------------------------------------------------+\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⣴⣯⣷⣿⢟⣻⠋⠠⢀⠀⠀⠀⠹⡱⣴⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢒⣵⣿⣿⣿⣿⣿⣿⣛⠀⠀⢀⠆⠀⠀⠠⢂⡿⣄⣷⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢫⣾⣿⣿⣿⣿⣿⡇⡽⠀⠒⠀⠀⠀⠀⡐⡐⠁⣀⣚⡉⢸⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢡⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⡐⡐⡐⢨⡾⡽⡎⢈⢁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢐⠃⣾⣿⣽⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠠⢥⠅⣅⢹⣷⣷⡽⣧⠺⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  |\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠁⣽⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠠⠀⠀⣰⢸⢿⣈⡆⢹⣿⣟⠂⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢸⣾⣿⣿⣿⣿⣿⡏⠀⠀⠀⠠⠤⠦⠤⠀⠍⠘⠛⡟⡦⢻⢿⣿⢡⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⣜⣿⣿⣿⣿⣿⣯⢛⠆⠀⠀⠀⠀⠀⠂⠁⠀⠀⠈⠵⣴⣹⢟⠃⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢇⣿⣿⣿⣿⣿⣿⣿⣿⠀⣀⠠⢄⣒⣲⣬⣐⢀⠀⣴⣥⢀⠔⣺⣳⢤⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣽⣽⣏⢋⣿⣿⠻⢜⣭⣶⣿⢇⣀⠯⣾⣿⡏⠐⠈⢈⢀⠀⢸⢹⣂⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡋⣿⣿⣿⣻⣾⡏⠘⡮⢛⠿⠷⠶⠾⣽⢛⢣⠄⢠⢮⠈⠔⣺⡇⢻⣋⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣷⢇⣾⣧⡜⠐⠀⠈⠁⠀⠐⠒⠚⠇⢀⠜⣯⡔⣄⣇⣿⢸⢣⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣻⣿⣿⣸⢻⣿⣧⡀⣨⣤⣄⣀⠀⠀⢀⡴⣰⢞⣏⠂⠁⢻⡿⠛⣼⠣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⡟⣿⣻⣛⣸⡟⠀⡏⣷⣮⡃⣷⣷⣿⢿⣽⣏⡅⠂⠸⠂⠀⢿⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣯⣿⣿⣿⣿⣏⣠⣅⢰⣎⣿⣿⣻⣟⡿⠽⡳⢋⣾⡾⠀⠀⢟⡏⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣽⣹⣍⣄⣇⢮⡴⠛⢿⣧⢥⠹⠊⢀⢌⣶⣀⠄⠀⣸⡇⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡇⣯⣧⡯⢽⡼⢀⣠⠀⢸⡿⡙⢒⣴⣟⢻⠰⣿⣷⣶⡞⣿⢅⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡽⢿⡿⢷⣢⠤⣀⣠⣀⣀⣀⡠⣤⣤⣜⣾⣿⣿⣷⣯⢿⣿⣿⢀⠶⣽⡇⠈⢟⠵⡿⠹⡤⣸⣵⣿⣷⢷⠷⡼⢸⣿⣻⡶⣦⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣖⠻⢿⣿⣻⣽⣿⣾⣶⣯⣽⣛⡽⣯⣭⣩⢭⠶⠮⡿⣾⣿⢿⣈⠺⠫⣴⣞⣩⣭⢃⣳⣶⣿⣋⡼⢄⣾⣏⣹⣸⠍⢫⣎⣤⠎⣿⠻⣷⣄⡄⢀⣠⣀⣠⣤⣶⣾⢶⡤⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⠀⠀⠠⣴⣾⣿⠟⠋⠉⣽⣦⡱⣟⣽⣿⣼⣾⠯⢟⣙⡿⣷⣮⣾⣿⡦⢤⣸⣷⣋⡾⣯⣍⣿⣯⣭⣽⣟⣞⣿⣿⠫⣋⣐⣒⢫⡧⢇⠀⠛⠃⠒⣾⣈⢟⣶⣚⠻⡏⣯⠭⣙⣽⣞⣯⢻⡚⠁⠀⠀⠀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⠀⣲⣾⡯⠛⠃⠀⠀⣦⣿⣿⣟⡷⡹⡜⡟⠫⡶⠦⠄⣀⡭⠍⠞⣪⣽⣿⣿⣟⣻⣿⣝⣯⣻⣧⣿⣾⡵⣿⣟⣦⣗⡤⡳⠾⠎⠛⠻⢓⡸⣿⣯⣄⣤⡽⠿⠛⣋⣉⣉⣩⣉⣀⣩⠝⣛⣘⡧⣤⣦⣀⡀⠀⠀⠀⠀⠀|\n");
                printf("     |⠀⠀⠀⢸⣿⣏⣴⣪⣵⣿⣯⣻⣿⣿⣿⢸⢎⡽⣗⡗⠄⢨⢜⣾⣿⣾⣼⣷⣿⣛⢞⣫⠻⣞⡾⣿⣿⣿⡻⢿⣿⢽⡇⣷⢿⣿⣿⡧⣸⣹⡿⡸⣟⠯⢓⢩⡔⣎⣊⣈⢀⣰⣭⣵⢿⣻⣽⢹⢸⢯⠁⠛⠿⢟⣭⣴⡦⣄⠀⠀|\n");
                printf("     |⠀⢀⣠⣖⣭⣮⢽⣿⣿⣿⣿⣿⣿⣿⣷⠵⣶⣾⣽⡞⣵⣷⣥⣾⣿⣿⣿⣿⣿⣷⣷⣬⣹⣟⣷⢭⠽⢿⣻⣿⣷⣿⣿⠇⣘⡻⢻⡽⠋⣖⠕⡊⠴⣺⣕⢿⣰⡧⡜⠝⠹⢶⣿⣿⣞⢋⠂⢸⠈⢒⡄⠀⠀⠀⠈⠙⠛⣷⢭⣳|\n");
                printf("     |⢠⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣯⣤⣶⡿⢤⡽⣞⢁⣶⣽⢗⣻⡿⣿⡿⣿⣯⢏⣯⣿⣿⡿⢩⠛⢛⢿⣿⣯⣯⣾⡿⣷⢖⡶⢎⣕⡊⠛⡯⢟⣿⣷⣝⢷⣵⣼⣴⣩⣤⣶⣾⡅⠄⢾⢀⡌⣰⠀⠀⠀⠀⠀⠀⡀⠷⢿|\n");
                printf("     |⢾⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⡟⣿⡷⢶⣿⣿⣿⣿⣿⣿⣎⢦⢟⣋⡯⠾⣿⣿⣿⢯⡿⣩⣿⡛⠁⠁⢠⡁⢸⢿⣿⣿⢿⢭⠕⣡⠎⡾⢻⣿⣿⣶⣯⣯⣟⣿⣷⡟⣿⣿⣿⣿⣿⣿⠀⢀⣜⠿⣇⠋⠀⠀⠀⢠⣴⣷⣾⣿⢿|\n");
                printf("     |⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣥⣿⡉⠑⠹⡿⡯⢿⣿⣷⣿⣾⢽⣓⣶⣿⣿⣿⣋⢗⣴⣿⣗⡤⠀⠀⡇⠀⣸⣿⣿⣿⠟⠋⠞⣺⠟⢀⣾⣿⢻⣿⣿⣿⡋⢼⡿⠷⣿⣿⣿⣿⣿⡏⡴⣿⣼⣽⣿⣧⢀⣲⣶⣿⣿⠟⢛⠛⠀|\n");
                printf("     +--------------------------------------------------------------------------------+\n");
                
                printf("\n               *************************************************************\n");
                printf("               * O Exterminador do futuro é um filme britano-estadunidense *\n");
                printf("               * de 1984, dos gêneros ficção científica, ação e suspense   *\n");
                printf("               * dirigido por James Cameron                                *\n");
                printf("               *                                                           *\n");
                printf("               * Fonte: Wikipedia                                          *\n");
                printf("               *************************************************************\n");

                printf("\n\nPressione [ENTER] para voltar ao menu\n");
                getchar();
                break;

            case 2:
                system("clear");
                printf("    +---------------------------------------------------+\n");
                printf("    |                    [Pulp Fiction]                 |\n");
                printf("    +---------------------------------------------------+\n\n");

                printf("     +------------------------------------------------+\n");
                printf("     |⠌⠊⠆⠕⠅⠕⠌⡆⣃⠪⠢⠣⡱⡑⢕⢅⢣⠱⡡⡣⡣⡣⡣⠄⠄⠄⠄⠄⠄⠄⠄⢀⣀⣠⣀⢀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⡀⡀⡀⡀⡀⡀⢄⠢⢀⠄⡁⢀⠠⠄⠄⡀⠅⠈⡈⢸⢸⢪⠄⠄⠄⠄⠄⢀⣴⣿⣿⡿⣿⡟⣿⣻⣆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠪⡐⡌⢆⢎⢢⠶⠿⠻⡟⠻⠾⠰⡕⡝⡜⣔⢕⢕⠄⡣⡣⡣⠄⠄⠄⠄⢰⣿⣿⡿⠯⠘⠄⠁⠄⠄⠉⢢⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⡊⢔⠜⡌⠎⢈⣬⣥⣤⣴⣶⠄⠄⠈⢪⡳⣕⡕⡧⡁⣇⢇⢇⠄⠄⠄⢀⣿⡏⠈⠄⠄⠄⠄⠄⠄⠄⠄⠄⡃⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⡨⠢⡑⡕⠄⢐⣿⣿⡿⠿⠟⢧⠄⠄⠘⣞⡞⡮⡳⡁⣇⢇⠧⠄⠄⠄⠄⢇⡂⠄⠄⠄⡄⠄⠄⠄⢠⢀⠄⠐⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠠⡑⢌⢺⡀⠰⣤⣖⣯⢶⣽⣟⠆⡄⠄⣗⡯⣯⣣⠃⣇⢇⢏⠄⠄⠄⠄⠄⠐⣠⡖⡦⣽⡿⢆⠄⠚⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⢐⠨⡐⣝⣇⠄⣝⣯⢭⢽⣻⡺⠅⠄⠄⣿⢽⣳⣳⠁⢱⢱⡑⠄⠄⠄⠄⠄⠄⠃⠈⠢⢕⠝⠐⠄⡑⠄⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⣔⣅⣆⣗⢿⡀⢐⢡⢭⢼⠸⠈⠄⠄⠄⣻⣟⣷⢷⢅⡇⡇⡇⠄⠄⠄⠄⠄⠄⠄⠅⠡⠄⠄⠄⠂⣊⣼⣿⠄⢠⣀⡀⠄⠄⠄⠄⠄|\n");
                printf("     |⣿⡯⠏⠃⠋⠃⠘⣷⣄⡀⢀⣤⠆⡄⠄⠛⣛⢙⢋⠃⢗⡝⡌⠄⣠⣤⣶⣶⡲⡶⡲⡆⢒⣶⠂⣾⣿⣿⡟⠄⠄⠙⠻⡿⡶⣦⣤⡀|\n");
                printf("     |⠛⠈⠄⠄⠄⠄⠄⢻⣿⡯⢩⣿⣿⣥⠄⠄⠄⠄⠉⠛⣿⣎⢇⢀⢼⠌⠪⠁⠄⢙⠽⠻⢸⠏⠐⣿⣿⣿⠇⠄⠄⠄⠄⠠⠁⠄⠠⠃|\n");
                printf("     |⠄⠄⠄⠄⠄⣀⣤⣼⡿⠗⡚⢛⣯⢿⠄⠄⠄⠄⠄⠄⢸⣯⣧⡶⠶⠇⠄⠄⠄⠄⠄⠄⢸⠄⠄⣿⣿⡿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⣝⠁⢐⣀⢁⠄⠆⠊⠚⠛⢢⣤⣶⣶⣿⣿⣿⢭⡛⠂⠄⠄⠄⠄⠄⠄⠄⡎⠄⢸⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⠄⢸⡧⢸⠄⠁⠄⠄⠄⠄⠉⣮⠃⠁⠈⠉⠉⠄⠄⠄⠄⠄⠄⠄⠄⠄⡇⠄⢸⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⠄⣸⣝⢈⡇⠄⠄⠬⠐⠄⠄⡼⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢰⠁⠄⢸⣿⡏⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⠄⣿⣿⡄⠁⢰⣶⣏⠄⠄⠁⠄⠄⠄⠄⠸⣟⠄⡁⠄⠄⠄⠄⠄⠄⢸⠄⠄⢸⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⢰⣿⣿⠁⠄⠈⣷⣧⠄⠄⠄⠄⠄⠄⠄⠄⣗⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⠭⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⢸⣿⣿⠇⠄⠄⣿⡏⠄⠄⠄⠄⠄⠄⠄⠄⡳⠄⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⡑⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⢀⠕⡽⣿⠄⠄⠄⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠄⠄⠄⠄⠄⠄⠄⡀⠄⠄⣻⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⢠⢠⣬⣿⣻⡆⠄⠄⣿⡇⠄⠄⠄⠄⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠄⠄⠄⢽⡂⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠉⠙⠛⠛⠻⠃⠄⠄⠿⠃⠄⠄⠄⠈⠁⠄⠄⠄⠈⠁⠄⠄⠄⠄⠄⠄⠪⡂⠄⠄⣸⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢠⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⡀⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢰⠞⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠠⢤⣀|\n");
                printf("     |⣷⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡶⠄⠄⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     |⠟⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⣧⡜⣾⣿⣷⢶⡠⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠄⠄⠄⢀⠄⠄⠄⠄⠄⠈⢀|\n");
                printf("     |⣺⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠙⠄⠘⠉⠉⠉⠈⠈⠈⠄⠄⠄⠄⠄⢀⠠⠄⠄⠄⠄⠄⠄⠄⠄⠐⠄⠄⠄⠈|\n");
                printf("     |⢷⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡀⠈⠄⠄⠄|\n");
                printf("     |⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠂⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄|\n");
                printf("     +------------------------------------------------+\n");

                printf("\n   *****************************************************\n");
                printf("   * Pulp Fiction é um filme estadunidense de 1994     *\n");
                printf("   * do gênero drama policial, escrito e dirigido por  *\n");
                printf("   * Quentin Tarantino, com roteiro dele e Roger Avary *\n");
                printf("   *                                                   *\n");
                printf("   * Fonte: Wikipedia                                  *\n");
                printf("   *****************************************************\n");

                printf("\n\nPressione [ENTER] para voltar ao menu\n");
                getchar();


                break;

            case 3:
                char sair3;
                system("clear");
                printf("                  +---------------------------------------------------+\n");
                printf("                  |                [O Senhor dos Anéis]               |\n");
                printf("                  +---------------------------------------------------+\n\n");
                printf("     +--------------------------------------------------------------------------+\n");
                printf("     |                                                                          |\n");
                printf("     |                                    ....                                  |\n");
                printf("     |                                  .'' .'''                                |\n");
                printf("     |  .                             .'   :                                    |\n");
                printf("     |  \\\\                          .:    :                                     |\n");
                printf("     |   \\\\                        _:    :       ..----.._                      |\n");
                printf("     |    \\\\                    .:::.....:::.. .'         ''.                   |\n");
                printf("     |     \\\\                 .'  #-. .-######'     #        '.                 |\n");
                printf("     |      \\\\                 '.##'/ ' ################       :                |\n");
                printf("     |       \\\\                  #####################         :                |\n");
                printf("     |        \\\\               ..##.-.#### .''''###'.._        :                |\n");
                printf("     |         \\\\             :--:########:            '.    .' :               |\n");
                printf("     |          \\\\..__...--.. :--:#######.'   '.         '.                     |\n");
                printf("     |          :     :  : : '':'-:'':'::        .         '.  .                |\n");
                printf("     |          '---'''..: :    ':    '..'''.      '.        :                  |\n");
                printf("     |             \\\\  :: : :     '      ''''''.     '.      .:                 |\n");
                printf("     |              \\\\ ::  : :     '            '.      '      :                |\n");
                printf("     |               \\\\::   : :           ....' ..:       '     '.              |\n");
                printf("     |                \\\\::  : :    .....####\\\\ .~~.:.             :             |\n");
                printf("     |                 \\\\':.:.:.:'#########.===. ~ |.'-.   . '''.. :            |\n");
                printf("     |                  \\\\    .'  ########## \\ \\ _.' '. '-.       '''.          |\n");
                printf("     |                  :\\\\  :     ########   \\ \\      '.  '-.        :         |\n");
                printf("     |                 :  \\\\'    '   #### :    \\ \\      :.    '-.      :        |\n");
                printf("     |                :  .'\\\\   :'  :     :     \\ \\       :      '-.    :       |\n");
                printf("     |               : .'  .\\\\  '  :      :     :\\ \\       :        '.   :      |\n");
                printf("     |               ::   :  \\\\'  :.      :     : \\ \\      :          '. :      |\n");
                printf("     |               ::. :    \\\\  : :      :    ;  \\ \\     :           '.:      |\n");
                printf("     |                : ':    '\\\\ :  :     :     :  \\:\\     :        ..'        |\n");
                printf("     |                   :    ' \\\\ :        :     ;  \\|      :   .'''           |\n");
                printf("     |                   '.   '  \\\\:                         :.''               |\n");
                printf("     |                    .:..... \\\\:       :            ..''                   |\n");
                printf("     |                   '._____|'.\\......'''''''.:..'''                        |\n");
                printf("     |                                                                          |\n");
                printf("     +--------------------------------------------------------------------------+\n");

                printf("\n                *****************************************************\n");
                printf("                * O Senhor dos aneis é uma trilogia cinematográfica *\n");
                printf("                * dirigida por Peter Jackson com base na obra-prima *\n");
                printf("                * de J. R. R. Tolkien.                              *\n");
                printf("                *                                                   *\n");
                printf("                * Fonte: Wikipedia                                  *\n");
                printf("                *****************************************************\n");

                printf("\n\nPressione [ENTER] para voltar ao menu\n");
                getchar();
                break;
            
            case 420:
                system("clear");
                printf("+-----------------------------------------------+\n");
                printf("|        VOCÊ ENCONTROU O TUX MISTERIOSO        |\n");
                printf("|           DIGA \"OLA TUX MISTERIOSO\"           |\n");
                printf("|     SE NÃO, TERA 100 ANOS DE AZAR !!!!!!!     |\n");
                printf("|                                               |\n");
                printf("|                    ..''..                     |\n");
                printf("|                 :x0XXXXXXKOl.                 |\n");
                printf("|               ,kOOOOOOOOOOOOOl                |\n");
                printf("|              'c:codlloddddodddc               |\n");
                printf("|               .dNWWWx.'.'coc'.;               |\n");
                printf("|               x0KXNNOx.dOKNWXl                |\n");
                printf("|               xkOKXx  ..cOKNXK.               |\n");
                printf("|               ,dxk0KooldOO0Kk,                |\n");
                printf("|                lxddkkOKNNKOk:                 |\n");
                printf("|        ..    cNWNX0xkkxx0XNWWNc    ..         |\n");
                printf("|      ',.    kWWWWWWNKOk0NWWWWWWO    .,.       |\n");
                printf("|    c:.     xWWWWWWWWWWWWWWWWWWWWk     .,.     |\n");
                printf("|  .c       ,XWWWWWWWWWWWWWWWWWWWWN,       ..   |\n");
                printf("|           oNWWWWWWWWWWWWWWWWWWWWNl            |\n");
                printf("|           oXWWWWWWWWWWWWWWWWWWWWNo            |\n");
                printf("|          .xKWWWWWWWWWWWWWWWWWWWWXx.           |\n");
                printf("|           cO00000KXNNWWWNNXK00O0Oc            |\n");
                printf("|        .:kKXXXXKOxxxkK0kxxxxO0KXXX0l.         |\n");
                printf("|       .xk00KKKKKXxxxd::dxxxk00KKKKKXk.        |\n");
                printf("|         ............    ............          |\n");
                printf("|                                               |\n");
                printf("|                                               |\n");
                printf("|                                               |\n");
                printf("+-----------------------------------------------+\n");

                printf("\n\nPressione [ENTER] para voltar ao menu\n");
                getchar();

                break;

            case 4:
                return;
                break;

            default:
                printf("Opção invalida");
                break;
        }
    }
    while(optt);
}


