#include "string.hpp"
#include "tokens.hpp"
#include "coll.hpp"
#include "array.hpp"

// Prototipo: void write(FILE* f,T t);
// Descripción: Escribe el valor t en la posición actual del archivo f.
// Parámetros:
// • FILE* f – Archivo donde vamos a escribir.
// • T – valor (registro) que vamos a escribir en f.
// Retorno: void

template<typename T>
void write(FILE* f,T t){
    fwrite(&t,sizeof(T),1,f);
}

// Prototipo: T read(FILE* f);
// Descripción: Lee del archivo f un registro tipo T y retorna el valor leído.
// Parámetro: FILE* f – Archivo desde el cual vamos a leer un registro.
// Retorna: T – Registro leído.

template<typename T>
T read(FILE* f){
    T t;
    fread(&t,sizeof(T),1,f);
    return t;
}

// Prototipo: void seek(FILE* f,int n);
// Descripción: Mueve el indicador de posición del archivo f al inicio del registro n.
// Parámetros:
// • FILE* f – Archivo cuyo indicador de posición vamos a modificar.
// • int n – Número de registro al que haremos apuntar el indicador de posición.
// Retorno: void

void seek(FILE* f,int n){
    fseek(f,n*sizeof(int),SEEK_SET);
}

// Prototipo: int fileSize(FILE* f);
// Descripción: Retorna la cantidad de registros tipo T que contiene el archivo.
// Parámetro: FILE* f – Archivo.
// Retorna: int – Cantidad de registros tipo T que contiene el archivo f.

template<typename T>
int fileSize(FILE* f){
    fseek(f,0,SEEK_END);
    int size = ftell(f)/sizeof(T);
    fseek(f,0,SEEK_SET);
    return size;
}

// Prototipo: int filePos(FILE* f);
// Descripción: Retorna el número de registro que está siendo apuntado por el indicador
// de posición del archivo f.
// Parámetro: FILE* f – Archivo.
// Retorna: int – Número de registro apuntado por el indicador de posición.

template<typename T>
int filePos(FILE* f){
    return ftell(f)/sizeof(T);
}
