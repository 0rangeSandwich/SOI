#include <stdio.h>
#include <stdlib.h>

int main(){
	char c;
	int i; //variable de entrada
	float j;
	FILE *archivo;
	c = getchar();

	archivo = fopen ("errores", "w");

	while (c != EOF){
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
	return 0;
}