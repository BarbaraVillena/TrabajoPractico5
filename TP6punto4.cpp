//Implementar una función/procedimiento que permita recorrer la lista y mostrar el valor mayor y el menor almacenado. 

#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};

void IniciarLista(pnodo &inicio){
	inicio = NULL;
}

void CrearNodo(pnodo &nuevo, int valor){
	nuevo = new tnodo;
	if(nuevo != NULL){
		nuevo -> dato = valor;
		nuevo -> sig = NULL;
		nuevo -> ant = NULL;
	}
}

void AgregarFinal(pnodo &inicio, pnodo nuevo){
    pnodo i;
    if(inicio == NULL){
        inicio = nuevo;
    }
    else{
        for(i = inicio; i -> sig != NULL; i = i -> sig);
        i -> sig = nuevo;
        nuevo -> ant = i;
    }
}

void MenorMayor(pnodo lista){
	pnodo i;
	int menor=lista->dato,mayor=lista->dato;
	
    if(lista != NULL){
        for(i = lista; i != NULL; i = i -> sig){
            if(i->dato < menor)
				menor=i->dato;
				
			if(i->dato>mayor)
				mayor=i->dato;
        }
    }
    cout<<"Menor: "<<menor<<endl;
    cout<<"Mayor: "<<mayor<<endl;
}

int main (){
	pnodo lista;
	IniciarLista(lista);
	for(int i=0;i<5;i++){
		int valor;
		pnodo nodo;
		cout<<"Ingrese elemento a la lista: ";cin>>valor;
		CrearNodo(nodo,valor);
		AgregarFinal(lista,nodo);
	}
	MenorMayor(lista);
}
