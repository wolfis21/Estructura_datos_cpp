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
    string data;
    Nodo * siguiente;
};

Nodo* insertar_nodo(Nodo* inicio, string data){
    Nodo * nuevo = new Nodo;
    nuevo->data = data;
    nuevo->siguiente = inicio;
    return nuevo;
}


/* Recorre una lista a partir del puntero dado, buscando si la data pasada por parámetro se
encuentra en la lista. Retorna true si se encuentra, false si no. */
bool dataRepetida(Nodo* inicio, string dataBuscada){
   Nodo* aux = inicio;
   while(aux != NULL){
       if (aux->data == dataBuscada){
           return true;
       }
       aux = aux->siguiente;     
   }
   return false;
}

/* Dada una lista de data, genera una nueva que contenga solamente las datas repetidas.
Retorna el puntero inicial a la nueva lista. */
Nodo* generarListarepet(Nodo* inicio){
   Nodo* repet = NULL;
   for (Nodo* aux = inicio; aux != NULL; aux = aux->siguiente){
       if (dataRepetida(aux->siguiente, aux->data)){
           repet=insertar_nodo(repet, aux->data);
       }
   }
   return repet;
}

void deleteDuplicados(Nodo* inicio)
{
    if (inicio == NULL) {
        return;
    }

    Nodo* current = inicio;
 
    // compara el nodo actual con el siguiente nodo
    while (current->siguiente != NULL)
    {
        if (current->data == current->siguiente->data)
        {
            Nodo* proximo = current->siguiente->siguiente;
            free(current->siguiente);
            current->siguiente = proximo;
        }
        else {
            current = current->siguiente;    // solo avanza si no hay borrado
        }
    }
}


/* Imprime en pantalla todos los elementos de la lista. */
void imprimir(Nodo* inicio){
    
    if(inicio != NULL){
        for (Nodo* aux = inicio; aux != NULL; aux = aux->siguiente)
        cout << aux->data << " -> "; 
     }else{
			cout<<"La lista esta vacia"<<endl;
		}

}


int main()
 {
    Nodo* inicio = NULL;
    Nodo* repetidas = NULL;
    int opc;
    string dato;
    srand(time(NULL));
   	    
        /* ---------------- menu ------------- */
	do{
        
				cout<<"\t \t \t Menu del Proyecto"<<endl;
		
		cout<<"\n 1. Insertar elementos en la lista L"<<endl;
        cout<<"\n 2. Insertar elementos aleatorios en la lista L"<<endl;
		cout<<"\n 3. Mostrar elementos de la lista L"<<endl;
		cout<<"\n 4. Obtener la lista R"<<endl;
        cout<<"\n 5. Mostrar elementos de la lista R"<<endl;
		cout<<"\n 6. Salir\n\n"<<endl;
		cin>>opc;
		
        cout<<"\n\n--------------------------------\n";
		
		switch(opc){
			
			case 1: 
				cout<<"Ingrese elemento en la lista "<<endl;
				cin>>dato; 
				inicio = insertar_nodo(inicio,dato);
				cout<<"\n";
				system("pause");
					break;
			
            case 2: 
				cout<<"Se insertara un elemento en la lista aleatorio "<<endl;
				dato = rand() %100; 
				inicio = insertar_nodo(inicio,dato);
				system("pause");
                cout<<"Agregado con exito"<<endl;
                cout<<"\n";
				system("pause");
					break;
			
            case 3:
                cout<<"La lista L es: "<<endl;
				imprimir(inicio);
				cout<<"\n";
				system("pause");
					break;
			
			case 4:
				cout<<"La nueva lista R es: "<<endl;
                 repetidas = generarListarepet(inicio);
                 imprimir(repetidas);   
				cout<<"\n";
                deleteDuplicados(inicio);
				system("pause");
					break;
			
            case 5:
                cout<<"La lista R es: "<<endl;
				imprimir(repetidas);
				cout<<"\n";
				system("pause");
					break;
			
            case 6:
               cout<<"\n\n\t...Hasta luego...\n";
                system("pause");
                break;    

			default:
				cout<<"Error"<<endl;
                system("pause");
                break;
			} 
		
		system("cls");
	}while (opc !=6);
	
	
	return 0;

}

/* Programa con funcionalidad de dada una lista L devuelva otra lista R conteniendo
 los elementos repetidos de L. Si en L no hay elementos repetidos, 
R será la lista vacía ( con opción de el usuario ingresé valores o con valores aleatorio) */
