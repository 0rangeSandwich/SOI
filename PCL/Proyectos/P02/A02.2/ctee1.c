// ctee.c
// Similar a tee (1). Version con funciones de biblioteca C
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    FILE* fd;
    FILE* archivo;
    char c;
    int i; //variable de entrada
    float j;

            //> 1
    if ((argc != 2)) {
                        //Error de argumento
        fprintf(stderr, "Uso: %s fichero_salida\n", argv[0]);
        exit(1);
    }

    if ((fd= fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "No se puede abrir para escritura en %s\n", argv[1]);
        exit(2);
    }
    while (c = getchar() != EOF) {
        i = (int)(c - 0);
        if (i>=0 & i<=5){
            j = (float)i/ (float)5;
            //Escribe en el archivo Probabilidad
            fprintf(stdout,"Probabilidad: %.2f\n", j);
        }else{
            //Escribe en el archivo error
            fprintf(archivo,"Error %d\n", i);
        }
        //C toma el valor obtenido la entrada de carácteres uno a uno.
        c = getchar();
    }
    fclose(fd);
}




/*
    (a) ¿qué llamadas al sistema usa stee y cómo son sus parámetros?,
    (b) ¿cómo se representan los descriptores de ficheros en ambas versiones?

    Llamadas a biblioteca y llamadas a sistema. (ctee y stee)
    UNIX, POSIX, BSD


    3. Prepara un fichero de texto largo, de algunos miles de caracteres. 
    Si se lo suministras a stee y a ctee como entrada, ¿notas alguna diferencia en la ejecución de ambos?

    Tamaño del buffer


*/