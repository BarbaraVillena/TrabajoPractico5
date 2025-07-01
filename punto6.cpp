//Haciendo uso de listas genérica que realice: 
//a.  Que la lista se cargue con números enteros y realice una función que busque 
//números primos dentro de la lista y los cuente. Muestre el resultado de la cuenta. 
//b.  Que la lista se cargue con caracteres y realice la cuenta de mayúsculas y 
//minúsculas dentro de la lista. Muestre los resultados por pantalla. 

#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;

struct tnodo{
    int dato;
    char letra;
    pnodo siguiente;
};

void iniciar_lista(pnodo &lista){
    lista = NULL;
}

void crear_nodo(pnodo &nuevo){
    nuevo = new tnodo;
    if(nuevo != NULL){
        cout << "Ingrese valor: ";
        cin >> nuevo -> dato;
        nuevo -> siguiente = NULL;
    }
    else{
        cout << "Memoria insuficiente" << endl;
    }
}

void crear_nodol(pnodo &nuevo){
    nuevo = new tnodo;
    if(nuevo != NULL){
        cout << "Ingrese valor: ";
        cin >> nuevo -> letra;
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

bool es_primo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void primo(pnodo lista, int &primo){
    pnodo i;
    if(lista != NULL){
        for(i = lista; i != NULL; i = i->siguiente){
            if (es_primo(i->dato)) primo++;
        }
    }
}

void mayus(pnodo lista, int &may){
    pnodo i;
    if(lista != NULL){
        for(i = lista; i != NULL; i = i->siguiente){
           if (i->letra>='A' && i->letra<='Z')
				may++;
        }
    }
}


int main (){
	int p=0,m=0;
	pnodo lista,lista2;
	iniciar_lista(lista);
	iniciar_lista(lista2);
	
	for(int i=0;i<5;i++){
		pnodo nuevo;
		crear_nodo(nuevo);
		agregar_final(lista,nuevo);
	}
	primo(lista,p);
	cout<<"Cant. de nnros primos: "<<p<<endl;
		
	for(int i=0;i<5;i++){
		pnodo nuevo;
		crear_nodol(nuevo);
		agregar_final(lista2,nuevo);
	}
	mayus(lista2,m);
	cout<<"Cant. de mayusculas: "<<m<<endl;
}
