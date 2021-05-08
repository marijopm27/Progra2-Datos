
#include <fstream>
#include <sstream>

using namespace std;

class arbolPais{//Arbol BB
	public:
		arbolPais(){
			raizPais=NULL;
		}
		
		void leerArchivoPais();
		void insertarPais(int codPais, string nombrePais);
		void InsertaBinarioPais(int codPais, string nombrePais, pnodoPais nodoPais);
		pnodoPais getRaizPais();
		
	private:
		pnodoPais raizPais;
};

void arbolPais::leerArchivoPais(){
	ifstream archivo;
	string delimitador=";";
	string nomArch="Paises.txt";
	archivo.open(nomArch.c_str(),ios::in); //Abrimos el archivo en modo lectura
	pnodoPais primer;
	
	string texto;
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);//obtener la linea
		string codPais="", nombrePais="";
		int posicion=0;
		for(int i=0;i<texto.size();i++){
			if(texto[i]!=';'){
				if(posicion==0){
					codPais+=texto[i];			
				}
				else{
					nombrePais+=texto[i];
				}	
			}else{
				posicion++;
			}
			
		}
		//cout<<codPais<<"   "<<nombrePais<<endl;
		int codigo=atoi(codPais.c_str());//pasar de string a entero	
		insertarPais(codigo, nombrePais);
	}
	archivo.close();	
}

void arbolPais::insertarPais(int codPais, string nombrePais){
	if(raizPais==NULL){
        raizPais = new nodoPais(codPais,nombrePais);
    }else{
        InsertaBinarioPais(codPais,nombrePais,raizPais);
    }
}
//No inserta repetidos
void arbolPais::InsertaBinarioPais(int codPais, string nombrePais, pnodoPais nodoP){
	if(codPais<nodoP->codigoPais){//insetar izquierda
        if(nodoP->Hizq==NULL){
            nodoP->Hizq = new nodoPais(codPais,nombrePais);
        }else{
            InsertaBinarioPais(codPais,nombrePais,nodoP->Hizq);
        }
    }else if (codPais>nodoP->codigoPais){//insertar derecha
        if(nodoP->Hder==NULL){
            nodoP->Hder = new nodoPais(codPais,nombrePais);
        }else{
            InsertaBinarioPais(codPais,nombrePais,nodoP->Hder);
        }
    }
}

pnodoPais arbolPais::getRaizPais(){
	return raizPais;
}

arbolPais pais;//se declara el arbol Mapa

void InordenR(pnodoPais R){//recorrido inorden recursivo para el arbol BB de Paises
    if(R==NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout<<R->codigoPais<<",";
        InordenR(R->Hder);
    }
}
