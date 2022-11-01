/*
¿Que hace el siguiente segmento de codigo? 
¿Para que se utiliza la variable va_eol?

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

enum { va_eol=-1 };

unsigned int average(int first, ...) {
    unsigned int count = 0;
    unsigned int sum = 0;
    int i = first;
    va_list args;

    va_start(args, first);

    while(i!=va_eol) {
        sum += i;
        count++;
        i = va_arg(args, int);
    }

    va_end(args);
    return (count ? (sum/count) : 0);
}

int main(int argc, char *argv[]) {
    average(42, 50, 84, 30, 10, 50, 65, 74, 21, 99, 88, 31, 45, 16);
    return 0;
}

/*
* 1. El codigo calcula la media a partir de una cadena dinamica de numeros enteros*    que se pasan por parametro.
* 2. va_eol se utiliza para saber cuando finaliza la lista de argumentos. Cuando i tiene el valor -1 significa que ha recibido todos los argumentos y que la función ha finalizado 
*/

/*
gcc ex1.c -std=c11 -Werror -Wall -Wextra -Wcast-align -Wcast-qual -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wredundant-decls -Wshadow -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option -pedantic  -o ex1
*/