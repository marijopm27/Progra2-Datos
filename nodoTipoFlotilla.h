#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/*
Descripcion: clase nodo PisosHotel que posee sus atributos, constructores 
*/

class nodoTipoFlotilla {
   public:
    nodoTipoFlotilla(int v,string x,int z)
    {
       codTipo = v;
       nombre=x;
       cantidadTipoCarros=z;
       Hizq =NULL;
       Hder=NULL;
       FB=0;
       derecha=NULL;
    }

	int FB;
    int codTipo;
    string nombre;
    int cantidadTipoCarros;
    nodoTipoFlotilla *Hizq;
    nodoTipoFlotilla *Hder;
    nodoCarro *derecha;
       
   
};
typedef nodoTipoFlotilla *pnodoTipoFlotilla;
