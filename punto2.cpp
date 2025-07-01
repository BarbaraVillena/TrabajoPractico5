//Implemente una lista con puntero al inicio y al final además de un contador que 
//registre la cantidad de elementos actuales que hay en la lista. Realice las 
//modificaciones necesarias a los métodos agregar y eliminar para que actualice el 
//contador, además de agregar una función que retorne la cantidad de elementos 
//actuales de la lista.

#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
struct tnodo{
    int dato;
    pnodo siguiente;
};

struct list{
	pnodo inicio;
	pnodo fin;
	int cant;
};

void cantidad(list &lista,int op){
	if(op==1)
		lista.cant++;
	else
		lista.cant--;
}

void iniciar_lista(list &lista){
    lista.inicio=NULL;
    lista.fin=NULL;
    lista.cant=0;
}

void agregar_final(list &lista, pnodo nuevo){
	if(lista.fin==NULL){
		lista.inicio=nuevo;
		lista.fin=nuevo;
	}else{
		lista.fin->siguiente=nuevo;
		lista.fin=nuevo;
	}
	cantidad(lista,1);
}

void agregar_inicio(list &lista, pnodo nuevo){
	if(lista.inicio==NULL){
		lista.inicio=nuevo;
		lista.fin=nuevo;
	}else{
		nuevo->siguiente=lista.inicio;
		lista.inicio=nuevo;
	}
	cantidad(lista,1);
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

void menu(int &op){
	cout<<"--------MENU--------"<<endl;
	cout<<"1_Agregar"<<endl;
	cout<<"2_Eliminar"<<endl;
	cout<<"3_Mostrar"<<endl;
	cout<<"4_Cerrar"<<endl;
	cout<<"--------------------"<<endl;
	cout<<"Elegir opcion: ";cin>>op;
}
void menu_agregar(int &op){
	cout<<"--------MENU--------"<<endl;
	cout<<"1_Agregar inicio"<<endl;
	cout<<"2_Agregar fin"<<endl;
	cout<<"3_Atras"<<endl;
	cout<<"--------------------"<<endl;
	cout<<"Elegir opcion: ";cin>>op;
}

void agregar(list &lista){
	int op;
	do{
		menu_agregar(op);
		switch(op){
			case 1:{
				pnodo nuevo;
				crear_nodo(nuevo);
				agregar_inicio(lista,nuevo); }
			break;
			case 2:
				pnodo nuevo;
				crear_nodo(nuevo);
				agregar_final(lista,nuevo);
			break;
			default: 
				if (op!=3)
					cout<<"Opcion no disponible"<<endl;
		}
	}while(op!=3);
}

pnodo eliminar_inicio(list &lista){
    pnodo borrado;
    if(lista.inicio==NULL){
        borrado = NULL;
    }
    else{
        borrado = lista.inicio;
        if(lista.inicio==lista.fin){
			lista.inicio = NULL;
			lista.fin= NULL;
		}else{
			lista.inicio=lista.inicio->siguiente;
		}
		borrado->siguiente=NULL;
		cantidad(lista,0);
    }

    return borrado;
}

pnodo eliminar_final(list &lista){
    pnodo borrado, i;
    if(lista.fin == NULL){
        borrado = NULL;
    }
    else{
        if(lista.inicio==lista.fin){
            borrado=lista.fin;
            lista.inicio=NULL;
            lista.fin=NULL;
        }
        else{
            for(i=lista.inicio; i->siguiente!=lista.fin;i=i->siguiente);
            borrado = lista.fin;
            lista.fin=i;
            lista.fin->siguiente=NULL;
        }
         cantidad(lista,0);
    }
    return borrado;
}

void menu_eliminar(int &op){
	cout<<"--------MENU--------"<<endl;
	cout<<"1_Eliminar inicio"<<endl;
	cout<<"2_Eliminar fin"<<endl;
	cout<<"3_Atras"<<endl;
	cout<<"--------------------"<<endl;
	cout<<"Elegir opcion: ";cin>>op;
}

void eliminar(list &lista){
	int op;
	do{
		menu_eliminar(op);
		switch(op){
			case 1:
				eliminar_inicio(lista);
			break;
			case 2:
				eliminar_final(lista);
			break;
			default: 
				if (op!=3)
					cout<<"Opcion no disponible"<<endl;
		}
	}while(op!=3);
}

void mostrar(list lista){
    pnodo i;
    if(lista.inicio != NULL){
        for(i = lista.inicio; i != NULL; i = i->siguiente){
            cout <<  "Nodo: " << i->dato << endl;
        }
        cout<<"Cantidad de elementos: "<<lista.cant<<endl;
    }
    else{
        cout << "Lista vacía";
    }
}


int main(){
	int op;
	list lista;
	iniciar_lista(lista);
	
	do{	menu(op);
		switch(op){
			case 1:
				agregar(lista);
			break;
			
			case 2:
				eliminar(lista);
			break;
			case 3:
				mostrar(lista);
			break;
			default: 
				if(op!=4)
					cout<<"Opcion no disponible"<<endl;
			break;
		}
	}while(op!=4);
	

}
