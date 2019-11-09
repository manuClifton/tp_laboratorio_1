#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int id;
    char marca[32];
    int modelo;
    float precio;
} eAuto;


int mostrarAuto(eAuto* unAuto);
int mostrarAutos(eAuto** autos, int tam);
// Getters y Setters
int setIdAuto(eAuto* unAuto, int id);
int setModeloAuto(eAuto* unAuto, int modelo);
int setPrecioAuto(eAuto* unAuto, float precio);
int setMarcaAuto(eAuto* unAuto, char* marca);
int getIdAuto(eAuto* unAuto);
int getModeloAuto(eAuto* unAuto);
float getPrecioAuto(eAuto* unAuto);
int getMarcaAuto(eAuto* unAuto, char* marca);
// Constructores
eAuto* newAuto();
eAuto* newAutoParam(int id, char* marca, int modelo, float precio);
// Comparison


// Escritura/Lectura Archivos
int guardarAutosBinario( eAuto** lista, int tam, char* path);
int guardarAutosCSV( eAuto** lista, int tam, char* path);
#endif // AUTO_H_INCLUDED
