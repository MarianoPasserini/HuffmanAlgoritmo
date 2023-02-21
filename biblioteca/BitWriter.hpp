#include "string.hpp"
#include "tokens.hpp"
#include "coll.hpp"
#include "array.hpp"

//Desarrollar el TAD BitWriter cuya función bitWriterWrite permite escribir en un archivo bit a bit.
//Estructura del tad:
struct BitWriter
{
    /* data */
};



// Prototipo: BitWriter bitWriter(FILE* f);
// Descripción: Crea e inicializa una variable tipo BitWriter.
// Parámetros: FILE* f – Archivo donde se grabarán los bit.
// Retorna: BitWriter.
BitWriter bitWriter(FILE* f){
    BitWriter bw;
    bw.f = f;
    bw.bitCount = 0;
    bw.byte = 0;
    return bw;
}

// Prototipo: void bitWriterWrite(BitWriter& bw,int bit);
// Descripción: Graba un bit en el archivo.
// Parámetros:
// • BitWriter br – Variable del TAD.
// • int bit – 1 o 0 que se grabará en el archivo.
// Retorna: void.

void bitWriterWrite(BitWriter& bw,int bit){
    if (bw.bitCount == 8){
        fwrite(&bw.byte,1,1,bw.f);
        bw.bitCount = 0;
        bw.byte = 0;
    }
    bw.byte = bw.byte << 1;
    bw.byte = bw.byte | bit;
    bw.bitCount++;
}

// Prototipo: void bitWriterClose(BitWriter& bw);