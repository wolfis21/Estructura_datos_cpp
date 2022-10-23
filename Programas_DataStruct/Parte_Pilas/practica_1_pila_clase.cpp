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
 
/*  void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  */

 void menu(){
 	
 	   gotoxy(3,3);cout<<" IMPLEMENTACION DE PILAS EN C++\n\n";
    gotoxy(5,5);cout<<" 1. INGRESAR                                "<<endl;
    gotoxy(5,6);cout<<" 2. MOSTRAR o ELIMIMAR PARES	               "<<endl;
    gotoxy(5,7);cout<<" 3. N. INGRESO A LA PILA                    "<<endl;
    gotoxy(5,8);cout<<" 4. DESTRUIR PILA                         "<<endl;
    gotoxy(5,9);cout<<" 5. SALIR                                 "<<endl;
 
    gotoxy(4,12);cout<<" INGRESE OPCION: ";
 }
 
 void TextColor(int color)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}
 
 int main(){
 	
 	ptrPila p = NULL;  
	ptrPila a = NULL;// creando pila
    int dato;
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
 
                 cout<< "\n NUMERO A APILAR: \n"; 
                 dato = rand() %100; 
                 push( p, dato );
                 TextColor(12); //rojo
                        cout<<"\t------"<<endl;
            			cout<<"\t|null|"<<endl;
                 mostrar_pila( p );
				TextColor(9);
                 cout<<"\n\n\t\tNumero " << dato << " apilado...\n\n";
            break;
 
 
            case 2:

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
                
				cout<<"\n\n MOSTRANDO PILA SIN PARES\n\n";      
					a = pop2(p);
				if(a!=NULL){
					TextColor(12); 
					cout<<"\t----"<<endl;
            		cout<<"\t|null|"<<endl;	
				 	mostrar_pila(a);
				 	TextColor(9);
				 }else{
				 	cout<<"\n\n\tPila vacia..!"<<endl;
				 }	
					
               //implementar
            break;
                 
            case 3:
 				cout << "\n\n MOSTRANDO PILA\n\n";
                 if(p!=NULL){
                 	TextColor(12); 
                 	cout<<"\t----"<<endl;
            		cout<<"\t|null|"<<endl;	
				 	 x = mostrar_pila( p );
				 	TextColor(9);
				 }else{
				 	cout<<"\n\n\tPila vacia..!"<<endl;
				 }
                
                 cout<<"\n\n\t\tCantidad de ingresos: "<< x <<" en la pila...\n\n";
            break;
 
 
            case 4:
 
                 destruir_pila( p );
                 cout<<"\n\n\t\tPila eliminada...\n\n";
            break;
           
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=5);
   
 	
 	
 	
 	return 0;
 }
