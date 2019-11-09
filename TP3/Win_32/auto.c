#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "auto.h"



int setIdAuto(eAuto* unAuto, int id)
{
    int todoOk=0;
    if( unAuto != NULL && id >= 1000 && id <= 2000)
    {
        unAuto->id = id;
        todoOk = 1;
    }
    return todoOk;
}


int getIdAuto(eAuto* unAuto)
{
    int id = -1;
    if( unAuto != NULL)
    {
        id = unAuto->id;
    }
    return id;
}

int setMarcaAuto(eAuto* unAuto, char* marca)
{
    int todoOk=0;
    if( unAuto != NULL && marca != NULL && strlen(marca) >= 3)
    {
        strcpy(unAuto->marca, marca);
        todoOk = 1;
    }
    return todoOk;
}

int getMarcaAuto(eAuto* unAuto, char* marca)
{
    int todoOk=0;
    if( unAuto != NULL && marca != NULL)
    {
        strcpy( marca,unAuto->marca);
        todoOk = 1;
    }
    return todoOk;
}

int setModeloAuto(eAuto* unAuto, int modelo)
{
    int todoOk=0;
    if( unAuto != NULL && modelo >= 1980 && modelo <= 2020)
    {
        unAuto->modelo = modelo;
        todoOk = 1;
    }
    return todoOk;
}


int getModeloAuto(eAuto* unAuto)
{
    int modelo = -1;
    if( unAuto != NULL)
    {
        modelo = unAuto->modelo;
    }
    return modelo;
}

int setPrecioAuto(eAuto* unAuto, float precio)
{
    int todoOk=0;
    if( unAuto != NULL && precio >= 500 && precio <= 1500)
    {
        unAuto->precio = precio;
        todoOk = 1;
    }
    return todoOk;
}


float getPrecioAuto(eAuto* unAuto)
{
    float precio = -1;
    if( unAuto != NULL)
    {
        precio = unAuto->precio;
    }
    return precio;
}



int mostrarAuto(eAuto* unAuto)
{
    int todoOk = 0;

    if( unAuto != NULL )
    {
        printf(" %d  %20s %d %6.2f\n", unAuto->id, unAuto->marca, unAuto->modelo, unAuto->precio);
        todoOk = 1;
    }
    return todoOk;
}
int mostrarAutos(eAuto** autos, int tam)
{

    int todoOk = 0;

    if( autos != NULL && tam > 0 )
    {
        for(int i=0; i < tam; i++)
        {
            mostrarAuto(*(autos + i) );
        }
        todoOk = 1;
    }
    return todoOk;
}

eAuto* newAuto()
{
    eAuto* nuevo = (eAuto*) malloc( sizeof(eAuto));
    if( nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->marca, " ");
        nuevo->modelo = 0;
        nuevo->precio = 0;
    }
    return nuevo;
}

eAuto* newAutoParam(int id, char* marca, int modelo, float precio)
{
    eAuto* nuevo = newAuto();
    if( nuevo != NULL)
    {
        if(
            setIdAuto(nuevo, id)
            && setModeloAuto(nuevo, modelo)
            && setMarcaAuto(nuevo, marca)
            && setPrecioAuto(nuevo, precio) == 0)
        {
            free(nuevo);
            nuevo = NULL;
        }
    }
    return nuevo;
}

int guardarAutosBinario( eAuto** lista, int tam, char* path)
{
    int todoOk = 0;
    FILE* f = NULL;

    if( lista != NULL && tam > 0 && path != NULL)
    {
        f = fopen(path, "wb");
        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            return todoOk;
        }

        for(int i=0; i < tam; i++)
        {
            fwrite( *(lista + i),  sizeof(eAuto), 1, f);
        }

        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}

int guardarAutosCSV( eAuto** lista, int tam, char* path)
{
    int todoOk = 0;
    FILE* f = NULL;

    if( lista != NULL && tam > 0 && path != NULL)
    {
        f = fopen(path, "w");
        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            return todoOk;
        }
        fprintf(f, "id,marca,modelo,precio\n");
        for(int i=0; i < tam; i++)
        {
            fprintf(f, "%d,%s,%d,%.2f\n", (*(lista+i))->id, (*(lista+i))->marca, (*(lista+i))->modelo, (*(lista+i))->precio);
        }
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}
