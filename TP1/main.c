#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Menu.h"
#include "Operation.h"

int main()
{
    int a;
    int b;
    int sum;
    int subtraction;
    int multiplication;
    int flagA = 0;
    int flagB = 0;
    int flagDivide = 0;
    int flagOperation = 0;
    float divide;
    long factorialA;
    long factorialB;
    char seguir = 's';
    char continuar;

    do{
        switch(menu(a, b, flagA, flagB)){
            case 1:
                printf("Ingrese el valor de A: ");
                scanf("%d", &a);
                flagA = 1;
                break;
            case 2:
                printf("Ingrese el valor de B: ");
                scanf("%d", &b);
                flagB = 1;
                break;
            case 3:
                if(flagA && flagB){

                    sum = sumOperation(a,b);
                    subtraction = subtractionOperation(a,b);

                    if(b > 0){
                        divide = divideOperation(a,b);
                        flagDivide = 1;
                    }
                    multiplication = multipliOperation(a,b);
                    factorialA = factorial(a);
                    factorialB = factorial(b);

                    flagOperation =1;
                }else{
                     printf("\nSe debe ingresar los operandos A y B para realizar las operaciones.\n\n");
                }

                if(flagOperation == 1){
                    printf("\nLos calculos se realizaron con exito\n");
                }

                break;
            case 4:
                if(flagOperation == 1){

                    printf("a) El resultado de A+B es: %d\n", sum);
                    printf("b) El resultado de A-B es: %d\n", subtraction);

                    if(flagDivide==1){
                    printf("c) El resultado de A/B es: %.2f.\n", divide);
                    }
                    else{
                        printf("c) No es posible dividir por cero \n");
                    }

                    printf("d) El resultado de A*B es: %d\n", multiplication);
                    printf("e) Los factoriales de A es %li y el factorial de B es %li\n\n", factorialA, factorialB);

                }else{
                    printf("\nEs necesario realizar los calculos primero\n");
                }

                break;
            case 5:
                printf("\nEstas seguro? ");
                fflush(stdin);
                continuar = getchar();
                continuar = tolower(continuar);

                if(continuar == 's'){
                    printf("\n CHAUU \n");
                    seguir = 'n';
                }
                break;
            default:
                printf("Opcion Invalida\n\n");
                break;
        }
         system("pause");

    }while(seguir == 's');


    return 0;
}

