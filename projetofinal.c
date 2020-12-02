#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

//Dúvidas
//1- Tirar dúvida de qual a quantidade máxima de associados - Não tem quantidade máxima, coloca 200
//2- O identificador do Associado deve ser automático ou manual? - Automático
//3- A quantidade de dependentes deve ser cadastrada no momento do cadastro ou deve ser uma variável que se atualiza de acordo que vai adicionando dependentes? - de acordo que vai adicionando dependentes?

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
    int qtdAulas;
    float mensalidade;
    dependente dep[3];
    bool fazNatacao;
    bool fazFutsal;
    bool fazTenis;
} associado;

void cadastrarAssociado(long int *quantidade, associado associados[]);
void cadastrarDependente(long int *quantidade, associado associados[]);

int main() //Início do Menu Princiapl
{
    associado associados[200]; 
    long int quantidade; //essa variável irá controlar a quantidade de associados e irá ser usada nos índices de vetores durante o cadastro
    int item;

    quantidade = 0;

    do
    {
        printf("**Menu Principal**\n");
        printf("1- Cadastrar Associado\n2- Cadastrar Dependente\n3- Listar Associados\n4- Listar Associados por Modalidades\n5- Pesquisar Associados\n6- Gerar Relatório de Assiociados\n7- Finalizar Programa\n");
        printf("O que você deseja fazer?: ");
        scanf("%d", &item);

        system(CLEAR); //Limpar Tela

        switch (item)
        {
        case 1:

            cadastrarAssociado(&quantidade, associados);
            break;

        case 2:

            if (quantidade>0)
            {
                cadastrarDependente(&quantidade, associados);
            }
            else
            {
                printf("Nenhum Associado foi cadastrado!\n");
            }
            break;

        default:
            break;
        }
    } while (item != 7);

    return 0;
} //Fim do Menu Principal

