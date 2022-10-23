 /*  ESTRUCTURA DE DATOS
    AUTOR: ISAAC SAADO
    CEDULA: 27765209 
    FECHA: 11-10-22     */
    
#include <iostream>
#include "pilas_h.h"
#include <stdlib.h>
#include <time.h> 
#include <cstdlib>
#include<stdio.h>
#include <windows.h>
using namespace std;
 
	ptrPila p = NULL;
	ptrPila p2 = NULL;
 	ptrPila aux = NULL;
 void menu(){
 	
 	   gotoxy(3,3);cout<<" IMPLEMENTACION DE PILAS EN C++\n\n";
    gotoxy(5,5);cout<<" 1. INGRESAR ALEATORIO                       "<<endl;
    gotoxy(5,6);cout<<" 2. BUSCAR	              				 "<<endl;
    gotoxy(5,7);cout<<" 3. MOSTRAR	   p1           				 "<<endl; 
	gotoxy(5,8);cout<<" 4. MOSTRAR	   p2           				 "<<endl; //implementar ver la p2
    gotoxy(5,9);cout<<" 5. DESTRUIR PILA                         "<<endl;
    gotoxy(5,10);cout<<" 6. SALIR                                 "<<endl;
 
    gotoxy(4,12);cout<<" INGRESE OPCION: ";
 }
 
 void TextColor(int color)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}

void Proceso(){
	
	int busq;
	int val;
	bool validar= false;
	aux = p;
	cout<<"Ingrese el numero que quiere sacar de la pila: ";cin>>busq;
	        //de pila A  a pila B
			do{
				while( aux != NULL){

					val = pop (aux); // el valor que se saca de la pila se ingresa
					
					if(val != busq){
						push(p2, val); //  en la pila 2	
					}
					
					validar = true;

				}
			}while( validar == false );
	   
	   mostrar_pila( p2 );
	   p = p2; //asignamos a la principal los valores del p2
	  //destruir_pila( p2 ); // se destruye para liberar memoria
}
 
 int main(){
 	
    int dato, verif=0;
    int op;
    int x ; // numero que devuelve la funcion mostrar
   	srand(time(NULL));
//    system("color 0b");
 
    do
    {
    	TextColor(9); 
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 				
                	do{
                	dato = rand() %100;		
                	 cout<< "\n NUMERO A APILAR: \n"; 
                 	if(dato != verif){
                 		push( p, dato );
                 		TextColor(12); 
                        cout<<"\t------"<<endl;
            			cout<<"\t|null|"<<endl;
                 			mostrar_pila( p );
							TextColor(9);
                 		cout<<"\n\n\t\tNumero " << dato << " apilado...\n\n";
					 }
					 	verif = dato;	
				  
					}while(verif!=dato);
				
            break;
 
            case 2:
			//busqueda en pila
			Proceso();
            break;
                 
            case 3:
     			cout << "\n\n MOSTRANDO PILA\n\n";
                 if(p!=NULL){
                 	TextColor(12); 
				 	cout<<"\t----"<<endl;
            		cout<<"\t|null|"<<endl;	
				 	mostrar_pila( p );
				 	TextColor(9);
				 }else{
				 	cout<<"\n\n\tPila vacia..!"<<endl;
				 }
 				//mostrar pilas
 			break;
			case 4:
				cout << "\n\n MOSTRANDO PILA\n\n";
                 if(p2!=NULL){
                 	TextColor(12); 
				 	cout<<"\t----"<<endl;
            		cout<<"\t|null|"<<endl;	
				 	mostrar_pila( p2 );
				 	TextColor(9);
				 }else{
				 	cout<<"\n\n\tPila vacia..!"<<endl;
				 }
 				//mostrar pilas
 			break;

			          
           case 5: 
                 destruir_pila( p );
                 cout<<"\n\n\t\tPila eliminada...\n\n";
            break;
 
           
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=6);
   
 	
 	
 	
 	return 0;
 }
