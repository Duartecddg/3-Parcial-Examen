
#include <stdlib.h>
#include <stdio.h>

struct Nodo {
	int dato; 
	struct Nodo* izquierda;
	struct Nodo* derecha;
	int nivel_Arbol;
};



struct Nodo* nuevoNodo(int dato);
void insertar(struct Nodo* root, struct Nodo* Nodo);
int buscar_dato(struct Nodo* arbol_binario, int dato);



struct Nodo* nuevoNodo(int dato) {
	struct Nodo* Nodo = NULL;
	Nodo = malloc(sizeof(struct Nodo));
	Nodo->izquierda = Nodo->derecha = NULL;
	Nodo->nivel_Arbol = 1;
	Nodo->dato = dato;
	return Nodo;
}

void insertar(struct Nodo* root, struct Nodo* Nodo) {
	if (root != NULL && Nodo != NULL) {
		Nodo->nivel_Arbol = root->nivel_Arbol + 1;
		if (Nodo->dato > root->dato) {
			if (root->derecha == NULL)
				root->derecha = Nodo;
			else
				insertar(root->derecha, Nodo);
		} else {
			if (root->izquierda == NULL)
				root->izquierda = Nodo;
			else
				insertar(root->izquierda, Nodo);
		}
	}
}

int buscar_dato(struct Nodo* raiz, int dato) {
	int l = 0;
	if (raiz == NULL)
		return 0;
	if (raiz->dato == dato)
		return raiz->nivel_Arbol;
	l = buscar_dato(raiz->izquierda, dato);
	if (l > 0)
		return l;
	l = buscar_dato(raiz->derecha, dato);
	if (l > 0)
		return l;
	return 0;
}


int main() {
	int n = 0, nivel_Arbol = 0;
	struct Nodo* raiz = nuevoNodo(6);
	insertar(raiz, nuevoNodo(5));
	insertar(raiz, nuevoNodo(11));
	insertar(raiz, nuevoNodo(4));
	insertar(raiz, nuevoNodo(3));
	insertar(raiz, nuevoNodo(8));
	insertar(raiz, nuevoNodo(12));
	insertar(raiz, nuevoNodo(9));
	insertar(raiz, nuevoNodo(21));
	
	printf("ingrese un numero a buscar ");
	scanf("%d", &n);
	nivel_Arbol = buscar_dato(raiz, n);
	if (nivel_Arbol > 0)
		printf("su numero esta en el nivel %d\n", nivel_Arbol);
	else 
		printf("no pudimos encontrar el nodo :( \n");

	return 0;
}
