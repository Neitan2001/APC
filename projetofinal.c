#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef enum { false, true } bool; //Definição de duas variáveis (false e true) e chamando esse tipo de bool

typedef struct Dependente
{
    char nome[20];
    int idade;
} dependente;

typedef struct Associado
{
    int id;
    char nome[20];
    int idade;
    int qtdDep;
    dependente dep[3];
    bool fazNatacao;
    bool fazFutsal;
    bool fazTenis;
} associado;

void cadastrarAssociado(long int *quantidade, associado associados[]);

int main()
{
    associado associados[100]; //Tirar dúvida de qual a quantidade máxima de associados
    long int quantidade; //essa variável irá controlar a quantidade de associados e irá ser usada nos índices de vetores durante o cadastro
    int item;

    quantidade = 0;

    do
    {
        printf("**Menu Principal**\n");
        printf("1-Cadastrar Associado\n2- Cadastrar Dependente\n3- Listar Associados\n4- Listar Associados por Modalidades\n5- Pesquisar Associados\n6- Gerar Relatório de Assiociados\n7- Finalizar Programa\n");
        printf("O que você deseja fazer?: ");
        scanf("%d", &item);

        switch (item)
        {
        case 1:

            cadastrarAssociado(&quantidade, associados);
            break;

        default:
            break;
        }
    } while (item != 7);

    return 0;
}

void cadastrarAssociado(long int *quantidade, associado associados[])
{
    int item,item2,item3,item4;

    do
    {
        printf("Digite o nome do Associado: ");
        scanf("%s", associados[*quantidade].nome); //Cadastro do Nome

        printf("Digite a idade do Associado: ");
        scanf("%d", &associados[*quantidade].idade); //Cadastro da Idade

        printf("Digite a quantidade de dependentes que esse Associado possui (máximo de 3): "); //Cadastro da Quantidade de dependentes
        scanf("%d", &associados[*quantidade].qtdDep);
        while (associados[*quantidade].qtdDep < 0 || associados[*quantidade].qtdDep > 3) //Verificar se a quantidade de dependentes é válida
        {
            printf("A quantidade de dependentes deve ser maior ou igual a zero e menor ou igual a 3\n");
            printf("Digite novamente a quantidade de dependentes: ");
            scanf("%d", &associados[*quantidade].qtdDep);
        }

        printf("Esse Associado faz natação?\n1- Sim\n2- Não\n"); //Cadastro de Natação
        printf("Digite o que deseja fazer: ");
        scanf("%d",&item2);
        while (item2<1 || item2>2)
        {
            printf("Número inválido!\nEsse Associado faz natação?\n1- Sim\n2- Não\n");
            printf("Digite o que deseja fazer: ");
            scanf("%d",&item2);
        }
        if (item2==1)
        {
            associados[*quantidade].fazNatacao = true;
        }
        else
        {
            if (item2==2)
            {
                associados[*quantidade].fazNatacao = false;
                
            }
            
        }

        printf("Esse Associado faz futsal?\n1- Sim\n2- Não\n"); //Cadastro de Futsal
        printf("Digite o que deseja fazer: ");
        scanf("%d",&item3);
        while (item3<1 || item3>2)
        {
            printf("Número inválido!\nEsse Associado faz futsal?\n1- Sim\n2- Não\n");
            printf("Digite o que deseja fazer: ");
            scanf("%d",&item3);
        }
        if (item3==1)
        {
            associados[*quantidade].fazFutsal = true;
        }
        else
        {
            if (item3==2)
            {
                associados[*quantidade].fazFutsal = false;
                
            }
            
        }

        printf("Esse Associado faz Tenis?\n1- Sim\n2- Não\n"); //Cadastro de Tenis
        printf("Digite o que deseja fazer: ");
        scanf("%d",&item4);
        while (item4<1 || item4>2)
        {
            printf("Número inválido!\nEsse Associado faz Tenis?\n1- Sim\n2- Não\n");
            printf("Digite o que deseja fazer: ");
            scanf("%d",&item4);
        }
        if (item4==1)
        {
            associados[*quantidade].fazTenis = true;
        }
        else
        {
            if (item4==2)
            {
                associados[*quantidade].fazTenis = false;
                
            }
            
        }
        
        
        

        associados[*quantidade].id = *quantidade; // A id do Associado é feita de forma automática, impedindo dois associados possuam o mesmo id
        

        (*quantidade)++;
        

        printf("Deseja Cadastrar outro Associado?\n1-Sim\n2-Não\n");
        printf("Digite o que deseja fazer?: ");
        scanf("%d", &item);
        switch (item)
        {
        case 1:

            printf("ok\n");
            break;

        case 2:

            printf("Voltando ao menu principal\n");
            break;
        
        default:

            printf("Número inválido, voltando ao menu principal\n");
            break;
        }

    } while (item == 1);
};
