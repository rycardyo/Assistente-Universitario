#include "assistUniv.h"
#include<stdio.h>
#include<stdlib.h>



ListaAvaliacoes *setAvaliacoes (ListaAvaliacoes *avaliacoes)
{
    system("cls");
    if (avaliacoes == NULL)
    {
        avaliacoes = (ListaAvaliacoes*) malloc(sizeof(ListaAvaliacoes));
        avaliacoes->prox = NULL;
        printf("Digite a data da avaliacao:\n");
        avaliacoes->data = setData();
        printf("\nDigite o tema da avaliacao:\n");
        fflush(stdin);
        scanf("%[^\n]s", &avaliacoes->tema);
        printf("\nDigite o peso da avaliacao:\n");
        scanf("%f", &avaliacoes->peso);
        printf("\nDigite a nota da avaliacao:\n");
        scanf("%f", &avaliacoes->nota);
        return avaliacoes;
    }else{
        ListaAvaliacoes *novo;
        novo = (ListaAvaliacoes*) malloc(sizeof(ListaAvaliacoes));
        novo->prox = NULL;
        printf("Digite a data da avaliacao:\n");
        novo->data = setData();
        printf("\nDigite o tema da avaliacao:\n");
        fflush(stdin);
        scanf("%[^\n]s", &novo->tema);
        printf("\nDigite o peso da avaliacao:\n");
        scanf("%f", &novo->peso);
        printf("\nDigite a nota da avaliacao:\n");
        scanf("%f", &novo->nota);
        novo->prox = avaliacoes;
        avaliacoes = novo;
        return avaliacoes;
    }
}

ListaAvaliacoes editAvaliacoes (ListaAvaliacoes avaliacao)
{
    printf("Digite a data da avaliacao:\n");
    avaliacao.data = setData();
    printf("\nDigite o tema da avaliacao:\n");
    fflush(stdin);
    scanf("%[^\n]s", &avaliacao.tema);
    printf("\nDigite o peso da avaliacao:\n");
    scanf("%f", &avaliacao.peso);
    printf("\nDigite a nota da avaliacao:\n");
    scanf("%f", &avaliacao.nota);
    return avaliacao;
}

ListaAvaliacoes *removeAvaliacao (ListaAvaliacoes *avaliacao)
{
    if (avaliacao->prox != NULL)
    {
        ListaAvaliacoes *aux = avaliacao->prox;
        if (avaliacao->prox->prox != NULL)
        {
            avaliacao->prox = avaliacao->prox->prox;
        }else{
            avaliacao->prox = NULL;
        }
        free(aux);
        return avaliacao;
    }else{
        free(avaliacao);
        return NULL;
    }
}


ListaAvaliacoes *menuAvaliacoes (ListaAvaliacoes *avaliacoes)
{
    int opcao = 0, avaliacaoEscolhida = 0, i;
    ListaAvaliacoes *aux = NULL;
    do
    {
        int cont = 0;
        system("cls");
        imprimeAvaliacoes(avaliacoes);
        printf("\n\nEscolha sua opcao\n");
        printf("1. Cadastrar nova avaliacao\n");
        printf("2. Editar avaliacao\n");
        printf("3. Remover avaliacao\n");
        printf("4. Trabalhos\n");
        printf("0. Voltar\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                avaliacoes = setAvaliacoes(avaliacoes);
                break;
            case 2:
                system("cls");
                aux = avaliacoes;
                printf("Digite a posicao da avaliacao na lista: ");
                while (aux != NULL)
                {
                    cont++;
                    aux = aux->prox;
                }
                scanf("%d", &avaliacaoEscolhida);
                if (cont >= 1)
                {
                    while (avaliacaoEscolhida < 1 || avaliacaoEscolhida > cont)
                    {
                        printf("\n\nDigite uma avaliacao valida: ");
                        scanf("%d", &avaliacaoEscolhida);
                    }
                    aux = avaliacoes;
                    for (i = 1; i < cont; i++)
                    {
                        aux = aux->prox;
                    }
                    (*aux) = editAvaliacoes(*aux);
                }else{
                    printf("Nao ha avaliacoes cadastradas\n\n");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                aux = avaliacoes;
                printf("Digite a posicao da avaliacao na lista: ");
                while (aux != NULL)
                {
                    cont++;
                    aux = aux->prox;
                }
                scanf("%d", &avaliacaoEscolhida);
                if (cont >= 1)
                {
                    while (avaliacaoEscolhida < 1 || avaliacaoEscolhida > cont)
                    {
                        printf("\n\nDigite uma avaliacao valida: ");
                        scanf("%d", &avaliacaoEscolhida);
                    }
                    aux = avaliacoes;
                    for (i = 1; i < cont-1; i++)
                    {
                        aux = aux->prox;
                    }
                    aux = removeAvaliacao(aux);
                }else{
                    printf("Nao ha avaliacoes cadastradas\n\n");
                    system("pause");
                }
                break;

            case 0:
                break;
            default:
                printf("\n\nDigite uma opcao valida\n\n");
                system("pause");
                break;
        }
    } while (opcao != 0);
    return avaliacoes;
}
void imprimeAvaliacoes(ListaAvaliacoes *avaliacoes)
{
    if (avaliacoes != NULL)
    {
        ListaAvaliacoes *aux = avaliacoes;
        while (aux != NULL)
        {
            printf("\nData de avaliacao: %d/%d/%d", aux->data.dia, aux->data.mes, aux->data.ano);
            printf("\nTema avaliacao: %s", aux->tema);
            printf("\nPeso da avaliacao: %f", aux->peso);
            printf("\nNota da Avaliacao: %f", aux->nota);
            aux = aux->prox;
            printf("\n\n");
        }
    }else{
        printf("\nNao ha avaliacoes cadastradas.");
    }
}

void gravaAvaliacao(ListaMaterias *materia, char *nome, int numPeriodo)
{
    FILE *arquivo;
    int cont = 0;
    char buffer1[30], buffer2[30];
    ListaAvaliacoes *aux = materia->avaliacoes;
    while (aux != NULL)
    {
        cont++;
        sprintf(buffer1, "%s.%d.%dAv%d", nome, numPeriodo, materia->numero, cont);
        arquivo = fopen(buffer1, "wb");
        fwrite(aux, sizeof(ListaAvaliacoes), 1, arquivo);
        fclose(arquivo);
        aux = aux->prox;
    }
    sprintf(buffer2, "%s.%d.%dAv.txt", nome, numPeriodo, materia->numero);
    arquivo = fopen(buffer2, "w");
    fprintf(arquivo, "%d", cont);
    fclose(arquivo);
}

ListaAvaliacoes *carregaAvaliacao (ListaMaterias *materia, char *nome, int numPeriodo)
{
    FILE *arquivo;
    ListaAvaliacoes *aux = materia->avaliacoes;
    char buffer1[30], buffer2[30];
    int cont = 0, i;
    sprintf(buffer1, "%s.%d.%dAv.txt", nome, numPeriodo, materia->numero);
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
        sprintf(buffer2, "%s.%d.%dAv%d", nome, numPeriodo, materia->numero, i);
        arquivo = fopen(buffer2, "rb");
        if (arquivo != NULL)
        {
            aux = (ListaAvaliacoes*) malloc(sizeof(ListaAvaliacoes));
            fread(aux, sizeof(ListaAvaliacoes), 1, arquivo);
        }else{
            return NULL;
        }
        fclose(arquivo);
        remove(buffer2);
        aux->prox = materia->avaliacoes;
        materia->avaliacoes = aux;
    }
    return materia->avaliacoes;
}
