#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#define CLEAR "cls"
#else 
#define CLEAR "clear"
#endif

int quantidade=0, vetor_numeros[200];



void InserirNumero ();
void ListarNumeros ();
void EditarNumero();
void ExcluirNumero();
void MediaVetores();

int main()
{
    int item;
    do
    {
        printf("Menu de opções\n 1-Inserir Número\n 2-Listar Números\n 3-Editar Número\n 4-Excluir Número\n 5-Listar Números maiores que a média\n 6-Sair\n");
        printf("O que você deseja fazer?: ");
        scanf("%d",&item);
        system(CLEAR);
        switch (item)
        {
        case 1:
            InserirNumero();
            break;
        
        case 2:
            ListarNumeros();
            break;

        case 3:
            EditarNumero();
            break;
        
        case 4:
            ExcluirNumero();
            break;
        
        case 5:
            MediaVetores();
            break;
        
        case 6:
            printf("Tchau, Volte Sempre!\n");
            break;

        default:
            printf("Número Inválido, Tente novamente!\n");
            break;
        }
    } while (item!=6);
    
    
    return 0;
}

void InserirNumero (){
    int opcao;
    do
    {
        printf("Insira um número: ");
        scanf("%d",&vetor_numeros[quantidade]);
        quantidade++;
        system(CLEAR);
        printf("Deseja Inserir mais um número?\n 1-Sim\n 2-Não\n Digite a sua escolha: ");
        scanf("%d",&opcao);
        system(CLEAR);
        switch (opcao)
        {
        case 1:
            printf("ok\n");
            break;
        case 2:
            printf("Ok, voltando ao menu principal\n");
            break;
        
        default:
            printf("Número inválido, voltando ao menu principal\n");
            break;
        }

    } while (opcao==1);
    
}

void ListarNumeros (){
    int i;

    if (quantidade>0)
    {
        for (i = 0; i < quantidade; i++)
        {
            printf("%dº Número: %d\n",(i+1),vetor_numeros[i]);
        }
    }
    else
    {
        printf("Nenhum número foi inserido\n");
    }
}

void EditarNumero(){
    int posicao,novo_numero;
    if (quantidade>0)
    {
        printf("Qual a posição do número que deseja edita?: ");
        scanf("%d",&posicao);
        system(CLEAR);
        if (posicao<=quantidade)
        {
            printf("Digite o novo número: ");
            scanf("%d",&novo_numero);
            system(CLEAR);
            vetor_numeros[posicao-1]=novo_numero;
            printf("Edição concluída!\n");
        }
        else
        {
            printf("Não há números nessa posição para ser editado!\n");
        }
    }
    else
    {
        printf("Nenhum número foi inserido\n");
    }
    
}

void ExcluirNumero(){
    int posicao,i;

    if (quantidade>0)
    {
        printf("Digite a posição do número que deseja excluir: ");
        scanf("%d",&posicao);
        system(CLEAR);
        if (posicao<=quantidade)
        {
            for (i = posicao-1; i <= quantidade; i++)
            {
                vetor_numeros[i]=vetor_numeros[i+1];
            }
            quantidade--;
            printf("Número excluído com sucesso!\n");
            
        }
        else
        {
            printf("Não há números nessa posição para ser excluído!");
        }
        
        

    }
    else
    {
        printf("Nenhum número foi inserido!\n");
    }
}

void MediaVetores(){
    int i,soma,controlador;
    float media;

    soma = 0;
    controlador=0;

    if (quantidade>0)
    {
        printf("Os números maiores que a média são:\n");
        for (i = quantidade-1; i >= 0; i--)
        {
            soma=soma+vetor_numeros[i];
        }
        media = (float) soma/quantidade;

        for (i = 0; i <= quantidade-1; i++)
        {
            if (vetor_numeros[i]>media)
            {
                printf("%dº Número: %d\n",i+1,vetor_numeros[i]);
                controlador++;
            }
            
        }
        if (controlador==0)
        {
            printf("Nenhum número é maior que a média\n");
        }
        
        
    }
    else
    {
        printf("Nenhum número foi inserido!\n");
    }
}