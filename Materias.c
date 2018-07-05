#include <stdlib.h>
#include <stdio.h>
#include "assistUniv.h"



ListaMaterias *setMaterias (ListaMaterias *materias)
{
    system("cls");
    if (materias == NULL)
    {
        materias = (ListaMaterias*) malloc(sizeof(ListaMaterias));
        materias->prox = NULL;
        printf("Digite o nome da materia:\n");
        fflush(stdin);
        scanf("%s[^\n]", &materias->nome);
        fflush(stdin);
        printf("\nDigite o numero da materia:\n");
        scanf("%d", &materias->numero);
        printf("\nDigite a carga horaria da materia:n");
        scanf("%d", &materias->cargaHoraria);
        printf("\nDigite a ementa da materia:\n");
        fflush(stdin);
        scanf("%[^\n]s", materias->ementa);
        fflush(stdin);
        materias->aulas = NULL;
        materias->avaliacoes = NULL;
        materias->trabalhos = NULL;
        materias->quandidadeAulas = setQuantidadeAulas(materias->aulas);
        materias->quantidadeFaltas = setQuantidadeFaltas(materias->aulas);
        materias->prox = NULL;
        return materias;
    }else{
        ListaMaterias *novo;
        novo = malloc(sizeof(ListaMaterias));
        novo->prox = NULL;
        printf("Digite o nome da materia:\n");
        fflush(stdin);
        scanf("%s[^\n]", &novo->nome);
        fflush(stdin);
        printf("\nDigite o numero da materia:\n");
        scanf("%d", &novo->numero);
        printf("\nDigite a carga horaria da materia:n");
        scanf("%d", &novo->cargaHoraria);
        printf("\nDigite a ementa da materia:\n");
        fflush(stdin);
        scanf("%[^\n]s", novo->ementa);
        fflush(stdin);
        novo->aulas = NULL;
        novo->avaliacoes = NULL;
        novo->trabalhos = NULL;
        novo->quandidadeAulas = setQuantidadeAulas(novo->aulas);
        novo->quantidadeFaltas = setQuantidadeFaltas(novo->aulas);
        novo->prox = materias;
        materias = novo;
        return materias;
    }
}

ListaMaterias editMateria (ListaMaterias materia)
{
    printf("Digite o nome da materia:\n");
    fflush(stdin);
    scanf("%s[^\n]", &materia.nome);
    fflush(stdin);
    printf("\nDigite o numero da materia:\n");
    scanf("%d", &materia.numero);
    printf("\nDigite a carga horaria da materia:n");
    scanf("%d", &materia.cargaHoraria);
    printf("\nDigite a ementa da materia:\n");
    fflush(stdin);
    scanf("%[^\n]s", materia.ementa);
    fflush(stdin);
    return materia;
}

ListaMaterias *removeMateria (ListaMaterias *inicio , ListaMaterias *materia)
{
    if (materia->prox != NULL)
    {
        ListaMaterias *aux = materia->prox;
        if (aux->prox != NULL)
        {
            materia->prox = aux->prox;
        }else{
            materia->prox = NULL;
        }
        free(aux);
        return inicio;
    }else{
        free(materia);
        return NULL;
    }
}