void cadastrarAssociado(long int *quantidade, associado associados[]) //Início de Cadastro de Associado
{
    int item,item2,item3,item4;

    do
    {
        printf("Digite o nome do Associado (máximo de 20 caracteres): ");
        scanf("%s", associados[*quantidade].nome); //Cadastro do Nome

        system(CLEAR); //Limpar Tela

        printf("Digite a idade do Associado: ");
        scanf("%d", &associados[*quantidade].idade); //Cadastro da Idade

        system(CLEAR); //Limpar Tela

        while (associados[*quantidade].idade<0) //Verificar se a Idade é válida
        {
            printf("Idade Inválida, digite novamente: ");
            scanf("%d", &associados[*quantidade].idade);

            system(CLEAR); //Limpar Tela

        }
        
        printf("Esse Associado faz natação?\n1- Sim\n2- Não\n"); //Cadastro de Natação
        printf("Digite o que deseja fazer: ");
        scanf("%d",&item2);

        system(CLEAR); //Limpar Tela

        while (item2<1 || item2>2)
        {
            printf("Número inválido!\nEsse Associado faz natação?\n1- Sim\n2- Não\n");
            printf("Digite o que deseja fazer: ");
            scanf("%d",&item2);
        }
        if (item2==1)
        {
            associados[*quantidade].fazNatacao = true;
            associados[*quantidade].mensalidade += 30; //Cada aula acrescenta 30 reais na mensalidade do Associado
            associados[*quantidade].qtdAulas ++; //Acrescentando a quantidade de aulas do associado
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

        system(CLEAR); //Limpar Tela

        while (item3<1 || item3>2)
        {
            printf("Número inválido!\nEsse Associado faz futsal?\n1- Sim\n2- Não\n");
            printf("Digite o que deseja fazer: ");
            scanf("%d",&item3);
        }
        if (item3==1)
        {
            associados[*quantidade].fazFutsal = true;
            associados[*quantidade].mensalidade += 30; //Cada aula acrescenta 30 reais na mensalidade do Associado
            associados[*quantidade].qtdAulas ++; //Acrescentando a quantidade de aulas do associado
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

        system(CLEAR); //Limpar Tela

        while (item4<1 || item4>2)
        {
            printf("Número inválido!\nEsse Associado faz Tenis?\n1- Sim\n2- Não\n");
            printf("Digite o que deseja fazer: ");
            scanf("%d",&item4);
        }
        if (item4==1)
        {
            associados[*quantidade].fazTenis = true;
            associados[*quantidade].mensalidade += 30; //Cada aula acrescenta 30 reais na mensalidade do Associado
            associados[*quantidade].qtdAulas ++; //Acrescentando a quantidade de aulas do associado
        }
        else
        {
            if (item4==2)
            {
                associados[*quantidade].fazTenis = false;
                
            }
            
        }
        
        
        

        associados[*quantidade].id = *quantidade; // A id do Associado é feita de forma automática, impedindo dois associados possuam o mesmo id
        associados[*quantidade].mensalidade += 100; //A cada associado, é imposto o valor de 100 reais na mensalidade

        (*quantidade)++;
        

        printf("Cadastro Concluído!\nDeseja Cadastrar outro Associado?\n1-Sim\n2-Não\n");
        printf("Digite o que deseja fazer?: ");
        scanf("%d", &item);
        
        system(CLEAR); //Limpar Tela

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
}; //Fim do Cadastro de Associados

void cadastrarDependente(long int *quantidade, associado associados[]){ //Início de Cadastro de Dependentes
    long int idDigitado, a, i, indice;
    int controlador,item;

    controlador = 0; //Essa variável irá controlar se o Associado foi encontrado: Quando for encontrado valerá "1" e assim posso usar em condições com mais facilidade

    for (a = 0; a < *quantidade; a++)
    {
        printf("Nome: %s - Id: %d \n",associados[a].nome,associados[a].id);
    }
    

    printf("Digite o Identificador do Associado para cadastrar seus dependentes: ");
    scanf("%ld",&idDigitado);

    system(CLEAR); //Limpar Tela

    for (i = 0; i < *quantidade; i++)
    {
        if (associados[i].id == idDigitado) //Verifica se o idDigitado é igual a algum id de Associado
        {
            indice = i;
            controlador = 1;
        }
    }

    if (controlador==1)
    {
        if (associados[indice].qtdDep<3) //Verificar se o associado já possui três dependentes
        {
            do
            {
                printf("Digite o nome do %dº Dependente(máximo de 20 caracteres): ", associados[indice].qtdDep+1); //Cadastro do nome do Dependente
                scanf(" %s",associados[indice].dep[associados[indice].qtdDep].nome);

                system(CLEAR); //Limpar Tela

                printf("Digite a Idade do %dº Dependente: ", associados[indice].qtdDep+1); //Cadastro da idade do Dependente
                scanf("%d",&associados[indice].dep[associados[indice].qtdDep].idade);

                system(CLEAR); //Limpar Tela

                while (associados[indice].dep[associados[indice].qtdDep].idade<0) //Verificar se a Idade é válida
                {
                    printf("Idade Inválida, digite novamente: ");
                    scanf("%d", &associados[indice].dep[associados[indice].qtdDep].idade);

                    system(CLEAR); //Limpar Tela
            
                }

                associados[indice].mensalidade += 50; //A cada dependente cadastrado, é acresentado 50 reais na mensalidade
                associados[indice].qtdDep++; // A quantidade de dependentes aumenta mais um depois do cadastro

                printf("Cadastro Concluído!\nDeseja cadastrar mais um Dependente?\n1- Sim\n2- Não\nDigite o que deseja fazer: ");
                scanf("%d",&item);

                system(CLEAR); //Limpar Tela

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

                if (associados[indice].qtdDep==3)
                {
                    printf("Quantidade máxima de dependetes atingida(3 dependentes)!\n");
                    break;
                }
                
            } while (item==1);
        }
        else
        {
            printf("Esse Associado já possui a quantidade máxima de Dependentes(3 dependentes)!\n");
        }
        
        
    }
    else
    {
        printf("Não há Associado com esse Identificador\n"); //Se o controlador for diferente de "1", ou seja, igual a "0", não há como cadastrar dependentes
    }
}; //Fim do Cadastro de Dependentes
