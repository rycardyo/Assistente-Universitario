#include <stdlib.h>
#include<stdio.h>
#include "assistUniv.h"

#define TRUE 1
#define FALSE 0


ListaAulas *setAulas(ListaAulas *aulas)
{
    system("cls");
    if (aulas == NULL)
    {
        aulas = (ListaAulas*) malloc(sizeof(ListaAulas));
        aulas->prox = NULL;
        aulas->data = setData();
        do
        {
            printf("Digite 1 para aula ministrada ou 0 para aula nao ministrada:\n");
            scanf("%d", &aulas->ministrada);
        }
        while (aulas->ministrada != TRUE && aulas->ministrada != FALSE);
        do
        {
            printf("\nDigite 1 para aula presente ou 0 para aula faltada:\n");
            scanf("%d", &aulas->presenca);
        }while (aulas->presenca != TRUE && aulas->presenca != FALSE);
        printf("\nDigite a descricao da aula:\n");
        fflush(stdin);
        scanf("%[^\n]s", &aulas->descricao);
        fflush(stdin);
        do{
            printf("\nDigite o tipo da aula, 'T' para teorica ou 'P' para pratica:\n");
            scanf("%c", &aulas->tipo);
            fflush(stdin);
        }while (aulas->tipo != 'T' && aulas->tipo != 'P');
        aulas->prox = NULL;
        return aulas;
    }else{
        ListaAulas *novo;
        novo = (ListaAulas*) malloc(sizeof(ListaAulas));
        novo->prox = NULL;
        novo->data = setData();
        do
        {
            printf("Digite 1 para aula ministrada ou 0 para aula nao ministrada:\n");
            scanf("%d", &novo->ministrada);
        }while (novo->ministrada != TRUE && novo->ministrada != FALSE);
        do
        {
            printf("\nDigite 1 para aula presente ou 0 para aula faltada:\n");
            scanf("%d", &novo->presenca);
        }while (novo->presenca != TRUE && novo->presenca != FALSE);
        printf("\nDigite a descricao da aula:\n");
        fflush(stdin);
        scanf("%[^\n]s", &novo->descricao);
        fflush(stdin);
        do{
            printf("\nDigite o tipo da aula, 'T' para teorica ou 'P' para pratica:\n");
            scanf("%c", &novo->tipo);
            fflush(stdin);
        }while (novo->tipo != 'T' && novo->tipo != 'P');
        novo->prox = aulas;
        aulas = novo;
        return aulas;
    }
}

ListaAulas editAula(ListaAulas aula)
{
    aula.data = setData();
    do
    {
        printf("Digite 1 para aula ministrada ou 0 para aula nao ministrada:\n");
        scanf("%d", &aula.ministrada);
    }while (aula.ministrada != TRUE && aula.ministrada != FALSE);
    do
    {
        printf("\nDigite 1 para aula presente ou 0 para aula faltada:\n");
        scanf("%d", &aula.presenca);
    }while (aula.presenca != TRUE && aula.presenca != FALSE);
    printf("\nDigite a descricao da aula:\n");
    fflush(stdin);
    scanf("%[^\n]s", &aula.descricao);
    fflush(stdin);
    do{
        printf("\nDigite o tipo da aula, 'T' para teorica ou 'P' para pratica:\n");
        scanf("%c", &aula.tipo);
        fflush(stdin);
    }while (aula.tipo != 'T' && aula.tipo != 'P');
    return aula;
}

ListaAulas *removeAula (ListaAulas *aula)
{
    if (aula->prox != NULL)
    {
        ListaAulas *aux = aula->prox;
        if (aula->prox->prox != NULL)
        {
            aula->prox = aula->prox->prox;
        }else{
            aula->prox = NULL;
        }
        free(aux);
        return aula;
    }else{
        free(aula);
        return NULL;
    }
}

int setQuantidadeAulas(ListaAulas *aulas)
{
    if (aulas != NULL)
    {
        int cont = 0;
        while (aulas != NULL)
        {
            cont++;
            aulas = aulas->prox;
        }
        return cont;
    }else{
        return 0;
    }
}


