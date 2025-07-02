//Utilizando el código de listas dobles con puntero inicio y fin. Complete las operaciones EliminarInicio y EliminarFinal.

#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
struct tnodo{
                    int dato;
                    pnodo sig;
                    pnodo ant;
                    };
struct tlista{
                    pnodo inicio;
                    pnodo fin;
                    };

void IniciarLista(tlista &lista)
{
    lista.inicio = NULL;
    lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
        nuevo -> dato = valor;
        nuevo -> sig = NULL;
        nuevo -> ant = NULL;
    }
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void AgregarFinal(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}

void EliminarInicio(tlista &lista) {
    if (lista.inicio!=NULL){
		pnodo temp = lista.inicio;
		lista.inicio = lista.inicio->sig;
		if (lista.inicio) 
			lista.inicio->ant = NULL;
		else 
			lista.fin = NULL;
    
		delete temp;
}
}

void EliminarFinal(tlista &lista) {
    if (lista.fin!=NULL){
		pnodo temp = lista.fin;
		lista.fin = lista.fin->ant;
		if (lista.fin)
			lista.fin->sig = NULL;
		else
			lista.inicio = NULL;
		
		delete temp;
}
}

int main(){

    return 0;
}


