#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef struct aluno
{
    char nome[20];
    int idade;
    float nota;
} aluno;

int main()
{
    int qtdLinhas, qtdColunas, i, j, linhaMaior, linhaMenor;
    float notaMaior, notaMenor, mediaMaior, mediaMenor, soma, media;

    notaMaior = 0;
    notaMenor = 10000;

    mediaMaior = 0;
    mediaMenor = 10000;

    printf("Quantas linhas você deseja inserir?: ");
    scanf("%d", &qtdLinhas);

    system(CLEAR); //Limpar Tela

    while (qtdLinhas < 0) //Não pode ter uma quantidade negativa de linhas
    {
        printf("Quantidade inválida, tente novamente: ");
        scanf("%d", &qtdLinhas);

        system(CLEAR); //Limpar Tela
    }

    printf("Quantas colunas você deseja inserir?: ");
    scanf("%d", &qtdColunas);

    system(CLEAR); //Limpar Tela

    while (qtdColunas < 0) //Não pode ter uma quantidade negativa de colunas
    {
        printf("Quantidade inválida, tente novamente: ");
        scanf("%d", &qtdColunas);

        system(CLEAR); //Limpar Tela
    }

    aluno alunos[qtdLinhas][qtdColunas];

    for (i = 0; i < qtdLinhas; i++) //Incício Cadastro de Alunos
    {
        for (j = 0; j < qtdColunas; j++)
        {
            printf("Digite o nome do aluno na %dº Linha e %dº Coluna: ", i + 1, j + 1);
            scanf(" %s", alunos[i][j].nome);

            system(CLEAR); //Limpar Tela

            printf("Digite a idade do aluno na %dº Linha e %dº Coluna: ", i + 1, j + 1);
            scanf("%d", &alunos[i][j].idade);

            system(CLEAR); //Limpar Tela

            while (alunos[i][j].idade < 0) //Não pode ter idade menor do que zero
            {
                printf("Idade inválida, digite novamente: ");
                scanf("%d", &alunos[i][j].idade);

                system(CLEAR); //Limpar Tela
            }

            printf("Digite a nota do aluno na %dº Linha e %dº Coluna: ", i + 1, j + 1);
            scanf("%f", &alunos[i][j].nota);

            system(CLEAR); //Limpar Tela

            while (alunos[i][j].nota < 0 || alunos[i][j].nota > 10) //Não pode ter nota menor do que zero e maior do que dez
            {
                printf("Nota inválida, tente novamente: ");
                scanf("%f", &alunos[i][j].nota);

                system(CLEAR); //Limpar Tela
            }
        }
    } //Fim Cadastro de Alunos

    for (i = 0; i < qtdLinhas; i++) //Verificar qual é a maior e a menor nota
    {
        for (j = 0; j < qtdColunas; j++)
        {
            if (alunos[i][j].nota >= notaMaior)
            {
                notaMaior = alunos[i][j].nota;
            }
            if (alunos[i][j].nota <= notaMenor)
            {
                notaMenor = alunos[i][j].nota;
            }
        }
    }

    printf("O(s) aluno(s) com a maior nota é(são):\n");
    printf("\n");
    printf("Maior nota: %.2f\n", notaMaior);

    for (i = 0; i < qtdLinhas; i++) //Verificar os alunos com a maior nota e imprimir seus nomes. Fazendo desse modo, é possível que mais de um aluno tenha a maior nota
    {
        for (j = 0; j < qtdColunas; j++)
        {
            if (alunos[i][j].nota == notaMaior)
            {
                printf("%s - Linha: %d - Coluna: %d\n", alunos[i][j].nome, i + 1, j + 1);
            }
        }
    }

    printf("\n");

    printf("O(s) aluno(s) com a menor nota é(são):\n");
    printf("\n");
    printf("Menor nota: %.2f\n", notaMenor);

    for (i = 0; i < qtdLinhas; i++) //Verificar os alunos com a menor nota e imprimir seus nomes. Fazendo desse modo, é possível que mais de um aluno tenha a maior nota
    {
        for (j = 0; j < qtdColunas; j++)
        {
            if (alunos[i][j].nota == notaMenor)
            {
                printf("%s - Linha: %d - Coluna: %d\n", alunos[i][j].nome, i + 1, j + 1);
            }
        }
    }
    printf("\n");

    for (i = 0; i < qtdLinhas; i++) //Verificar qual é a maior e a menor média
    {
        for (j = 0; j < qtdColunas; j++)
        {
            soma += alunos[i][j].nota;
        }

        media = soma / qtdColunas;

        
        if (media > mediaMaior)
        {
            mediaMaior = media;
            linhaMaior = i + 1;
        }
        if (media < mediaMenor)
        {
            mediaMenor = media;
            linhaMenor = i + 1;
        }
        soma = 0; //resetar a soma antes de continuar o loop
    }

    printf("A linha %d possui a Maior Média\n", linhaMaior);
    printf("\n");
    printf("A linha %d possui a Menor Média\n", linhaMenor);
    printf("\n");

    for (i = 0; i < qtdLinhas; i++)
    {
        for (j = 0; j < qtdColunas; j++)
        {
            printf("%.2f    ", alunos[i][j].nota);
        }
        printf("\n");
    }

    return 0;
}
