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

            /*Ponteiros Globais*/

    char *nomePTR;
    char *emailPTR;
    char *senhaPTR;
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

    //SysADM;
    char sysLogin[MAX_STRING];
    char sysPassword[MAX_STRING];
}
cadastro;

typedef struct 
{
    char resposta[256];
    int avaliacao;
} 
resposta;

            /*FUNÇÕES*/

//Menu Login
void loginMenu (void);

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
        printf("  * 2.Registrar cadastro                                *\n");
        printf("  * 3.Sobre o museu                                     *\n");
        printf("  * 4.Administração                                     *\n");
        printf("  * 5.Sair                                              *\n");
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
                mostrarDados();
                break;

            case 4:
                system("clear");
                //sysAdmin();
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
                nomePTR = nome;
                emailPTR = email;
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
            while (getchar() != '\n');

            
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
        sleep(1);
        return;
    }
        
    fprintf(dados, "%s,%d,%d,%d,%s,%s,%s\n", nome, idade, numCPF, telefone,
    sexo, email, senha);

    system("clear");
    printf("Cadastro realizado com sucesso!\n");
    sleep(1);

    fclose(dados);
}

void loginDados(void)
{
    cadastro dados[MAX_DATA];
    FILE *data;
    char emailLogin[MAX_DATA];
    char senhaLogin[MAX_DATA];
    int read = 0;
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
        while (getchar() != '\n');
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
                sleep(1);
                loginMenu();
            }
            else
            {
                system("clear");
                printf("Dados incorretos, tente novamente.\n");
                sleep(1);
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
        printf("  * 2.Pesquisa de satisfação                            *\n");
        printf("  * 3.Gerenciar dados                                   *\n");
        printf("  * 4.Voltar ao menu principal                          *\n");
        printf("  *******************************************************\n");
        printf("\nPor favor, escolha a opção de 1 a 7: \n");
        scanf("%d", &optt);
        switch(optt)
        {
            case 1:
                vendaIngressos();
                break;

            case 2:
                //pesquisaMuseu();
                break;

            case 3:
                gerenciarDados();
                break;
            
            case 4:
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
    cadastro dados[MAX_DATA];
    if(numData >= 1)
    {
        int qntd;
        int tipoIngresso;
        char metodoPagamento[MAX_STRING];
        float total;
        printf("Qual a quantidade de ingressos desejados?\n");
        scanf("%d", &qntd);
        //Limpar Buffer
        while (getchar() != '\n');

        for(int j = 1; j <= qntd; j++)
        {
            printf("Escolha o tipo de ingresso\n1 - Inteiro = R$30,00\n2 - Meia entrada = R$15,00\n3 - Isento = R$00,00\n(OBS: Ingresso isento apenas para crianças menores de 6 anos e idosos maiores de 60 anos.)\n> ");
            scanf("%d", &tipoIngresso);
            dados[j].ingressoI = 30;
        
            switch(tipoIngresso)
            {
                case 1:
                    printf("\nIngresso selecionado: Inteiro\n");
                    printf("Valor: R$%.2f\n\n", dados[j].ingressoI);
                    total += dados[j].ingressoI;
                    sleep(1);
                    break;

                case 2:
                    dados[j].ingressoM = dados[j].ingressoI / 2;
                    printf("\n Ingresso selecionado: Meia entrada\n");
                    printf("Valor: R$%.2f\n\n", dados[j].ingressoM);
                    total += dados[j].ingressoM;
                    sleep(2);
                    break;

                case 3:
                    if(dados[j].idade < 6 || dados[j].idade >= 60)
                    {
                        dados[j].ingressoF = dados[j].ingressoI * 0;
                        printf("Ingresso selecionado: Isento\n");
                        printf("Valor: R$%.2f\n\n",dados[j].ingressoF);
                        total += dados[j].ingressoF;
                    }
                    else
                    {
                        printf("Você nao está apto para comprar ingresso isento.\n");
                        sleep(2);
                    }
                    break;
            }

            for (int i = 1; i <= qntd; i++)
            {
            while (getchar() != '\n');
            printf("\nQual o metodo de pagamento?\n(Aceitamos PIX, Crédito e Débito)\n> ");
            fgets(metodoPagamento, MAX_STRING, stdin);
            metodoPagamento[strlen(metodoPagamento) - 1] = '\0';

            dados[i].ticketID = rand() % 100 + 1;
            printf("-------------------------------------------------\n");
            printf("INGRESSO - [%d]\n", i);
            printf("Nome: %10s\n", dados[i].nome);
            printf("CPF: %10.11s\n", dados[i].ticketID);
            printf("Total ingresso: R$%5.2f\n", total);
            printf("Método de pagamento: %s\n", metodoPagamento);
            printf("ID do Ingresso: 000%d\n", dados[i].ticketID);
            printf("-------------------------------------------------\n");
            }
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

void pesquisaMuseu (void)
{

}

void sysAdmin (void)
{
    
}
