#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

//pagina
class PaginaAdministradorH{
  public:
    PaginaAdministrador(){
    	for(int i =0;i<5;i++){
    		clave[i]=-1;
    		nombre[i]="";
    	}
    	for(int i=0;i<5;i++){
    		rama[i]=NULL;
    	}
    	cuenta=0;
    }
    long double clave[5];
    string nombre[5];
    PaginaAdministradorH *rama[5];
    int cuenta;
    static const int max=4;
    static const int min=2;
    friend class ArbolAdministradorH;
};


class ArbolAdministradorH{
  	public:
  		PaginaAdministradorH *raiz;
  		ArbolAdministradorH(){raiz = NULL;}
	    void BuscarNodo(long double c1, PaginaAdministradorH *&p, bool &encontrado, int &k);
	    void InsertarArbolB(long double c1,string nombre,PaginaAdministradorH *&raiz);
		void Empujar(long double c1, string& nombre,  PaginaAdministradorH *&r, bool &empujarArriba,long double& mdna,PaginaAdministradorH *&xr);	                            
		void MeterHoja(string nombre,long double x,PaginaAdministradorH *&xder,PaginaAdministradorH *&p,int &k);
	    void DividirNodo(string nombre,long double x,PaginaAdministradorH *xder,PaginaAdministradorH *&p,int& k,long double& mdna,PaginaAdministradorH *&mder);
	    bool arbolBVacio(){return raiz==NULL;}
	    void leerArchivoAdministradorH();
		bool validaAdministradorH(long double x,PaginaAdministradorH *actual); 
		void buscar(PaginaAdministradorH *actual,long double codigo,int k);
		
};



//---------------------------------------------------------------------------------------------------------------------------------------- 




void ArbolAdministradorH::BuscarNodo(long double c1, PaginaAdministradorH *&p, bool &encontrado,int &k){
  if(c1<p->clave[1]){
  	encontrado=false;
  	k=0;
  }
  else{
  	k=p->cuenta;
  	while((c1<p->clave[k]) && (k>1)){
  		k=k-1;
  	}
  	if(c1==p->clave[k])
  		encontrado=true;
  	else{
  		encontrado=false;
  	}
   }
   
}
//----------------------------------------------------------------------------------------------------------------------------------

void ArbolAdministradorH::InsertarArbolB(long double c1, string nombre, PaginaAdministradorH *&raiz){ 
	long double x;
	PaginaAdministradorH *xr;
	PaginaAdministradorH *p;
	bool empujarArriba= false;
    Empujar(c1, nombre ,raiz,empujarArriba,x,xr);
    if(empujarArriba){
       p = new PaginaAdministradorH();
       p->cuenta=1;
       p->clave[1]=x;
       p->nombre[1]=nombre;
       p->rama[0]=raiz;
       p->rama[1]=xr;
       raiz=p;
    }
}

//----------------------------------------------------------------------------------------------------------------------------------
void ArbolAdministradorH::Empujar(long double c1, string& nombre, PaginaAdministradorH *&r, bool &empujarArriba,long double& mdna,PaginaAdministradorH *&xr){
	bool encontrado = false;
	int k=0;
	if(r==NULL){
	  	empujarArriba=true;
	  	mdna=c1;
	  	xr=NULL;
  	}
  	else{
	    BuscarNodo(c1,r,encontrado,k);
	    if(encontrado){
	    	return;
	    	cout<<"Elemento Repetido"<<endl;
	    }
	    Empujar(c1, nombre,r->rama[k],empujarArriba,mdna,xr);
	    if(empujarArriba){
	    	if(r->cuenta<PaginaAdministradorH().max){
	    		empujarArriba=false;
	    		MeterHoja( nombre,mdna,xr,r,k);
	      	}
	      	else{
	      		empujarArriba=true;
	      		DividirNodo(nombre ,mdna,xr,r,k,mdna,xr);
	      	}
  		}
	}
}
void ArbolAdministradorH::MeterHoja(string nombre,long double x,PaginaAdministradorH *&xder,PaginaAdministradorH *&p,int& k){
   	for(int i=p->cuenta;i>=k+1;i--){
   		p->clave[i+1]=p->clave[i];
   		p->nombre[i+1]=p->nombre[i];
   		p->rama[i+1]=p->rama[i];
   	}
	p->clave[k+1]=x;
	p->nombre[k+1]=nombre;
	p->rama[k+1]=xder;
	p->cuenta=p->cuenta+1; 	
}

