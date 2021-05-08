#include <fstream>
#include <sstream>

using namespace std;

class arbolAgencia{//Arbol BB
	public:
		arbolAgencia(){
			raizAgencia=NULL;
		}
		
		//Archivos e inserciones de Agencias
		void leerArchivoAgencias();
		void verificarInsertarAgencia(pnodoPais R,int codPais, int identificacion, string nomAgencia, int canVehiculos);
		void InsertaBinarioAgencia(pnodoAgencia nodoA,int identificacion, string nomAgencia, int canVehiculos);
		pnodoAgencia getRaizAgencia();
		void consultarAgencias(pnodoPais R, int codPais, int i);
		void mostrarCantidadCarrosAgencia(pnodoAgencia R,int identificacion);
		void consultarCantidadCarros(pnodoPais R,int codPais, int identificacion);
		void mostrarAgencias(pnodoAgencia R);
		void modificarCantidadCarrosA(pnodoPais R, int codPais , int identificacion, int cantidad);
		void modificarCantidadCarrosAux(pnodoAgencia R, int identificaion, int cantidad);
		void modificarNombreAgencia(pnodoPais R, int codPais, int identificacion, string nombre);
		void modificarNombreAgenciaAux(pnodoAgencia R, int identificacion, string nombre);
		void uAgencia();
		bool existeCarrosDatos(pnodoPais R, int codPais, int identificacion, int codTipo, long double placa);
		bool existeCarrosDatosA(pnodoAgencia R, int identificacion, int codTipo, long double placa);
		bool existeCarrosDatosT(pnodoTipoFlotilla R, int codTipo, long double placa);
		bool existeCarrosDatosC(pnodoCarro R, long double placa );
		bool agenciaenPais(pnodoPais R, int codPais, int identificacion);
		bool agenciaenPaisA(pnodoAgencia R,  int identificacion);
		
		//Archivos e inserciones de Flotilla
		void leerArchivoTipoFlotilla();
		void verificarInsertarTipoFlotilla(pnodoPais nodoP,int codPais, int identificacion,int codTipo, string nombreTipo, int cantCarrosTipo);
		void insertarBalanceadoTipoFlotilla(pnodoTipoFlotilla &ra,bool Hh,int codTipo, string nombreTipo, int cantCarrosTipo);
		void verificarAgenciasTipoFlotilla(pnodoAgencia R,int identificacion,int codTipo, string nombreTipo, int cantCarrosTipo);
		void modificarDatosFlotilla(pnodoPais R,int codPais,int identificacion,int codTipo, int modificar);
		void modificarDatosFlotillaA(pnodoAgencia R,int identificacion,int codTipo, int modificar);
		void modificarDatosFlotillaF(pnodoTipoFlotilla R,int codTipo, int modificar);
		//consultas 
		void consultarTipoFlotillas(pnodoPais R, int codPais, int identificacion, int i);
		void consultarTipoFlotillaAgencias(pnodoAgencia R, int identificacion);
		void mostrarFlotillas(pnodoTipoFlotilla R);
		void uTipoFlotilla();
		
		//Rotaciones AVL de Flotillas
		void RotacionDobleDerecha(pnodoTipoFlotilla n, pnodoTipoFlotilla n1);
		void RotacionSimpleDerecha(pnodoTipoFlotilla n, pnodoTipoFlotilla n1);
		void RotacionDobleIzquierda(pnodoTipoFlotilla n, pnodoTipoFlotilla n1);
		void RotacionSimpleIzquierda(pnodoTipoFlotilla n, pnodoTipoFlotilla n1);
		
		//Archivos e inseciones de Carros
		void leerArchivoCarros();
		void verificarInsertarCarroPais(pnodoPais nodoP,int codPais, int identificacion,int codTipo, long double placa, string modelo, int numAsientos, int ano, int precioCarro, string estadoCarro);
		void verificarInsertarCarroAgencia(pnodoAgencia nodoP,int identificacion,int codTipo, long double placa, string modelo, int numAsientos, int ano, int precioCarro, string estadoCarro);
		void verificarInsertarCarroTipoFlotillas(pnodoTipoFlotilla nodoP,int codTipo, long double placa, string modelo, int numAsientos, int ano, int precioCarro, string estadoCarro);
		void verPlacaRepetida(pnodoTipoFlotilla R, long double placa, string modelo, int numAsientos, int ano, int precioCarro, string estadoCarro);
		//Insercion arbol AA de Carros
		pnodoCarro insertarAA(pnodoCarro &raizP, long double placa, string modelo, int numAsientos, int ano, int precioCarro, string estadoCarro);
    	pnodoCarro Giro(pnodoCarro &nodoP);
    	pnodoCarro Reparto(pnodoCarro &nodoP);
    	pnodoCarro insertarBalanceado(int num);
    	//consultas de Carros
    	void modificacionConsultasCarro(pnodoPais R, int codPais,int identificacion,int codTipo, long double placa,int modificar);
    	void modificacionConsultasCarroA(pnodoAgencia R,int identificacion,int codTipo, long double placa,int modificar);
    	void modificacionConsultasCarroT(pnodoTipoFlotilla R,int codTipo, long double placa,int modificar);
    	void modificacionConsultasCarroC(pnodoCarro R, long double placa,int modificar);
    	void consultarCarros(pnodoPais R,int codPais,int identificacion,int codTipo, long double placa,int i);
    	int verificarPlacaGlobal(pnodoPais R, long double placa);
    	int verificarPlacaGlobalA(pnodoAgencia R, long double placa);
    	int verificarPlacaGlobalT(pnodoTipoFlotilla R, long double placa);
    	int verificarPlacaGlobalC(pnodoCarro R, long double placa);
    	void uCarro();
    	
