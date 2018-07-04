#include <stdlib.h>
#include "assistUniv.h"


Data setData()
{
    Data data;
    do
    {
        printf("Digite o dia: ");
        scanf("%d", &data.dia);
    }while (data.dia < 1 || data.dia > 31);
   do
    {
        printf("Digite o mes: ");
        scanf("%d",  &data.mes);
    }while (data.mes < 1 || data.mes > 12);
    do
    {
        printf("Digite o ano: ");
        scanf("%d", &data.ano);
    }while (data.ano < 1980);
    return data;
}
