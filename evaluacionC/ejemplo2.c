/*
*   ¿que hace el siguiente segmento de codigo?
*       Declara una estructura con un numero entero y un vector de tamaño 1
*       Func  crea un nuevo struct y reserva el espacio necesario para el struct, aunque reserva una barbaridad de espacio
*   de haber algun problema ¿podrias decir la linea en que se encuentra?
*       EN LA LINEA INTERNA DEL FOR (LINEA -- DE MI CODIGO) si array_size es mayor que 1 se saldrá del vector y escribirá sobre sepa usted
*   Define la regla que se incumple y propon una alternativa correcta
*       siguiendo el SEI CERT C
*
*/


#include <stdlib.h>

struct flexArrayStruct {
    int num; 
    //int data[1]; //DCL38-C ASIGNA un tamaño fijo al array. Si array_size fuese mayor a 1, daria overflow
    int data[]; //una posible solución es convertir en dinámico el array
};


//crea un puntero que almazena un struct de tipo flexArrayStruct. Reserva memoria para la estructura, el numero entero y el tamaño de array 
void func(size_t array_size){
    /*Space is allocated for de struct*/
    struct flexArrayStruct *structP
        = (struct  flexArrayStruct *)
        malloc(sizeof(struct flexArrayStruct)
        + sizeof(int)*(array_size -1));
    
    if (structP == NULL) {
        /*ERROR*/
    }
    structP->num = array_size; //guarda en num el tamaño del array
    /*
    * Access data[] as if it had been allocated
    * as data[array_size].
    */
   for (size_t i = 0; i < array_size; i++) { //rellena con un 1 data hasta llegar a array_size -1
    structP->data[i] = 1; //DCL38
   }
}
int main(void){
    func(5);
    return 0;
}
