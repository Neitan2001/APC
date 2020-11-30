#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

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
    int fazNatacao;
    int fazFutsal;
    int fazTenis;
} associado;

void cadastrarAssociado(long int *quantidade, associado associados[]);

int main()
{
    associado associados[100]; //Tirar dúvida de qual a quantidade máxima de associados
    long int quantidade;
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
    int item;

    do
    {
        printf("Digite o nome do Associado: ");
        scanf("%s", associados[*quantidade].nome);
        printf("Digite a idade do Associado: ");
        scanf("%d", &associados[*quantidade].idade);
        printf("Digite a quantidade de dependentes que esse Associado possui (máximo de 3): ");
        scanf("%d", &associados[*quantidade].qtdDep);
        while (associados[*quantidade].qtdDep < 0 || associados[*quantidade].qtdDep > 3)
        {
            printf("A quantidade de dependentes deve ser maior que zero e menor ou igual a 3\n");
            printf("Digite novamente a quantidade de dependentes: ");
            scanf("%d", &associados[*quantidade].qtdDep);
        }

        associados[*quantidade].id = *quantidade;
        printf("%d\n", associados[*quantidade].id);
        (*quantidade)++;
        printf("%ld\n", *quantidade);

        printf("Deseja Cadastrar outro Associado?\n1-Sim\n2-Não\n");
        printf("Digite o que deseja fazer?: ");
        scanf("%d", &item);

    } while (item == 1);
};