    	pnodoAgencia ultimoAgencia;
    	pnodoTipoFlotilla ultimoTipoFlotilla;
    	pnodoCarro ultimoCarro;
    	
	private:
		pnodoAgencia raizAgencia;
	
};

void arbolAgencia::leerArchivoAgencias(){
	ifstream archivo;
	string delimitador=";";
	string nomArch="Agencias.txt";
	archivo.open(nomArch.c_str(),ios::in); //Abrimos el archivo en modo lectura
	
	string texto;
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);//obtener la linea
		string identificacion="", nomAgencia="",canVehiculos="",codPais="";
		int posicion=0;
		for(int i=0;i<texto.size();i++){
			if(texto[i]!=';'){
				if(posicion==0){
					codPais+=texto[i];			
				}
				else if(posicion==1){
					identificacion+=texto[i];			
				}
				else if(posicion==2){
					nomAgencia+=texto[i];
				}
				else{
					canVehiculos+=texto[i];
				}	
			}else{
				posicion++;
			}
			
		}
		int codigo=atoi(codPais.c_str());//pasar de string a entero;
		int iden=atoi(identificacion.c_str());//pasar de string a entero;
		int cantidad=atoi(canVehiculos.c_str());//pasar de string a entero;
		verificarInsertarAgencia(pais.getRaizPais(),codigo,iden,nomAgencia,cantidad);		
	}
	archivo.close();
}	

//Revisar si existe al pais para hacer la inserccion
void arbolAgencia::verificarInsertarAgencia(pnodoPais R,int codPais, int identificacion, string nomAgencia, int canVehiculos){
	if(R==NULL){
		return;
	}
	else{
        if (R->codigoPais==codPais){
			if(R->derecha==NULL){//en caso de ser la primera insercion
        		R->derecha=new nodoAgencia(identificacion,nomAgencia,canVehiculos);
        		ultimoAgencia=R->derecha;
    		}
    		else{
    			InsertaBinarioAgencia(R->derecha, identificacion,nomAgencia,canVehiculos);
    		
			}
		}
        verificarInsertarAgencia(R->Hizq,codPais,identificacion,nomAgencia,canVehiculos);
        verificarInsertarAgencia(R->Hder,codPais,identificacion,nomAgencia,canVehiculos);
    }
}

//Hacer la inserccion en el arbol BB de las ageencias, pegado a paises
void arbolAgencia::InsertaBinarioAgencia(pnodoAgencia nodoA,int identificacion, string nomAgencia, int canVehiculos){
	if(identificacion<nodoA->identificacion){//insetar izquierda
        if(nodoA->Hizq==NULL){
            nodoA->Hizq = new nodoAgencia(identificacion,nomAgencia,canVehiculos);
            ultimoAgencia=nodoA->Hizq;
        }else{
            InsertaBinarioAgencia(nodoA->Hizq,identificacion,nomAgencia,canVehiculos);
        }
    }else if (identificacion>nodoA->identificacion){//insertar derecha
        if(nodoA->Hder==NULL){
            nodoA->Hder = new nodoAgencia(identificacion,nomAgencia,canVehiculos);
            ultimoAgencia=nodoA->Hder;
        }else{
            InsertaBinarioAgencia(nodoA->Hder,identificacion,nomAgencia,canVehiculos);
        }
    }
}

void arbolAgencia::consultarAgencias(pnodoPais R, int codPais, int i){
	if( i==1){
		cout<<"Identificacion          Nombre          CantidadVehiculos"<<endl;
	}
	if(R==NULL){
   
        return;
    }
	if(R->codigoPais==codPais){
		mostrarAgencias(R->derecha);
		return;
	}
	consultarAgencias(R->Hizq,codPais,0);
	consultarAgencias(R->Hder,codPais,0);
}

//ultima insercion
void arbolAgencia::uAgencia(){
	cout<<"La ultima agencia insertada fue:"<<endl;
	cout<<"Identificacion: "<<ultimoAgencia->identificacion<<"  "<<"EL nombre de la agencia es: "<<ultimoAgencia->nombreAgencia<<endl;
}

