#include <stdio.h>
#include <stdlib.h>

typedef struct avlnode
{
    int clave;
    int balance; /* Factor de balance -1,0,1 */
    struct avlnode *izquierdo, *derecho;
} nodo, *pnodo;

# define max(A,B) ((A)>(B)?(A):(B)) /* Definimos la funcion mayor o menor*/
# define min(A,B) ((A)>(B)?(B):(A))

static pnodo rotacionIzquierda(pnodo t)
{
    pnodo temp;
    int x,y;
    temp = t;
    t = t->derecho;
    temp->derecho = t->izquierdo;
    t->izquierdo = temp;
    //Recalcula factores de balance de los dos nodos
    x = temp->balance; // oldbal(A)
    y = t->balance; // oldbalance(B)
    temp->balance = x-1-max(y, 0); // nA
    t->balance = min(x-2+min(y, 0), y-1); // nB
    return t;
}

static pnodo rotacionDerecha(pnodo t)
{
    pnodo temp = t;
    int x,y;
    t = t->izquierdo;
    temp->izquierdo = t->derecho;
    t->derecho = temp;
    x = temp->balance; // oldbal(A)
    y = t->balance;    // oldbal(B)
    temp->balance = x+1-min(y, 0);  // nA
    t->balance = max(x+2+max(y, 0), y+1); //nB
    return t;

}

void salir(){
    printf("Programa finalizado");
}



void menu(){

    int opcion;
    pnodo t=NULL;
    int valor;


    do{
        printf("*****Menu*****\n");

        printf("Elige una opcion\n");

        printf("1. Cargar valor \n");
        printf("2. Listar in order\n");
        printf("3. Listar pos order \n");
        printf("4. Listar Pre order \n");
        printf("5. Borrar Nodo \n");
        printf("6. Buscar Nodo \n");
        printf("7. Salir \n");

        printf("SELECCIONA LA OPCION \n");
        scanf("%d", &opcion);

        switch(opcion)
        {

            case 1:
                printf("ingresar un valor \n");
                scanf("%d", &valor);
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;
            
            case 6:
                break;

            case 7:
                salir();
                break;


        }

    }while (opcion != 7);


}


int main() {
    menu();
    return 0;

}
    
    
    
