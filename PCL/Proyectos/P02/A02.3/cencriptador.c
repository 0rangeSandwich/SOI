/* cencriptador.c
	Cifra un fichero de texto con una clave de 4 bits y lo escribe por la salida estandar
	Se utilizan funciones de biblioteca
*/

//stdout = 1
//stderr = 2


#include <stdio.h>
#include <stdlib.h>

#define CLAVE 0x08  //clave


int main (int argc, char* argv[])
{
	//apuntador al archivo de probabilidades
	FILE* fdP;
	int c;

	if (argc != 2) {
        fprintf(stderr, "Uso: %s salida-cifrada\n", argv[0]);
        exit(1);
    }

    //Comprueba el archivo de probabilidades para realizar la escritura en el archivo a crear
	if((fdP = fopen(argv[1], "w")) == NULL) {
		fprintf(stderr, "No se puede abrir para escritura en %s\n", argv[1]);
		exit(2);
	}

	//Ciclo para realizar el cifrado
	while ((c=getc(stdin)) != EOF) {
		putc(c, stdout); //Usa la salida estandar
		if (c== '\n') putc ('\n', fdP);
		else {
			char cifrado = c^CLAVE;	//Cifrado
	   		putc(cifrado, fdP);	//Escribir en fichero
		}
	}
}

