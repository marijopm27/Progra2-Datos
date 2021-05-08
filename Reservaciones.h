#include <iostream>
using namespace std;

class Reservaciones {
   public:
    Reservaciones()
	{
      primero=NULL;   	
    	
	}

    void InsertarFinal(long double v, int c, string x);
    bool ReservacionesVacia() { return primero == NULL; } 
    void Mostrar();
    void Primero();
    bool ValidaReservacion(int codigoArb);

    int largoReservaciones();
    
      
   private:
    pnodoReserva primero; // nodoReserva *primero; tipo nodoReserva tiene derechoi direccionar un nodoReserva
   
};
  

Reservaciones ReservacionesH;
int Reservaciones::largoReservaciones(){ //largo
    int cont=0;

    pnodoReserva aux; //nodoReserva *aux;
    aux = primero;
    if(ReservacionesVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void Reservaciones::InsertarFinal(long double identificacion, int cod, string t)
{
   if (ReservacionesVacia())
     primero = new nodoReserva(identificacion, cod, t);
   else
     { pnodoReserva aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoReserva(identificacion, cod, t);
      }    
}

bool Reservaciones::ValidaReservacion(int codigoArb){
	bool existe_reserva = false;
	nodoReserva *aux;
   if (primero== NULL)
       return existe_reserva; 
   else
   {

   		aux = primero;
		while(aux) 
		{
		    if(aux->codigo == codigoArb){
		    	existe_reserva = true;
		    	break;
			}
		    aux = aux->siguiente;
		}
		
   }
   return existe_reserva;
	
}
void Reservaciones::Mostrar()
{
   nodoReserva *aux;
   if (primero== NULL)
       cout << "No se han realizado reservas";  
   else
   {
   
       	cout<<"LISTA DE RESERVACIONES"<<endl;
   		aux = primero;
		while(aux) 
		{
		    cout << "Usuario: "<<aux->identificacion << endl;
		    if(aux->tipo == "c")
		    
		    	cout<<"Codigo del Carro reservado: "<<aux->codigo<<endl;
		    if(aux->tipo == "h")
		    	cout<<"Codigo de la Habitacion reservado: "<<aux->codigo<<endl;
		    
		    aux = aux->siguiente;
		}
		cout << endl;
   }
}


