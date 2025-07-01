#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
struct tnodo{
    int dato;
    pnodo siguiente;
};

struct Cola{
    pnodo frente;
    pnodo fin;
};




void crear_nodo(pnodo &nuevo){
    nuevo = new tnodo;
    if(nuevo != NULL){
        cout << "Ingrese valor a la cola: ";
        cin >> nuevo -> dato;
        nuevo -> siguiente = NULL;
    }
    else{
        cout << "Memoria insuficiente" << endl;
    }
}

void initqueue(Cola &c){
    c.frente = NULL;
    c.fin = NULL;
}

bool isemptyqueue(Cola c){
    return c.frente == NULL;
}


void pushqueue(Cola &c){
	pnodo nuevo;
	crear_nodo(nuevo);
	
	if(isemptyqueue(c)){
		c.frente=nuevo;
		c.fin=nuevo;
	}else{
		c.fin->siguiente=nuevo;
		c.fin=nuevo;
	}
}


int popqueue(Cola &c){
    int extraido;
    if(isemptyqueue(c)){
        cout<<"La cola está vacía"<<endl;
        extraido=-999; //Valor arbitrario
    }
    else{
		extraido=c.frente->dato;
		pnodo aux=c.frente;
		c.frente=c.frente->siguiente;
		if(c.frente==NULL){
			c.fin=NULL;
			delete aux;}
    }
    return extraido;
}

int topqueue(Cola c){
    int extraido;
    if(isemptyqueue(c)){
        cout<<"La cola está vacía"<<endl;
        extraido =  -999;
    }
    else{
		extraido=c.frente->dato;
    }
    return extraido;
}

int bottomqueue(Cola c){
    int extraido;
    if(isemptyqueue(c)){
        cout<<"La cola está vacía"<<endl;
        extraido =  -999;
    }
    else{
        extraido = c.fin->dato;
    }
    return extraido;
}

void menu(int &op){
	cout<<"--------MENU--------"<<endl;
	cout<<"1_Ingresar elemento a la cola"<<endl;
	cout<<"2_Extraer elemento de la cola"<<endl;
	cout<<"3_Consultar frente"<<endl;
	cout<<"4_Consultar final"<<endl;
	cout<<"5_Mostrar cola"<<endl;
	cout<<"6_Cerrar"<<endl;
	cout<<"--------------------"<<endl;
	cout<<"Elegir opcion: ";cin>>op;
}

void mostrar_cola(Cola c){
    pnodo i=c.frente;
    while(i != NULL){
        cout<<i->dato<<endl;
        i=i->siguiente;
    }
}

int main(){
	int op;
	Cola cola;
	initqueue(cola);
	do{ menu(op);
		switch(op){
			case 1: pushqueue(cola);break;
			case 2:	popqueue(cola);break;
			case 3: 
			{	int aux= topqueue(cola);
				cout<<"Frente: "<<aux<<endl;
			break;
			}
			case 4: 
			{	int aux=bottomqueue(cola);
				cout<<"Fin: "<<aux<<endl;
			;break;
			}
			case 5:
				if(isemptyqueue(cola))
					cout<<"Cola vacia"<<endl;
				else
					mostrar_cola(cola);
				
			break;	
			default: 
				if(op!=6)
					cout<<"Opcion no disponible"<<endl;
		}
	}while(op!=6);
}

