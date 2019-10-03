
#include "function.h"

/**\brief Menu de Opciones
 *
 * \return devuelve un entero ingresado por el usuario.
 *
 */

int menu(){
    int option;
    char aux[100];
    int num;

    system("cls");
    printf("************* TRABAJO PRACTICO 2 *************\n");
    printf("*************        ABM         *************\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion\n");
    printf("4- Mostrar Empleados\n");
    printf("5- Buscar Empleado\n");
    printf("6- Informar\n");
    printf("7- Salir\n\n");
    printf("\nIngrese Opcion: ");
    fflush(stdin);
    scanf("\n%s", aux);

    num = validarNumero(aux);
    option = atoi(aux);

    while( (!num) ){
        printf("\nError. ingrese Opcion: ");
        fflush(stdin);
        scanf("\n%s", aux);
        num = validarNumero(aux);
        option = atoi(aux);
    }
    return option;
}

/**\brief Menu de Informes
 *
 * \return devuelve un entero ingresado por el usuario.
 *
 */
int menuInfo(){
    int option;
    char aux[100];
    int num;

    system("cls");
    printf("\n************* INFORMES *************\n\n");
    printf("1- Ordenar por Apellido y Sector: \n");
    printf("2- Mostrar cantidad de Empleados y promedio de sueldos: \n");
    printf("3- Mostrar empleados que superan el promedio de sueldo\n\n");
     printf("\nIngrese Opcion: ");
    fflush(stdin);
    scanf("\n%s", aux);

    num = validarNumero(aux);
    option = atoi(aux);


     while( (!num) ){
        printf("\nError. ingrese Opcion: ");
        fflush(stdin);
        scanf("\n%s", aux);
        num = validarNumero(aux);
        option = atoi(aux);
    }

    return option;
}

/**\brief Menu que permite seleccionar el tipo de orden
 *
 * \return devuelve un entero ingresado por el usuario.
 *
 */
int menuAlphabet(){
    int option;
    char aux[100];
    int num;

    system("cls");
    printf("************* MOSTRAR EMPLEADOS POR APELLIDO Y SECTOR *************\n\n");
    printf("1- ASCENDENTE\n");
    printf("2- DESCENDENTE\n\n");

    printf("\nIngrese Opcion: ");
    fflush(stdin);
    scanf("\n%s", aux);

    num = validarNumero(aux);
    option = atoi(aux);

    while( (!num) ){
        printf("\nError. ingrese Opcion: ");
        fflush(stdin);
        scanf("\n%s", aux);
        num = validarNumero(aux);
        option = atoi(aux);
    }

    return option;
}

/** \brief Hardcodeo de vector de estructuras eEmployee
 *
 * \param vector eEmploye
 * \param tamaño del vector
 * \param cantidad que desea hardcodear
 * \return retorna un entero con cantidad de empleados
 *
 */

int generateEmployee(eEmployee list[], int len, int quantity){
    int cont = 0;
    eEmployee auxEmp[]={
        {1, "Hernesto", "Guevara",  25000, 1, 1},
        {2,    "Pablo",  "Cepeda",  30000, 2, 1},
        {3,     "Luis",   "Lopez",  25000, 3, 1},
        {4,      "Ana",    "Soto",  37000, 4, 1},
        {5,    "Sofia", "Guevara",  20000, 5, 1},
        {6,    "Lucas",   "Elano",  40000, 1, 1},
        {7,    "Carla", "Pascual",  34000, 2, 1},
        {8,   "Andres", "Montiel",  37000, 3, 1},
        {9,   "Romina",   "Perez",  21000, 4, 1},
        {10, "Claudio",   "Gallo",  33000, 5, 1},
        {11,  "Karina",   "Perez",  45000, 1, 1},
        {12,    "Ayde",  "Chacon",  23000, 2, 1},
        {13, "Gustavo",   "Perez",  28000, 3, 1},
        {14, "Ezequiel",   "Posta", 35000, 4, 0},
        {15, "Liliana",  "Guerra",  34000, 5, 1}
    };

     if( quantity <= 10000 && len >= quantity)
    {
        for(int i=0; i<quantity; i++){
        list[i]=auxEmp[i];
        cont++;
        }
    }
    return cont;
}

