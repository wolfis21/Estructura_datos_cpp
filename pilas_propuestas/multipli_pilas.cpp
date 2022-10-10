/* Mediante programación en C++, desarrollar un programa que permita ingresar un número para multiplicar una pila. */

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

#define lim 100
struct nodo
{
    int nro;
    struct nodo *sgte;
};
typedef struct nodo *pila;
void imprimir(pila);
void push(pila &, int);
void main()
{
    pila p = NULL;
    int i, n, k, y, v[lim];
    cout << "Numero que desea multiplicar a toda la pila:";
    cin >> k;
    cout << "limite:";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Elemento [" << (i + 1) << "]:";
        cin >> v[i];
        y = k * v[i];
        push(p, y);
    }
    cout << "La pila mutiplicada es:" << endl;
    imprimir(p);
    getch();
}
void imprimir(pila p)
{
    while (p != NULL)
    {
        cout << p->nro << endl;
        p = p->sgte;
    }
    cout << endl;
}
void push(pila &p, int n)
{
    pila q = new (struct nodo);
    q->nro = n;
    q->sgte = p;
    p = q;
}