#include <stdio.h>
#include <stdbool.h>

int main (){
    short int item,resto;
    long int numero;
    float peso, altura,imc;
    double termo1_mult,termo2_mult,resultado_mult,termo1_div,termo2_div,resultado_div;

    do{
        printf("**Menu principal**\n1-Informações\n2-Calcular IMC\n3-Par ou Impar\n4-Multiplicação\n5-Divisão\n6-Sair\n");
        printf("O que você deseja fazer?: ");
        scanf("%hd",&item);
        switch (item)
        {
            case 1:
                printf("O meu nome é Natan Tavares Santana, minha matrícula é 20/0025449 e estou no 1º Semestre\n");
                break;
            
            case 2:
                printf("Digite o seu peso: ");
                scanf("%f",&peso);
                printf("Digite a sua altura: ");
                scanf("%f",&altura);
                imc=peso/(altura*altura);
                printf("O seu IMC é: %.2lf\n",imc);

                break;

            case 3:
                printf("Digite um número inteiro qualquer: ");
                scanf("%ld",&numero);
                resto =numero%2;
                if (resto==1)
                    {
                        printf("O número digitado é ímpar.\n");
                    }
                else
                    {
                        printf("O número digitado é par.\n");
                    }
                break;
            case 4:
                printf("Digite o primeiro número a ser multiplicado: ");
                scanf("%lf",&termo1_mult);
                printf("Digite o segundo número a ser multiplicado: ");
                scanf("%lf",&termo2_mult);
                resultado_mult = termo1_mult*termo2_mult;
                printf("o resultado da sua multiplicação é: %.2lf\n",resultado_mult);
                break;

            case 5:
                printf("Digite o primeiro número a ser dividido: ");
                scanf("%lf",&termo1_div);
                printf("Digite o segundo número a ser dividido: ");
                scanf("%lf",&termo2_div);
                if (termo2_div==0)
                    {
                        printf("Divisão inválida!\n");
                    }
                else
                    {
                        resultado_div= termo1_div/termo2_div;
                        printf("O resultado da divisão é: %.2lf\n",resultado_div);
                    }
                break;
                
            case 6:
                printf("Tchau\n");
                break;
            default:
                printf("Número inválido, tente novamente");
                break;    
        }
    }while(item!=6);


    return 0;
}