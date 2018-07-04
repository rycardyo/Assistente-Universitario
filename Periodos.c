#include <stdlib.h>
#include <stdio.h>
#include "assistUniv.h"
#include <string.h>



PilhaPeriodos *inserePilhaPeriodos(PilhaPeriodos *topoPeriodos)
{
    system("cls");
    if (topoPeriodos == NULL)
    {
        topoPeriodos = (PilhaPeriodos*) malloc(sizeof(PilhaPeriodos));
        topoPeriodos->prox = NULL;
        printf("Digite o numero do periodo: ");
        scanf("%d", &topoPeriodos->numero);
        topoPeriodos->materias = NULL;
        return topoPeriodos;
    }else{
        PilhaPeriodos *novo;
        novo = (PilhaPeriodos*) malloc(sizeof(PilhaPeriodos));
        novo->prox = NULL;
        printf("Digite o numero do periodo: ");
        scanf("%d", &novo->numero);
        novo->materias = NULL;
        novo->prox = topoPeriodos;
        topoPeriodos = novo;
        return topoPeriodos;
    }
}

PilhaPeriodos editPeriodo(PilhaPeriodos periodo)
{
    printf("Digite o numero do periodo: ");
    scanf("%d", &periodo.numero);
    return periodo;
}

PilhaPeriodos *removePeriodo (PilhaPeriodos *topoPeriodo)
{
    PilhaPeriodos *aux = topoPeriodo;
    topoPeriodo = topoPeriodo->prox;
    free(aux);
    return topoPeriodo;
}

PilhaPeriodos *menuPeriodos (PilhaPeriodos *periodos)
{
    int opcao;
    PilhaPeriodos *aux = NULL;
    do
    {
        system("cls");
        int achou = 0;
        int periodoEscolhido = 0;
        imprimePeriodos(periodos);
        printf("\n\nEscolha sua opcao\n");
        printf("1. Cadastrar novo periodo\n");
        printf("2. Editar periodo\n");
        printf("3. Menu de materias\n");
        printf("4. Remover peiodo\n");
        printf("0. Voltar\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                periodos = inserePilhaPeriodos(periodos);
                break;
            case 2:
                aux = periodos;
                system("cls");
                printf("Digite o numero do periodo que deseja editar: ");
                scanf("%d", &periodoEscolhido);
                while (aux != NULL)
                {
                    if (aux->numero == periodoEscolhido)
                    {
                        (*aux) = editPeriodo(*aux);
                        achou = 1;
                    }
                    aux = aux->prox;
                }
                if (achou == 0)
                {
                    printf("\nPeriodo nao encontrado\n\n");
                    system("pause");
                }else{
                    printf("Periodo editado\n\n");
                    system("pause");
                }
                break;
            case 3:
                aux = periodos;
                system("cls");
                printf("Digite o numero do periodo que deseja ver as materias: ");
                scanf("%d", &periodoEscolhido);
                while (aux != NULL)
                {
                    if (aux->numero == periodoEscolhido)
                    {
                        aux->materias = menuMaterias(aux->materias);
                        achou = 1;
                    }
                    aux = aux->prox;
                }
                if (achou == 0)
                {
                    printf("\nPeriodo nao encontrado\n\n");
                }
                break;
            case 4:
                periodos = removePeriodo(periodos);
            case 0:
                break;
            default:
                printf("\n\nDigite uma opcao valida\n\n");
                system("pause");
        }
    }while (opcao != 0);
    return periodos;
}

void imprimePeriodos(PilhaPeriodos *periodos)
{
    if (periodos != NULL)
    {
        PilhaPeriodos *aux;
        aux = periodos;
        while (aux != NULL)
        {
            printf("\nPeriodo: %d\n\n", aux->numero);
            aux = aux->prox;
        }
    }else{
        printf("\nNao ha periodos cadastrados.");
    }
}
void gravaPeriodo(Aluno *aluno)
{
    FILE *arquivo;
    int cont = 0;
    char buffer1[30], buffer2[30];
    PilhaPeriodos *aux = aluno->faculdade.curso.periodos;
    while (aux != NULL)
    {
        cont++;
        sprintf(buffer1, "%s.%d", aluno->nome, cont);
        arquivo = fopen(buffer1, "wb");
        fwrite(aux, sizeof(PilhaPeriodos), 1, arquivo);
        fclose(arquivo);
        gravaMateria(aux, aluno->nome);
        aux = aux->prox;
    }
    sprintf(buffer2, "%s.Num.txt", aluno->nome);
    arquivo = fopen(buffer2, "w");
    fprintf(arquivo, "%d", cont);
    fclose(arquivo);
}

PilhaPeriodos *carregaPeriodo (Aluno *aluno)
{
    FILE *arquivo;
    PilhaPeriodos *aux = aluno->faculdade.curso.periodos;
    char buffer1[30], buffer2[30];
    int cont = 0, i;
    sprintf(buffer1, "%s.Num.txt", aluno->nome);
    arquivo = fopen(buffer1, "r");
    remove(buffer1);
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
        sprintf(buffer2, "%s.%d", aluno->nome, i);
        arquivo = fopen(buffer2, "rb");
        if (arquivo != NULL)
        {
            aux = (PilhaPeriodos*) malloc(sizeof(PilhaPeriodos));
            fread(aux, sizeof(PilhaPeriodos), 1, arquivo);
            aux->materias = NULL;
            aux->materias = carregaMateria(aux, aluno->nome);
        }else{
            return NULL;
        }
        fclose(arquivo);
        remove(buffer2);
        aux->prox = aluno->faculdade.curso.periodos;
        aluno->faculdade.curso.periodos = aux;
    }
    return aluno->faculdade.curso.periodos;
}
