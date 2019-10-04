
#include "function.h"

#define SIZEEMP 1000
#define SIZESEC 5

int main()
{
    char seguir = 's';
    char confirmar;
    int legajo = 0;

    eEmployee employee[SIZEEMP];

//-----------------------LLAMADA DE FUNCIONES-----------/
    initEmployees(employee, SIZEEMP);

    legajo = legajo + generateEmployee(employee, SIZEEMP, 5);

    do
    {
        switch(menu())
        {
        case 1:
            //printf("\nAlta empleado\n");
            if(highEmployee(employee, SIZEEMP, legajo)){
                legajo++;
            }
            system("pause");
            break;

        case 2:
            //printf("\nBaja empleado\n");

            removeEmployee(employee, SIZEEMP);
            system("pause");
            break;

        case 3:
            //printf("\nModificar empleado\n");
            modifyEmployee(employee, SIZEEMP);
            system("pause");
            break;
        case 4:
           printEmployees(employee, SIZEEMP);
            system("pause");
            break;
        case 5:
            findEmployeeById(employee, SIZEEMP);
            system("pause");
            break;
        case 6:
            if(legajo != 0){
                switch(menuInfo()){
                case 1:
                        switch(menuAlphabet()){
                            case 1:
                                    sortEmployeesUpward(employee, SIZEEMP);
                                break;
                            case 2:
                                    sortEmployeesDecendent(employee, SIZEEMP);
                                break;
                      }
                      break;
                case 2:
                      //printf("Total empleados y promedio de sueldos: ");
                      totalEmployees(employee, SIZEEMP);
                      system("pause");
                      break;
                case 3:
                     // printf("Empleados que superan el sueldopromedio: ");
                     employeeExceedsAverage(employee, SIZEEMP);
                     system("pause");
                      break;
                }
            }
            else{
                printf("\n\nPRIMERO SE DEBEN CARGAR EMPLEADOS!!!\n\n\n");
                system("pause");
            }

            break;


        case 7:
            printf("\nConfirmar salida ??  S o N: \n\n");
            fflush(stdin);
            confirmar = getche();

            if(tolower(confirmar) == 's'){
                seguir = 'n';
            }
            system("\npause\n");
            break;

        default:
            printf("\nOpcion invalida. Reingrese opcion.\n\n");
           system("pause");
        }
    }
    while(seguir == 's');
    return 0;
}
