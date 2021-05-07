#include <iostream>
using namespace std;

class nodoReservaA{
   public:
    nodoReservaA(int a, int b, int c,long double d, string e)
    {
        codPais=a;
    	identificacion=b;
		codigo=c;
		placa=d;
		nombreU=e;  
		siguiente; 
    }
	int codPais;
    int identificacion;
    int codigo;
	int placa;
	string nombreU;
	nodoReservaA *siguiente;
};
typedef nodoReservaA *pnodoReservaA;

class listaReservasA{
	public:
		listaReservasA(){
			Primero=NULL;
		}
		void InsertarFinal();
		void eliminar();
		void Mostrar();
		pnodoReservaA Primero;
};
