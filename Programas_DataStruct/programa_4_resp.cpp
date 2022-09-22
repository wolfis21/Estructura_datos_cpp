/*  ESTRUCTURA DE DATOS
    AUTOR: ISAAC SAADO
    CEDULA: 27765209 
    FECHA: 26-09-22     */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <regex>
#include <map>
using namespace std;

struct Nodo{
    string cedula;
    string fecha;
    string cargo;
	Nodo *siguiente=NULL;
	Nodo *anterior=NULL;
};

Nodo *primero = NULL;
Nodo *ultimo =NULL;

bool validarCedula(string ced){
	//regex para validar que sea cedula numeros
	const regex expReg("(\\d{2}.\\d{3}.\\d{3})|(\\d{1}.\\d{3}.\\d{3})");
	return regex_match(ced, expReg);
}
bool validarFecha(string fec){
	//regex para validar que sea una fecha valida
	const regex expReg("(0[1-9]|[12][0-9]|3[01]{1,2})/(0[1-9]|[12]{1,2})/(19[0-9][0-9]|20[0-9][0-9])");
	return regex_match(fec, expReg);
}
bool buscardato(Nodo *&primero, string dato){
	Nodo *actual = new Nodo();
	actual=primero;
	bool encontrado = false;
	
	while(actual != NULL){
		if(dato==actual->cedula){
			encontrado=true;
		}
		actual=actual->siguiente;
	}	
	return(encontrado==true)? true:false;	
}

void llenar_lista(Nodo *&primero, Nodo *&ultimo){
    Nodo *nuevo_nodo = new Nodo(); // se construye el nodo
	string identificacion, fecha, cargo;
    int opc;
        // creacion de cedula
	cout<<"Ingrese identificacion del empleado en formato ###.###.###: ";
	cin>>identificacion;
	
    nuevo_nodo->cedula=identificacion;
	if (buscardato(primero, nuevo_nodo->cedula)||!validarCedula(identificacion)){	
		while(buscardato(primero, nuevo_nodo->cedula)||!validarCedula(identificacion)){
			cout<<"\nIdentificacion ya existe o no esta en formato ###.###.###: ";
			cin>>identificacion;
			nuevo_nodo->cedula=identificacion;
		}
	}
        //creacion de fecha
    cout<<"\n\nIngrese la fecha de nacimiento en formato dd/mm/yy: ";
	cin>>fecha;
	
    nuevo_nodo->fecha=fecha;
	if (!validarFecha(fecha)){	
		while(!validarFecha(fecha)){
			cout<<"\nNo esta en formato dd/mm/yy o no es fecha valida, vuelva a ingresar: ";
			cin>>fecha;
			nuevo_nodo->fecha=fecha;
		}
	}
        //seleccion de cargo
    do{
	cout<<"\n\nSeleccione el cargo que quiere tomar: "<<endl;
    cout<<"\t 1. Operador"<<endl;
    cout<<"\t 2. Analista"<<endl;
    cout<<"\t 3. Ejecutivo"<<endl;
    cin>>opc;

	map<int,string> seleccion; //uso de map variable de control de flujo
	
	seleccion[1] = "operador";
	seleccion[2] = "analista";
	seleccion[3] = "ejecutivo";
	
	if(seleccion.count(opc)){
		cargo = seleccion[opc];
		nuevo_nodo->cargo=cargo;		
	}else {
  		cout << "Error valor no valido" <<endl;
	}
	}while(!(opc >= 1 && opc <= 3));
/* 
        if(opc == 1){
            cargo = "operador";
        }else if(opc == 2){
            cargo = "analista";
        }else if(opc == 3){
            cargo = "ejecutivo";
        }    */
        //puede mejorar con un switch case o un map


	if(primero==NULL){
		primero = nuevo_nodo;
		primero->siguiente = NULL;
		primero->anterior = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo_nodo;
		nuevo_nodo->siguiente = NULL;
		nuevo_nodo->anterior = ultimo;
		ultimo = nuevo_nodo;
	}
}

//se crea esta funcion que imprime el nodo actual que se este solicitando en cada funcion
void print(Nodo *actual){
	cout<<"Cedula\t: "<<actual->cedula<<endl;
	cout<<"Fecha de Nacimiento\t: "<<actual->fecha<<endl;
	cout<<"Cargo\t: "<<actual->cargo<<endl;
	cout<<"--------------------------------------"<<endl;
}

//funcion para imprimir toda la lista
void mostrarTodos(Nodo *primero){
	Nodo *actual=primero;
	cout<<"\n------Planilla de Empleado------\n"<<endl;
	while(actual!=NULL){		
		print(actual);
		actual=actual->siguiente;
	}	
}

//funcion para buscar e imprimir empleados por cargo
bool buscar(Nodo *primero, string cargo){
	Nodo *actual=primero;
	bool encontrado=false;
	while(actual!=NULL){
		if(actual->cargo==cargo){
			encontrado=true;
			print(actual);
		}
		actual=actual->siguiente;
	}
	return(encontrado)? true:false;
}

//funcion para verificar si la lista esta vacia 
bool listaVacia(Nodo *primero){
	return(primero==NULL)? true:false;
}
//funcion para vaciar una lista completamente
void vaciar(Nodo *&primero){	
	while(primero!=NULL){
		Nodo *aux=primero;
		primero=aux->siguiente;
		delete aux;
	}	
}

string aMinuscula(string cadena) {
	for (int i = 0; i < cadena.length(); i++) {
		cadena[i] = tolower(cadena[i]);
	}
	return cadena;
}

void menu(){
	int opcion;
	string cargoBus;

		do{
		cout<<"---------MENU---------";
		cout<<"\n1. Insertar empleado.";
		cout<<"\n2. Buscar empleado por cargo. ";
		cout<<"\n3. Lista de empleados. ";
		cout<<"\n4. Salir.";
		cout<<"\nOpcion: ";
		cin>>opcion;	
	
		switch(opcion){
			case 1: 
				llenar_lista(primero,ultimo);								
					system("pause");
					break;

			case 2: 
				cout<<"Ingrese cargo para realizar la busqueda: ";
					cin>>cargoBus;
					cargoBus = aMinuscula(cargoBus);
					cout<<"\n";
					if(buscar(primero, cargoBus)==false){
						cout<<"\nEmpleado con cargo de: "<<cargoBus<<" No existe. "<<endl;
						cout<<"Recuerde los cargos son: Operador, Analista y Ejecutivo"<<endl;
					}
					system("pause");
					break;
					
			case 3: 
				if(listaVacia(primero)){
						cout<<"\n\n\tLa lista se encuentra vacia. "<<endl;				
					}else{
						mostrarTodos(primero);
					}
					system("pause");
					break;
			case 4: 
				cout<<"\n\n\t...Hasta luego...\n";
				vaciar(primero);
				system("pause");
				break;
			default: cout<<"\nOpcion no valida. ";	
					system("pause");
					break;	
		}
		system("cls");
	}while(opcion!=4);
}

int main(){
	menu();
	return 0;
}
/* 
programa que llena una lista con la siguiente información cédula, fecha de nacimiento, cargo.
En ella buscar todas las personas que tenga algunos de los cargos ingresados, los cargos son:
 operador, analista, ejecutivo. Si se ingresa otro cargo error.

 */