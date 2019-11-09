#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "biblioteca.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
     FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile= fopen(path,"r");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_EmployeeFromText(pFile, pArrayListEmployee);
        }
    }
    fclose(pFile);

    return result;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile = fopen(path,"rb");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        }
    }
    fclose(pFile);

    return result;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    int result=-1;
    char auxId[50];
    char auxHoras[50];
    char auxSalario[50];
    char auxNombre[130];
    char confirm;


    system("cls");
    printf("---Carga de empleado nuevo---\n\n");

   // printf("Ingrese ID: ");
    //fflush(stdin);
    //gets(auxId);

    getString(auxId, "Ingrese ID: ", "Error. Reingrese ID: ", 1,50);


    //printf("Ingrese nombre: ");
    //fflush(stdin);
    //gets(auxNombre);
    //strlwr(auxNombre);
    //auxNombre[0] = toupper(auxNombre[0]);

    getString(auxNombre, "Ingrese Nombre: ", "Error. Reingrese Nombre: ", 1,50);

    //printf("Ingrese horas trabajadas: ");
    //fflush(stdin);
    //gets(auxHoras);

    getString(auxHoras, "Ingrese horas trabajadas: ", "Error. Reingrese horas trabajadas: ", 1,50);

    //printf("Ingrese salario: ");
    //fflush(stdin);
    //gets(auxSalario);

    getString(auxSalario, "Ingrese Salario: ", "Error. Reingrese Salario: ", 1, 50);

    //printf("\nConfirma la carga? s/n: ");
    //fflush(stdin);
    //confirm=getchar();
    //confirm=tolower(confirm);

    getChar(&confirm, "Confirma la carga? S/N: ", "Error. Confirma la carga? S/N: ", 'S', 'N');

        if(confirm=='S')
        {
            Employee* empNew = employee_newParametros(auxId,auxNombre,auxHoras,auxSalario);
            ll_add(pArrayListEmployee,empNew);
            result=1;
        }
        else
        {
            result=0;
        }

    return result;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int result=-1;
    int id;
    char auxNombre[100];
    int auxHoras;
    int auxSueldo;

    int index=-1;
    int tam;
    char confirm;

    Employee* auxEmployee=employee_new();

    showEmployees(pArrayListEmployee);

    //printf("Ingrese ID: ");
    //scanf("%d", &id);

    getInt(&id, "Ingrese ID: ", "Error. Reingrese ID: ");

        if(auxEmployee==NULL)
        {
            result=-1;
        }
        else
        {
            if(ll_len(pArrayListEmployee)==0){
                result=-1;
            }
            else
            {
                tam = ll_len(pArrayListEmployee);

                for(int i=0; i<tam; i++)
                {
                    auxEmployee = ((Employee*) ll_get(pArrayListEmployee,i));

                    if(auxEmployee->id == id)
                    {
                        printf("\nEmpleado seleccionado: \n");
                        printf(" ID     Nombre     Horas    Sueldo\n");
                        printf("------------------------------------\n");
                        index=i;
                        showEmployee(auxEmployee);
                        break;
                    }
                }
            }
        }



    if(index!=-1)
    {
        //printf("\nIngrese nombre: ");
        //fflush(stdin);
        //gets(auxNombre);

        getString(auxNombre, "Ingrese Nombre: ", "Error. Reingrese Nombre: ", 1,50);

        printf("Ingrese horas trabajadas: ");
        scanf("%d",&auxHoras);

        //getString(auxHoras, "Ingrese horas trabajadas: ", "Error. Reingrese horas trabajadas: ", 1,50);

        printf("Ingrese salario: ");
        scanf("%d",&auxSueldo);

        //getString(auxSueldo, "Ingrese Salario: ", "Error. Reingrese Salario: ", 1, 50);


        printf("\n");

        // printf("\nConfirma editar el usuario? s/n: ");
        //fflush(stdin);
        //confirm= getchar();
        //confirm=tolower(confirm);

         getChar(&confirm, "Confirma la carga? S/N: ", "Error. Confirma la carga? S/N: ", 'S', 'N');

            if(confirm == 'S')
            {
                strcpy(auxEmployee->nombre,auxNombre);
                auxEmployee->horasTrabajadas = auxHoras;
                auxEmployee->sueldo = auxSueldo;

                ll_remove(pArrayListEmployee,index);
                ll_push(pArrayListEmployee,index,auxEmployee);
                result=1;
            }
            else{
                result=-1;
            }
    }
    else{
        result=2;
    }


    return result;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int result=-1;
    int id;
    int index=-1;

    char confirm;


    Employee* auxEmployee=employee_new();

    if(pArrayListEmployee != NULL){



        showEmployees(pArrayListEmployee);

        getInt(&id, "Ingrese ID: ", "Error. Reingrese ID numerico: ");

        index = buscarPorId(pArrayListEmployee, id);
    }

    if(index!=-1)
    {

    auxEmployee = (Employee*) ll_get(pArrayListEmployee, index);
    showEmployee(auxEmployee);

    getChar(&confirm, "Confirma eliminar el usuario? S/N: ", " Error. Confirma eliminar el usuario? S/N: ", 'S','N');

        if(confirm=='S')
        {
            ll_remove(pArrayListEmployee,index);
            result=1;
        }
        else
        {
            result=0;
        }
    }
    else
    {
        result=2;
    }
    return result;
}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int result=0;

        if(pArrayListEmployee != NULL){
            system("cls");
            showEmployees(pArrayListEmployee);
            result=1;
        }

    return result;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int order;

    if(pArrayListEmployee != NULL){

    switch( orderMenu() ){

    case 1:

        //printf("Ingrese por orden Descendente (0), o Ascendente (1): ");
        //scanf("%d", &order);
        getIntRange(&order, "Ingrese por orden Descendente (0), o Ascendente (1): ", "Error. Reingrese por orden Descendente (0), o Ascendente (1): ", 0,1);

        printf("Espere un momento, esto podria tardar un poco...");

        if(order==1)
        {
            ll_sort(pArrayListEmployee,orderID,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        else
        {
            ll_sort(pArrayListEmployee,orderID,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        break;


    case 2:

        getIntRange(&order, "Ingrese por orden Descendente (0), o Ascendente (1): ", "Error. Reingrese por orden Descendente (0), o Ascendente (1): ", 0,1);

        printf("Espere un momento, esto podria tardar un poco...");

        if(order==1)
        {
            ll_sort(pArrayListEmployee,orderName,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        else
        {
            ll_sort(pArrayListEmployee,orderName,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        break;

    case 3:

        getIntRange(&order, "Ingrese por orden Descendente (0), o Ascendente (1): ", "Error. Reingrese por orden Descendente (0), o Ascendente (1): ", 0,1);

        printf("Espere un momento, esto podria tardar un poco...");

        if(order==1)
        {
            ll_sort(pArrayListEmployee,orderHours,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        else
        {
            ll_sort(pArrayListEmployee,orderHours,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        break;

    case 4:

        getIntRange(&order, "Ingrese por orden Descendente (0), o Ascendente (1): ", "Error. Reingrese por orden Descendente (0), o Ascendente (1): ", 0,1);

        printf("Espere un momento, esto podria tardar un poco...");
        if(order==1)
        {
            ll_sort(pArrayListEmployee,orderSalary,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;

        }
        else
        {
            ll_sort(pArrayListEmployee,orderSalary,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        break;
    }
    }

    return order;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = NULL;
    Employee* auxEmp = NULL;
    int size=ll_len(pArrayListEmployee);
    int result=-1;

    int id;
    int hours;
    int salary;
    char name[130];

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"w");

            if(pFile!=NULL)
            {
                 for(int i=0;i<size;i++)
                {
                    auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(auxEmp,&id);
                    employee_getNombre(auxEmp,name);
                    employee_getHorasTrabajadas(auxEmp,&hours);
                    employee_getSueldo(auxEmp,&salary);
                    fprintf(pFile,"%d,%s,%d,%d\n",id,name,hours,salary);
                }
                fclose(pFile);
                result=1;
            }
            else{
                result=0;
            }
        }
    }

    return result;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = NULL;
    Employee* auxEmp = NULL;
    int size = ll_len(pArrayListEmployee);
    int result = -1;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"wb");

            if(pFile!=NULL)
            {
                for(int i=0; i<size;i++)
                {///  aca te quedaste
                    auxEmp=ll_get(pArrayListEmployee,i);
                    if(auxEmp!=NULL)
                    {
                        fwrite(auxEmp,sizeof(Employee),1,pFile);
                    }
                }
            result=1;
            fclose(pFile);
            }
            else{
            result=0;
            }
        }
    }
    else{
        result=0;
    }

    return result;
}



