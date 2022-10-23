#ifndef pilas_h
#define pilas_h
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <cstdlib>
#include<stdio.h>
#include <windows.h>
using namespace std;

 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 

struct nodo{
    int nro;
    struct nodo *sgte;
};
 
typedef nodo *ptrPila;   // creando nodo tipo puntero( tipo de dato )
 
 /*                        Apilar elemento      
------------------------------------------------------------------------*/
ptrPila push( ptrPila &p, int valor )
{
     ptrPila aux;
     aux = new(struct nodo);  // apuntamos al nuevo nodo creado
     aux->nro = valor;
     
     aux->sgte = p ;
     p = aux ;
}
 
/*                Desapilar elemento(devuelve elemento)      
------------------------------------------------------------------------*/
int pop( ptrPila &p )
{
     int num ;
     ptrPila aux;
     
     aux = p ;
     num = aux->nro;   // asignamos el primer vamor de la pila
     
     p = aux->sgte ;
     delete(aux);
     
     return num;
}
/*----------------------------Buscar elemento de pila y sacarlo ----- */
void busq_sacar(ptrPila &p, int valor){
	
     ptrPila aux;
     
     while( p != NULL)
     {
     	if(valor == aux->nro){
     	 	aux = p;
           	delete(aux);
			p = aux->sgte;
        	
		 }
          p = aux->sgte;
     }
}
/* ------------------------ retorno de cambio de pila A a B*/
ptrPila pop2( ptrPila &p )
{
     ptrPila repet1 = NULL;
	  
   for (ptrPila aux = p; aux != NULL; aux = aux->sgte){
   		if( ((aux->nro %2) == 0)){
   			push(repet1, aux->nro);	
		   }
   }
    return repet1;
}
 
/*                     Muestra elementos de la pila      
------------------------------------------------------------------------*/
int mostrar_pila( ptrPila p )
{
     ptrPila aux;
     aux = p;     // apunta al inicio de la lista
   	int cont = 0;  
     while( aux !=NULL )
     {
            cout<<"\t------"<<endl;
            cout<<"\t| "<< aux->nro<<" |"<<endl;
            cout<<"\t------"<<endl;
            aux = aux->sgte;
            cont++;
     }    
     return cont; //returna los elementos que hay en la pila
}
 
/*                Eliminar todos los elementos de la pila      
------------------------------------------------------------------------*/
void destruir_pila( ptrPila &p)
{
     ptrPila aux;
     
     while( p != NULL)
     {
           aux = p;
           p = aux->sgte;
           delete(aux);
     }
}


#endif
