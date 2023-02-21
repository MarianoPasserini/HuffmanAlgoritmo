#include "biblioteca/strings.hpp"
#include "biblioteca/tokens.hpp"
#include "biblioteca/coll.hpp"
#include "biblioteca/array.hpp"
#include "biblioteca/arrays.hpp"
#include "biblioteca/string.hpp"
#include "biblioteca/BitWriter.hpp"
#include <iostream>

//Algoritmo de Huffman. Ejercicio integrador 
//Path: main.cpp

//El primer paso es contar la frecuencia de cada caracter en el archivo de entrada.
//Para ello se utiliza el TAD Array que permite almacenar la frecuencia de cada caracter.
//La función countFrecuency recibe como parámetro el nombre del archivo de entrada y retorna un array con la frecuencia de cada caracter.

Array<int> countFrecuency(string fileName){
    FILE* f = fopen(fileName.c_str(),"r");
    Array<int> frecuency(256);
    int c;
    while ((c = fgetc(f)) != EOF){
        frecuency[c]++;
    }
    fclose(f);
    return frecuency;
}

//El siguiente paso es crear una lista enlazada de nodos que ordena ascendentemente por frecuencia, colocando primero los bytes con menos frecuencia.
//Para ello se utiliza el TAD Coll que permite agregar y eliminar nodos de la lista.
//La función createList recibe como parámetro el array con la frecuencia de cada caracter y retorna una lista enlazada de nodos.

struct Node{
    int frecuency;
    int byte;
    Node* left;
    Node* right;
};

Coll<Node> createList(Array<int> frecuency){
    Coll<Node> list;
    for (int i = 0; i < frecuency.size(); i++){
        if (frecuency[i] > 0){
            Node* node = new Node;
            node->frecuency = frecuency[i];
            node->byte = i;
            node->left = NULL;
            node->right = NULL;
            list.add(node);
        }
    }
    return list;
}

//El siguiente paso es crear el árbol de Huffman.
//Para ello se utiliza el TAD Coll que permite agregar y eliminar nodos de la lista.
//La función createTree recibe como parámetro la lista enlazada de nodos y retorna el nodo raíz del árbol de Huffman.

Node* createTree(Coll<Node> list){
    while (list.size() > 1){
        Node* node = new Node;
        node->frecuency = list[0]->frecuency + list[1]->frecuency;
        node->byte = -1;
        node->left = list[0];
        node->right = list[1];
        list.remove(0);
        list.remove(0);
        int i = 0;
        while (i < list.size() && list[i]->frecuency < node->frecuency){
            i++;
        }
        list.add(i,node);
    }
    return list[0];
}

//El siguiente paso es crear el código de Huffman para cada byte.
//Para ello se utiliza el TAD Array que permite almacenar el código de cada byte.
//La función createCode recibe como parámetro el nodo raíz del árbol de Huffman y retorna un array con el código de cada byte.

Array<string> createCode(Node* root){
    Array<string> code(256);
    string s = "";
    createCode(root,s,code);
    return code;
}

void createCode(Node* node,string s,Array<string>& code){
    if (node->byte != -1){
        code[node->byte] = s;
    }else{
        createCode(node->left,s + "0",code);
        createCode(node->right,s + "1",code);
    }
}

//El siguiente paso es reconocer el codigo con el que debemos recodificar cada byte del archivo original.
//Para ello se utiliza el TAD Array que permite almacenar el codigo de cada byte.
//La función createCode recibe como parámetro el nombre del archivo de entrada y retorna un array con el codigo de cada byte.

Array<string> readCode(string fileName){
    FILE* f = fopen(fileName.c_str(),"r");
    Array<string> code(256);
    int c;
    while ((c = fgetc(f)) != EOF){
        string s = "";
        while ((c = fgetc(f)) != EOF && c != '\n'){
            s += c;
        }
        code[c] = s;
    }
    fclose(f);
    return code;
}

//El siguiente paso es recodificar el archivo original.
