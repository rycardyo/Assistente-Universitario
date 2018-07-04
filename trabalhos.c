#include "assistUniv.h"
#include<stdio.h>
#include<stdlib.h>


ListaTrabalhos *setTrabalhos (ListaTrabalhos *trabalhos)
{
    system("cls");
    if (trabalhos == NULL)
    {
        trabalhos = (ListaTrabalhos*) malloc(sizeof(ListaTrabalhos));
        trabalhos->prox = NULL;
        printf("Digite a data da trabalho:\n");
        trabalhos->data = setData();
        printf("\nDigite o tema da trabalho:\n");
        fflush(stdin);
		scanf("%[^\n]s", &trabalhos->tema);
		printf("\nDescricao: :\n");
        fflush(stdin);
		scanf("%[^\n]s", &trabalhos->descricao);
        fflush(stdin);
		printf("\nLink :\n");
		scanf("%[^\n]s", &trabalhos->link);
		printf("\Relevancia (avalie de 1 a 3):\n");
		scanf("%d", &trabalhos->relevancia);
        printf("\nDigite o peso da trabalho:\n");
        scanf("%f", &trabalhos->peso);
        printf("\nDigite a nota da trabalho:\n");
        scanf("%f", &trabalhos->nota);
        return trabalhos;
    }else{
        ListaTrabalhos *novo;
        novo = (ListaTrabalhos*) malloc(sizeof(ListaTrabalhos));
        novo->prox = NULL;
        printf("Digite a data da trabalho:\n");
        trabalhos->data = setData();
        printf("\nDigite o tema da trabalho:\n");
        fflush(stdin);
		scanf("%[^\n]s", &trabalhos->tema);
		printf("\nDescricao: :\n");
		scanf("%[^\n]s", &trabalhos->descricao);
		printf("\nLink :\n");
		scanf("%[^\n]s", &trabalhos->link);
		printf("\Relevancia (avalie de 1 a 3):\n");
		scanf("%d", &trabalhos->relevancia);
        printf("\nDigite o peso da trabalho:\n");
        scanf("%f", &trabalhos->peso);
        printf("\nDigite a nota da trabalho:\n");
        scanf("%f", &trabalhos->nota);
        novo->prox = trabalhos;
        trabalhos = novo;
        return trabalhos;
    }
}

ListaTrabalhos editTrabalhos (ListaTrabalhos trabalho)
{
    printf("Digite a data da trabalho:\n");
    trabalho.data = setData();
    printf("\nDigite o tema da trabalho:\n");
    fflush(stdin);
    scanf("%[^\n]s", &trabalho.tema);
    printf("\nDigite a descricao do trabalho:\n");
    fflush(stdin);
    scanf("%[^\n]s", &trabalho.descricao);
    printf("\nDigite o link do trabalho:\n");
    fflush(stdin);
    scanf("%[^\n]s", &trabalho.link);
    printf("\nDigite a relevancia do trabalho:\n");
    fflush(stdin);
    scanf("%[^\n]s", &trabalho.relevancia);
    printf("\nDigite o peso da trabalho:\n");
    scanf("%f", &trabalho.peso);
    printf("\nDigite a nota da trabalho:\n");
    scanf("%f", &trabalho.nota);
    return trabalho;
}

ListaTrabalhos *removeTrabalho (ListaTrabalhos *trabalho)
{
    if (trabalho->prox != NULL)
    {
        ListaTrabalhos *aux = trabalho->prox;
        if (trabalho->prox->prox != NULL)
        {
            trabalho->prox = trabalho->prox->prox;
        }else{
            trabalho->prox = NULL;
        }
        free(aux);
        return trabalho;
    }else{
        free(trabalho);
        return NULL;
    }
}
void imprimeTrabalhos(ListaTrabalhos *trabalhos)
{
    if (trabalhos != NULL)
    {
        ListaTrabalhos *aux = trabalhos;
        while (aux != NULL)
        {
            printf("\nData de trabalho: %d/%d/%d", aux->data.dia, aux->data.mes, aux->data.ano);
            printf("\nTema trabalho: %s", aux->tema);
            printf("\nPeso da trabalho: %f", aux->peso);
            printf("\nNota da trabalho: %f", aux->nota);
            aux = aux->prox;
            printf("\n\n");
        }
    }else{
        printf("\nNao ha trabalhos cadastradas.");
    }
}


