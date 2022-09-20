#include <iostream>
#include <cstdlib>
using namespace std;
// n rand() % 100;


struct Nodo{
	int dato;
	Nodo *siguiente;	
};

	Nodo *lista = NULL;

void insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	
	while((aux1 != NULL ) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if (lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
	
	cout<<"\tElemento "<<n<<" insertado en la lista correctamente\n"<<endl;
}

void buscarLista(Nodo *lista, int n){
	bool band = false;
	
	Nodo *actual = new Nodo();
	actual = lista;
	
	while ((actual != NULL) && (actual->dato <= n)){
		if (actual->dato == n){
			band = true;
		}
		actual = actual->siguiente;
	}
	
	if(band == true){
		cout<<" Elemento "<<n<<" fue encontrado en la lista"<<endl;
	}
	else{
		cout<<"Elemento "<<n<<" no fue encontrado en lista"<<endl;
	}
}

void mostrarLista(Nodo*){
	Nodo *actual = new Nodo();
	actual = lista;


while (actual != NULL){
	cout<<actual->dato<<" -> ";
	actual = actual->siguiente;
     }
}

int main(){
	
	int opc, dato;
	
	do{
				cout<<"\t \t \t Menu del Proyecto Final"<<endl;
		
		cout<<"\n 1. Insertar elementos en la lista"<<endl;
		cout<<"\n 2. Mostrar elementos de la lista"<<endl;
		cout<<"\n 3. Buscar un elemento de la lista"<<endl;
		cout<<"\n 4. Salir"<<endl;
		cin>>opc;
		
		switch(opc){
			
			case 1: 
				cout<<"Se insertara un elemento en la lista entero "<<endl;
				dato = rand() %100;
				//cin>>dato; se metera un elemento randoms
				insertarLista(lista,dato);
				cout<<"\n";
				system("pause");
					break;
			
			case 2:
				mostrarLista(lista);
				cout<<"\n";
				system("pause");
					break;
			
			case 3:
				cout<<"Digite el numero que desea buscar"<<endl;
				cin>>dato;
				buscarLista(lista,dato);
				cout<<"\n";
				system("pause");
					break;
			
			defaulf:
				cout<<"Error"<<endl;
			} 
		
		system("cls");
	}while (opc !=4);
	
	
	return 0;
}

