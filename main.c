#include <stdio.h>
#include <stdlib.h>

// Estructura para un nodo en la pila
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int dato) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para insertar un elemento a la pila
void push(struct Nodo** pila, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
    printf("Se ha agregado %d a la pila.\n", dato);
}

// Función para sacar un elemento de la pila
int pop(struct Nodo** pila) {
    if (*pila == NULL) {
        printf("La pila esta vacia.\n");
        return -1;
    }
    struct Nodo* temp = *pila;
    *pila = (*pila)->siguiente;
    int dato = temp->dato;
    free(temp);
    return dato;
}

// Función para mostrar los elementos en la pila
void mostrarPila(struct Nodo* pila) {
    struct Nodo* actual = pila;
    if (actual == NULL) {
        printf("La pila esta vacia.\n");
        return;
    }
    printf("Elementos en la pila:\n");
    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}

int main() {
    struct Nodo* pila = NULL;
    int opcion, valor;

    do {
        printf("\nOpciones:\n");
        printf("1. Ingresar (push) un elemento en la pila\n");
        printf("2. Borrar (pop) un elemento de la pila\n");
        printf("3. Mostrar la pila\n");
        printf("0. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un valor numerico: ");
                scanf("%d", &valor);
                push(&pila, valor);
                break;
            case 2:
                valor = pop(&pila);
                if (valor != -1) {
                    printf("Se saco %d de la pila.\n", valor);
                }
                break;
            case 3:
                mostrarPila(pila);
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, elija una opcion valida.\n");
        }
    } while (opcion != 0);

    return 0;
}
