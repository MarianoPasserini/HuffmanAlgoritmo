#include "coll.hpp"
#include "strings.hpp"
#include "tokens.hpp"
using namespace std;

template <typename T>
int add(T arr[],int& len,T e){
    arr[len] = e;
    len++;
    return len-1;
}

template <typename T>
void insert(T arr[],int& len,T e,int p){
    //Descripción: Inserta el elemento e en la posición p del array arr.
    for(int i=len;i>p;i--){
        arr[i] = arr[i-1];
    }
    arr[p] = e;
    len++;
}


template<typename T>
 bool cmpTT(T a,T b){
    //Descripción: Determina si el elemento t1 precede al elemento t2.
    //Retorna: bool – true si t1 precede a t2, false en caso contrario.
    return a < b;
 }

//descripcion: Remueve el elemento ubicado en la posición p del array arr. Desplaza ubicados a partir de p y decrementa la longitud len.
template <typename T>
void remove(T arr[],int& len,int p){
    for(int i=p;i<len-1;i++){
        arr[i] = arr[i+1];
    }
    len--;
}

// Prototipo: int find(T arr[],int len,K k,int cmpTK(T,K));
// Descripción: Retorna la posición de la primera ocurrencia de k dentro de arr o un valor
// negativo si arr no contiene a k.
// Parámetros:
// • T arr[] – Array donde buscaremos un elemento.
// • int len – Longitud actual del array.
// • K k– Valor a buscar dentro de arr.
// • int cmpTK(T,K) – Función de comparación.
// Retorna: int – Posición de la primera ocurrencia de k dentro de arr o un valor
// negativo si arr no contiene a k.


template <typename T,typename K>
int find(T arr[],int len,K k,int cmpTK(T,K)){
    for(int i=0;i<len;i++){
        if(cmpTK(arr[i],k) == 0){
            return i;
        }
    }
    return -1;
}

// Prototipo: int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T));
// Descripción: Inserta e dentro de arr según el criterio de precedencia que establece
// cmpTT, y retorna la posición donde dicho elemento quedó insertado. El array arr debe
// estar ordenado o vacío.
// Parámetros:
// • T arr[] – Array donde insertaremos un elemento.
// • int& len – Longitud actual del array.
// • T e – Valor a insertar dentro de arr.
// • int cmpTT(T,T) – Función de comparación.
// Retorna: int – Posición donde quedó insertado e dentro de arr.

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T)){
    int i = 0;
    while(i < len && cmpTT(arr[i],e) < 0){
        i++;
    }
    insert(arr,len,e,i);
    return i;
}

template<typename T>
struct Array
{
    T* arr; // Array de elementos
    int len; // Longitud actual del array
    int cap; // Capacidad del array
};

// Prototipo: Array<T> array();
// Descripción: Inicializa un array cuya capacidad inicial será establecida por defecto. La
// longitud del array será 0, y se incrementará a medida que se agreguen o inserten nuevos elementos.
// Retorna: Array<T> – El array.

template <typename T>
Array<T> array(){
    Array<T> a;
    a.len = 0;
    a.cap = 100;
    a.arr = new T[a.cap];
    return a;
}

// Prototipo: int arrayAdd(Array<T>& a,T t);
// Descripción: Agrega t al final de a incrementando, de ser necesario, su capacidad.
// Retorna la posición del arr donde quedó ubicado el elemento t.
// Parámetros:
// • Array<T>& a – El array.
// • T t – Elemento que se agregará.
// Retorna: int – Posición de a donde se agregó el elemento t.

template <typename T>
int arrayAdd(Array<T>& a,T t){
    if(a.len == a.cap){
        T* aux = new T[a.cap*2];
        for(int i=0;i<a.len;i++){
            aux[i] = a.arr[i];
        }
        delete[] a.arr;
        a.arr = aux;
        a.cap = a.cap*2;
    }
    a.arr[a.len] = t;
    a.len++;
    return a.len-1;
}

// Prototipo: T* arrayGet(Array<T> a,int p);
// Descripción: Retorna la dirección del elemento de a ubicado en la posición p.
// Parámetros:
// • Array<T> a – El array.
// • int p – Posición del elemento de a al cual queremos acceder.
// Retorna: T* – Dirección del elemento ubicado en la posición p del array a.

template <typename T>
T* arrayGet(Array<T> a,int p){
    return &a.arr[p];
}

// Prototipo: void arraySet(Array<T>& a,int p,T t);
// Descripción: Asigna el elemento t en la posición p del array a.
// Parámetros:
// • Array<T>& a – El array.
// • int p – Posición del elemento de a al cual queremos acceder.
// • T t – Elemento que vamos a asignar en la posición p de a.

template <typename T>
void arraySet(Array<T>& a,int p,T t){
    a.arr[p] = t;
}