ListaTrabalhos *menuTrabalhos (ListaTrabalhos *trabalhos)
{
    int opcao = 0, trabalhoEscolhido = 0, i;
    ListaTrabalhos *aux = NULL;
    do
    {
        int cont = 0;
        system("cls");
        imprimeTrabalhos(trabalhos);
        printf("\n\nEscolha sua opcao\n");
        printf("1. Cadastrar novo trabalho\n");
        printf("2. Editar trabalho\n");
        printf("3. Remover trabalho\n");
        printf("0. Voltar\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                trabalhos = setTrabalhos(trabalhos);
                break;
            case 2:
                system("cls");
                aux = trabalhos;
                printf("Digite a posicao da trabalho na lista: ");
                while (aux != NULL)
                {
                    cont++;
                    aux = aux->prox;
                }
                scanf("%d", &trabalhoEscolhido);
                if (cont >= 1)
                {
                    while (trabalhoEscolhido < 1 || trabalhoEscolhido > cont)
                    {
                        printf("\n\nDigite uma trabalho valida: ");
                        scanf("%d", &trabalhoEscolhido);
                    }
                    aux = trabalhos;
                    for (i = 1; i < cont; i++)
                    {
                        aux = aux->prox;
                    }
                    (*aux) = editTrabalhos(*aux);
                }else{
                    printf("Nao ha trabalhos cadastradas\n\n");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                aux = trabalhos;
                printf("Digite a posicao da trabalho na lista: ");
                while (aux != NULL)
                {
                    cont++;
                    aux = aux->prox;
                }
                scanf("%d", &trabalhoEscolhido);
                if (cont >= 1)
                {
                    while (trabalhoEscolhido < 1 || trabalhoEscolhido > cont)
                    {
                        printf("\n\nDigite uma trabalho valida: ");
                        scanf("%d", &trabalhoEscolhido);
                    }
                    aux = trabalhos;
                    for (i = 1; i < cont-1; i++)
                    {
                        aux = aux->prox;
                    }
                    aux = removeTrabalho(aux);
                }else{
                    printf("Nao ha trabalhos cadastradas\n\n");
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
    return trabalhos;
}

void imprimeTrabalhosPorRelevancia(ListaTrabalhos *trabalhos, int relevancia)
{
    if (trabalhos != NULL)
    {
        ListaTrabalhos *aux = trabalhos;
        while (aux != NULL)
        {
			if(aux->relevancia == relevancia){
            printf("\nData de trabalho: %d/%d/%d", aux->data.dia, aux->data.mes, aux->data.ano);
            printf("\nTema trabalho: %s", aux->tema);
			printf("\n Nivel de Relevancia do Trabaho %d: ", aux->relevancia);
            printf("\nPeso da trabalho: %f", aux->peso);
            printf("\nNota da trabalho: %f", aux->nota);
            aux = aux->prox;
            printf("\n\n");
			}
        }
    }else{
        printf("\nNao ha trabalhos cadastradas.");
    }
}

void gravaTrabalho(ListaMaterias *materia, char *nome, int numPeriodo)
{
    FILE *arquivo;
    int cont = 0;
    char buffer1[30], buffer2[30];
    ListaTrabalhos *aux = materia->trabalhos;
    while (aux != NULL)
    {
        cont++;
        sprintf(buffer1, "%s.%d.%dTr.%d", nome, numPeriodo, materia->numero, cont);
        arquivo = fopen(buffer1, "wb");
        fwrite(aux, sizeof(ListaTrabalhos), 1, arquivo);
        fclose(arquivo);
        aux = aux->prox;
    }
    sprintf(buffer2, "%s.%d.%dTr.txt", nome, numPeriodo, materia->numero);
    arquivo = fopen(buffer2, "w");
    fprintf(arquivo, "%d", cont);
    fclose(arquivo);
}

ListaTrabalhos *carregaTrabalho (ListaMaterias *materia, char *nome, int numPeriodo)
{
    FILE *arquivo;
    ListaTrabalhos *aux = materia->trabalhos;
    char buffer1[30], buffer2[30];
    int cont = 0, i;
    sprintf(buffer1, "%s.%d.%dTr.txt", nome, numPeriodo, materia->numero);
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
        sprintf(buffer2, "%s.%d.%dTr%d", nome, numPeriodo, materia->numero, i);
        arquivo = fopen(buffer2, "rb");
        if (arquivo != NULL)
        {
            aux = (ListaTrabalhos*) malloc(sizeof(ListaTrabalhos));
            fread(aux, sizeof(ListaTrabalhos), 1, arquivo);
        }else{
            return NULL;
        }
        fclose(arquivo);
        remove(buffer2);
        aux->prox = materia->trabalhos;
        materia->trabalhos = aux;
    }
    return materia->trabalhos;
}
