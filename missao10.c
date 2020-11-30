#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define CLEAR "cls"
#else 
#define CLEAR "clear"
#endif

int quantidade = 0;

void TestarString (char s[100]);
void ImprimeString(char s[100]);
void AoContrario(char s[100]);
void ValidarString(char s[100]);
void ModificarString(char s[100]);

int main()
{
    int item;
    char string[100];
    do
    {
        printf("**Menu principal**\n");
        printf("1- Testar String\n2- Imprimir String\n3- Imprimir de trás para frente\n4- Validar String\n5- Modificar String\n6- Sair\n");
        printf("O que você deseja fazer?: ");
        scanf("%d",&item);
        system(CLEAR);

        switch (item)
        {
        case 1:
            TestarString(string);
            
            break;

        case 2:
            ImprimeString(string);

            break;
        
        case 3:
            AoContrario(string);

            break;
        
        case 4:
            ValidarString(string);

            break;
        
        case 5:
            ModificarString(string);

            break;
        
        case 6:
            printf("Tchau!\n");

            break;
        
        default:
            printf("Número inválido, tente novamente!\n");
            break;
        }

    } while (item!=6);
    
    
    return 0;
}

void TestarString (char s[100]){
    printf("Digite uma String, máximo de 99 caracteres: ");
    scanf("%s",s);
    system(CLEAR);
    quantidade++;

}

void ImprimeString(char s[100]){
    int tamanho;
    
    if (quantidade>0)
    {
        tamanho = strlen(s);
        printf("A String \"%s\" possui uma quantidade de caracteres igual a: %d\n",s,tamanho);
    }
    else
    {
        printf("Insira uma string primeiro!\n");
    }
}

void AoContrario(char s[100]){
    int tamanho,i;

    if (quantidade>0)
    {
        tamanho = strlen(s);
        printf("Sua String ao contrário é: ");
        for (i = tamanho-1; i >= 0; i--)
        {
            printf("%c",s[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Insira uma string primeiro!\n");
    }

}

void ValidarString(char s[100]){
    int tamanho,i,controladora;
    controladora=0;

    if (quantidade>0)
    {
        tamanho = strlen(s);
        for (i = 0; i < tamanho-1; i++)
        {
            if ((s[i]<'a' || s[i]>'z') || (tamanho<10) || 
                (s[0]!='a' && s[0]!='e' && s[0]!='i' && s[0]!='o' && s[0]!='u') )
            {
                printf("String inválida, ela deve conter pelo menos 10 caracteres, ter somente letras minúsculas e começar com uma vogal!\n");
                controladora=1;
                break;
            }
        }

        
        if (controladora==0)
        {
            printf("String Válida\n");
        }
        
        
    }
    else
    {
        printf("Insira uma string primeiro!\n");
    }

}

void ModificarString(char s[100]){
    int tamanho,i,controladora;
    char char_antigo, char_novo;

    controladora=0;

    if (quantidade>0)
    {
        tamanho = strlen(s);
        printf("Digite o caractere que deseja mudar: ");
        scanf(" %c",&char_antigo);
        system(CLEAR);
        printf("Digite o caractere que deseja colocar no lugar: ");
        scanf(" %c",&char_novo);
        system(CLEAR);
        for (i = 0; i < tamanho-1; i++)
        {
            if (s[i]==char_antigo)
            {
                s[i]=char_novo;
                controladora=1;
            }
            
            
            
        }
        if (controladora==1)
        {
            printf("Atualização Concluída!\n");
        }
        else
        {
            printf("Não foi encontrado o caractere!\n");
        }
        
        
        

        
    }
    else
    {
        printf("Insira uma string primeiro!\n");
    }

}
