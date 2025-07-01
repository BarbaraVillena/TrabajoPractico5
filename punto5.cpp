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

void crear_nodo(pnodo &nuevo,int valor){
    nuevo = new tnodo;
    if(nuevo != NULL){
		nuevo -> dato=valor;
        nuevo -> siguiente = NULL;
    }
    else{
        cout << "Memoria insuficiente" << endl;
    }
}

void agregar_final(pnodo &lista, pnodo nuevo){
    pnodo i;
    if(lista == NULL){
        lista = nuevo;
    }
    else{
        for(i = lista; i->siguiente != NULL; 
i=i->siguiente);
        i->siguiente = nuevo;
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

void ordenar_lista(pnodo &lista){
    pnodo i, j;
    for(i = lista; i != NULL; i = i->siguiente){
        for(j = i->siguiente; j != NULL; j = j->siguiente){
            if(i->dato > j->dato){
                int aux = i->dato;
                i->dato = j->dato;
                j->dato = aux;
            }
        }
    }
}

int main(){
	int valor;
   pnodo lista1,lista2,listacombinada;
	iniciar_lista(lista1);
	iniciar_lista(lista2);
	iniciar_lista(listacombinada);
	
	cout<<"1era LISTA"<<endl;
	for(int i=0;i<5;i++){
		cout<<"Ingrese elemento: ";cin>>valor;
		
		pnodo nuevo,nuevoaux;
		
		crear_nodo(nuevo,valor);
		crear_nodo(nuevoaux,valor);
		agregar_final(lista1,nuevo);
		agregar_final(listacombinada,nuevoaux);
	}

	cout<<"2da LISTA"<<endl;
	for(int i=0;i<5;i++){
		cout<<"Ingrese elemento: ";cin>>valor;
		
		pnodo nuevo,nuevoaux;
		
		crear_nodo(nuevo,valor);
		crear_nodo(nuevoaux,valor);
		agregar_final(lista2,nuevo);
		agregar_final(listacombinada,nuevoaux);
	}
	
	cout<<"1er LISTA"<<endl;
	mostrar(lista1);
	
	cout<<"2da LISTA"<<endl;
	mostrar(lista2);
	
	cout<<"LISTA COMBINADA"<<endl;
	mostrar(listacombinada);
	
	ordenar_lista(lista1);
	ordenar_lista(lista2);
	ordenar_lista(listacombinada);
	
	cout<<"1er LISTA - ordenada"<<endl;
	mostrar(lista1);
	
	cout<<"2da LISTA - ordenada "<<endl;
	mostrar(lista2);
	
	cout<<"LISTA COMBINADA - ordenada"<<endl;
	mostrar(listacombinada);
}
