#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"


int menu(int a, int b, int flagA, int flagB){
    system("cls");
    int option;

        printf("\n    *************************************\n");
        printf("    *      TRABAJO PRACTICO NUMERO 1    *");
        printf("\n    *************************************\n");

        printf("\n\n   *** Menu de Opciones ***\n\n");

        if(flagA == 0){
            printf(" 1- Ingresar 1er operando (A=x): \n");
        }else{
            printf(" 1. 1er operando (A=%d) \n", a);
        }

        if(flagB == 0){
            printf(" 2- Ingresar 2do operando (B=y): \n");
        }else{
            printf(" 2.  2do operando (B=%d) \n", b);
        }

        printf(" 3- Calcular todas las operaciones \n");
        printf(" 4- Informar resultados \n");
        printf(" 5- Salir \n");

         printf("\n  Ingrese opcion: ");
            scanf("%d", &option);

    return option;
}

