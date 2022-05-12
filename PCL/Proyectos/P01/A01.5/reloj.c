#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

//funcion para el retardo de la impresion
unsigned esperar_tiempo (int unitiempo){
	
	if (unitiempo <= 0)
                return 0;
        else {
                Sleep(unitiempo*1000);
                return(unitiempo);
    }
}

//funcion para cronometrar el tiempo en MS



int main(int argc, const char * argv[]){
        clock_t tiempo_inicio, tiempo_final;

        tiempo_inicio = clock();

	int i;
        double microsegundos;

	
        //Sin unidad de tiempo
	if (argc != 2) {
                printf("Uso: %s unidad de tiempo\n", argv[0]);
                exit(1);
        }

        //Impresion
	for (i=1; i<=10; i++) {  
            esperar_tiempo(atoi(argv[1]));
            printf("%d\n", i);
        }

        tiempo_final = clock();
        microsegundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
        microsegundos = microsegundos * 10000; //Conversión a segundos
        microsegundos = microsegundos * 1000000; //microsegundos
        printf("Tiempo real en micro segundos: %f \n",microsegundos);
}