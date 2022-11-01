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
           //int i=4; DCL41-C se declara i y se llama a f antes de el primer case, por lo que NUNCA se ejecutaría
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
/*
RATS: no consigo instalarlo, seguiré probando
cppcheck: no da ningun error
splint: Splint 3.1.2 --- 21 Feb 2021

ejempl03.c: (in function func)
ejempl03.c:22:17: Fall through case (no preceding break)
  Execution falls through from the previous case (use @fallthrough@ to mark
  fallthrough cases). (Use -casebreak to inhibit warning)
ejempl03.c:14:6: Function exported but not used outside ejempl03: func
  A declaration is exported, but not used outside this module. Declaration can
  use static qualifier. (Use -exportlocal to inhibit warning)
   ejempl03.c:25:1: Definition of func

Finished checking --- 2 code warnings
vera++:
ejempl03.c:1: no copyright notice found
ejempl03.c:18: line is longer than 100 characters
ejempl03.c:24: closing curly bracket not in the same line or column
ejempl03.c:25: closing curly bracket not in the same line or column
ejempl03.c:29: closing curly bracket not in the same line or column
ejempl03.c:32: trailing whitespace
ejempl03.c:33: trailing empty line(s)


*/