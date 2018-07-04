#include <stdlib.h>
#include<stdio.h>
#include "assistUniv.h"



Curso setCurso()
{
    Curso curso;
    curso.periodos = NULL;
    system("cls");
    printf("Digite o nome do curso:\n");
    fflush(stdin);
    scanf("%[^\n]s", &curso.nome);
    fflush(stdin);
    return curso;
}

Curso editCurso (Curso curso)
{
    curso.periodos = NULL;
    system("cls");
    printf("Digite o nome do curso:\n");
    fflush(stdin);
    scanf("%[^\n]s", &curso.nome);
    fflush(stdin);
    return curso;
}

void imprimeCurso(Curso curso)
{
    PilhaPeriodos *aux;
    aux = curso.periodos;
    printf("\nCurso: %s", curso.nome);
}
