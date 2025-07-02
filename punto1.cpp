//De acuerdo a la definición de TDA lista simple, implemente el TDA y sus 
//operaciones fundamentales considerando que la lista solo tiene un puntero con la 
//dirección del primer nodo de la lista (HEAD). Luego, implemente la operación 
//mínimo que permita extraer el menor valor almacenado en una lista desordenada. 

#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;

struct tnodo{
    int dato;
    pnodo siguiente;
};

void iniciar_lista(pnodo &lista){
    lista = NULL;
}

void agregar_inicio(pnodo &lista, pnodo nuevo){
    nuevo -> siguiente = lista;
    lista = nuevo;
}

void crear_nodo(pnodo &nuevo){
    nuevo = new tnodo;
    if(nuevo != NULL){
        cout << "Ingrese valor: ";
        cin >> nuevo -> dato;
        nuevo -> siguiente = NULL;
    }
    else{
        cout << "Memoria insuficiente" << 
endl;
    }
}

void mostrar(pnodo lista){
    pnodo i;
    if(lista != NULL){
        for(i = lista; i != NULL; i = i->siguiente){
            cout <<  "Nodo: " << i->dato << endl;
        }
    }
    else{
        cout << "Lista vacía";
    }
}

pnodo minimo(pnodo &lista){
	pnodo menor=lista;///apunta al primer nodo de la lista
	pnodo segundo=lista->siguiente;///apunta al segundo nodo de la lista
	pnodo anterior=NULL;///alamcenara el nodo anterior al menor valor 
	pnodo anteriorsegundo=lista;///almacenara al nodo anterior al nodo actual que se esta procesando
	
	while(segundo!=NULL){
		if (segundo->dato < menor->dato){
			menor =segundo;
			anterior=anteriorsegundo;
		}
			anteriorsegundo=segundo;
			segundo=segundo->siguiente;
		}
			if(anterior == NULL){
				pnodo temp=lista;
				lista =lista->siguiente;
				return temp;}
				else{
					anterior->siguiente = menor->siguiente;
					return menor;}
}

int main(){
	pnodo lista;
	iniciar_lista(lista);
	for(int i=0;i<5;i++){
		pnodo nuevo;
		crear_nodo(nuevo);
		agregar_inicio(lista,nuevo);
	}
	mostrar(lista);
	pnodo menor= minimo(lista);
	cout<<"Valor menor: "<<menor->dato;
}