/** \brief Inicializa todos los elementos del vector eEmployee en 0
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 * \return
 *
 */

void initEmployees(eEmployee list[], int len){
    for(int i=0; i<len; i++){
        list[i].isEmpty = 0;
    }
}


/** \brief Encuentra un elemento en estado 0 (libre) en el vector de eEmployee
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 * \return devuelve un entero con el indice del elemento.
 *
 */
int findFree(eEmployee list[], int len){
    int index = -1;

    for(int i=0; i<len; i++){
        if(list[i].isEmpty == 0){
            index = i;
            break;
        }
    }
    return index;
}

/** \brief Encuentra un elemento del vector
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 * \param un entero por el cual se compara al elemento del vector
 * \return devuelve un entero con el indice del elemento
 *
 */
int findEmployee(eEmployee list[], int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].id == file)
        {
            index = i;
            break;
        }
    }

    return index;
}

/** \brief Alta de un nuevo empleado
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 * \param entero que se pasa por parametro para el legajo auto incremental
 * \return devuelve un entero 0 si no se dio de alta, 1 si el alta es exitosa
 *
 */
int highEmployee(eEmployee list[], int len, int legajo)
{
    int res = 0;
    int index;


    index = findFree(list, len);

    if( index == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
            list[index].id = legajo;

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(list[index].lastName);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(list[index].name);

            printf("Ingrese sueldo: ");
            scanf("%f", &list[index].salary );

            printf("Ingrese sector del 1 al 5: ");
            scanf("%d", &list[index].sector);
              while(list[index].sector<1|| list[index].sector>5)
            {
            printf("Sector incorrecto, reingrese valor entre 1 y 5: ");
            scanf("%d",&list[index].sector);
            }

            list[index].isEmpty = 1;

            res = 1;

            printf("Alta empleado exitosa!!!\n\n");
    }
    return res;
}


/** \brief Baja logica de un empleado
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 *
 */
void removeEmployee(eEmployee list[], int len)
{
    int file;
    char confirm;
    int is;

    printf("Ingrese legajo: ");
    scanf("%d", &file);

    is = findEmployee(list, len, file);

    if( is == -1)
    {
        printf("\nEl legajo %d no esta registrado en el sistema\n", file);
    }
    else
    {
        printEmployee(list[is]);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirm = tolower(getche());

        if(confirm == 's')
        {
            list[is].isEmpty = 0;
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }
    }
}



/** \brief Busca un empleado por su legajo.
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 *
 */
void findEmployeeById(eEmployee list[], int len){
    int file;
    int is=0;

    printf("Ingrese numero de legajo que desea encontrar: ");
    scanf("%d", &file);

    for(int i=0; i<len; i++){
        if(list[i].id == file && list[i].isEmpty == 1){
            printf(" Legajo      Apellido    Nombre       Sueldo        Sector\n");
            printf("--------    ----------  --------     --------      --------\n");
            printEmployee(list[i]);
            is = 1;
            break;
        }
    }
    if(is == 0){
        printf("\nNo hay empleado registrado con ese numero de legajo.\n\n");
    }
}


/** \brief Modificar el sueldo de un empleado
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 *
 */
void modifyEmployee(eEmployee list[], int len)
{
    int file;
    char confirm;
    float nowSalary;
    int is;

    char aux[100];
    int num;

    printf("Ingrese legajo: ");
    fflush(stdin);
    scanf("\n%s", aux);

    num = validarNumero(aux);
    file = atoi(aux);

     while( (!num) ){
        printf("\nError. ingrese Legajo: ");
        fflush(stdin);
        scanf("\n%s", aux);
        num = validarNumero(aux);
        file = atoi(aux);
    }

    is = findEmployee(list, len, file);

    if( is == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", file);
    }
    else
    {
        findEmployee(list, len, file);

        printf("\nQuiere cambiar el sueldo? s/n:  ");
        fflush(stdin);
        confirm = tolower(getche());

        if(confirm == 's')
        {
            printf("\n\nIngrese nuevo sueldo: ");
            scanf("%f", &nowSalary);
            //valido sueldo
            list[is].salary = nowSalary;
        }
        else
        {
            printf("\n\nNo se ha modificado el sueldo\n\n");
        }
    }
}


/** \brief Ordena los elementos de el vector de manera ascendente
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 *
 */
