/*  ESTRUCTURA DE DATOS
    AUTOR: ISAAC SAADO
    CEDULA: 27765209 
    FECHA: 20-09-22     */

#include <iostream>
#include <stdio.h>
using namespace std;

struct nodo{
	char dato[20];
	nodo* siguiente;
} *primero;

void insertarNodo();
int buscarNodoNum();
void desplegarPila();

int main(){
	int opcion_menu=0, cantidad;
	do
	{
		cout << endl << "|-------------------------------------|";
		cout << endl << "|              � PILA �               |";
		cout << endl << "|------------------|------------------|";
		cout << endl << "| 1. Insertar      | 4. Eliminar      |";
		cout << endl << "| 2. Buscar        | 5. Desplegar     |";
		cout << endl << "| 3. Modificar     | 6. Salir         |";
		cout << endl << "|------------------|------------------|";
		cout << endl << endl << " Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu ){
			case 1:
				cout << endl << endl << " INSERTA NODO EN LA PILA " << endl << endl;
				insertarNodo();
				break;
			case 2:
				cout << endl << endl << " BUSCAR UN NODO EN LA PILA " << endl << endl;
				cantidad = buscarNodoNum();
                cout<<"La cantidad de numeros en la pila es: "<<cantidad<<endl;
				break;
			case 3:
				cout << endl << endl << " MODIFICAR UN NODO DE LA PILA " << endl << endl;
				break;
			case 4:
				cout << endl << endl << " ELIMINAR UN NODO DE LA PILA " << endl << endl;
				break;
			case 5: 
				cout << endl << endl << " DESPLEGAR PILA DE NODOS " << endl << endl;
				desplegarPila();
				break;
			case 6:
				cout << endl << endl << " Programa finalizado..." << endl << endl;
				break;
			default:
				cout << endl << endl << " Opcion No Valida " << endl << endl;
			}
	} while (opcion_menu != 6);
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

int buscarNodoNum(){
	nodo* actual = new nodo();
	actual = primero;
	char nodoBuscado[20];
    int contarNum=0;
	//bool encontrado = false;
/* 	cout << " Ingrese el dato del Nodo a Buscar: ";
	cin >> nodoBuscado; */
	if(primero!=NULL){
		do{
			for (int i=0; nodoBuscado[i]; i++){
				nodoBuscado[i] = actual->dato[i];
                //no esta listo no agarra bien el contenio ni condiciona bien 
/*                 if(nodoBuscado[i] =='0' ||
					 nodoBuscado[i] =='1' ||
					 nodoBuscado[i] =='2' ||
					 nodoBuscado[i] =='3' ||
					 nodoBuscado[i] =='4' ||
					 nodoBuscado[i] =='5' ||
					 nodoBuscado[i] =='6' ||
					 nodoBuscado[i] =='7' ||
					 nodoBuscado[i] =='8' ||
					 nodoBuscado[i] =='9' ){
                    cout << endl << " Nodo con el dato de tipo numero ( " << nodoBuscado[i] << " ) Encontrado" << endl << endl;
                    contarNum++;
                } */
                if(nodoBuscado[i] >'0' || nodoBuscado[i] <'9'){
                    cout << endl << " Nodo con el dato de tipo numero ( " << nodoBuscado[i] << " ) Encontrado" << endl << endl;
                    contarNum++;
                }
                
                actual = actual->siguiente;
               
            }
            
		}while(actual!=NULL);
	}
	return contarNum;
}

void desplegarPila(){
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




