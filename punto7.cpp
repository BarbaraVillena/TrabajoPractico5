void enigma(Nodo* nodo) 
    { 
        if(nodo!=nullptr)  //verifica si se trata de un puntero nulo
          if(nodo->getSiguiente() == nullptr) //verifica si el nodo actual es el ultimo elemento
             cout << nodo->getDato() << endl; 
          else{ 
             enigma(nodo->getSiguiente()); //llama a la funcion con el siguiente elemento hasta encontrar al ultimo elemento y empezar a imprimirlos por pantalla
             cout << nodo->getDato() << endl; 
          } 
    }
    
    
///Esta funcion, se trata de una funcion recursiva, pues se llama así misma. 
///Su funcion es la de imprimir los elementos de una lista en orden inverso

        __
	if |_|| -> NULL
		no hace nada 
   
			  _
	Lista -> |3||->NULL
		el nodo actual es el ultimo

		  	  _      _     _	
	Lista -> |3||-> |4||->|5||->NULL
	5
	
	Lista -> |3||-> |4||->NULL
	4
	Lista -> |3||-> NULL
	3
	
	
	
	
	
int misterio (Nodo* nodo) 
{ 
    if(nodo == nullptr) //verifica si el nodo es nulo
      return 0; 
    else 
      return misterio(nodo->getSiguiente()) + 1; //llama a la funcion sumando 1
}


///Esta funcion recursiva devuelve el numero de elementos de una lista


	|1||->|2||->|6||->NULL
	
	nodo3 return 0+1=1
	nodo2 return 1+1=2
	nodo3 return 2+1=3
	
	3
	
	
	
	
Nodo* desconocido(Nodo* nodo) { 
   if(nodo == nullptr || nodo ->getSiguiente() == nullptr) //verifica si el puntero es nulo
       return nodo; 
   else 
       return desconocido(nodo->getSiguiente()); 
}

///Esta funcion se llama asi misma hasta llegar al ultimo elemento


	
