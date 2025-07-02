//Implemente una función/procedimiento que permita recorrer la lista y eliminar todos los nodos que contengan valores múltiplos de 3. Mostrar la lista actualizada. 

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

pnodo QuitarNodo(pnodo &inicio, int valor){
	pnodo extraido, i;
	if(inicio == NULL)
	extraido = NULL;
	else{
		if(inicio -> dato == valor){
			extraido = inicio;
			inicio = inicio->sig;
			inicio->ant = NULL;
			extraido->sig = NULL;
		}else{
			for(i = inicio; i != NULL && i -> dato != valor; i = i -> sig);
			if(i != NULL){
				extraido = i; 
				(i -> ant) -> sig = i -> sig; 
				i -> sig = i -> ant;
				extraido -> sig = NULL;
				extraido -> ant = NULL;
				}    }    }    
	return extraido;
}

void MostrarLista(pnodo inicio){
    pnodo i;
    if(inicio != NULL){
        for(i = inicio; i != NULL; i = i -> sig){
            cout << i -> dato << endl;
        }
    }
}

void BorrarMultiplos(pnodo &lista){
	if(lista != NULL){
		pnodo i=lista;
		while(i!=NULL){
			pnodo siguiente=i->sig;
            if(i->dato%3==0){
				int valor=i->dato;
				QuitarNodo(lista,valor);
			}
			i=siguiente;
        }
    }
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
	BorrarMultiplos(lista);
	MostrarLista(lista);
}