//auxiliar de Consultar agencias
void arbolAgencia::mostrarAgencias(pnodoAgencia R){
	if(R==NULL){
        return;
    }
    mostrarAgencias(R->Hizq);
    int cantEspacios=20;
    cout <<R->identificacion<<string(cantEspacios,' ')<<R->nombreAgencia<<string(cantEspacios,' ')<<R->cantidadVehiculos<<endl;
    mostrarAgencias(R->Hder);
}

void arbolAgencia::consultarCantidadCarros(pnodoPais R,int codPais, int identificacion){
	if(R==NULL){
        return;
    }
	if(R->codigoPais==codPais){
		mostrarCantidadCarrosAgencia(R->derecha, identificacion);
		return;
	}
	consultarCantidadCarros(R->Hizq,codPais,identificacion);
	consultarCantidadCarros(R->Hder,codPais,identificacion);
}

void arbolAgencia::mostrarCantidadCarrosAgencia(pnodoAgencia R,int identificacion){
	if(R==NULL){
        return;
    }
	if(R->identificacion==identificacion){
		cout<<endl;
		cout<<"La cantidad de vehiculos es:"<<R->cantidadVehiculos<<endl;
		return;
	}
	mostrarCantidadCarrosAgencia(R->Hizq,identificacion);
	mostrarCantidadCarrosAgencia(R->Hder,identificacion);
}

void arbolAgencia::modificarCantidadCarrosA(pnodoPais R, int codPais, int identificacion, int cantidad){
	if(R==NULL){
   		return;
    }
    if(R->codigoPais==codPais){
		modificarCantidadCarrosAux(R->derecha, identificacion, cantidad);
		return;
	}
	modificarCantidadCarrosA(R->Hizq,codPais,identificacion, cantidad);
	modificarCantidadCarrosA(R->Hder,codPais,identificacion,cantidad);
}

void arbolAgencia::modificarCantidadCarrosAux(pnodoAgencia R, int identificacion, int cantidad){
	if(R==NULL){
		return;
	}
	if(R->identificacion==identificacion){
		R->cantidadVehiculos=cantidad;
		return;
	}
	modificarCantidadCarrosAux(R->Hizq,identificacion, cantidad);
	modificarCantidadCarrosAux(R->Hder,identificacion, cantidad);
}

void arbolAgencia::modificarNombreAgencia(pnodoPais R, int codPais, int identificacion, string nombre){
	if(R==NULL){
   		return;
    }
    if(R->codigoPais==codPais){
		modificarNombreAgenciaAux(R->derecha, identificacion, nombre);
		return;
	}
	modificarNombreAgencia(R->Hizq,codPais,identificacion, nombre);
	modificarNombreAgencia(R->Hder,codPais,identificacion,nombre);
}

void arbolAgencia::modificarNombreAgenciaAux(pnodoAgencia R, int identificacion, string nombre){
	if(R==NULL){
		return;
	}
	if(R->identificacion==identificacion){
		R->nombreAgencia=nombre;
		return;
	}
	modificarNombreAgenciaAux(R->Hizq,identificacion, nombre);
	modificarNombreAgenciaAux(R->Hder,identificacion, nombre);
}

bool arbolAgencia::agenciaenPais(pnodoPais R, int codPais, int identificacion){
	int r=0;
	if(R==NULL){
		return r;
	}
	if(codPais<R->codigoPais){
		r=agenciaenPais(R->Hizq, codPais, identificacion);
	}
	if(codPais>R->codigoPais){
		r=agenciaenPais(R->Hder, codPais, identificacion);
	}
    else if(codPais==R->codigoPais){
    	if(agenciaenPaisA(R->derecha, identificacion)){
    		r=1;
		}
	}
	return r;
}

bool arbolAgencia::agenciaenPaisA(pnodoAgencia R,  int identificacion){
	int r=0;
	if(R==NULL){
		return r;
	}
	if(identificacion<R->identificacion){
		r=agenciaenPaisA(R->Hizq, identificacion);
	}
	if(identificacion>R->identificacion){
		r=agenciaenPaisA(R->Hder,  identificacion);
	}
    else if(identificacion==R->identificacion){
    	r=1;
	}
	return r;
}


//-------------------------------------------------------------------------------------------------------------------------------------------

void arbolAgencia::leerArchivoTipoFlotilla(){
	ifstream archivo;
	string delimitador=";";
	string nomArch="TipoFlotilla.txt";
	archivo.open(nomArch.c_str(),ios::in); //Abrimos el archivo en modo lectura
	
	string texto;
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);//obtener la linea
		string identificacion="", nombreTipo="",canVehiculosTipo="",codPais="", codTipo="";
		int posicion=0;
		for(int i=0;i<texto.size();i++){
			if(texto[i]!=';'){
				if(posicion==0){
					codPais+=texto[i];			
				}
				else if(posicion==1){
					identificacion+=texto[i];			
				}
				else if(posicion==2){
					codTipo+=texto[i];
				}
				else if(posicion==3){
					nombreTipo+=texto[i];
				}
				else{
					canVehiculosTipo+=texto[i];
				}	
			}else{
				posicion++;
			}
			
		}
		int codigoP=atoi(codPais.c_str());//pasar de string a entero;
		int codigoT=atoi(codTipo.c_str());
		int iden=atoi(identificacion.c_str());//pasar de string a entero;
		int cantidad=atoi(canVehiculosTipo.c_str());//pasar de string a entero;
		//cout<<codigoT<<" "<<nombreTipo<<" "<<cantidad<<endl;
		verificarInsertarTipoFlotilla(pais.getRaizPais(),codigoP,iden,codigoT,nombreTipo, cantidad);		
	}
	archivo.close();
}

