
#include <iostream>
using namespace std;

class nodoLista {
   public:
    nodoLista(int v, string n)
    {
       valor = v;
       nombre = n;
       siguiente = NULL;
       anterior =NULL;
    }

   nodoLista(int v, nodoLista * signodo)
    {
       valor = v;
       siguiente = signodo;
    }
    int valor;
    string nombre;
    nodoLista*siguiente;
    nodoLista *anterior;

};
typedef nodoLista *pnodoLista;
