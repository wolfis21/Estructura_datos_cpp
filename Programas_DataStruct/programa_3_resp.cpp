/*  ESTRUCTURA DE DATOS
    AUTOR: ISAAC SAADO
    CEDULA: 27765209 
    FECHA: 26-09-22     */

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

void insertar_nodo(Nodo*&inicio, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = inicio;
	Nodo *aux2;
	
	while((aux1 != NULL ) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if (inicio == aux1){
		inicio = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
	
	cout<<"\n...Elemento insertado en la lista correctamente\n"<<endl;
} //con ordenamiento creciente


void mostrarLista(Nodo* lista){
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
	
	int opc,opc2, dato;
    div_t resp;
    Nodo* lista1 = NULL; //lista con numeros pares
    Nodo* lista2 = NULL; //lista con numeros impares
	srand(time(NULL));
	
	do{
				cout<<"\t \t \t Menu del Proyecto"<<endl;
		
		cout<<" 1. Insertar elementos en la listas"<<endl;
		cout<<" 2. Mostrar elementos de la lista con numeros pares"<<endl;
        cout<<" 3. Mostrar elementos de la lista con numeros impares"<<endl;
		cout<<" 4. Salir"<<endl;
		cin>>opc;
		
		switch(opc){
			
			case 1: 
				cout<<"\nSe insertara un elemento en la lista entero "<<endl;
				//dato = rand() %100; Opcional
                cout<<"\t 1. Insertar elementos en la lista 1"<<endl;
                cout<<"\t 2. Insertar elementos en la lista 2"<<endl;
				cin>>opc2;

                if(opc2 == 1 || opc2 == 2){
                    do{    
                    cout<<"Ingrese un numero mayor de 100: "<<endl;
                    cin>>dato;
                    if(dato >= 100){
                        if(dato % 2 == 0){
                        insertar_nodo(lista1,dato);
                        } else{
                        insertar_nodo(lista2,dato);    
                        } 
                    }
                  }while(dato<100);
                }
				cout<<"\n";
				system("pause");
					break;
			
			case 2:
				cout<<"\n\n";
				mostrarLista(lista1);
				cout<<"\n";
				system("pause");
					break;
		
        
			case 3:
				cout<<"\n\n";
				mostrarLista(lista2);
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
-Lea 2 listas de números enteros mayores de 100
En una colocar los pares y otra los impares

*/
