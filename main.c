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

int flag;
//flag = 1 indica que debe seguir el ascenso rebalanceando.
int key;
int alto_avl = 0;

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

static void Error(int tipo)
{
    if (tipo) printf("\nError en insercion\n");
    else printf("\nError en descarte\n");
}

int Altura(void) //te da la altura actual del arboi
{
    return alto_avl;
}

pnodo CreaNodo(int key)//crea un nodo sin hijos
{
    pnodo nodo;
    nodo = (pnodo) malloc(sizeof(nodo));
    nodo->clave=key;
    nodo->izquierdo=0;
    nodo->derecho=0;
    return t;
}

pnodo insertR(pnodo nodo)
{
    if (nodo == NULL)  /* Llego a un punto de insercion */
    {
        nodo = CreaNodo(key);
        nodo->balance = 0; /* Los dos hijos son nulos */
        flag = 1; /* Marca necesidad de revisar balances */
        return nodo; /* retorna puntero al insertado */
    }
    else if (nodo->clave < key)
    {
        //desciende por la derecha
        nodo->derecho = insertR(nodo->derecho);
        //se pasa por la siguiente linea en la revision ascendente
        nodo->balance += flag; /* Incrementa factor de balance cuando sumo uno a la derecha sumo 1 al balance*/
    }
    else if (nodo->clave > key)
    {
        //desciende por la izquierda
        nodo->izquierdo = insertR(nodo->izquierdo);
        //se corrige en el ascenso
        nodo->balance -= flag; /* Decrementa balance a la izquierda resto 1 si es 0 el total esta balanceado*/
    }
    else   /* (nodo->k == key) Ya estaba en el arbol */
    {
        Error(1);
        flag = 0;
    }

    if (flag == 0) /* No hay que rebalancear. Sigue el ascenso */
        return nodo;

    /*El codigo a continuacion es el costo adicional para mantener propiedad AVL */
    /* Mantiene arbol balanceado avl. Solo una o dos rotaciones por insercion */
    if (nodo->balance < -1)
    {
        /* Quedo desbalanceado por la izquierda. Espejos Casos c y d.*/
        if (nodo->izquierdo->balance > 0)
            /* Si hijo izquierdo esta cargado a la derecha */
            nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        nodo = rotacionDerecha(nodo);
        flag = 0; /* El subarbol no aumenta su altura */
    }
    else if (nodo->balance > 1)
    {
        /* Si quedo desbalanceado por la derecha: Casos c y d.*/
        if (nodo->derecho->balance < 0)
            /* Si hijo derecho esta cargado a la izquierda Caso d.*/
            nodo->derecho = rotacionDerecha(nodo->derecho);
        nodo = rotacionIzquierda(nodo); /* Caso c.*/
        flag = 0; /* El subarbol no aumenta su altura */
    }
    else if (nodo->balance == 0)/* La insercion lo balanceo */
        flag = 0; /* El subarbol no aumenta su altura. Caso a*/
    else /* Quedo desbalanceado con -1 ? +1 Caso b */
        flag = 1; /* Propaga ascendentemente la necesidad de rebalancear */
    return nodo;


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
    
    
    
