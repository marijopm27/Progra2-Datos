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
        //derecha = NULL;
        //izquierda=NULL;
    	
	}

    int codigoPais;
    string nombrePais;
    nodoPais *Hizq, *Hder;
    //nodo hotel
    //nodo agencia
    
};

typedef nodoPais *pnodoPais;

