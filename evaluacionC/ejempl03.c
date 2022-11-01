/*
 ¿qué hae el siguiente segmento de código si invocamos la funcoin func con un 0?
 de haber algun problema, en qué linea se encuentra?
 crea un fichero con un main y ejecuta
 propon una solucion con las CMU
 realiza un analisis estatico del código erróneo y copia su solucion usando las erramientas
*/


#include <stdio.h>

extern void f (int i);

void func(int expr){
    int i=4; //la solución es colocar ambas lineas fuera del switch
    f(i);
    switch (expr){
           //int i=4; DCL-C se declara i y se llama a f antes de el primer case, por lo que NUNCA se ejecutaría
            //f(i);
        case 0:
            i=17;
        default:
        printf("%d\n", i);
    }
}
int main(void){
    func(0);
    return 0;
}

// Si llamamos a func con un 0, la función entrará en el case 0 del switch e imprimirá 17
// El problema está en las líneas 11 y 12, porque el código de esas líneas nunca se va a ejecutar 

