#include <stdio.h>
#include <stdbool.h>


int main (){
   
    int n,i,atual,futuro,aux;

    atual = 0;
    futuro = 1;
    printf("Digite um número: ");
    scanf("%d",&n);

    /* 0 1 1 2 3 5 8 13 */
    for (i = 0; i < n; i++)
    {
        printf("%d ",atual);
        aux=atual;
        atual = futuro;
        futuro=futuro+aux;
    }
    printf("\n");
    
          
    
    
    
    
    
    
    

    return 0;
}