//encontrar el pais al cual se debe insertar la flotilla
void arbolAgencia::verificarInsertarTipoFlotilla(pnodoPais R, int codPais, int identificacion,int codTipo, string nombreTipo, int cantCarrosTipo){
	if(R==NULL){
		return;
	}
	else{
        if (R->codigoPais==codPais){
    		verificarAgenciasTipoFlotilla(R->derecha,identificacion,codTipo, nombreTipo, cantCarrosTipo);
		}
        verificarInsertarTipoFlotilla(R->Hizq,codPais,identificacion,codTipo, nombreTipo, cantCarrosTipo);
        verificarInsertarTipoFlotilla(R->Hder,codPais,identificacion,codTipo, nombreTipo, cantCarrosTipo);
    }
}

//encontrar la agencia para insertar la flotilla
void arbolAgencia::verificarAgenciasTipoFlotilla(pnodoAgencia R,int identificacion,int codTipo, string nombreTipo, int cantCarrosTipo){
	if(R==NULL){
		return;
	}
	else{//encontrar con la identificacion de la agencia
        if (R->identificacion==identificacion){
    		insertarBalanceadoTipoFlotilla(R->derecha,false, codTipo, nombreTipo, cantCarrosTipo);	
		}
        verificarAgenciasTipoFlotilla(R->Hizq,identificacion,codTipo, nombreTipo, cantCarrosTipo);
        verificarAgenciasTipoFlotilla(R->Hder,identificacion,codTipo, nombreTipo, cantCarrosTipo);
    }
}

//Insertar en el arbol AVL de Flotilla, una vez encontrado el pais y la agencias
void arbolAgencia::insertarBalanceadoTipoFlotilla(pnodoTipoFlotilla &ra,bool Hh,int codTipo, string nombreTipo, int cantCarrosTipo){
	pnodoTipoFlotilla n1;
    
    if(ra==NULL){
    	
        ra=new nodoTipoFlotilla(codTipo, nombreTipo, cantCarrosTipo);
        ultimoTipoFlotilla=ra;
        Hh = true;
    }else{
        ra->codTipo;
        if(codTipo<ra->codTipo){
        	
            insertarBalanceadoTipoFlotilla(ra->Hizq, Hh, codTipo,nombreTipo,cantCarrosTipo);
			
		if(Hh){
            switch(ra->codTipo){
                case 1: ra->FB=0;
                Hh = false;
                break;
                case 0: ra->FB  = -1;
                break;
                case -1: n1=ra->Hizq;
                if(n1->FB =-1){
                    RotacionSimpleIzquierda(ra, n1);
                }else{
                    RotacionDobleIzquierda(ra,n1);
                }
                Hh = false;
                break;
            }
        }
 
        }else{
            if(codTipo>ra->codTipo){
				insertarBalanceadoTipoFlotilla(ra->Hder, Hh, codTipo,nombreTipo,cantCarrosTipo);
				
            if(Hh){
                    switch(ra->FB){
                        case -1: ra->FB=0;
                        Hh = false;
                        break;
                        case 0: ra->FB=1;
                        break;
                        case 1:n1=ra->Hder;
                        if(n1->FB=1){
                           RotacionSimpleDerecha(ra, n1);
                           
                        }else{
                            RotacionDobleDerecha(ra, n1);
                        }
                        Hh=false;
                        break;
                    }
                }

            }
        }
    }
}