ListaMaterias *menuMaterias (ListaMaterias *materias)
{
    int opcao;
    ListaMaterias *aux = NULL;
    do
    {
        system("cls");
        int materiaEscolhida = 0, achou = 0;
        imprimeMaterias(materias);
        printf("\n\nEscolha sua opcao\n");
        printf("1. Cadastrar nova materia\n");
        printf("2. Editar materia\n");
        printf("3. Menu de Avaliacoes\n");
        printf("4. Menu Trabalhos/Projetos\n");
        printf("5. Menu de Aulas\n");
        printf("6. Remove materia\n");
        printf("0. Voltar\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                materias = setMaterias(materias);
                break;
            case 2:
                aux = materias;
                system("cls");
                printf("Digite o numero da materia que deseja editar: ");
                scanf("%d", &materiaEscolhida);
                while (aux != NULL)
                {
                    if (aux ->numero == materiaEscolhida)
                    {
                        (*aux) = editMateria(*aux);
                        achou = 1;
                    }
                    aux = aux->prox;
                }
                if (achou == 0)
                {
                    printf("Materia nao encontrada\n\n");
                    system("pause");
                }else{
                    printf("Materia editada\n\n");
                    system("pause");
                }
                break;
            case 3:
                aux = materias;
                system("cls");
                printf("Digite o numero da materia que deseja ver as avaliacoes: ");
                scanf("%d", &materiaEscolhida);
                while (aux != NULL)
                {
                    if (aux->numero == materiaEscolhida)
                    {
                        aux->avaliacoes = menuAvaliacoes(aux->avaliacoes);
                        achou = 1;
                        //break;
                    }
                    aux = aux->prox;
                }
                if (achou == 0)
                {
                    printf("\nMateria nao encontrado\n\n");
                    system("pause");
                }
                break;
            case 4:
                aux = materias;
                system("cls");
                printf("Digite o numero da materia que deseja ver os trabalhos/projetos: ");
                scanf("%d", &materiaEscolhida);
                while (aux != NULL)
                {
                    if (aux->numero == materiaEscolhida)
                    {
                        aux->trabalhos = menuTrabalhos(aux->trabalhos);
                        achou = 1;
                        //break;
                    }
                    aux = aux->prox;
                }
                if (achou == 0)
                {
                    printf("\nMateria nao encontrado\n\n");
                    system("pause");
                }
                break;
            case 5:

                aux = materias;
                system("cls");
                printf("Digite o numero da materia que deseja ver as aulas: ");
                scanf("%d", &materiaEscolhida);
                while (aux != NULL)
                {
                    if (aux->numero == materiaEscolhida)
                    {
                        aux->aulas = menuAulas(aux->aulas);
                        achou = 1;
                    }
                    aux = aux->prox;
                }
                if (achou == 0)
                {
                    printf("\nMateria nao encontrado\n\n");
                    system("pause");
                }
                break;
            case 6:
                aux = materias;
                system("cls");
                printf("Digite o numero da materia que deseja remover: ");
                scanf("%d", &materiaEscolhida);
                while (aux->prox != NULL)
                {
                    if ((aux->prox)->numero == materiaEscolhida)
                    {
                        materias = removeMateria(materias ,aux);
                        achou = 1;
                    }
                    aux = aux->prox;
                }
                if (aux->numero == materiaEscolhida)
                {
                    materias = removeMateria(materias, aux);
                    achou = 1;
                }
                if (achou == 0)
                {
                    printf("Materia nao encontrada\n\n");
                    system("pause");
                }else{
                    printf("Materia removida\n\n");
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
    }while (opcao != 0);
    return materias;
}

void imprimeMaterias(ListaMaterias *materia)
{
    if (materia != NULL)
    {
        ListaMaterias *aux = materia;
        while (aux != NULL)
        {
            printf("\nMateria: %s", aux->nome);
            printf("\nNumero da materia: %d", aux->numero);
            printf("\nCarga Horaria: %d", aux->cargaHoraria);
            printf("\nQuantidade de aulas: %d", setQuantidadeAulas(materia->aulas));
            printf("\nQuantidade de faltas: %d", setQuantidadeFaltas(materia->aulas));
            printf("\nEmenta: %s", aux->ementa);

            situacaoFrequencia(materia, materia->aulas);
            printf("\n\n\n");
            aux = aux->prox;
        }
    }else{
        printf("\nNao ha materias cadastradas.");
    }
}
void gravaMateria(PilhaPeriodos *periodo, char *nome)
{
    FILE *arquivo;
    int cont = 0;
    char buffer1[30], buffer2[30];
    ListaMaterias *aux = periodo->materias;
    while (aux != NULL)
    {
        cont++;
        sprintf(buffer1, "%s.%d.M%d", nome, periodo->numero, cont);
        arquivo = fopen(buffer1, "wb");
        fwrite(aux, sizeof(ListaMaterias), 1, arquivo);
        fclose(arquivo);
        gravaAula(aux, nome, periodo->numero);
        gravaAvaliacao(aux, nome, periodo->numero);
        gravaTrabalho(aux, nome, periodo->numero);
        aux = aux->prox;
    }
    sprintf(buffer2, "%s.%d.M.txt", nome, periodo->numero);
    arquivo = fopen(buffer2, "w");
    fprintf(arquivo, "%d", cont);
    fclose(arquivo);
}

ListaMaterias *carregaMateria (PilhaPeriodos *periodo, char *nome)
{
    FILE *arquivo;
    ListaMaterias *aux = periodo->materias;
    char buffer1[30], buffer2[30];
    int cont = 0, i;
    sprintf(buffer1, "%s.%d.M.txt", nome, periodo->numero);
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
        sprintf(buffer2, "%s.%d.M%d", nome, periodo->numero, i);
        arquivo = fopen(buffer2, "rb");
        if (arquivo != NULL)
        {
            aux = (ListaMaterias*) malloc(sizeof(ListaMaterias));
            fread(aux, sizeof(ListaMaterias), 1, arquivo);
            aux->aulas = NULL;
            aux->aulas = carregaAula(aux, nome, periodo->numero);
            aux->avaliacoes = NULL;
            aux->avaliacoes = carregaAvaliacao(aux, nome, periodo->numero);
            aux->trabalhos = NULL;
            aux->trabalhos = carregaTrabalho(aux, nome, periodo->numero);
        }else{
            return NULL;
        }
        fclose(arquivo);
        remove(buffer2);
        aux->prox = periodo->materias;
        periodo->materias = aux;
    }
    return periodo->materias;
}