void sortEmployeesUpward(eEmployee list[], int len)
{
        eEmployee auxChar;
        system("cls");
        printf(" Legajo      Apellido    Nombre       Sueldo        Sector\n");
        printf("--------    ----------  --------     --------      --------\n");

            for(int i=0; i<len-1; i++){
                for(int j=i+1; j<len; j++){
                    if(strcmp(list[i].lastName,list[j].lastName)>0 && list[i].isEmpty == 1){
                        auxChar = list[i];
                        list[i] = list[j];
                        list[j] = auxChar;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector > list[j].sector && list[i].isEmpty == 1){
                               auxChar = list[i];
                               list[i] = list[j];
                               list[j] = auxChar;
                            }
                }
            }
            printEmployees(list, len);
            system("pause");
}

/** \brief Ordena los elementos de el vector de manera descendente
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 *
 */
void sortEmployeesDecendent(eEmployee list[], int len)
{
        eEmployee auxChar;
        system("cls");

        printf(" Legajo      Apellido    Nombre       Sueldo        Sector\n");
        printf("--------    ----------  --------     --------      --------\n");

            for(int i=0; i<len-1; i++){
                for(int j=i+1; j<len; j++){
                    if(strcmp(list[i].lastName,list[j].lastName)<0 && list[i].isEmpty == 1){
                        auxChar = list[i];
                        list[i] = list[j];
                        list[j] = auxChar;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector < list[j].sector && list[i].isEmpty == 1){
                               auxChar = list[i];
                               list[i] = list[j];
                               list[j] = auxChar;
                            }
                }
            }
            printEmployees(list, len);
            system("pause");
}

/** \brief Muestra un empleado
 *
 * \param una estructura eEmploye
 *
 */
void printEmployee(eEmployee list){

    if(list.isEmpty == 1){
         printf("%5d       %7s     %8s     %7.2f         %d\n", list.id, list.lastName, list.name, list.salary, list.sector);
    }
}

/** \brief Muestra el total de empleados
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 * \return devuelve 0
 *
 */
int printEmployees(eEmployee list[], int len){

    int contador = 0;

    system("cls");


    printf(" Legajo      Apellido    Nombre       Sueldo        Sector\n");
    printf("--------    ----------  --------     --------      --------\n");

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            printEmployee(list[i]);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNO HAY EMPLEADOS QUE MOSTRAR.\n\n");
    }
    return 0;
}


/** \brief Muestra la cantidad de empleados y el promedio de sueldos.
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 *
 */
void totalEmployees(eEmployee list[], int len)
{
    int counterEmployee = 0;
    int counterSalary = 0;
    float average;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1){
            counterEmployee = counterEmployee + 1;
        counterSalary = counterSalary + list[i].salary;
        }
    }

    average = (float) counterSalary / counterEmployee;
        printf("\nCantidad: %d\n\n", counterEmployee);
        printf("Promedio de sueldos: %.2f\n\n", average);


}


/** \brief Muestra los empleados que exeden el salario promedio
 *
 * \param vector de estructura eEmployee
 * \param tamaño del vector
 *
 */
void employeeExceedsAverage(eEmployee list[], int leng)
{
    int counterEmployee = 0;
    int counterSalary = 0;
    float average;

    printf("****     EMPLEADOS QUE SUPERAN EL SUELDO PROMEDIO    *****\n\n");
    printf(" Legajo      Apellido    Nombre       Sueldo        Sector\n");
    printf("--------    ----------  --------     --------      --------\n");

    for(int i=0; i < leng; i++)
    {
        if(list[i].isEmpty == 1){
            counterEmployee = counterEmployee + 1;
        counterSalary = counterSalary + list[i].salary;
        }
    }

    average = (float) counterSalary / counterEmployee;

    for(int i=0; i<leng; i++)
    {
        if(list[i].salary > average){
            printEmployee(list[i]);
        }
    }
}

/** \brief Valida que el usuario ingrese un numero
 *
 * \param caracter resivido por parametro
 * \return retorna 0 si no es un numero o 1 si es un numero.
 *
 */

int validarNumero(char num[]){
    int res = 1;
    for(int i=0; i<strlen(num); i++){
        if( !(isdigit(num[i])) ){
            res = 0;
        }
    }
    return res;
}
