#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "nodoTipoFlotilla.h"
#include "nodoAgencia.h"
#include "nodoPais.h"
#include "arbolPais.h"
#include "arbolAgencia.h"
using namespace std;

int main(){
	pais.leerArchivoPais();
	arbolAgencia agencia;
	agencia.leerArchivoAgencias();
	agencia.leerArchivoTipoFlotilla();
	//InordenAgencia(pais.getRaizPais());
	
	return 0;
}