void ArbolAdministradorH::DividirNodo(string nombre,long double x,PaginaAdministradorH *xder,PaginaAdministradorH *&p,int& k,long double& mdna,PaginaAdministradorH *&mder){
	int posmda;
	if(k<=PaginaAdministradorH().min){
		posmda=PaginaAdministradorH().min;
	}
	else{
		posmda=PaginaAdministradorH().min+1;
	}
	mder = new PaginaAdministradorH();
	for(int i=posmda+1;i<=PaginaAdministradorH().max;i++){
		mder->clave[i-posmda]=p->clave[i];
		mder->nombre[i-posmda]=p->nombre[i];
		mder->rama[i-posmda]=p->rama[i];
	}
	mder->cuenta = PaginaAdministradorH().max-posmda;
	p->cuenta = posmda;
	if(k<=PaginaAdministradorH().min)
		MeterHoja (nombre,x,xder,p,k);
	else{
		k = k-posmda;
		MeterHoja(nombre, x,xder,mder,k);
	}
	mdna = p->clave[p->cuenta];
	mder->rama[0]=p->rama[p->cuenta];
	p->cuenta=p->cuenta-1;
}

//recorrer el arbol 
void listaCrecienteA(PaginaAdministradorH *actual){
	if(actual!=NULL){
		int j;
		listaCrecienteA(actual->rama[0]);
		for(j=1;j<=actual->cuenta;j++){
			printf("%Lf",actual->clave[j]);
			cout<<actual->nombre[j]<<endl;
			/*if(actual->clave[j]==998434402){
				cout<<"aaaa";
			}*/
			listaCrecienteA(actual->rama[j]);
		}
	}
}


void ArbolAdministradorH::leerArchivoAdministradorH(){
	ifstream archivo;
	string delimitador=";";
	string nomArch="AdministradorH.txt";
	archivo.open(nomArch.c_str(),ios::in); //Abrimos el archivo en modo lectura	
	string texto;
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);//obtener la linea
		string codAdmin="", nombre="";
		int posicion=0;
		for(int i=0;i<texto.size();i++){
			if(texto[i]!=';'){
				if(posicion==0){
					codAdmin+=texto[i];			
				}
				else{
					nombre+=texto[i];
				}	
			}else{
				posicion++;
			}
			
		}
		long double codigoH=atoi(codAdmin.c_str());
		InsertarArbolB(codigoH,nombre,raiz);
	}
	archivo.close();
}


 void ArbolAdministradorH::buscar(PaginaAdministradorH *actual,long double codigo, int k){
	bool encontrado=false;
	/*if(actual==NULL){
		return actual;
	}*/
	
		BuscarNodo(codigo,actual,encontrado,k);
		if(encontrado){
			return;
		}else{
			return buscar(actual->rama[k],codigo,k);
		}
	}

	//numero, raiz, encontrado, indice
//}




