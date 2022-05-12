// ctee.c
// Similar a tee (1). Version con funciones de biblioteca C
///////////////////////////////////////////////////////////
//stdout = 1
//stderr = 2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    //apuntador al archivo de probabilidades
    FILE* fdP;
    //apuntador al archivo de errores
    FILE* fdE;

    int c;
    float calculoProbabilidad;
    char probaChar[4];

    if ((argc > 1)) {
        fprintf(stderr, "Error en argumentos\n");
        exit(1);
    }
    /*
    if ((fdP= fopen(" ", "w")) == NULL) {
        fprintf(stderr, "No se puede abrir para escritura en %s\n", argv[1]);
        exit(2);
    }*/
    

    while ((c=getc(stdin)) != EOF) {
        //Conversion de caracter a numero
        int numero = c - 48;


        //Bloque donde validamos las condiciones planteadas al inicio del programa
        if(numero >= 0 && numero <= 5){
           
            //Convertimos de entero a flotante numero para usarlo en la división
            float numeroF=numero;

            //Calculamos la probabilidad
            calculoProbabilidad = numeroF/5;

            //Convertimos la probabilidad resultante de float a
            sprintf(probaChar, "%.1f", calculoProbabilidad);
                
            //Ciclo repetitivo para escribir en archivo lo establecido    
            fdP= fopen(" ", "w");
            
            for(int i=0; i<3 ; i++){
                //putc(probaChar[i],fdPProbabilidades);
                //putc(c, stdout);
                //putc(c, fdPProbabilidades);
                putc(probaChar[i], stdout);
            }
            putc('\n',stdout);
            


       }else{
            if(numero < 0){
                //Si es menor a 0, no realiza ninguna acción
            }else{
                //Caso contrario, escribe en errores
                fdE= fopen(" ", "w");
                putc(c,stderr);
                putc('\n',stderr);
            }
        }

        //putc(c, stdout);
        //putc(c, fdP);
        //usleep(10000);
    }
    fclose(fdP); //Cierra el archivo de probabilidades
}