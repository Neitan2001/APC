#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#define CLEAR "cls"
#else 
#define CLEAR "clear"
#endif

int VerPositivo(long int numero, unsigned short int * quant_neg);

int VerTriplo (long int numero, unsigned short int quant, unsigned short int * quant_triplo);

int VerPrimo (long int numero,unsigned short int * quant_primo);

void RegraCritica (unsigned short int quant_neg, unsigned short int quant_triplo, unsigned short int quant_primo,unsigned short int quant_invalido);

int main (){
    unsigned short int quant,maior,menor,quant_invalido,item, quant_neg, quant_triplo, quant_primo;
    long int numero,positivo,triplo,primo;
    unsigned long int total;
    float media;

    quant_primo=0;
    quant_triplo=0;
    quant_neg=0;
    maior = 0;
    menor = 101;
    quant_invalido = 0;
    total = 0;

    printf("Digite a quantidade de números que deseja inserir: ");
    scanf("%hu",&quant);
    system(CLEAR);

    for (unsigned short int i = 1; i <= quant; i++)
    {
        printf("Digite um número positivo, menor que o triplo da quantidade e que não seja primo: ");
        scanf("%ld",&numero);
        system(CLEAR);
        positivo = VerPositivo(numero,&quant_neg);
        triplo = VerTriplo(numero,quant,&quant_triplo);
        primo = VerPrimo(numero,&quant_primo);
       
        
        if (positivo && triplo && primo)
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
       
        
        
        
        while (!(positivo && triplo && primo))
        {

            printf("Tente novamente: ");
            quant_invalido++;
            scanf("%ld",&numero);
            system(CLEAR);
            positivo = VerPositivo(numero,&quant_neg);
            triplo = VerTriplo(numero,quant,&quant_triplo);
            primo = VerPrimo(numero,&quant_primo);
            
            
            if (positivo && triplo && primo)
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
        printf("1-Total\n2-Total de tentativas inválidas\n3-Média\n4-Maior\n5-Menor\n6-Regra Crítica\n7-Sair\n");
        printf("Digite o que deseja fazer: ");
        scanf("%hu",&item);
        system(CLEAR);
        switch (item)
        {
            case 1:
                printf("A quantidade de números válidos digitados é: %hu\n",quant);
                break;
            
            case 2:
                printf("A quantidade de números inválidos digitados é: %hu\n",quant_invalido);
                break;
            
            case 3:
                media = (float)total/quant;
                printf("A sua média é: %.2f\n",media);
                break;
                

            case 4:
                printf("O maior número digitado é: %hu\n",maior);
                break;

            case 5:
                printf("O menor número é: %hu\n",menor);
                break;

            case 6:
                RegraCritica(quant_neg,quant_triplo,quant_primo,quant_invalido);
                break;
                
            case 7:
                printf("Tchau\n");
                break;

            default:
                printf("Número inválido, tente novamente\n");
                break;
        }
    } while (item!=7);
    
    

    return 0;
}

int VerPositivo(long int numero, unsigned short int * quant_neg){
    if (numero<0)
    {
        printf("Número negativo!\n");
        (*quant_neg)++;
    }
    return numero>=0;

}

int VerTriplo (long int numero, unsigned short int quant, unsigned short int * quant_triplo){
    if (numero>=(3*quant))
    {
        printf("Número maior ou igual que o triplo da quantidade!\n");
        (*quant_triplo)++;
    }
    return numero<(3*quant);
}

int VerPrimo (long int numero,unsigned short int * quant_primo){
    int i, resto, divisores;
    divisores = 0;
    if (numero>0)
    {
        for (i = 1; i <=numero; i++)
        {
            resto=numero%i;
            if (resto==0)
            {
                divisores++;
            }
        
        }
        if (divisores<=2)
        {
            printf("Número primo!\n");
            (*quant_primo)++;
        }
    }
    return divisores >2;
    
}

void RegraCritica (unsigned short int quant_neg, unsigned short int quant_triplo, unsigned short int quant_primo,unsigned short int quant_invalido){
    if (quant_neg>quant_triplo && quant_neg>quant_primo)
    {
        printf("Números negativos foram os mais digitados entre os números inválidos\n");
    }
    else
    {
        if (quant_triplo>quant_neg && quant_triplo>quant_primo)
        {
            printf("Números maiores que o triplo da quantidade foram os mais digitados entre os números inválidos\n");
        }
        else
        {
            if (quant_primo>quant_neg && quant_primo>quant_triplo)
            {
                printf("Números primos foram os mais digitados entre os números inválidos\n");
            }
            else
            {
                if (quant_invalido==0)
                {
                    printf("Não teve números inválidos digitados\n");
                }
                else
                {
                    if (quant_neg==quant_triplo==quant_primo)
                    {
                        printf("A quantidade de números inválidos digitados foram iguais para as três regras\n");
                    }
                    else
                    {
                        if (quant_neg==quant_triplo)
                        {
                            printf("Foram digitados uma quantidade igual de número negativo e números maiores que o triplo da quantidade\n");
                        }
                        else
                        {
                            if (quant_neg==quant_primo)
                            {
                                printf("Foram digitados uma quantidade igual de números negativos e números primos\n");
                            }
                            else
                            {
                                if (quant_triplo==quant_primo)
                                {
                                    printf("Foram digitados uma quantidade igual de números maiores que o triplo da quantidade e números primos\n");
                                } 
                            }  
                        }  
                    } 
                }  
            }
        }  
    }
}