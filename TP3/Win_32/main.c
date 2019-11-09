#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "biblioteca.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char salir = 'N';
    int flagLoadLinkedList = 0;
    int devolution;
    int flagBuffer=0;

    LinkedList* listaEmploye = ll_newLinkedList();

    do{
        switch(menu())
        {
            case 1:
                if(flagLoadLinkedList == 0){
                    devolution=controller_loadFromText("data.csv",listaEmploye);
                    if(devolution==1)
                    {
                        printf("\n   **********************\n");
                        printf("   * Cargo Exitosamente *\n");
                        printf("   **********************\n\n");
                        flagLoadLinkedList=1;
                    }
                    else if (devolution==0)
                    {
                        printf("\n   *******************\n");
                        printf("   * Error al cargar *\n");
                        printf("   *******************\n\n");
                    }
                }else{
                    printf("\n   *********************\n");
                    printf("   * Ya estan cargados *\n");
                    printf("   *********************\n\n");
                }
                break;
            case 2:
                if(flagLoadLinkedList == 0){
                    devolution=controller_loadFromBinary("data.bin",listaEmploye);
                    if(devolution==1)
                    {
                        printf("\n   **********************\n");
                        printf("   * Cargo Exitosamente *\n");
                        printf("   **********************\n\n");

                        flagLoadLinkedList=1;
                    }
                    else if (devolution==0)
                    {
                        printf("\n   *******************\n");
                        printf("   * Error al cargar *\n");
                        printf("   *******************\n\n");
                    }
                }
                else{
                    printf("\n   *********************\n");
                    printf("   * Ya estan cargados *\n");
                    printf("   *********************\n\n");
                }

                system("pause");
                break;
            case 3:
                if(flagLoadLinkedList == 1){
                    devolution=controller_addEmployee(listaEmploye);
                    if(devolution==1)
                    {
                        printf("\n   *************************************\n");
                        printf("   * Cargo nuevo empleado Exitosamente *\n");
                        printf("   *************************************\n\n");

                        flagBuffer=1;
                    }
                    else if(devolution==0)
                    {
                        printf("\n   ***********************\n");
                        printf("   * Se cancelo la carga *\n");
                        printf("   ***********************\n\n");
                    }
                    else
                    {
                        printf("\n   ******************************\n");
                        printf("   * Error al cargar el nuevo empleado *\n");
                        printf("   ******************************\n\n");
                    }
                }
                else{
                    printf("\n   *********************************************\n");
                    printf("   * Primero debe cargar los datos del archivo *\n");
                    printf("   *********************************************\n\n");
                }

                system("pause");
                    break;

            case 4:
                if(flagBuffer == 1 || flagLoadLinkedList == 1){
                    devolution=controller_editEmployee(listaEmploye);
                    if(devolution==2){
                        printf("\n   *****************************\n");
                        printf("   * No se encontro ninguna ID *\n");
                        printf("   *****************************\n\n");
                    }
                    else if(devolution==1){
                        printf("\n   *******************************\n");
                        printf("   * Se edito de manera correcta *\n");
                        printf("   *******************************\n\n");
                    }
                    else if(devolution==-1){
                        printf("\n   ***************************************\n");
                        printf("   * No se pudo realizar por algun error *\n");
                        printf("   ***************************************\n\n");
                    }
                }
                else{
                    printf("\n   ******************************\n");
                    printf("   * No hay ningun dato cargado *\n");
                    printf("   ******************************\n\n");
                }

                system("pause");
                    break;

            case 5:
                if(flagBuffer == 1 || flagLoadLinkedList == 1){
                    devolution=controller_removeEmployee(listaEmploye);
                    if(devolution==-1){
                        printf("\n   *********************\n");
                        printf("   * Error al eliminar *\n");
                        printf("   *********************\n\n");
                    }
                    else if(devolution==0){
                        printf("\n   **********************\n");
                        printf("   * La baja se cancelo *\n");
                        printf("   **********************\n\n");
                    }
                    else if(devolution==1){
                        printf("\n   ************************************\n");
                        printf("   * La baja se realizo correctamente *\n");
                        printf("   ************************************\n\n");
                    }
                    else if(devolution==2){
                        printf("\n   ********************************************\n");
                        printf("   * No se encontro ningun usuario con esa ID *\n");
                        printf("   ********************************************\n\n");
                    }
                }
                else{
                    printf("\n   ******************************\n");
                    printf("   * No hay ningun dato cargado *\n");
                    printf("   ******************************\n\n");
                }


                system("pause");
                    break;

            case 6:
                if(!flagBuffer &&  !flagLoadLinkedList  ){
                    printf("\n   ******************************\n");
                    printf("   * No hay ningun dato cargado *\n");
                    printf("   ******************************\n\n");
                }
                else
                {
                    system("cls");
                    //showEmployees(listaEmploye);
                    controller_ListEmployee(listaEmploye);
                    printf("\n\n");
                }
                system("pause");
                break;
            case 7:
                if(!flagBuffer && !flagLoadLinkedList){
                        printf("\n   ******************************\n");
                        printf("   * No hay ningun dato cargado *\n");
                        printf("   ******************************\n\n");
                }else{
                    controller_sortEmployee(listaEmploye);
                }

                system("pause");
                break;
            case 8:
                       devolution = controller_saveAsText("./data.csv",listaEmploye);
                       if(devolution == 1){
                            printf("\n   ********************************\n");
                            printf("   * Se Guardo de manera correcta *\n");
                            printf("   ********************************\n\n");
                            flagLoadLinkedList=0;
                            flagBuffer=0;
                            ll_deleteLinkedList(listaEmploye);
                            listaEmploye=ll_newLinkedList();
                       }else{
                            printf("\n   *******************************\n");
                            printf("   * Ocurrio un Error al Guardar *\n");
                            printf("   *******************************\n\n");
                       }
                       system("pause");
                        break;
            case 9:
                       devolution = controller_saveAsBinary("./data.bin",listaEmploye);
                       if(devolution == 1){
                            printf("\n   ********************************\n");
                            printf("   * Se Guardo de manera correcta *\n");
                            printf("   ********************************\n\n");
                            flagLoadLinkedList=0;
                            flagBuffer=0;
                            ll_deleteLinkedList(listaEmploye);
                            listaEmploye=ll_newLinkedList();
                       }else{
                            printf("\n   *******************************\n");
                            printf("   * Ocurrio un Error al Guardar *\n");
                            printf("   *******************************\n\n");
                       }
                       system("pause");
                        break;
            case 10:
                getChar(&salir,"Desea Salir?  S o N: ","Error. Ingrese S o N: ", 'S', 'N');
                printf("\n\n");

            default:
                printf("\n   ******************************\n");
                printf("   * Opcion invalida. Reingrese *\n");
                printf("   ******************************\n\n");
                 system("pause");
            break;
        }
        system("pause");

    }while(salir == 'N');

    if(salir == 'S'){
                printf("\n ******************************\n");
                printf("   **********  ADIOS  ***********\n");
                printf("   ******************************\n\n");
                 system("pause");
    }
    return 0;
}
