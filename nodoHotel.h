#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*
Descripcion: clase nodo Hotelque posee sus atributos, constructores 
*/
class nodoHotel {
   public:
    nodoHotel(int codhotel, string nombre, int cantestrellas)
    {
    	
       codigoh = codhotel;
       nombrehotel = nombre;
       estrellas = cantestrellas;
       izq = NULL;
       der =NULL;
       PisosHotel=NULL;
    }

  //Hotles
  	
    int codigoh;
    string nombrehotel;
    int estrellas;
    nodoHotel *izq;   
    nodoHotel *der;
    nodoPiso* PisosHotel;
   
};
typedef nodoHotel *pnodoHotel;
