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

