#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class nodoPais {
   public:

    nodoPais(int num,string x){
    	codigoPais=num;
    	nombrePais=x;
    	Hizq=NULL;
    	Hder=NULL;
        derecha = NULL;
        hoteles = NULL;
        //izquierda=NULL;
    	
	}

    int codigoPais;
    string nombrePais;
    nodoPais *Hizq, *Hder;
    pnodoHotel hoteles;
    pnodoAgencia derecha;
    
};

typedef nodoPais *pnodoPais;

