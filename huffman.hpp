#include "string.hpp"
#include "tokens.hpp"
#include "coll.hpp"
#include "array.hpp"
#include "BitWriter.hpp"
#include "files.hpp"
#include "map.hpp"

// El ejercicio que proponemos es un compresor/descompresor de archivos.
// El programa debe recibir en linea de comandos el nombre de un archivo a comprimir y guardara la compresion en un archivo con el mismo nombre pero con extension .huf

//TAD HUFFMAN que permite recorrer el arbol de Huffman.

struct Huffman
{
    /* data */
};

// a) huffmanTree: funcion de inicializacion
// nos ayudara a recorrer el arbol de Huffman hoja por hoja e indicar el codigo de cada hoja.

Huffman huffmanTree(){
    Huffman h;
    return h;
}

// b) huffmanTreeHasNext: funcion que nos indica si quedan hojas por recorrer.

bool huffmanTreeHasNext(Huffman h){
    return false;
}

// c) huffmanTreeNext: funcion que nos devuelve el codigo de la hoja actual y nos posiciona en la siguiente hoja.

string huffmanTreeNext(Huffman h){
    return "";
}

// d) huffmanCreateDemoTree: funcion que nos permite crear un arbol de Huffman de prueba.

Huffman huffmanCreateDemoTree(){
    Huffman h;
    return h;
}

// e) huffmanTreeDemo: funcion que nos permite recorrer el arbol de Huffman de prueba.

void huffmanTreeDemo(){
    Huffman h = huffmanCreateDemoTree();
    while (huffmanTreeHasNext(h)){
        string code = huffmanTreeNext(h);
        cout << code << endl;
    }
}
