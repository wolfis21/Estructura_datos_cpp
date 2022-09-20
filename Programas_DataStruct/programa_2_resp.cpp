/*  ESTRUCTURA DE DATOS
    AUTOR: ISAAC SAADO
    CEDULA: 27765209 
    FECHA: 20-09-22     */

#include <iostream>
#include <stdlib.h>
#include <time.h>  
#include <cstdlib>
#include <string>
using namespace std;

struct Nodo {
    int dato;
    Nodo * siguiente;
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
	
	cout<<"\n...Elemento insertado en la lista correctamente\n"<<endl;
} //insertar con ordenamiento de menor a mayor

int eliminarNodo(Nodo *&lista, int n){
    	int cantidad = 0;
        Nodo* a_eliminar;
        Nodo* aux = lista;
        
        while (aux != NULL) {
            if (lista->dato > n) {   //Condicion para saber si hay elementos mayores de n en la listas
                    a_eliminar = lista;
                    lista = lista->siguiente;
                    aux = lista;
                    delete a_eliminar;
                    cantidad++;
       }
       else {
           if (aux->siguiente != NULL && aux->siguiente->dato > n) { //Este es el caso en que el siguiente nodo se debe eliminar
                a_eliminar = aux->siguiente;
                aux->siguiente = a_eliminar->siguiente;
                delete a_eliminar;
                cantidad++;
           }
           else {  //El siguiente nodo no se debe eliminar
               aux = aux->siguiente;
           }
       }
   }
   return cantidad;
}

void mostrarLista(Nodo*){
	Nodo *actual = new Nodo();
	actual = lista;

if (lista != NULL){
	while (actual != NULL){
	cout<<actual->dato<<" -> ";
	actual = actual->siguiente;
     }
	}else{
			cout<<"La lista esta vacia"<<endl;
		} 
}

int main(){
	
	int opc, dato;
	srand(time(NULL));
	
	do{
				cout<<"\t \t \t Menu del Proyecto"<<endl;
		
		cout<<"\n 1. Insertar elementos en la lista"<<endl;
		cout<<"\n 2. Mostrar elementos de la lista"<<endl;
		cout<<"\n 3. Eliminar nodo de la lista"<<endl;
		cout<<"\n 4. Salir"<<endl;
		cin>>opc;
		
		switch(opc){
			
			case 1: 
				cout<<"\nSe insertara un elemento en la lista entero "<<endl;
				dato = rand() %100;
				insertarLista(lista,dato);
				cout<<"\n";
				system("pause");
					break;
			
			case 2:
				cout<<"\n\n";
				mostrarLista(lista);
				cout<<"\n";
				system("pause");
					break;
			
			case 3:
				cout<<"Digite el limite de la lista para eliminar"<<endl; cin>>dato;
				eliminarNodo(lista,dato);
				cout<<"\n";
				system("pause");
					break;

			case 4:
               cout<<"\n\n\t...Hasta luego...\n";
                system("pause");
                break;   
			
			default:
				cout<<"Error"<<endl;
				system("pause");
                break;
			} 
		
		system("cls");
	}while (opc !=4);
	
	
	return 0;
}
/* 
 función que suprima o borre de la lista
  /todos los elementos mayores de un número dado como límite, 
  con elementos aleatorios. ejemplo (20, 10, 15) da valor 15 entonces 
  la lista queda como (10,15)
 */