bool ArbolAdministradorH::validaAdministradorH( long double x,PaginaAdministradorH *actual){
	 for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(actual->clave[j]==x){
                return true;
            }
        }
        if(actual->rama[i]!=NULL){
            if(validaAdministradorH(x,actual->rama[i])==true)
            	return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
class PaginaAdministradorA{
  public:
    PaginaAdministrador(){
    	for(int i =0;i<5;i++){
    		clave[i]=-1;
    		nombre[i]="";
    	}
    	for(int i=0;i<5;i++){
    		rama[i]=NULL;
    	}
    	cuenta=0;
    }
    long double clave[5];
    string nombre[5];
    PaginaAdministradorA *rama[5];
    int cuenta;
    static const int max=4;
    static const int min=2;
    friend class ArbolAdministradorA;
};


class ArbolAdministradorA{
  	public:
  		PaginaAdministradorA *raiz;
  		ArbolAdministradorA(){raiz = NULL;}
	    void BuscarNodoA(long double c1, PaginaAdministradorA *&p, bool &encontrado, int &k);
	    void InsertarArbolBA(long double c1,string nombre,PaginaAdministradorA *&raiz);
		void EmpujarA(long double c1, string& nombre,  PaginaAdministradorA *&r, bool &empujarArriba,long double& mdna,PaginaAdministradorA *&xr);	                            
		void MeterHojaA(string nombre,long double x,PaginaAdministradorA *&xder,PaginaAdministradorA *&p,int &k);
	    void DividirNodoA(string nombre,long double x,PaginaAdministradorA *xder,PaginaAdministradorA *&p,int& k,long double& mdna,PaginaAdministradorA *&mder);
	    bool arbolBVacioA(){return raiz==NULL;}
	    void leerArchivoAdministradorA();
		bool validaAdministradorA(long double x,PaginaAdministradorA *actual); 
		void buscarA(PaginaAdministradorA *actual,long double codigo,int k);
		
};



//---------------------------------------------------------------------------------------------------------------------------------------- 

void ArbolAdministradorA::BuscarNodoA(long double c1, PaginaAdministradorA *&p, bool &encontrado,int &k){
  if(c1<p->clave[1]){
  	encontrado=false;
  	k=0;
  }
  else{
  	k=p->cuenta;
  	while((c1<p->clave[k]) && (k>1)){
  		k=k-1;
  	}
  	if(c1==p->clave[k])
  		encontrado=true;
  	else{
  		encontrado=false;
  	}
   }
   
}
//----------------------------------------------------------------------------------------------------------------------------------

void ArbolAdministradorA::InsertarArbolBA(long double c1, string nombre, PaginaAdministradorA *&raiz){ 
	long double x;
	PaginaAdministradorA *xr;
	PaginaAdministradorA *p;
	bool empujarArriba= false;
    EmpujarA(c1, nombre ,raiz,empujarArriba,x,xr);
    if(empujarArriba){
       p = new PaginaAdministradorA();
       p->cuenta=1;
       p->clave[1]=x;
       p->nombre[1]=nombre;
       p->rama[0]=raiz;
       p->rama[1]=xr;
       raiz=p;
    }
}

//----------------------------------------------------------------------------------------------------------------------------------
void ArbolAdministradorA::EmpujarA(long double c1, string& nombre, PaginaAdministradorA *&r, bool &empujarArriba,long double& mdna,PaginaAdministradorA *&xr){
	bool encontrado = false;
	int k=0;
	if(r==NULL){
	  	empujarArriba=true;
	  	mdna=c1;
	  	xr=NULL;
  	}
  	else{
	    BuscarNodoA(c1,r,encontrado,k);
	    if(encontrado){
	    	return;
	    	cout<<"Elemento Repetido"<<endl;
	    }
	    EmpujarA(c1, nombre,r->rama[k],empujarArriba,mdna,xr);
	    if(empujarArriba){
	    	if(r->cuenta<PaginaAdministradorA().max){
	    		empujarArriba=false;
	    		MeterHojaA( nombre,mdna,xr,r,k);
	      	}
	      	else{
	      		empujarArriba=true;
	      		DividirNodoA(nombre ,mdna,xr,r,k,mdna,xr);
	      	}
  		}
	}
}
void ArbolAdministradorA::MeterHojaA(string nombre,long double x,PaginaAdministradorA *&xder,PaginaAdministradorA *&p,int& k){
   	for(int i=p->cuenta;i>=k+1;i--){
   		p->clave[i+1]=p->clave[i];
   		p->nombre[i+1]=p->nombre[i];
   		p->rama[i+1]=p->rama[i];
   	}
	p->clave[k+1]=x;
	p->nombre[k+1]=nombre;
	p->rama[k+1]=xder;
	p->cuenta=p->cuenta+1; 	
}

void ArbolAdministradorA::DividirNodoA(string nombre,long double x,PaginaAdministradorA *xder,PaginaAdministradorA *&p,int& k,long double& mdna,PaginaAdministradorA *&mder){
	int posmda;
	if(k<=PaginaAdministradorA().min){
		posmda=PaginaAdministradorA().min;
	}
	else{
		posmda=PaginaAdministradorA().min+1;
	}
	mder = new PaginaAdministradorA();
	for(int i=posmda+1;i<=PaginaAdministradorA().max;i++){
		mder->clave[i-posmda]=p->clave[i];
		mder->nombre[i-posmda]=p->nombre[i];
		mder->rama[i-posmda]=p->rama[i];
	}
	mder->cuenta = PaginaAdministradorA().max-posmda;
	p->cuenta = posmda;
	if(k<=PaginaAdministradorA().min)
		MeterHojaA (nombre,x,xder,p,k);
	else{
		k = k-posmda;
		MeterHojaA(nombre, x,xder,mder,k);
	}
	mdna = p->clave[p->cuenta];
	mder->rama[0]=p->rama[p->cuenta];
	p->cuenta=p->cuenta-1;
}

//recorrer el arbol 
void listaCrecienteA(PaginaAdministradorA *actual){
	if(actual!=NULL){
		int j;
		listaCrecienteA(actual->rama[0]);
		for(j=1;j<=actual->cuenta;j++){
			printf("%Lf",actual->clave[j]);
			cout<<actual->nombre[j]<<endl;
			/*if(actual->clave[j]==998434402){
				cout<<"aaaa";
			}*/
			listaCrecienteA(actual->rama[j]);
		}
	}
}


void ArbolAdministradorA::leerArchivoAdministradorA(){
	ifstream archivo;
	string delimitador=";";
	string nomArch="AdministradorA.txt";
	archivo.open(nomArch.c_str(),ios::in); //Abrimos el archivo en modo lectura	
	string texto;
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);//obtener la linea
		string codAdmin="", nombre="";
		int posicion=0;
		for(int i=0;i<texto.size();i++){
			if(texto[i]!=';'){
				if(posicion==0){
					codAdmin+=texto[i];			
				}
				else{
					nombre+=texto[i];
				}	
			}else{
				posicion++;
			}
			
		}
		long double codigoA=atoi(codAdmin.c_str());
		InsertarArbolBA(codigoA,nombre,raiz);
	}
	archivo.close();
}


 void ArbolAdministradorA::buscarA(PaginaAdministradorA *actual,long double codigo, int k){
	bool encontrado=false;
	/*if(actual==NULL){
		return actual;
	}*/
	
		BuscarNodoA(codigo,actual,encontrado,k);
		if(encontrado){
			return;
		}else{
			return buscarA(actual->rama[k],codigo,k);
		}
	}

	//numero, raiz, encontrado, indice
