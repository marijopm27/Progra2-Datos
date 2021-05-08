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

    int valor;
    string nombre;
    nodoLista*siguiente;
    nodoLista *anterior;

};
typedef nodoLista *pnodoLista;
