// descifrador.c
// 
// Lee un fichero cifrado con encriptador y lo descifra con una clave 
/////////////////////////////////////////////////

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "cambia_eco.h"

#define MASK 0x08

int main (int argc, char* argv[])
{
    int c, i, k;
    char clave;
    FILE *fdP;
    FILE *fp1;
    struct stat atrib;


   if (argc != 2) {
        fprintf(stderr, "Uso: %s fichero-cifrado fichero-descifrado\n", argv[0]);
        exit(1);
    }

    while (!cambia_eco()) ;  // Por si estuviera en no eco
        scanf("%d", &i);
    

        //Comprueba archivo salidacifrada
   if ((fdP = fopen(argv[1], "r")) == NULL) {
       fprintf(stderr, "No se puede leer de %s\n", argv[1]);
       exit(1);
    }
   
        //Comprueba archivo descifrado
   if ((fp1 = fopen(argv[2], "w")) == NULL) {
       fprintf(stderr, "No se puede escribir en %s\n", argv[2]);
       exit(1);
    }

    clave = ((char)i) & MASK;  // Pone a cero los 4 bits mas significativos
    while ((c=getc(fdP)) != EOF) {
    putchar(c);
        if (c=='\n') putc(c, fp1);
        else putc(c^clave, fp1);
    }
}