ListaAulas *menuAulas (ListaAulas *aulas)
{
    int opcao = 0, aulaEscolhida = 0, i;
    ListaAulas *aux = NULL;
    do
    {
        int cont = 0;
        system("cls");
        imprimeAulas(aulas);
        printf("\n\nEscolha sua opcao\n");
        printf("1. Cadastrar nova aula\n");
        printf("2. Editar aula\n");
        printf("3. Remover aula\n");
        printf("0. Voltar\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                aulas = setAulas(aulas);
                break;
            case 2:
                system("cls");
                aux = aulas;
                printf("Digite a posicao da aula na lista: ");
                while (aux != NULL)
                {
                    cont++;
                    aux = aux->prox;
                }
                scanf("%d", &aulaEscolhida);
                if (cont >= 1)
                {
                    while (aulaEscolhida < 1 || aulaEscolhida > cont)
                    {
                        printf("\n\nDigite uma aula valida: ");
                        scanf("%d", &aulaEscolhida);
                    }
                    aux = aulas;
                    for (i = 1; i < cont; i++)
                    {
                        aux = aux->prox;
                    }
                    (*aux) = editAula(*aux);
                }else{
                    printf("Nao ha aulas cadastradas\n\n");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                aux = aulas;
                printf("Digite a posicao da aula na lista: ");
                scanf("%d", &aulaEscolhida);
                while (aux != NULL)
                {
                    cont++;
                    aux = aux->prox;
                }
                scanf("%d", &aulaEscolhida);
                if (cont >= 1)
                {
                    while (aulaEscolhida < 1 || aulaEscolhida > cont)
                    {
                        printf("\n\nDigite uma aula valida: ");
                        scanf("%d", &aulaEscolhida);
                    }
                    aux = aulas;
                    for (i = 1; i < cont-1; i++)
                    {
                        aux = aux->prox;
                    }
                    aux = removeAula(aux);
                }else{
                    printf("Nao ha aulas cadastradas\n\n");
                    system("pause");
                }
            case 0:
                break;
            default:
                printf("\n\nDigite uma opcao valida\n\n");
                system("pause");
                break;
        }
    } while (opcao != 0);
    return aulas;
}
void imprimeAulas(ListaAulas *aulas)
{
    if (aulas != NULL)
    {
        ListaAulas *aux = aulas;
        while (aux != NULL)
        {
            printf("\nData da aula: %d/%d/%d", aux->data.dia, aux->data.mes, aux->data.ano);
            printf("\nAula ministrada: %d", aux->ministrada);
            printf("\nPresenca: %d", aux->presenca);
            printf("\nTipo: %c", aux->tipo);
            printf("\nDescricao: %s", aux->descricao);
            aux = aux->prox;
            printf("\n\n");
        }
    }else{
        printf("\nNao ha aulas cadastradas.");
    }
}

int setQuantidadeFaltas(ListaAulas *aulas)
{
    if (aulas != NULL)
    {
        int cont = 0;
        while (aulas != NULL)
        {
            if (aulas->presenca == FALSE)
            {
                cont++;
            }
            aulas = aulas->prox;
        }
        return cont;
    }else{
        return 0;
    }
}

void gravaAula(ListaMaterias *materia, char *nome, int numPeriodo)
{
    FILE *arquivo;
    int cont = 0;
    char buffer1[30], buffer2[30];
    ListaAulas *aux = materia->aulas;
    while (aux != NULL)
    {
        cont++;
        sprintf(buffer1, "%s.%d.%dAu%d", nome, numPeriodo, materia->numero, cont);
        arquivo = fopen(buffer1, "wb");
        fwrite(aux, sizeof(ListaAulas), 1, arquivo);
        fclose(arquivo);
        aux = aux->prox;
    }
    sprintf(buffer2, "%s.%d.%dAu.txt", nome, numPeriodo, materia->numero);
    arquivo = fopen(buffer2, "w");
    fprintf(arquivo, "%d", cont);
    fclose(arquivo);
}

ListaAulas *carregaAula (ListaMaterias *materia, char *nome, int numPeriodo)
{
    FILE *arquivo;
    ListaAulas *aux = materia->aulas;
    char buffer1[30], buffer2[30];
    int cont = 0, i;
    sprintf(buffer1, "%s.%d.%dAu.txt", nome, numPeriodo, materia->numero);
    arquivo = fopen(buffer1, "r");
    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d", &cont);
    }else{
        cont = 0;
        return NULL;
    }
    fclose(arquivo);
    remove(buffer1);
    for (i = cont; i >= 1; i--)
    {
        aux = NULL;
        sprintf(buffer2, "%s.%d.%dAu%d", nome, numPeriodo, materia->numero, i);
        arquivo = fopen(buffer2, "rb");
        if (arquivo != NULL)
        {
            aux = (ListaAulas*) malloc(sizeof(ListaAulas));
            fread(aux, sizeof(ListaAulas), 1, arquivo);
        }else{
            return NULL;
        }
        fclose(arquivo);
        remove(buffer2);
        aux->prox = materia->aulas;
        materia->aulas = aux;
    }
    return materia->aulas;
}

