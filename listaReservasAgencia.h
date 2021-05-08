#include <iostream>
using namespace std;

class nodoReservaA{
   public:
    nodoReservaA(int a, int b, int c,long double d, long double e)
    {
        codPais=a;
    	identificacion=b;
		codigo=c;
		placa=d;
		numIden=e;  
		siguiente=NULL; 
    }
	int codPais;
    int identificacion;
    int codigo;
	int placa;
	long double numIden;
	nodoReservaA *siguiente;
};
typedef nodoReservaA *pnodoReservaA;

class listaReservaA{
	public:
		listaReservaA(){
			primero=NULL;
		}
		void InsertarFinal(int codPais, int indentificaion, int codigo,long double placa, long double numIden);
		void eliminar(long double placa);
		bool ListaVacia() { return primero == NULL; } 
		void Mostrar();
		pnodoReservaA primero;
};

listaReservaA listaReservaA;

void listaReservaA::InsertarFinal(int codPais, int indentificaion, int codigo,long double placa, long double numIden){
	if (ListaVacia())
    	primero = new nodoReservaA(codPais,indentificaion, codigo,placa, numIden);
   else
     { pnodoReservaA aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoReservaA(codPais,indentificaion, codigo,placa, numIden);
      }    
}

void listaReservaA::eliminar(long double placa){
	if (ListaVacia()){
     	return;
    }else{
    	pnodoReservaA aux=primero;
    	if(primero->placa==placa){//primero
    		aux=primero->siguiente;
    		delete primero;
    		primero=aux;
    		return;
		}
		while(aux->siguiente->placa!=placa){
             aux=aux->siguiente;
        }
		pnodoReservaA temp=aux->siguiente;
        aux->siguiente=aux->siguiente->siguiente;
        delete temp;
		
    }
    return;
}

void listaReservaA::Mostrar(){
	pnodoReservaA aux=primero;
	while(aux!=NULL){
		cout<<"Reservacion del usuario "<<aux->numIden<<endl;
		cout<<"CodPais: "<<aux->codPais<<"        Identificacion: "<<aux->identificacion<<"        CodTipo: "<<aux->codigo<<"        Placa: "<<aux->placa<<endl;
		aux=aux->siguiente;
	}
}
