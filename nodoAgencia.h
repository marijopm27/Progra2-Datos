#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/*
Descripcion: clase nodo Agencia que posee sus atributos, constructores 
*/
class nodoAgencia {
   public:
    nodoAgencia(int v,string x, long double z)
    {
       identificacion = v;
       nombreAgencia=x;
       cantidadVehiculos=z;
       Hizq = NULL;
       Hder=NULL;
       derecha=NULL;
    }
	
    int identificacion;
    string nombreAgencia;
    int cantidadVehiculos;
    nodoAgencia *Hizq;
    nodoAgencia *Hder;
    nodoTipoFlotilla *derecha;
    	   
};
typedef nodoAgencia *pnodoAgencia;
