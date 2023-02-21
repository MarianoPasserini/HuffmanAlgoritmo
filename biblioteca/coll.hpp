#include "arrays.hpp"
#include "string.hpp"
#include "tokens.hpp"
template<typename T>
struct Coll
{
    string s;
    char sep;
};

//Crea una colección vacía, preparada para contener elementos de tipo T. utilizando el carácter sep como separador de la cadena tokenizada sobre la que seimplementa la colección.
template<typename T>
Coll<T> coll(char sep){
    Coll<T> c;
    c.s = "";
    c.sep = sep;
    return c;
}

//Descripción: Crea una colección vacía, preparada para contener elementos tipo T; definiendo un separador por defecto para usar en la cadena tokenizada sobre la cual se implementa la colección.
template<typename T>
Coll<T> coll(){
    Coll<T> c;
    c.s = "";
    c.sep = '|';
    return c;
}

//Descripción: Agrega el elemento t a la colección c.
template<typename T>
void collAdd(Coll<T>& c,T t){
    string s = stringToString(t);
    addToken(c.s,c.sep,s);
}

//Descripción: Devuelve la cantidad de elementos que contiene la colección c.
template<typename T>
int collSize(Coll<T> c){
    return tokenCount(c.s,c.sep);
}
//Descripción: Remueve de la colección c todos sus elementos, dejándola vacía.
template<typename T>
void collClear(Coll<T>& c){
    c.s = "";
}

//Descripción: Remueve de la colección c el elemento ubicado en la posición p.
template<typename T>
void collRemoveAt(Coll<T>& c,int p){
    removeTokenAt(c.s,c.sep,p);
}

//Descripción: Reemplaza por t al elemento que se ubica en la posición p.
template<typename T>
void collSetAt(Coll<T>& c,T t,int p){
    string s = to_string(t);
    setTokenAt(c.s,c.sep,s,p);
}

//Descripción: Retorna el elemento que se ubica en la posición p de la colección c.
template<typename T>
T collGetAt(Coll<T> c,int p){
    string s = getTokenAt(c.s,c.sep,p);
    return s;
}
//Descripción: Determina si la colección c contiene al elemento k.
template<typename T, typename K>
bool collFind(Coll<T> c,K k){
    for(int i=0;i<collSize(c);i++){
        if(collGetAt(c,i) == k){
            return true;
        }
    }
    return false;
}

//Descripción: Ordena los elementos de la colección c según el criterio de precedencia
// que establece cmpTT.
// Parámetros:
// • Coll<T>& c - La colección.
// • int cmpTT(T,T) - Función que compara dos elementos tipo T (t1,t2) y
// retorna: negativo si t1<t2; cero si t1==t2; positivo si t1>t2.
// • T tFromString(string) - Función que convierte de string a T.
// • string tToString(T) - Función que convierte de T a string.

template<typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T)){
    int len = collSize(c);
    T arr[len];
    for(int i=0;i<len;i++){
        arr[i] = tFromString(collGetAt(c,i));
    }
    sort(arr,len,cmpTT);
    collClear(c);
    for(int i=0;i<len;i++){
        collAdd(c,arr[i]);
    }
}

//Prototipo: bool collHasNext(Coll<T> c);
//Descripción: Retorna true o false según queden, en la colección c, más elementos para continuar iterando.
//Parámetro: Coll<T> c – La colección.
// Retorna: bool - true o false según queden o no elementos para continuar iterando sobre la colección c.
template<typename T>
bool collHasNext(Coll<T> c){
    return collSize(c) > 0;
}

// Prototipo: T collNext(Coll<T>& c,T tFromString(string));
// Descripción: Retorna el siguiente elemento de la colección c.
// Parámetros:
// Coll<T>& c - La colección.
// T tFromString(string) - Función que convierte de string a T.
// Retorna: T - El siguiente elemento de la colección c.
template<typename T>
T collNext(Coll<T>& c,T tFromString(string)){
    T t = tFromString(collGetAt(c,0));
    collRemoveAt(c,0);
    return t;
}