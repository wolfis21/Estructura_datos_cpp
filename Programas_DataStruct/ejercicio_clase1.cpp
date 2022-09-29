/*  ESTRUCTURA DE DATOS
    AUTOR: ISAAC SAADO
    CEDULA: 27765209
    FECHA: 27-09-22     */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Productos {
	string nombre_p;
	int cant;
	float precio;
	int codigo;
	Productos *siguiente;
};

Productos *lista = NULL;

void llenar_ls(Productos *&lista) {
	Productos *nuevo = new Productos();
	Productos *aux1 = lista;
	Productos *aux2;

//variables para validar a futuro
//    string nombre_prod;
	//  int cantidad, cod;
	//float precio;
	cout<<"--------------------------------------"<<endl;
	// Registro de producto
	cout<<"\nIngrese nombre del producto: ";
	cin>>nuevo->nombre_p;
	cout<<"\nIngrese la cantidad existente: ";
	cin>>nuevo->cant;
	cout<<"\nIngrese el precio del producto: ";
	cin>>nuevo->precio;

	//valor de codigo aleatorio
	srand(time(NULL));
	int dato = rand() %999;
	//ingreso de codigo aleatorio
	nuevo->codigo=dato;

	while(aux1 != NULL) {
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}

	if (lista == aux1) {
		lista = nuevo;
	} else {
		aux2->siguiente = nuevo;
	}

	nuevo->siguiente = aux1;
}

void buscarLista(Productos *&lista, int n) {
	bool band = false;
	float tasa;
	Productos *actual = new Productos();
	actual = lista;

	while ((actual != NULL) && (actual->codigo <= n)) {
		if (actual->codigo == n) {
			band = true;
		}
		actual = actual->siguiente;
	}

	if(band == true) {
		cout<<" Elemento "<<n<<" fue encontrado en el inventario"<<endl;

		cout<<"\n------Planilla de Productos------\n"<<endl;
		cout<<"Codigo\tNombre_Producto\tCantidad\tPrecio en $\tPrecio en bs"<<endl;
		cout<<lista->codigo<<"\t";
		cout<<lista->nombre_p<<"\t\t";
		cout<<lista->cant<<"\t\t";
		cout<<lista->precio<<"\t\t\t";
		cout<<"\n--------------------------------------"<<endl;

		cout<<"\n\tTASA DE CAMBIO: ";
		cin>>tasa;

		if (tasa > 1) {
			cout<<"Codigo\tNombre_Producto\tCantidad\tPrecio en $\tPrecio en bs"<<endl;
			cout<<lista->codigo<<"\t";
			cout<<lista->nombre_p<<"\t\t";
			cout<<lista->cant<<"\t\t";
			cout<<lista->precio<<"\t\t\t";
			cout<<lista->precio*tasa<<"\t";

			cout<<"\n--------------------------------------"<<endl;
		}
	} else {
		cout<<"Elemento "<<n<<" no fue encontrado en el inventario"<<endl;
	}
}
void print(Productos *lista, float tasa) {

	cout<<lista->codigo<<"\t";
	cout<<lista->nombre_p<<"\t\t";
	cout<<lista->cant<<"\t\t";
	cout<<lista->precio<<"\t\t\t";
	if(tasa > 1) {
		cout<<lista->precio*tasa<<"\t";
	}
	cout<<"\n--------------------------------------"<<endl;

}

//funcion para imprimir toda la lista
void mostrarTodos(Productos *lista, float tasa) {
	Productos *actual=lista;
	cout<<"\n------Planilla de Productos------\n"<<endl;
	cout<<"Codigo\tNombre_Producto\tCantidad\tPrecio en $\tPrecio en bs"<<endl;
	while(actual!=NULL) {
		print(actual,tasa);
		actual=actual->siguiente;
	}
}

//funcion para verificar si la lista esta vacia
bool listaVacia(Productos *lista) {
	return(lista==NULL)? true:false;
}

//funcion para vaciar una lista completamente
void vaciar(Productos *&lista) {
	while(lista!=NULL) {
		Productos *aux=lista;
		lista=aux->siguiente;
		delete aux;
	}
}

void menu() {
	int opcion, codig;
	float tasa;

	do {
		cout<<"---------MENU---------";
		cout<<"\n1. Insertar Productos.";
		cout<<"\n2. Buscar por codigo. ";
		cout<<"\n3. Lista de productos enteros. ";
		cout<<"\n4. Salir.";
		cout<<"\nOpcion: ";
		cin>>opcion;

		switch(opcion) {
			case 1:
				llenar_ls(lista);
				system("pause");
				break;

			case 2:
				cout<<"Ingrese codigo para realizar la busqueda: ";
				cin>>codig;
				cout<<"\n";
				buscarLista(lista,codig);
				system("pause");
				break;

			case 3:
				if(listaVacia(lista)) {
					cout<<"\n\n\tNO EXISTE EL PRODUCTO. "<<endl;
				} else {
					mostrarTodos(lista,tasa=0);
					cout<<"\n\tTASA DE CAMBIO: ";
					cin>>tasa;
					mostrarTodos(lista,tasa);
				}
				system("pause");
				break;
			case 4:
				cout<<"\n\n\t...Hasta luego...\n";
				vaciar(lista);
				system("pause");
				break;
			default:
				cout<<"\nOpcion no valida. ";
				system("pause");
				break;
		}
		system("cls");
	} while(opcion!=4);
}
int main() {
	menu();
	return 0;
}