//Rotaciones del Arbol ALV de Flotilla
void arbolAgencia::RotacionDobleDerecha(pnodoTipoFlotilla n, pnodoTipoFlotilla n1){
    pnodoTipoFlotilla n2;
    n2=n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq=n;
    n1->Hizq=n2->Hder;
    n2->Hder=n1;

    if(n2->FB==1){
        n->FB=-1;
    }else{
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void arbolAgencia::RotacionSimpleDerecha(pnodoTipoFlotilla n, pnodoTipoFlotilla n1){
    n->Hder=n1->Hizq;
    n1->Hizq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
}

void arbolAgencia::RotacionDobleIzquierda(pnodoTipoFlotilla n, pnodoTipoFlotilla n1){
    pnodoTipoFlotilla n2;
    n2=n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder=n;
    n1->Hder=n2->Hizq;
    n2->Hizq=n1;

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void arbolAgencia::RotacionSimpleIzquierda(pnodoTipoFlotilla n, pnodoTipoFlotilla n1){
    n->Hizq=n1->Hder;
    n1->Hder=n;

    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    n=n1;
}

void arbolAgencia::modificarDatosFlotilla(pnodoPais R,int codPais,int identificacion,int codTipo, int modificar){//encontrar pais
	if(R==NULL){
   		return;
    }
    if(R->codigoPais==codPais){
		modificarDatosFlotillaA(R->derecha, identificacion,codTipo,modificar);
		return;
	}
	modificarDatosFlotilla(R->Hizq,codPais,identificacion, codTipo,modificar);
	modificarDatosFlotilla(R->Hder,codPais,identificacion,codTipo,modificar);
}

void arbolAgencia::modificarDatosFlotillaA(pnodoAgencia R,int identificacion,int codTipo, int modificar){//encontrar agencia
	if(R==NULL){
		return;
	}
	if(R->identificacion==identificacion){
		modificarDatosFlotillaF(R->derecha,codTipo,modificar);//encontrar Flotilla
	}
	modificarDatosFlotillaA(R->Hizq,identificacion, codTipo,modificar);
	modificarDatosFlotillaA(R->Hder,identificacion, codTipo,modificar);
}

void arbolAgencia::modificarDatosFlotillaF(pnodoTipoFlotilla R,int codTipo, int modificar){
	if(R==NULL){
		return;
	}
	if(R->codTipo==codTipo){
		if (modificar==1){
			cout<<"El nuevo nombre del Tipo FLotilla: "<<endl;
			string nombre;
			getline(cin,nombre);
			R->nombre=nombre;
		}else{
			cout<<"El nueva cantidad de carros: "<<endl;
			int cantidad;
			cin>>cantidad;
			R->cantidadTipoCarros=cantidad;
		}
	}
	modificarDatosFlotillaF(R->Hizq,codTipo,modificar);
	modificarDatosFlotillaF(R->Hder,codTipo,modificar);
}

void arbolAgencia::consultarTipoFlotillas(pnodoPais R, int codPais, int identificacion, int i){
	if(R==NULL){
        return;
    }
	if(R->codigoPais==codPais){
		consultarTipoFlotillaAgencias(R->derecha, identificacion);
		return;
	}
	consultarTipoFlotillas(R->Hizq,codPais,identificacion,0);
	consultarTipoFlotillas(R->Hder,codPais,identificacion,0);
}

void arbolAgencia::consultarTipoFlotillaAgencias(pnodoAgencia R, int identificacion){
	if(R==NULL){
        return;
    }
	if(R->identificacion==identificacion){
		mostrarFlotillas(R->derecha);
		return;
	}
	consultarTipoFlotillaAgencias(R->Hizq,identificacion);
	consultarTipoFlotillaAgencias(R->Hder,identificacion);
}

void arbolAgencia::mostrarFlotillas(pnodoTipoFlotilla R){
	if(R==NULL){
        return;
    }
    mostrarFlotillas(R->Hizq);
    cout<<"Codigo: "<<R->codTipo<<"        Nombre: "<<R->nombre<<"        CantidadVehiculos: "<<R->cantidadTipoCarros<<endl;
    mostrarFlotillas(R->Hder);
}

void arbolAgencia::uTipoFlotilla(){
	cout<<"El ultimo Tipo Flotilla insertado fue:"<<endl;
	cout<<"EL codigo es: "<<ultimoTipoFlotilla->codTipo<<"  "<<"El nombre del Tipo Flotilla es: "<<ultimoTipoFlotilla->nombre<<endl;
}
//-----------------------------------------------------------------------------------------------------------------------
//Arbol AA de Agencia

void arbolAgencia::leerArchivoCarros(){
	ifstream archivo;
	string delimitador=";";
	string nomArch="Carros.txt";
	archivo.open(nomArch.c_str(),ios::in); //Abrimos el archivo en modo lectura	
	string texto;
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);//obtener la linea
		string codPais="", identificacion="", codTipo="",numPlaca="", modelo="", numAsientos="", ano="", precioCarro="", estadoCarro="";
		int posicion=0;
		for(int i=0;i<texto.size();i++){
			if(texto[i]!=';'){
				if(posicion==0){
					codPais+=texto[i];	
				}	
				else if (posicion==1){
					identificacion+=texto[i];			
				}
				else if(posicion==2){
					codTipo+=texto[i];
				}
				else if(posicion==3){
					numPlaca+=texto[i];
				}
				else if(posicion==4){
					modelo+=texto[i];
				}
				else if(posicion==5){
					numAsientos+=texto[i];
				}
				else if(posicion==6){
					ano+=texto[i];
				}
				else if(posicion==7){
					precioCarro+=texto[i];
				}
				else{
					estadoCarro+=texto[i];
				}	
			}else{
				posicion++;
			}
		}
		//verificarInsertarCarros(identificacion, codTipo ,placa, modelo, numAsientos,ano,precioCarro, estadoCarro);	
		int codigoP=atoi(codPais.c_str());//pasar de string a entero;
		int codigoT=atoi(codTipo.c_str());
		int iden=atoi(identificacion.c_str());//pasar de string a entero;
		long double placa=atoi(numPlaca.c_str());//pasar de string a entero;
		int numA=atoi(numAsientos.c_str());
		int anoA=atoi(ano.c_str());
		int precio=atoi(precioCarro.c_str());
		//cout<<codigoP<<identificacion<<" "<<codigoT<<" "<<placa<<" "<<modelo<<" "<<numAsientos<<" "<<ano<<precioCarro<<" "<<estadoCarro<<endl;
		
		verificarInsertarCarroPais(pais.getRaizPais(),codigoP,iden, codigoT,placa, modelo, numA,anoA, precio,estadoCarro);
	}
	archivo.close();
}

void arbolAgencia::verificarInsertarCarroPais(pnodoPais R,int codPais, int identificacion,int codTipo, long double placa, string modelo, int numAsientos, int ano, int precioCarro, string estadoCarro){
	if(R==NULL){
		return;
	}
	else{
        if (R->codigoPais==codPais){
    		verificarInsertarCarroAgencia(R->derecha,identificacion,codTipo, placa, modelo, numAsientos,ano, precioCarro,estadoCarro);
		}
        verificarInsertarCarroPais(R->Hizq,codPais,identificacion,codTipo, placa, modelo, numAsientos,ano, precioCarro,estadoCarro);
        verificarInsertarCarroPais(R->Hder,codPais,identificacion,codTipo, placa, modelo, numAsientos,ano, precioCarro,estadoCarro);
    }
}

//Recorre el arbol ABB de pais
//Encuenta la agencia correspondiente
void arbolAgencia::verificarInsertarCarroAgencia(pnodoAgencia R,int identificacion,int codTipo, long double placa, string modelo, int numAsientos, int ano, int precioCarro, string estadoCarro){
	if(R==NULL){
		return;
	}
	else{//encontrar con la identificacion de la agencia
        if (R->identificacion==identificacion){
        	verificarInsertarCarroTipoFlotillas(R->derecha,codTipo,placa, modelo, numAsientos,ano, precioCarro,estadoCarro);	
		}
        verificarInsertarCarroAgencia(R->Hizq,identificacion,codTipo,placa, modelo, numAsientos,ano, precioCarro,estadoCarro);
        verificarInsertarCarroAgencia(R->Hder,identificacion,codTipo, placa, modelo, numAsientos,ano, precioCarro,estadoCarro);
    }
}

void arbolAgencia::verificarInsertarCarroTipoFlotillas(pnodoTipoFlotilla R,int codTipo, long double placa, string modelo, int numAsientos, int ano, int precioCarro, string estadoCarro){
	if(R==NULL){
		return;
	}
	else{//encontrar con la identificacion de la agencia
        if (R->codTipo==codTipo){
        	verPlacaRepetida(R,placa, modelo, numAsientos,ano, precioCarro,estadoCarro);	
		}
        verificarInsertarCarroTipoFlotillas(R->Hizq,codTipo,placa, modelo, numAsientos,ano, precioCarro,estadoCarro);
        verificarInsertarCarroTipoFlotillas(R->Hder,codTipo, placa, modelo, numAsientos,ano, precioCarro,estadoCarro);
    }
}

void arbolAgencia::verPlacaRepetida(pnodoTipoFlotilla R, long double placa, string modelo, int numAsientos, int ano, int precioCarro, string estadoCarro){
	if(verificarPlacaGlobal(pais.getRaizPais(),placa)>0){
		return;
	}else{
		insertarAA(R->derecha,placa, modelo, numAsientos,ano, precioCarro,estadoCarro);
	}
}

pnodoCarro arbolAgencia::insertarAA(pnodoCarro &raizP, long double placa, string modelo, int numAsientos, int ano, int precioCarro, string estadoCarro){
    if(raizP==NULL){
        raizP=new nodoCarro(placa,modelo,numAsientos,ano,precioCarro,estadoCarro);
        ultimoCarro=raizP;
        return raizP;
    }
    else{
        if (placa<raizP->placa)
        {
            raizP->hizq = insertarAA(raizP->hizq,placa, modelo, numAsientos,ano, precioCarro,estadoCarro);
        }
        else if (placa>raizP->placa)
        {
            raizP->hder = insertarAA(raizP->hder,placa, modelo, numAsientos,ano, precioCarro,estadoCarro);
        }
        else
        {
            return raizP;
        }
        
        raizP = Giro(raizP);
        raizP = Reparto(raizP);
    }
    return raizP;
}

pnodoCarro arbolAgencia::Giro(pnodoCarro &nodoP){
    if (nodoP==NULL){
        return NULL;
        }
    else if ((nodoP->hizq) && (nodoP->hizq->nivel == nodoP->nivel)){
        pnodoCarro L = nodoP->hizq;
        nodoP->hizq = L->hder;
        L->hder = nodoP;
        return L;
    }
    else
        return nodoP;
}

pnodoCarro arbolAgencia::Reparto(pnodoCarro &nodoP){
    if (nodoP==NULL){
        return NULL;
    }
    else if ((nodoP->hder->hder) && (nodoP->nivel == nodoP->hder->hder->nivel)){
        pnodoCarro R = nodoP->hder;
        nodoP->hder = R->hizq;
        R->hizq = nodoP;
        R->nivel++; 
        return R;
    }
    return nodoP;
}

void inordenCarro(pnodoCarro R){
	if(R==NULL){
        return;
    }else{
        inordenCarro(R->hizq);
        cout<<R->placa<<" -> ";
        inordenCarro(R->hder);
    }	
}

void InordenFlotilla(pnodoTipoFlotilla R){
	cout<<endl;
	if(R==NULL){
        return;
    }else{
        InordenFlotilla(R->Hizq);
        cout<<R->codTipo<<")";
		inordenCarro(R->derecha);
        InordenFlotilla(R->Hder);
    }
}

void InordenAgenciaAux(pnodoAgencia R){//recorrido recursivo para el Arbol BB de agencia
	if(R==NULL){
        return;
    }else{
        InordenAgenciaAux(R->Hizq);
        cout<<R->identificacion<<",";
        InordenFlotilla(R->derecha);
        InordenAgenciaAux(R->Hder);
    }
}

void InordenAgencia(pnodoPais R){//recorrido inorden recursivo para el arbol BB de Paises para llegar agencias
    if(R==NULL){
        return;
    }else{
        InordenAgencia(R->Hizq);
        cout<<R->codigoPais<<"--";
        InordenAgenciaAux(R->derecha);
        
        InordenAgencia(R->Hder);
    }
}

//Consultas y modificaciones de Carros
void arbolAgencia::modificacionConsultasCarro(pnodoPais R, int codPais,int identificacion,int codTipo, long double placa, int modificar){
	if(R==NULL){
   		return;
    }
    if(R->codigoPais==codPais){
		modificacionConsultasCarroA(R->derecha, identificacion,codTipo,placa,modificar);
		return;
	}
	modificacionConsultasCarro(R->Hizq,codPais,identificacion, codTipo,placa,modificar);
	modificacionConsultasCarro(R->Hder,codPais,identificacion,codTipo,placa,modificar);
}

void arbolAgencia::modificacionConsultasCarroA(pnodoAgencia R,int identificacion,int codTipo, long double placa,int modificar){
	if(R==NULL){
   		return;
    }
    if(R->identificacion==identificacion){
		modificacionConsultasCarroT(R->derecha, codTipo,placa,modificar);
		return;
	}
	modificacionConsultasCarroA(R->Hizq,identificacion,codTipo,placa,modificar);
	modificacionConsultasCarroA(R->Hder,identificacion,codTipo,placa,modificar);
}

void arbolAgencia::modificacionConsultasCarroT(pnodoTipoFlotilla R,int codTipo, long double placa,int modificar){
	if(R==NULL){
   		return;
    }
    if(R->codTipo==codTipo){
		modificacionConsultasCarroC(R->derecha, placa,modificar);
		return;
	}
	modificacionConsultasCarroT(R->Hizq,codTipo,placa,modificar);
	modificacionConsultasCarroT(R->Hder,codTipo,placa,modificar);
}

void arbolAgencia::modificacionConsultasCarroC(pnodoCarro R, long double placa, int modificar){
	if(R==NULL){
   		return;
    }
    if(placa==0&&modificar==0){
    	cout<<"Placa: "<<R->placa<<"  Modelo: "<<R->modelo<<"  NumAsientos:"<<R->numAsientos<<"  Ano: "<<R->ano<<"  Precio: "<<R->precioCarro<<"  Estado: "<<R->estadoCarro<<endl;
		modificacionConsultasCarroC(R->hizq,placa,modificar);
		modificacionConsultasCarroC(R->hder,placa,modificar);
		return;
	}
    
    if(R->placa==placa){
		if (modificar==1){
			cout<<"El nuevo numero de asientos: "<<endl;
			int numAsientos;
			cin>>numAsientos;
			R->numAsientos=numAsientos;
			return;
		}
		else if(modificar==2){
			cout<<"El precio del carro: "<<endl;
			int precio;
			cin>>precio;
			R->precioCarro=precio;
			return;
		}
		else if(modificar==3){
				cout<<endl;
				cout<<"R-Reservado"<<endl;
				cout<<"O-Ocupado"<<endl;
				cout<<"L-Libre"<<endl;
				cout<<"El nuevo estado del carro es: ";
				string estado;
				getline(cin,estado);
				if(estado=="R"){
					R->estadoCarro="R";	
				}
				else if(estado=="O"){
					R->estadoCarro="O";		
				}
				else if(estado=="L"){
					if(R->estadoCarro=="R"){
						listaReservaA.eliminar(R->placa);
					}
					R->estadoCarro="L";
				}else{
					cout<<"Error. Se debe seleccionar una de las 3 letras."<<endl;
				}	
				cout<<endl;
				return;
		}
		else if(modificar==4){
			cout<<"La cantidad de asientos del carro es "<<R->numAsientos<<endl;
			return;
		}
		else if(modificar==5){
			cout<<"El modelo del carro es "<<R->modelo<<endl;
			return;
		}
		else if(modificar==6){
			cout<<"El ano del carro es "<<R->ano<<endl;
			return;
		}
		else if(modificar==7){
			cout<<"El precio del carro es "<<R->precioCarro<<endl;
			return;
		}
		else if(modificar==8){
			cout<<"El estado del carro es "<<R->estadoCarro<<endl;
			return;
		}
	}
	modificacionConsultasCarroC(R->hizq,placa,modificar);
	modificacionConsultasCarroC(R->hder,placa,modificar);
}

void arbolAgencia::uCarro(){
	cout<<"El ultimo carro insertado fue: "<<endl;
	cout<<"La placa del carro es:"<<ultimoCarro->placa<<"  "<<"El modelo del carro es: " <<ultimoCarro->modelo<<endl;
}

int arbolAgencia::verificarPlacaGlobal(pnodoPais R, long double placa){
	int r=0;
	if(R==NULL){
		return r;
	}
	if(verificarPlacaGlobalA(R->derecha,placa)>0){
		r=1;
	}
	
	return r+verificarPlacaGlobal(R->Hder, placa)+verificarPlacaGlobal(R->Hizq, placa);
}

int arbolAgencia::verificarPlacaGlobalA(pnodoAgencia R, long double placa){
	int r=0;
	if(R==NULL){
		return r;
	}
	if(verificarPlacaGlobalT(R->derecha,placa)>0){
		r=1;
	}
	
	return r+verificarPlacaGlobalA(R->Hder, placa)+verificarPlacaGlobalA(R->Hizq, placa);
}

int arbolAgencia::verificarPlacaGlobalT(pnodoTipoFlotilla R, long double placa){
	int r=0;
	if(R==NULL){
		return r;
	}
	if(verificarPlacaGlobalC(R->derecha,placa)>0){
		r=1;
	}
	
	return r+verificarPlacaGlobalT(R->Hder, placa)+verificarPlacaGlobalT(R->Hizq, placa);
}

int arbolAgencia::verificarPlacaGlobalC(pnodoCarro R, long double placa){
	int r=0;
	if(R==NULL){
		return r;
	}
	if(R->placa==placa){
		r=1;
	}
	
	return r+verificarPlacaGlobalC(R->hder, placa)+verificarPlacaGlobalC(R->hizq, placa);
}

bool arbolAgencia::existeCarrosDatos(pnodoPais R, int codPais, int identificacion, int codTipo, long double placa){
	int r=0;
	if(R==NULL){
		return r;
	}
	if(codPais<R->codigoPais){
		r=existeCarrosDatos(R->Hizq, codPais, identificacion,  codTipo, placa);
	}
	if(codPais>R->codigoPais){
		r=existeCarrosDatos(R->Hder, codPais, identificacion,  codTipo, placa);
	}
    else if(codPais==R->codigoPais){
    	if(existeCarrosDatosA(R->derecha, identificacion, codTipo, placa)){
    		r=1;
		}
	}
	return r;
}

bool arbolAgencia::existeCarrosDatosA(pnodoAgencia R, int identificacion, int codTipo, long double placa){
	int r=0;
	if(R==NULL){
		return r;
	}
	if(identificacion<R->identificacion){
		r=existeCarrosDatosA(R->Hizq, identificacion,  codTipo, placa);
	}
	if(identificacion>R->identificacion){
		r=existeCarrosDatosA(R->Hder,  identificacion,  codTipo, placa);
	}
    else if(identificacion==R->identificacion){
    	if(existeCarrosDatosT(R->derecha,  codTipo, placa)){
    		r=1;
		}
	}
	return r;
}

bool arbolAgencia::existeCarrosDatosT(pnodoTipoFlotilla R, int codTipo, long double placa){
	int r=0;
	if(R==NULL){
		return r;
	}
	if(codTipo<R->codTipo){
		r=existeCarrosDatosT(R->Hizq,   codTipo, placa);
	}
	if(codTipo>R->codTipo){
		r=existeCarrosDatosT(R->Hder,   codTipo, placa);
	}
    else if(codTipo==R->codTipo){
    	if(existeCarrosDatosC(R->derecha, placa)){
    		r=1;
		}
	}
	return r;
}

bool arbolAgencia::existeCarrosDatosC(pnodoCarro R, long double placa ){
	int r=0;
	if(R==NULL){
		return r;
	}
	if(placa<R->placa){
		r=existeCarrosDatosC(R->hizq,  placa);
	}
	if(placa>R->placa){
		r=existeCarrosDatosC(R->hder, placa);
	}
    else if(placa==R->placa&&R->estadoCarro=="L"){
    	R->estadoCarro="R";
    	r=1;
	}
	return r;
}