//}




bool ArbolAdministradorA::validaAdministradorA( long double x,PaginaAdministradorA *actual){
	 for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(actual->clave[j]==x){
                return true;
            }
        }
        if(actual->rama[i]!=NULL){
            if(validaAdministradorA(x,actual->rama[i])==true)
            	return true;
        }
    }
    return false;
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------
class PaginaUsuario{
  public:
    PaginaUsuario(){
    	for(int i =0;i<5;i++){
    		clave[i]=-1;
    		nombre[i]="";
    	}
    	for(int i=0;i<5;i++){
    		rama[i]=NULL;
    	}
    	cuenta=0;
    }
    long double clave[5];
    string nombre[5];
    PaginaUsuario *rama[5];
    int cuenta;
    static const int max=4;
    static const int min=2;
    friend class ArbolUsuario;
};


class ArbolUsuario{
  	public:
  		PaginaUsuario *raiz;
  		ArbolUsuario(){raiz = NULL;}
	    void BuscarNodoU(long double c1, PaginaUsuario *&p, bool &encontrado, int &k);
	    void InsertarArbolBU(long double c1,string nombre,PaginaUsuario *&raiz);
		void EmpujarU(long double c1, string& nombre,  PaginaUsuario *&r, bool &empujarArriba,long double& mdna,PaginaUsuario *&xr);	                            
		void MeterHojaU(string nombre,long double x,PaginaUsuario *&xder,PaginaUsuario *&p,int &k);
	    void DividirNodoU(string nombre,long double x,PaginaUsuario *xder,PaginaUsuario *&p,int& k,long double& mdna,PaginaUsuario *&mder);
	    bool arbolBVacioU(){return raiz==NULL;}
	    void leerArchivoUsuarios();
		bool validaUsuario(long double x,PaginaUsuario *actual); 
		void buscarU(PaginaUsuario *actual,long double codigo,int k);
		string nombreUsuario(long double x,PaginaUsuario *actual);
		
};



//---------------------------------------------------------------------------------------------------------------------------------------- 




void ArbolUsuario::BuscarNodoU(long double c1, PaginaUsuario *&p, bool &encontrado,int &k){
  if(c1<p->clave[1]){
  	encontrado=false;
  	k=0;
  }
  else{
  	k=p->cuenta;
  	while((c1<p->clave[k]) && (k>1)){
  		k=k-1;
  	}
  	if(c1==p->clave[k])
  		encontrado=true;
  	else{
  		encontrado=false;
  	}
   }
   
}
//----------------------------------------------------------------------------------------------------------------------------------

void ArbolUsuario::InsertarArbolBU(long double c1, string nombre, PaginaUsuario *&raiz){ 
	long double x;
	PaginaUsuario *xr;
	PaginaUsuario *p;
	bool empujarArriba= false;
    EmpujarU(c1, nombre ,raiz,empujarArriba,x,xr);
    if(empujarArriba){
       p = new PaginaUsuario();
       p->cuenta=1;
       p->clave[1]=x;
       p->nombre[1]=nombre;
       p->rama[0]=raiz;
       p->rama[1]=xr;
       raiz=p;
    }
}

