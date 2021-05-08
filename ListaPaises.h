#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h> 
#include <cctype>
#include <cstring>
#include <cstdlib>


class listaPaises {
   public:
    listaPaises() { primero = NULL; }
    
    
    void leerArchivoPais();
    void InsertarFinal(int v, string nombre);

    bool ListaVacia() { return primero == NULL; } 
    int Validar(int cod);

    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos, int cod);
    void Datos(int opcion);
    int largoLista();
    
   private:
    pnodoLista primero;
   
};



int listaPaises::largoLista()
{
    int cont=0;

    pnodoLista aux = primero;
    if(ListaVacia())
    {
        return cont;
    }
    else
    {
        while(aux->siguiente!=primero)
        {
          aux=aux->siguiente;
          cont++;
        }
        cont++;
    return cont;
    }
    
}
void listaPaises::Datos(int opcion){
	string Nombre;
    int codpais;
	bool repetido1 = false;	
	while(repetido1==false){
        cout<<"\nIngrese el codigo del pais: ";
        if(cin>>codpais){
		
        	if(Validar(codpais)==0 && opcion==1){
        		//Entra si el codigo no existe o no hay hoteles
            	repetido1=true;
            	break;
			}
			if(Validar(codpais)==1 && opcion==1){
				cout<<"\nEste codigo de pais ya esta registrado, favor ingresar otro distinto "<<endl;
				break;
			}
			if(Validar(codpais)==0 && opcion==2){
				cout<<"\nEste codigo de pais NO esta registrado, favor ingresar otro distinto "<<endl;
				break;
				
			}
			if(Validar(codpais)==1 && opcion==2){
				
            	break;
				
			}
			if(Validar(codpais)==0 && opcion==3){
				cout<<"\nEste codigo de pais NO esta registrado, favor ingresar otro distinto "<<endl;
				break;
				
			}
			if(Validar(codpais)==1 && opcion==3){
				repetido1=true;
            	break;
				
			}
			
		}
		else{
			cout<<"\nEl codigo de pais debe ser un numero entero."<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	if(repetido1==true && opcion==1){
		cout<<"\nIngrese el nombre del pais : ";
		cin.ignore();
		getline(cin,Nombre);
		
		InsertarFinal(codpais,Nombre);
	}
	if(repetido1==false && opcion==2){
		pnodoLista encontrado  =  primero;
    	pnodoLista actual;
	    actual = encontrado;
	    int posicion = 1;
	   	 while(actual->siguiente!=encontrado){
			 if (actual->valor==codpais){
			 	break;
		 	}
		 	else{
		 		actual = actual->siguiente;
		 		
			 }
			 posicion ++;
		 	
		  }
		  BorrarPosicion(posicion,codpais);
	}
	if(repetido1==true && opcion==3){
		cout<<"\nIngrese el nombre del pais : ";
		cin.ignore();
		getline(cin,Nombre);
		pnodoLista encontrado  =  primero;
    	pnodoLista actual;
	    actual = encontrado;

	   	 while(actual->siguiente!=encontrado){
			 if (actual->valor==codpais){
			 	actual->nombre = Nombre;
			 	break;
		 	}
		 	else{
		 		actual = actual->siguiente;
		 		
			 }
		  }
		  if (actual->valor==codpais){
			 	actual->nombre = Nombre;
			 	
		 	}

	}
		
	
}
void listaPaises::leerArchivoPais(){
  ifstream archivo;
  archivo.open("Paises.txt",ios::in); //abre archivo en modo lectura
  while (!archivo.eof()){
  	string texto = ""; //almacena linea del archivo
  	string w = "";  //constructor segun la descomposicion del texto
  	int cont = 0; //Posicion en el txt
  	//componentes de cada hotel
  	int codpais;

  	string nombre ="";

    getline(archivo,texto);
    
    for (auto rem : texto) 
   { 
       if (rem==';') 
       { 
       		if (cont==0){
       			istringstream(w) >> codpais; //almacena el codigo del pais
           		w=""; 
            }
            
			
			cont++;
       } 
       
       else
       { 
           w=w+rem; 
       } 
   }  
	nombre = nombre+w; //almacena el nombre del hotel

 	if(Validar(codpais)==0){
 		InsertarFinal(codpais, nombre);
	 }
   	
   w="";
} 
  
  archivo.close();
}

void listaPaises::InsertarFinal(int v, string nombre)
{
   if (primero==NULL)
     {
     primero = new nodoLista(v, nombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
   	
     	pnodoLista nuevo = new nodoLista(v, nombre);
     	nuevo->anterior = primero->anterior;
     	nuevo->siguiente=primero->anterior->siguiente;
     	primero->anterior->siguiente=nuevo;
     	primero->anterior=nuevo;
    	
	}  
}



void listaPaises::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodoLista temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodoLista aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodoLista temp = aux->siguiente;
         aux->siguiente= primero;
         primero->anterior=aux;
         delete temp;
      }
    }
}

void listaPaises::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodoLista temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodoLista aux = primero->anterior;
        pnodoLista temp= primero;
        aux->siguiente=primero->siguiente;
        primero=primero->siguiente; 
        primero->anterior=aux;
        delete temp;
      }
    }
}

void listaPaises:: BorrarPosicion(int pos, int cod)
{
    
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
  	pnodoLista actual;
    actual = primero;
    int pos = 1;
   	 while(actual->siguiente!=primero){
		 if (actual->valor==cod){
		 	break;
	 	}
	 	else{
	 		actual = actual->siguiente;
	 		
		 }
		 pos ++;
	 	
	  }
	   if((pos>largoLista())||(pos<0))
	        cout << "Error en posicion" << endl;
	   else
	   {
	      if(pos==1)
	        BorrarInicio();
	      else
	      {
	       int cont=2;
	       pnodoLista aux=  primero;
	       while(cont<pos)
	       {
	         aux=aux->siguiente;
	         cont++;
	       }
	       pnodoLista temp = aux->siguiente;
	       aux->siguiente=aux->siguiente->siguiente;
	       aux->siguiente->anterior=aux;// FALTABA ESTA LINEA
	       delete temp;
	     }
	    }
  }
}

listaPaises Paises;
int listaPaises::Validar(int cod)
{

	int verificador = 0;
	if(ListaVacia()){
		return 0;
	}
	else{
	
	   pnodoLista aux=primero;
	   while(aux->siguiente!=primero)
	     {
	      if(cod == aux->valor) {
	      	verificador = 1;
	      	
		  } 
		  aux=aux->siguiente;               
	      
	     }
	     if(cod == aux->valor) {
	      	verificador = 1;
	      }
	}
      return verificador;
}  

void listaPaises::Mostrar()
{
	cout<<"LISTA PAISES"<<endl;
   pnodoLista aux=primero;
   while(aux->siguiente!=primero)
     {
                                
      cout <<"Codigo: "<< aux->valor << endl;
      cout<<"Nombre: "<<aux->nombre<<endl;
      cout<<endl;
      aux = aux->siguiente;
     }
     cout <<"Codigo: "<< aux->valor << endl;
      cout<<"Nombre: "<<aux->nombre<<endl;
     cout<<endl;
}   
