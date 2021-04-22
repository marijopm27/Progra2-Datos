#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "nodoPais.h"
#include "arbolPais.h"

using namespace std;

arbolPais pais;


int main(){
	pais.leerArchivoPais();
	InordenR(pais.getRaizPais());
	return 0;
}
