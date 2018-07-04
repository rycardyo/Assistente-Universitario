#include <stdlib.h>
#include<stdio.h>
#include "assistUniv.h"



Faculdade setFaculdade()
{
    Faculdade faculdade;
    system("cls");
    printf("Digite o nome da faculdade:\n");
    fflush(stdin);
    scanf("%[^\n]s", faculdade.nome);
    fflush(stdin);
    printf("\nDigite a data de ingresso:\n");
    faculdade.dataIngresso = setData();
    faculdade.curso = setCurso();
    return faculdade;
}

Faculdade editFaculdade(Faculdade faculdade)
{
    system("cls");
    printf("Digite o nome da faculdade:\n");
    fflush(stdin);
    scanf("%[^\n]s", faculdade.nome);
    fflush(stdin);
    printf("\nDigite a data de ingresso:\n");
    faculdade.dataIngresso = setData();
    faculdade.curso = setCurso();
    return faculdade;
}

void imprimeFaculdade(Faculdade faculdade)
{
    printf("\nFaculdade: %s\n", faculdade.nome);
    printf("Data de ingresso: %d/%d/%d", faculdade.dataIngresso.dia,
           faculdade.dataIngresso.mes, faculdade.dataIngresso.ano);
    imprimeCurso(faculdade.curso);
}
