#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#define CLEAR "cls"
#else 
#define CLEAR "clear"
#endif


int main (){
    unsigned short int quant,maior,menor,quant_regras,resto,item;
    int numero;
    unsigned long int total;
    float media;

    maior = 0;
    menor = 101;
    quant_regras = 0;
    total = 0;

    printf("Digite a quantidade de números que deseja inserir: ");
    scanf("%hu",&quant);
    system(CLEAR);

    for (unsigned short int i = 1; i <= quant; i++)
    {
        printf("Digite um número positivo, menor que 100 e que não seja múltiplo de 3: ");
        scanf("%d",&numero);
        system(CLEAR);
        resto = numero%3;
        if (numero <=100 && numero>0 && resto!=0)
        {
            total= total+numero;
            if (numero>maior)
            {
                maior=numero;
            }
            if (numero<menor)
            {
                menor=numero;
            }
        }
       
        
        
        
        while (numero>100 || numero<0 || resto==0)
        {
            if (numero>100)
            {
                printf("Número maior que 100\n");
            }
            if (numero<0)
            {
                printf("Número negativo\n");
            }
            if (resto==0)
            {
                printf("Número múltiplo de 3\n");
            }

            printf("Tente novamente: ");
            quant_regras= quant_regras+1;
            scanf("%d",&numero);
            system(CLEAR);
            resto = numero%3;
            if (numero <=100 && numero>0 && resto!=0)
            {
                total= total+numero;
                if (numero>maior)
                {
                    maior=numero;
                }
                if (numero<menor)
                {
                    menor=numero;
                }
            }
            
            
        }
        
    }

    do
    {
        printf("**Menu**\n");
        printf("1-Total\n2-Média\n3-Maior\n4-Menor\n5-Número de números inválidos\n6-Sair\n");
        printf("Digite o que deseja fazer: ");
        scanf("%hu",&item);
        system(CLEAR);
        switch (item)
        {
            case 1:
                printf("Você digitou %hu números\n",quant);
                break;
            
            case 2:
                media = (float)total/quant;
                printf("A sua média é: %.2f\n",media);
                break;
            
            case 3:
                printf("O maior número digitado é: %hu\n",maior);
                break;

            case 4:
                printf("O menor número é: %hu\n",menor);
                break;

            case 5:
                printf("A quantidade de números inválidos digitados é: %hu\n",quant_regras);
                break;

            case 6:
                printf("Tchau\n");
                break;

            default:
                printf("Número inválido, tente novamente\n");
                break;
        }
    } while (item!=6);
    
    

    return 0;
}