//----------------------------------------------------------------------------------------------------------------------------------
void ArbolUsuario::EmpujarU(long double c1, string& nombre, PaginaUsuario *&r, bool &empujarArriba,long double& mdna,PaginaUsuario *&xr){
	bool encontrado = false;
	int k=0;
	if(r==NULL){
	  	empujarArriba=true;
	  	mdna=c1;
	  	xr=NULL;
  	}
  	else{
	    BuscarNodoU(c1,r,encontrado,k);
	    if(encontrado){
	    	return;
	    	cout<<"Elemento Repetido"<<endl;
	    }
	    EmpujarU(c1, nombre,r->rama[k],empujarArriba,mdna,xr);
	    if(empujarArriba){
	    	if(r->cuenta<PaginaUsuario().max){
	    		empujarArriba=false;
	    		MeterHojaU( nombre,mdna,xr,r,k);
	      	}
	      	else{
	      		empujarArriba=true;
	      		DividirNodoU(nombre ,mdna,xr,r,k,mdna,xr);
	      	}
  		}
	}
}
void ArbolUsuario::MeterHojaU(string nombre,long double x,PaginaUsuario *&xder,PaginaUsuario *&p,int& k){
   	for(int i=p->cuenta;i>=k+1;i--){
   		p->clave[i+1]=p->clave[i];
   		p->nombre[i+1]=p->nombre[i];
   		p->rama[i+1]=p->rama[i];
   	}
	p->clave[k+1]=x;
	p->nombre[k+1]=nombre;
	p->rama[k+1]=xder;
	p->cuenta=p->cuenta+1; 	
}

void ArbolUsuario::DividirNodoU(string nombre,long double x,PaginaUsuario *xder,PaginaUsuario *&p,int& k,long double& mdna,PaginaUsuario *&mder){
	int posmda;
	if(k<=PaginaUsuario().min){
		posmda=PaginaUsuario().min;
	}
	else{
		posmda=PaginaUsuario().min+1;
	}
	mder = new PaginaUsuario();
	for(int i=posmda+1;i<=PaginaUsuario().max;i++){
		mder->clave[i-posmda]=p->clave[i];
		mder->nombre[i-posmda]=p->nombre[i];
		mder->rama[i-posmda]=p->rama[i];
	}
	mder->cuenta = PaginaUsuario().max-posmda;
	p->cuenta = posmda;
	if(k<=PaginaUsuario().min)
		MeterHojaU (nombre,x,xder,p,k);
	else{
		k = k-posmda;
		MeterHojaU(nombre, x,xder,mder,k);
	}
	mdna = p->clave[p->cuenta];
	mder->rama[0]=p->rama[p->cuenta];
	p->cuenta=p->cuenta-1;
}

//recorrer el arbol 
void listaCrecienteU(PaginaUsuario *actual){
	if(actual!=NULL){
		int j;
		listaCrecienteU(actual->rama[0]);
		for(j=1;j<=actual->cuenta;j++){
			printf("%Lf",actual->clave[j]);
			cout<<actual->nombre[j]<<endl;
			/*if(actual->clave[j]==998434402){
				cout<<"aaaa";
			}*/
			listaCrecienteU(actual->rama[j]);
		}
	}
}


void ArbolUsuario::leerArchivoUsuarios(){
	ifstream archivo;
	string delimitador=";";
	string nomArch="Usuarios.txt";
	archivo.open(nomArch.c_str(),ios::in); //Abrimos el archivo en modo lectura	
	string texto;
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);//obtener la linea
		string codUsu="", nombre="";
		int posicion=0;
		for(int i=0;i<texto.size();i++){
			if(texto[i]!=';'){
				if(posicion==0){
					codUsu+=texto[i];			
				}
				else{
					nombre+=texto[i];
				}	
			}else{
				posicion++;
			}
			
		}
		long double codigoU=atoi(codUsu.c_str());
		InsertarArbolBU(codigoU,nombre,raiz);
	}
	archivo.close();
}


 void ArbolUsuario::buscarU(PaginaUsuario *actual,long double codigo, int k){
	bool encontrado=false;
	/*if(actual==NULL){
		return actual;
	}*/
	
		BuscarNodoU(codigo,actual,encontrado,k);
		if(encontrado){
			return;
		}else{
			return buscarU(actual->rama[k],codigo,k);
		}
	}

	//numero, raiz, encontrado, indice
//}




bool ArbolUsuario::validaUsuario( long double x,PaginaUsuario *actual){
	 for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(actual->clave[j]==x){
                return true;
            }
        }
        if(actual->rama[i]!=NULL){
            if(validaUsuario(x,actual->rama[i])==true)
            	return true;
        }
    }
    return false;
}

string ArbolUsuario::nombreUsuario(long double x,PaginaUsuario *actual){
	for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(actual->clave[j]==x){
                return actual->nombre[j];
            }
        }
        if(actual->rama[i]!=NULL){
            if(validaUsuario(x,actual->rama[i])==true)
            	return actual->nombre[i];
        }
    }
    return false;
}
