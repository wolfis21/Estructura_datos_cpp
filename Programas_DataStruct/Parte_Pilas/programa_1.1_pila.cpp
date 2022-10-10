/*  ESTRUCTURA DE DATOS
    AUTOR: ISAAC SAADO
    CEDULA: 27765209 
    FECHA: 20-09-22     */

#include <iostream>
#include <stdio.h>
using namespace std;

struct nodo{
	char dato;
	nodo* siguiente;
} *primero;

void insertarNodo();
nodo* insertarN(nodo*&primero, char dato);
nodo* buscarNodoNum();
void desplegarPila(nodo*primero);

int main(){
	int opcion_menu=0, cantidad;
    nodo* aux1 =NULL;
    nodo* aux2 =NULL;
	do
	{
		cout << endl << "|-------------------------------------|";
		cout << endl << "|                 PILA            	   |";
		cout << endl << "|------------------|------------------|";
		cout << endl << "| 1. Insertar      |                  |";
		cout << endl << "| 2. hacer cambio  | 3. Desplegar     |";
		cout << endl << "|                  | 4. Salir         |";
		cout << endl << "|------------------|------------------|";
		cout << endl << endl << " Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu ){
			case 1:
				cout << endl << endl << " INSERTA NODO EN LA PILA " << endl << endl;
				insertarNodo();
				break;
			case 2:
				cout << endl << endl << " HACER CAMBIO EN LA PILA " << endl << endl;
				//cantidad = buscarNodoNum();
               // cout<<"La cantidad de numeros en la pila es: "<<cantidad<<endl;
				aux1 = buscarNodoNum();
                cout<<"la pila de puro numero es:"<<endl;
                desplegarPila(aux1);
                cout<<"la pila es:"<<endl;
                desplegarPila(primero);
                break;
			case 3:
				cout << endl << endl << " DESPLEGAR PILA DE NODOS " << endl << endl;
				desplegarPila(primero);
				break;

			case 4:
				cout << endl << endl << " Programa finalizado..." << endl << endl;
				break;
			default:
				cout << endl << endl << " Opcion No Valida " << endl << endl;
			}
	} while (opcion_menu != 4);
	return 0;
}

// primero = 9       actual =  4      nodoBuscado = 7    encontrado = true              4,7,8,9

//PILA  -     9 -> 8 -> 7 -> 4 -> null                       9   8  7  4

void insertarNodo(){
	nodo* nuevo = new nodo();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> nuevo->dato;
	nuevo->siguiente = primero;
	primero = nuevo;
	cout << endl << " Nodo Ingresado " << endl << endl;
}
nodo* insertarN(nodo*&primero, char dato){
	nodo* nuevo = new nodo();
    nuevo->dato = dato;
	nuevo->siguiente = primero;
    primero = nuevo;
	return nuevo;
//	cout << endl << " Nodo Ingresado " << endl << endl;
}
/* //esta funcion te muestra cuantos numeros hay en la pila 
    // y te dice cuales son
int buscarNodoNum(){
	nodo* actual = new nodo();
	actual = primero;
	char nodoBuscado;
    int contarNum=0;
	bool encontrado = false;
	//cout << " Ingrese el dato del Nodo a Buscar: ";
	//cin >> nodoBuscado;
	if(primero!=NULL){
		while(actual!=NULL){
                 if( actual->dato =='0' ||
					 actual->dato =='1' ||
					 actual->dato =='2' ||
					 actual->dato =='3' ||
					 actual->dato =='4' ||
					 actual->dato =='5' ||
					 actual->dato =='6' ||
					 actual->dato =='7' ||
					 actual->dato =='8' ||
					 actual->dato =='9' ){
				cout << endl << " Nodo con el tipo de number ( " << actual->dato << " ) Encontrado" << endl << endl;
				//encontrado = true;
                contarNum++;
			}
			
			actual = actual->siguiente;
		}
		if(encontrado==false){
			cout << endl << " Nodo no Encontrado" << endl << endl;
		}
	}else{
		cout << endl << " La Pila se encuentra vacia" << endl << endl;
	}
    return contarNum;
}
 */

 nodo* buscarNodoNum(){
	nodo* actual = new nodo();
    nodo* repet = NULL;
	actual = primero;
	char nodoBuscado;
	bool encontrado = false;
	//cout << " Ingrese el dato del Nodo a Buscar: ";
	//cin >> nodoBuscado;
	if(primero!=NULL){
		while(actual!=NULL){
                 if( actual->dato =='0' ||
					 actual->dato =='1' ||
					 actual->dato =='2' ||
					 actual->dato =='3' ||
					 actual->dato =='4' ||
					 actual->dato =='5' ||
					 actual->dato =='6' ||
					 actual->dato =='7' ||
					 actual->dato =='8' ||
					 actual->dato =='9' ){
                repet = insertarN(primero, actual->dato);                  
			}
			
			actual = actual->siguiente;
		}
		if(encontrado==false){
			cout << endl << " Nodo no Encontrado" << endl << endl;
		}
	}else{
		cout << endl << " La Pila se encuentra vacia" << endl << endl;
	}
   return repet;
}

void desplegarPila(nodo*primero){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		while(actual!=NULL){
			cout << endl << " " << actual->dato; 
			actual = actual->siguiente;
		}
	}else{
		cout << endl << " La Pila se encuentra vacia" << endl << endl;
	}
}







/*
	
*/




