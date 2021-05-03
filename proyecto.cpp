#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "nodoTipoFlotilla.h"
#include "nodoAgencia.h"
#include "nodoHotel.h"
#include "nodoPais.h"


#include "arbolPais.h"
#include "arbolHotel.h"
#include "arbolAgencia.h"



using namespace std;

int main(){

	pais.leerArchivoPais();
	pais.InordenR(pais.getRaizPais());
	
	arbolAgencia agencia;
	arbolHotel hotel;
	hotel.lecturaHoteles();
	InordenHotel(pais.getRaizPais());
	cout<<endl;
	
	agencia.leerArchivoAgencias();
	//agencia.leerArchivoTipoFlotilla();
	InordenAgencia(pais.getRaizPais());
	
	return 0;
}
