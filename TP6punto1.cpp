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

///Agregar
void agregar_inicio(pnodo &inicio, pnodo nuevo){
    if(inicio == NULL){
        inicio = nuevo;
    }
    else{
        nuevo -> sig = inicio;
        inicio -> ant = nuevo;
        inicio = nuevo;
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

void AgregarOrden(pnodo &inicio, pnodo nuevo){
    pnodo i;
    if(inicio == NULL)
        inicio = nuevo;
    else{
        if(nuevo -> dato < inicio -> dato){
            nuevo -> sig = inicio;
            inicio -> ant = nuevo;
            inicio = nuevo;
        }
        else{
            for(i = inicio; i -> sig != NULL && (i -> sig) -> dato < nuevo -> dato; i = i -> sig);
            if(i -> sig != NULL){
                nuevo -> sig = i -> sig;
                nuevo -> ant = i;
                (i -> sig) -> ant = nuevo;
                i -> sig = nuevo;
            }
            else{
                i -> sig = nuevo;
                nuevo -> ant = i;
       } } }
}

///Quitar

pnodo QuitarInicio(pnodo &inicio){
	pnodo extraido;
	if(inicio == NULL)
		extraido = NULL;
	else{
		if(inicio -> sig == NULL){
			extraido = inicio;
			inicio = NULL;
		}else{
			extraido = inicio;
			inicio = inicio -> sig;
			inicio -> ant = NULL; 
			extraido -> sig = NULL;}
			}    
	return extraido;
}

pnodo QuitarFinal(pnodo &inicio){
    pnodo extraido, i;
    if(inicio == NULL)
        extraido = NULL;
    else{
        for(i = inicio; i -> sig != NULL; i = i -> sig);
        extraido = i;
        (i -> ant) -> sig = NULL;
        i -> ant = NULL;
    }
    return extraido;
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

bool buscar_nodo(pnodo lista,int valor){
	bool band=false;
	 pnodo i;
    if(lista != NULL){
        for(i = lista; i != NULL; i = i -> sig){
         if(i->dato==valor)
			band=true;
        }
    }
    return band;
}
///MENUS
void menu(int &op){
	cout<<"----------MENU----------"<<endl;
	cout<<"1_Agregar elementos"<<endl;
	cout<<"2_Quitar elementos"<<endl;
	cout<<"3_Buscar elementos"<<endl;
	cout<<"4_Mostrar elemento"<<endl;
	cout<<"5_Cancelar"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"Elegir opcion: ";cin>>op;
}

void menu_agregar(int &op){
	cout<<"----------MENU----------"<<endl;
	cout<<"1_Agregar inicio"<<endl;
	cout<<"2_Agregar final"<<endl;
	cout<<"3_Agregar en orden"<<endl;
	cout<<"4_Atras"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"Elegir opcion: ";cin>>op;
}

void menu_quitar(int &op){
	cout<<"----------MENU----------"<<endl;
	cout<<"1_Quitar inicio"<<endl;
	cout<<"2_Quitar final"<<endl;
	cout<<"3_Quitar nodo a eleccion"<<endl;
	cout<<"4_Atras"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"Elegir opcion: ";cin>>op;
}

void insertar(pnodo &lista){
	int op;
	int valor;
	pnodo nuevo;
	do{ menu_agregar(op);
		switch(op){
			case 1: 
				cout<<"Ingrese elemento a la lista: ";cin>>valor;
				CrearNodo(nuevo,valor);
				agregar_inicio(lista,nuevo); break;
			case 2:
				cout<<"Ingrese elemento a la lista: ";cin>>valor;
				CrearNodo(nuevo,valor);
				AgregarFinal(lista,nuevo); break;
			case 3:
				cout<<"Ingrese elemento a la lista: ";cin>>valor;
				CrearNodo(nuevo,valor);
				AgregarOrden(lista,nuevo); break;
			default:
				if(op!=4)
					cout<<"Opcion no disponible: "<<endl;
					
		}
	}while(op!=4);

}


void extraer(pnodo &lista){
	int op;
	int valor;
	do{ menu_quitar(op);
		switch(op){
			case 1: QuitarInicio(lista); break;
			case 2: QuitarFinal(lista); break;
			case 3:
				MostrarLista(lista);
				cout<<"Ingrese elemento quitar: ";cin>>valor;
				QuitarNodo(lista,valor);
				break;
			default:
				if(op!=4)
					cout<<"Opcion no disponible: "<<endl;
					
		}
	}while(op!=4);

}


int main(){
	int op;
	pnodo lista;
	IniciarLista(lista);
	
	do{ menu(op);
		switch(op){
			case 1:	insertar(lista); break;
			case 2:
				if(lista==NULL)
					cout<<"Lista vacia"<<endl;
				else
					extraer(lista); 
					
			break;
			case 3: 
				int elemento;
				if(lista==NULL)
					cout<<"Lista vacia"<<endl;
				else{
					cout<<"Ingrese elemento a buscar: ";cin>>elemento;
					if(buscar_nodo(lista,elemento))
						cout<<"Nodo encontrado"<<endl;
					else
						cout<<"Nodo no encontrado"<<endl;
				}
			break;
			case 4:  
				if(lista==NULL)
					cout<<"Lista vacia"<<endl;
				else
					MostrarLista(lista); 
			
			break;
			default: break;
		}
	}while(op!=5);
	
}
