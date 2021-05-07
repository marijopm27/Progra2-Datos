#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class nodoCarro {
   public:
    nodoCarro(long double v,string x, int z, int a, int b, string c)
    {
       placa = v;
       modelo=x;
       numAsientos=z;
       ano=a;
       precioCarro=b;
       estadoCarro=c;
       hder=NULL;
       hizq=NULL;
    
    }

	long double placa;
	string modelo;
    int numAsientos;
    int ano;
    int precioCarro;
    string estadoCarro;
    int count, nivel;
	nodoCarro *hder;
    nodoCarro *hizq;
      
};
typedef nodoCarro *pnodoCarro;

