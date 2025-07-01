//Utilizando listas simples implemente: 
//a.  TDA Pila y sus operaciones fundamentales. 

#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
struct tnodo{
    int dato;
    pnodo siguiente;
};

struct pila{
    pnodo cima;
};

void initstack(pila &p){
    p.cima = NULL;
}

bool isemptystack(pila p){
    return p.cima== NULL;
}


void crear_nodo(pnodo &nuevo){
    nuevo = new tnodo;
    if(nuevo != NULL){
        cout << "Ingrese valor a la pila: ";
        cin >> nuevo -> dato;
        nuevo -> siguiente = NULL;
    }
    else{
        cout << "Memoria insuficiente" << 
endl;
    }
}

void pushstack(pila &p){
    pnodo nuevo;
    crear_nodo(nuevo);
    nuevo->siguiente=p.cima;
    p.cima=nuevo;
}

int popstack(pila &p){
    if(isemptystack(p)){
        cout << "Pila vacía" << endl;
        return -999;
    }
    else{
		int valor=p.cima->dato;
		pnodo aux=p.cima;
		p.cima = p.cima->siguiente;
		delete aux;
		return valor; }
}

int topstack(pila p){
    if(isemptystack(p)){
        cout<<"Pila vacía"<<endl;
        return -999;
    }
    return p.cima->dato;
}

void mostrar_pila(pila p){
    pnodo i=p.cima;
    while(i != NULL){
        cout<<i->dato<<endl;
        i=i->siguiente;
    }
}
void menu(int &op){
	cout<<"--------MENU--------"<<endl;
	cout<<"1_Ingresar elemento a pila"<<endl;
	cout<<"2_Extraer elemento de la pila"<<endl;
	cout<<"3_Consultar cima"<<endl;
	cout<<"4_Mostrar pila"<<endl;
	cout<<"5_Cerrar"<<endl;
	cout<<"--------------------"<<endl;
	cout<<"Elegir opcion: ";cin>>op;
}

int main(){
	int op;
    pila Pila;
    initstack(Pila);
    
	
	do{menu(op);
		
		switch(op){
		case 1: pushstack(Pila); break;
		case 2: popstack(Pila); break;
		case 3: 
			{int aux=topstack(Pila);
			cout<<"Cima: "<<aux<<endl; 
		}
			break;
		case 4:	
			if(!isemptystack(Pila))
				mostrar_pila(Pila); 
			else
				cout<<"Pila vacía"<<endl;
			
		break;
		default: 
			if(op!=5)
				cout<<"Opcion no disponible"<<endl;
		
		}
	}while(op!=5);
}
