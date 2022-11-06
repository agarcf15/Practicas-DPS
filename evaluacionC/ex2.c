/*
¿Que hace el siguiente segmento de codigo? 
Comenta que reglas/recomendaciones se estan rompiendo aquı. Tambien entran
reglas pasadas.
Instala la herramienta perf para realizar el profiling de la aplicacion. Se puede instalar con apt.
El programa permite mostrar el codigo desensamblado de la aplicacion, adjunta
alguna captura.
¿Podıas decir cual es la instruccion que mas tiempo de CPU requiere? Adjunta una captura y describe la razon.
*/

#include <stdio.h>

unsigned long long int factorial(unsigned int i) {
    if(i<=1) {
        return 1;
    }
    return i*factorial(i-1);
}

int main(int argc, char *argv[]) {
    int i=12, j=3, f=0;

    if(argc==1) {
        printf("Factorial of %d is %11d\n", i, factorial(i));
    }
    else {
        j = atoi(argv[1]);
        for(f=0;f<j;f++) {
            printf("Factorial of %d id %11d\n", f, factorial(f));
        }
    }
}

//El codigo calcula el factorial de i recursivamente
//se incumplen las siguientes reglas: INT30-C DCL04-C DCL00-C DCL01-C INT08-C

//La linea que más consume es, en mi caso, la 29, que imprime la llamada a la funcion factorial y calcula todos los factoriales anteriores