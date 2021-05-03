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



using namespace std;
class arbolHotel{//Arbol BB
	public:
		arbolHotel(){
			raizHotel=NULL;
		}
		
		//Archivos e inserciones de Agencias
		void lecturaHoteles();
		void verificarInsertarHotel(pnodoPais R,int codPais, int identificacion, string nomAgencia, int canVehiculos);
		void InsertaBinarioHotel(pnodoHotel Hotel,int codhotel, string nomHotel, int estrellas);
		pnodoHotel getRaizHotel();
		
	private:
		pnodoHotel raizHotel;
	
};

//M E T O D O S
// Lectura Hotel
void arbolHotel::lecturaHoteles(){
  ifstream archivo;
  archivo.open("Hoteles.txt",ios::in); //abre archivo en modo lectura
  while (!archivo.eof()){
  	string texto = ""; //almacena linea del archivo
  	string w = "";  //constructor segun la descomposicion del texto
  	int cont = 0; //Posicion en el txt
  	//componentes de cada hotel
  	int codpais;
  	int codhotel;
  	string nombre ="";
  	int cantestrellas;
  	
    getline(archivo,texto);
    
    for (auto rem : texto) 
   { 
       if (rem==';') 
       { 
       		if (cont==0){
       			istringstream(w) >> codpais; //almacena el codigo del pais
           		w=""; 
            }
            if (cont==1){
            	istringstream(w) >> codhotel; //almacena el codigo de hotel
           		w=""; 
            			
			}
			if(cont==2){
				nombre = nombre+w; //almacena el nombre del hotel
            	w="";
			}
			
			cont++;
       } 
       
       else
       { 
           w=w+rem; 
       } 
   }  

   istringstream(w) >> cantestrellas; //almacena la cantidad de estrellas
 	
 	verificarInsertarHotel(pais.getRaizPais(), codpais,codhotel,nombre,cantestrellas);
   	
   w="";
} 
  
  archivo.close();
}

//Revisar si existe al pais para hacer la inserccion
void arbolHotel::verificarInsertarHotel(pnodoPais R,int codPais, int codhotel, string nomHotel, int estrellas){
	if(R==NULL){
		return;
	}
	else{
        if (R->codigoPais==codPais){
			if(R->hoteles==NULL){//en caso de ser la primera insercion
        		R->hoteles=new nodoHotel(codhotel,nomHotel,estrellas);
    		}
    		else{
    			InsertaBinarioHotel(R->hoteles, codhotel,nomHotel,estrellas);
    		
			}
		}
        verificarInsertarHotel(R->Hizq,codPais,codhotel,nomHotel,estrellas);
        verificarInsertarHotel(R->Hder,codPais,codhotel,nomHotel,estrellas);
    }
}

//Hacer la inserccion en el arbol BB de las ageencias, pegado a paises
void arbolHotel::InsertaBinarioHotel(pnodoHotel Hotel,int codhotel, string nomHotel, int estrellas){
	if(codhotel<Hotel->codigoh){//insetar izquierda
        if(Hotel->izq==NULL){
            Hotel->izq = new nodoHotel(codhotel,nomHotel,estrellas);
        }else{
            InsertaBinarioHotel(Hotel->izq,codhotel,nomHotel,estrellas);
        }
    }else if (codhotel>Hotel->codigoh){//insertar derecha
        if(Hotel->der==NULL){
            Hotel->der = new nodoHotel(codhotel,nomHotel,estrellas);
        }else{
            InsertaBinarioHotel(Hotel->der,codhotel,nomHotel,estrellas);
        }
    }
}

void InordenHotelAux(pnodoHotel R){//recorrido recursivo para el Arbol BB de agencia
	if(R==NULL){
        return;
    }else{
        InordenHotelAux(R->izq);
        cout<<R->codigoh<<",";
        InordenHotelAux(R->der);
    }
}

void InordenHotel(pnodoPais R){//recorrido inorden recursivo para el arbol BB de Paises para llegar agencias
    if(R==NULL){
        return;
    }else{
        InordenHotel(R->Hizq);
        cout<<R->codigoPais<<"--";
        InordenHotelAux(R->hoteles);
        
        InordenHotel(R->Hder);
    }
}
