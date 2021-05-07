#include <iostream>
using namespace std;

class nodoReservaReserva { 
	
   public:
    nodoReserva(int v, int cod, string t) 
    {
       identificacion = v;
       codhab = cod;
       tipo = t;
       siguiente = NULL;
    }

   // atributos
    int identificacion; // tipo entero. Ej clase estudiante nombre,dir,tel,siguente
    int codigo;
    string tipo;
    nodoReserva *siguiente; // tipo de la clase, clase autoreferencia. Direccion 


};
typedef nodoReserva *pnodoReserva; //alias redefinir los punteros

