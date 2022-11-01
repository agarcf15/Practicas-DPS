/*
*   Revisa y evalua el siguiente codigo
*   
*  Define la regla que incumple y propon
*    una alternativa más adecuada segun el SEI CERT C
*
*/


#include <stdio.h>
#include <stddef.h>

const char *p;

char *funcion1(void){
    /*
    char array[10] = "Mi Cadena";//DCL30-C. Se declara un objeto con una direccion, puede dar overflow
    Initialize array 
    return array;  //Devuelve la direccion de memoria del objeto, no el objeto
    */
    char array[] = "Mi Cadena";//una posible solucion al DCL30 es quitar el tamaño en la declaración
    
    char *temp = array; //SOlucion al warning por devolver el la direccion de memoria, creas un puntero que contiene esa direccion
    return temp;

}
void funcion2(void){ //DCL30-C. Puede generar que c_str se sobreescriba yo se pierda cuando termine funcion2
    const char c_str[] = "Todo va bien";
    p = c_str;
}
void funcion3(void){
    printf("%s\n", p);
}

int main(void){
    p = funcion1();
    printf("%s\n", p);
    p = NULL;//una posible solucion es vaciar p después de usarlo
    funcion2();
    funcion3();
    printf("%s\n", p);

    return 0;
}