#include <stdio.h>
#include <stdlib.h>
#include "assistUniv.h"


int main()
{
    Aluno *alunos = NULL;
    alunos = carregaAluno(alunos);
    alunos = menu(alunos);
    gravaAluno(alunos);
}
