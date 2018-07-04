#include <stdlib.h>
#include<stdio.h>
#include "assistUniv.h"
#include <string.h>


Aluno *setAluno(Aluno *aluno)
{
    if (aluno == NULL)
    {
        aluno = (Aluno*) malloc(sizeof(Aluno));
        aluno->prox = NULL;
        system("cls");
        printf("Digite o nome do aluno:\n");
        fflush(stdin);
        scanf("%[^\n]s", &aluno->nome);
        fflush(stdin);
        printf("\nDigite o numero da matricula:\n");
        scanf("%d", &aluno->matricula);
        aluno->faculdade = setFaculdade();
        return aluno;
    }else{
        Aluno *novo;
        novo = (Aluno*) malloc(sizeof(Aluno));
        novo->prox = NULL;
        system("cls");
        printf("Digite o nome do aluno:\n");
        fflush(stdin);
        scanf("%[^\n]s", &novo->nome);
        fflush(stdin);
        printf("\nDigite o numero da matricula:\n");
        scanf("%d", &novo->matricula);
        novo->faculdade = setFaculdade();
        novo->prox = aluno;
        aluno = novo;
        return aluno;
    }
}

Aluno editAluno (Aluno aluno)
{
    system("cls");
    printf("Digite o nome do aluno:\n");
    fflush(stdin);
    scanf("%[^\n]s", &aluno.nome);
    fflush(stdin);
    printf("\nDigite o numero da matricula:\n");
    scanf("%d", &aluno.matricula);
    aluno.faculdade = editFaculdade(aluno.faculdade);
    return aluno;
}
Aluno menuAluno (Aluno aluno)
{
    int opcao;
    do
    {
        system("cls");
        imprimeAluno(aluno);
        printf("\n\n");
        printf("Escolha sua opcao:\n\n");
        printf("1. Editar aluno\n");
        printf("2. Menu de periodos\n");
        printf("0. Voltar\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                aluno = editAluno(aluno);
                break;
            case 2:
                aluno.faculdade.curso.periodos = menuPeriodos(aluno.faculdade.curso.periodos);
                break;
            case 0:
                break;
            default:
                printf("Digite opcao valida.\n\n");
                system("pause");
                break;
        }
    }while (opcao != 0);
    return aluno;
}

Aluno *menu(Aluno *alunos)
{
    int opcao;
    do
    {
        system("cls");
        int cont = 0;
        int alunoEscolhido = 0;
        int i;
        Aluno *aux = NULL;
        aux = alunos;
        printf("\n\n\t\t\tBem vindo. Escolha um aluno para acessar e/ou cadastrar suas informacoes:");
        if (aux == NULL)
        {
            printf("\nNao ha alunos cadastrados.");
            printf("\n\n1. Cadastrar novo aluno");
            printf("\n0. Sair");
        }else{
            printf("\n\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\t\t\t\t::::::::::::::::::::ASSISTENTE::::::::::::::::::::");
            printf("\n\t\t\t\t::::::::::::::::::UNIVERSITARIO:::::::::::::::::::");
            printf("\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\n");

            while (aux != NULL)
            {
                cont++;
                printf("\n\t%d. %s", cont, aux->nome);
                aux = aux->prox;
            }
            printf("\n\n\n\t-----------------------------------------");
            printf("\n\n\t%d. Cadastrar novo aluno", cont + 1);
            printf("\n\t%d. Remover aluno", cont + 2);
            printf("\n\t0. Sair");
        }
        printf("\n\n\tDigite o numero correspondente: ");
        scanf("%d", &opcao);
        while (opcao < 0 || opcao > cont+2)
        {
            printf("\n\t\t\tDigite um numero validdo: ");
            scanf("%d", &opcao);
        }
        if (opcao == cont+1)
        {
            alunos = setAluno(alunos);
        }else{
            if (opcao > 0 && opcao < cont+1)
            {
                aux = alunos;
                for (i = 1; i <= opcao-1; i++)
                {
                    aux = aux->prox;
                }
                (*aux) = menuAluno(*aux);
            }else{
                if (opcao != 0)
                {
                    aux = alunos;
                    printf("\n\nDigite qual aluno deseja remover: ");
                    scanf("%d", &alunoEscolhido);
                    alunos = removeAluno(alunos, alunoEscolhido);
                }
            }
        }
    }while (opcao != 0);
     printf("\n\t\t\tAte Logo ;)\n\n");
    return alunos;

}

Aluno *removeAluno (Aluno *aluno, int alunoEscolhido)
{
if (aluno->prox != NULL)
    {
        Aluno *aux = aluno, *auxAntes = aluno;
        int i = 0;
        for (i = 1; i < alunoEscolhido; i++)
        {
            auxAntes = aux;
            aux = aux->prox;
        }
        auxAntes->prox = aux->prox;
        if (aux == aluno)
        {
            aluno = aluno->prox;
        }
        free(aux);
        return aluno;
    }else{
        free(aluno);
        return NULL;
    }
}
void imprimeAluno(Aluno aluno)
{
    system("cls");
    printf("Nome: %s\n", aluno.nome);
    printf("Matricula: %d", aluno.matricula);
    imprimeFaculdade(aluno.faculdade);
}



void gravaAluno(Aluno *aluno)
{
    FILE *arquivo;
    int cont = 0;
    char buffer[1];
    Aluno *aux = aluno;
    while (aux != NULL)
    {
        cont++;
        sprintf(buffer, "%d", cont);
        arquivo = fopen(buffer, "wb");
        fwrite(aux, sizeof(Aluno), 1, arquivo);
        fclose(arquivo);
        gravaPeriodo(aux);
        aux = aux->prox;
    }
    arquivo = fopen("Num.txt", "w");
    fprintf(arquivo, "%d", cont);
    fclose(arquivo);
}

Aluno *carregaAluno (Aluno *aluno)
{
    FILE *arquivo;
    Aluno *aux = aluno;
    char buffer[1];
    int cont = 0, i;
    arquivo = fopen("Num.txt", "r");
    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d", &cont);
    }else{
        cont = 0;
        return NULL;
    }
    fclose(arquivo);
    for (i = cont; i >= 1; i--)
    {
        aux = NULL;
        sprintf(buffer, "%d", i);
        arquivo = fopen(buffer, "rb");
        if (arquivo != NULL)
        {
            aux = (Aluno*) malloc(sizeof(Aluno));
            fread(aux, sizeof(Aluno), 1, arquivo);
            aux->faculdade.curso.periodos = NULL;
            aux->faculdade.curso.periodos = carregaPeriodo(aux);
        }else{
            return NULL;
        }
        fclose(arquivo);
        remove(buffer);
        aux->prox = aluno;
        aluno = aux;
    }
    return aluno;
}
