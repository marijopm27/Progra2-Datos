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
		
		//Archivos e inserciones de Flotilla
		void leerArchivoTipoFlotilla();
		void verificarInsertarTipoFlotilla(pnodoPais nodoP,int codPais, int identificacion,int codTipo, string nombreTipo, int cantCarrosTipo);
		void insertarBalanceadoTipoFlotilla(pnodoTipoFlotilla &ra,bool Hh,int codTipo, string nombreTipo, int cantCarrosTipo);
		void verificarAgenciasTipoFlotilla(pnodoAgencia R,int identificacion,int codTipo, string nombreTipo, int cantCarrosTipo);
		
		//Rotaciones AVL de Flotillas
		void RotacionDobleDerecha(pnodoTipoFlotilla n, pnodoTipoFlotilla n1);
		void RotacionSimpleDerecha(pnodoTipoFlotilla n, pnodoTipoFlotilla n1);
		void RotacionDobleIzquierda(pnodoTipoFlotilla n, pnodoTipoFlotilla n1);
		void RotacionSimpleIzquierda(pnodoTipoFlotilla n, pnodoTipoFlotilla n1);
		
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
        }else{
            InsertaBinarioAgencia(nodoA->Hizq,identificacion,nomAgencia,canVehiculos);
        }
    }else if (identificacion>nodoA->identificacion){//insertar derecha
        if(nodoA->Hder==NULL){
            nodoA->Hder = new nodoAgencia(identificacion,nomAgencia,canVehiculos);
        }else{
            InsertaBinarioAgencia(nodoA->Hder,identificacion,nomAgencia,canVehiculos);
        }
    }
}

void InordenFlotilla(pnodoTipoFlotilla R){
	cout<<endl;
	if(R==NULL){
        return;
    }else{
        InordenFlotilla(R->Hizq);
        cout<<R->codTipo<<")";
        cout<<endl;
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


