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
		
		//----------------------------------------------------------------------Archivos e inserciones de Agencias
		void lecturaHoteles();
		void verificarInsertarHotel(pnodoPais R,int codPais, int identificacion, string nomAgencia, int canVehiculos);
		void InsertaBinarioHotel(pnodoHotel Hotel,int codhotel, string nomHotel, int estrellas);
		pnodoHotel getRaizHotel();
		//----------------------------------------------------------------------Archivos e inserciones Pisos Hotel
		void lecturaPisosHotel();
		void verificarInsertarPisos(pnodoPais nodoP,int codPais, int codigoh,int NumPiso, string NombrePiso, int habitaciones);
		void insertarBalanceadoPisos(pnodoPiso &ra,bool Hh,int NumPiso, string NombrePiso, int habitaciones);
		void verificarHoteles(pnodoHotel R,int codigoh,int NumPiso, string NombrePiso, int habitaciones);
		
		//----------------------------------------------------------------------Rotaciones AVL de PisosHotel
		void RotacionDobleDerecha(pnodoPiso n, pnodoPiso n1);
		void RotacionSimpleDerecha(pnodoPiso n, pnodoPiso n1);
		void RotacionDobleIzquierda(pnodoPiso n, pnodoPiso n1);
		void RotacionSimpleIzquierda(pnodoPiso n, pnodoPiso n1);
		
		//---------------------------------------------------------------------arbol rojinegro Habitaciones
		void lecturaHabitaciones();
		void verificarPais(pnodoPais R,int codPais, int codigoh,int NumPiso, int codigoHabitacion, string cuartos, int Numcamas, int Precio, string Estado);
		void verificarHotelesH(pnodoHotel R,int codigohotel,int NumPiso, int codigoHabitacion, string cuartos, int Numcamas, int Precio, string Estado);
		void verificarPisos(pnodoPiso R,int NumPiso, int codigoHabitacion, string cuartos, int Numcamas, int Precio, string Estado);
		void insertarNodoRojoNegro(int codigoHabitacion,string cuartos,int Numcamas,int Precio,string Estado, pnodoPiso u);
		void insertarTio(pnodoHabitaciones t, pnodoPiso o);
		void rotacionIzquierda(pnodoHabitaciones p,pnodoPiso j);
		void rotacionDerecha(pnodoHabitaciones p,pnodoPiso j);
		
		//VALIDACIONES-----------------------------------------------------------------------------------
		int existeHotel(nodoHotel *R, int hotel);
		int existePiso(nodoPiso *R, int NumPiso);
		int existePais(nodoPais *R, int pais);
		int existeHabitaciones(nodoHabitaciones *R, int hab);
		
		//INSERTAR- MENU----------------------------------------------------------------------------------
		void insertarHotel();
		void insertarPisos();
		void insertarHabitacion();
		//MODIFICAR MENU----------------------------------------------------------------------------------
		void modificarHotel(int opcion_menu, int verificador);
		void modificarhotelaux(pnodoHotel RaizHotel,int codhotel,int opcion_menu, int verificador);
		
		void modificarPisos(int opcion, int verificar);
		void modificarPisosaux(pnodoPiso Pisos, int NumPiso, int opcion, int verificar);
		
		void modificarHabitacion(int opcion, int verificar);
		void modificarHabitacionaux(pnodoHabitaciones Habitacion, int codhabitacion, int opcion, int verificar);
		
		//Reportes
		void Reportes(int verificar);
		void recorrePais(pnodoPais p, int verificar, int codpais, int codhotel, int numpiso, int codhab);
		void MostrarHoteles(pnodoHotel h, int verificar,int codpais, int codhotel, int numpiso, int codhab);
		void MostrarPisos(pnodoPiso p, int verificar,int codpais, int codhotel, int numpiso, int codhab);
		void MostrarHabitaciones(pnodoHabitaciones h, int verificar,int codpais, int codhotel, int numpiso, int codhab);
		//RECORRER ELEMENTO---------------------------------------------------------------------------------
		int cantHab(pnodoHabitaciones Piso, int pos);
		void verificarDatos(long double codigo, int op);
		bool validaR(nodoHabitaciones *R, int hab);
		pnodoHabitaciones Habitacion(nodoHabitaciones *R, int hab);
		

		
		pnodoPais paisencontrado;
		pnodoHotel hotelencontrado;
		pnodoPiso pisoencontrado;
		pnodoHabitaciones habitacionencontrada;

		pnodoHotel raizHotel;
		
	
};
		pnodoHotel UltimoHotel;
		pnodoPiso UltimoPiso;
		pnodoHabitaciones UltimaHabitacion;
//-------------------------------------------------------------------------------M E T O D O S-----------------------------------------------------
void arbolHotel::verificarDatos(long double codigo, int op)	{
	cout<<codigo<<endl;
	if (op==1){
		//Reservar Habitacion Simple
		int codhotel, codpais;
		int NumPiso;
		int codigoHabitacion;
		
	    bool no_repetido = false;
	    bool existe_piso = false;
	    bool existe_hotel = false;
	
	   	bool repetido1 = false;	
		bool verifica = false;
		while(verifica==false){
	        cout<<"\nIngrese el codigo del pais en que desea reservar: ";
	        if(cin>>codpais){
	        	if(Paises.Validar(codpais)==1){
				
				
		        	if(existePais(pais.getRaizPais(),codpais)==2){
		        		//Entra si el codigo no existe o no hay hoteles
		            	repetido1=true;
		            	verifica=true;
		            	break;
					}
					if ((existePais(pais.getRaizPais(),codpais)==3)){
						cout<<"Este pais no tiene hoteles registrados"<<endl;
						verifica=true;
						break;
						
					}
					else{
						cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
					}
				}
				else{
					cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
					verifica = true;
				}
			}
			else{
				cout<<"\nEl codigo de pais debe ser un numero entero."<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		if(repetido1==true){
				while(existe_hotel==false){
		    	cout<<"\nIngrese el codigo del Hotel en que desea reservar: ";
		    	if(cin>>codhotel){
		    		//Valores que devuelve la funcion
					/*
					 0 -> No existe el codigo hotel
					 2-> Existe Hotel con pisos
					 3-> El hotel existe, pero no tiene pisos
					 */
					 nodoHotel* RaizHotel = paisencontrado->hoteles;
					if((existeHotel(RaizHotel, codhotel)==0)){
		        		cout<<"\nEste codigo de hotel no esta registrado, favor ingresar otro distinto "<<endl;
		        		cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if((existeHotel(RaizHotel, codhotel)==3)){
						cout<<"\nEn este hotel no existen pisos registradas"<<endl;
						break;
					}
					if((existeHotel(RaizHotel, codhotel)==2)){		
						existe_hotel=true;
		       	 		break;
					}
				}
				else{
					cout<<"\nEl codigo de hotel debe ser un numero entero"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			
			}
			if(existe_hotel==true){
				existe_piso = false;
				while(existe_piso==false){
		        	cout<<"\nIngrese el numero del piso del Hotel que desea reservar: ";
		        	if(cin>>NumPiso){
			    	//Valores que devuelve la funcion
						/*
						 0 -> No existe el NumPiso
						 1-> Existe el NumPios
						 2-> La lista de pisos est[a vacia
						 3-> El piso existe, pero no tiene habitaciones
						 */
						 nodoPiso* RaizPisos = hotelencontrado->PisosHotel;
		        		if((existePiso(RaizPisos,NumPiso)==0)){
		        			cout<<"\nEste numero del piso no esta registrado, favor ingresar otro distinto "<<endl;
		        			break;
						}
						if((existePiso(RaizPisos,NumPiso)==2)){
							//Para ingresar habitaciones solo importa si el piso existe
								
							existe_piso=true;
		            		break;
						}
						if((existePiso(RaizPisos,NumPiso)==3)){
							cout<<"\nEste numero de piso no posee habitaciones, por lo que no ouede utilizar la opcion"<<endl;
							break;
						}
						
					}
					else{
						cout<<"\nEl numero de piso debe ser un numero entero"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				if(existe_piso == true){
				
					while(no_repetido==false){
		        		cout<<"\nIngrese el codigo de habitacion: ";
		        		if(cin>>codigoHabitacion){
		        				//Valores que devuelve la funcion
							/*
							 0 -> No existe el habitacion
							 1-> Existe la habitacion
							 2-> No hay habitaciones
							 3-> Piso sin habitaciones
							 */
							 nodoHabitaciones* RaizHabitacion = pisoencontrado->Habitaciones;
		        			if((existeHabitaciones(RaizHabitacion,codigoHabitacion)==0)){
		            			cout<<"\nEste codigo de habitacion no esta registrado, favor ingresar otro distinto "<<endl;
		                		
							}
							else{
								
								no_repetido=true;
		           				break;
								
							}
						}
						else{
							cout<<"\nEl codigo de habitacion debe ser un numero entero"<<endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					}
					if(ReservacionesH.ValidaReservacion(codigoHabitacion)==false && habitacionencontrada->estado=="L")
						habitacionencontrada->estado = "R";
						ReservacionesH.InsertarFinal(codigo,codigoHabitacion,"h");
			}
			
		}
			
		}
}
}

bool arbolHotel::validaR(nodoHabitaciones* R, int hab){
	bool r=false;   // 0 indica que no lo encontro
     if(R==NULL)
        return r;

     if(hab<R->codHabitacion)
         r = existeHabitaciones(R->izq, hab);
     else if(hab> R->codHabitacion)
         r = existeHabitaciones(R->der, hab);
     else{
     	r=true;
	 }

     return r;
	 
		
}


//H O T E L------------------------------------------------------------------
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
   if(Paises.Validar(codpais)==1){
 		verificarInsertarHotel(pais.getRaizPais(), codpais,codhotel,nombre,cantestrellas);
   	
   }

   w="";
} 
  
  archivo.close();
}

//Verifica Para Insertar Hotel
void arbolHotel::verificarInsertarHotel(pnodoPais R,int codPais, int codhotel, string nomHotel, int estrellas){
	if(R==NULL){
		return;
	}
	else{
        if (R->codigoPais==codPais){
			if(R->hoteles==NULL){//en caso de ser la primera insercion
        		R->hoteles=new nodoHotel(codhotel,nomHotel,estrellas);
        		UltimoHotel = R->hoteles;
    		}
    		else{
    			InsertaBinarioHotel(R->hoteles, codhotel,nomHotel,estrellas);
    			
    		
			}
		}
        verificarInsertarHotel(R->Hizq,codPais,codhotel,nomHotel,estrellas);
        verificarInsertarHotel(R->Hder,codPais,codhotel,nomHotel,estrellas);
    }
}

//Hacer la inserccion en el arbol BB de los hoteles, pegado a paises
void arbolHotel::InsertaBinarioHotel(pnodoHotel Hotel,int codhotel, string nomHotel, int estrellas){
	if(codhotel<Hotel->codigoh){//insetar izquierda
        if(Hotel->izq==NULL){
        	
            Hotel->izq =  new nodoHotel(codhotel,nomHotel,estrellas);
            UltimoHotel = Hotel->izq;
            
        }else{
            InsertaBinarioHotel(Hotel->izq,codhotel,nomHotel,estrellas);
            
        }
    }else if (codhotel>Hotel->codigoh){//insertar derecha
        if(Hotel->der==NULL){
            Hotel->der =  new nodoHotel(codhotel,nomHotel,estrellas);
            UltimoHotel = Hotel->der;
        }else{
            InsertaBinarioHotel(Hotel->der,codhotel,nomHotel,estrellas);
        }
    }
}

//Mostrar--------------------------------------------------------------------------------
void InordenHabitaciones(pnodoHabitaciones R){
	cout<<endl;
	if(R==NULL){
        return;
    }else{
        InordenHabitaciones(R->izq);
        cout<<R->codHabitacion<<" hab"<<endl;
        cout<<endl;
        InordenHabitaciones(R->der);
    }
}

void InordenPisos(pnodoPiso R){
	cout<<endl;
	if(R==NULL){
        return;
    }else{
        InordenPisos(R->izq);
        cout<<R->piso<<",";
        cout<<endl;
        InordenHabitaciones(R->Habitaciones);
        InordenPisos(R->der);
    }
}

void InordenHotelAux(pnodoHotel R){//recorrido recursivo para el Arbol BB de Hotel
	if(R==NULL){
        return;
    }else{
        InordenHotelAux(R->izq);
        cout<<R->codigoh<<",";
        InordenPisos(R->PisosHotel);
        InordenHotelAux(R->der);
    }
}

void InordenHotel(pnodoPais R){//recorrido inorden recursivo para el arbol BB de Paises para llegar agencias
    if(R==NULL){
        return;
    }else{
        InordenHotel(R->Hizq);
        cout<<R->codigoPais<<"--"<<endl;
        InordenHotelAux(R->hoteles);
        
        InordenHotel(R->Hder);
    }
}

//Validaciones sobre inserción
int arbolHotel::existePais(nodoPais *R, int pais){
	/*
	0 =  No existe el pais o no hay paises
	1 = Existe / Repetido
	2 = Existe y tiene hoteles
	3 = Existe y no tiene hoteles
	*/
	 int r=0;   // 0 indica que no lo encontro
     if(R==NULL)
        return r;

     if(pais<R->codigoPais)
         r = existePais(R->Hizq, pais);
     else if(pais> R->codigoPais)
         r = existePais(R->Hder, pais);
     else{
     	paisencontrado = R;
	 
     	if(R->hoteles == NULL){
     		r = 3;   // son iguales, lo encontre
		 }
		else{
			 r = 2;
		}
        
	}	
     return r;
		
	}
	
int arbolHotel::existeHotel(nodoHotel *R, int hotel){
	/*
	0 =  No existe el hotel o no hay hoteles
	1 = Existe / Repetido
	2 = Existe y tiene pisos
	3 = Existe y no tiene pisos
	*/
	 int r=0;   // 0 indica que no lo encontro
     if(R==NULL)
        return r;

     if(hotel<R->codigoh)
         r = existeHotel(R->izq, hotel);
     else if(hotel> R->codigoh)
         r = existeHotel(R->der, hotel);
     else{
     	hotelencontrado = R;
     	if(R->PisosHotel == NULL)
     		r=3;
     	else{
     		r=2;
		 }
	 }

     return r;
		
	}
	
int arbolHotel::existePiso(nodoPiso *R, int NumPiso){
	/*
	0 =  No existe el piso o no hay pisos en ese hotel
	1 = Existe / Repetido
	2 = Existe y tiene habitaciones
	3 = Existe y no tiene habitaciones
	*/
	 int r=0;   // 0 indica que no lo encontro
     if(R==NULL)
        return r;

     if(NumPiso<R->piso)
         r = existePiso(R->izq, NumPiso);
     else if(NumPiso> R->piso)
         r = existePiso(R->der, NumPiso);
     else{
     	pisoencontrado = R;
     	if(R->Habitaciones == NULL){
     		r=3;
		 }
		 else{
		 	r=2;
		 }
	 }

     return r;
		
	}
	
int arbolHotel::existeHabitaciones(nodoHabitaciones *R, int hab){
	/*
	0 =  No existe el habitacion o no hay habitaciones
	1 = Existe / Repetido
	*/
	int r=0;   // 0 indica que no lo encontro
     if(R==NULL)
        return r;

     if(hab<R->codHabitacion)
         r = existeHabitaciones(R->izq, hab);
     else if(hab> R->codHabitacion)
         r = existeHabitaciones(R->der, hab);
     else{
     	habitacionencontrada = R;
     	r=1;
	 }

     return r;
	 
		
	}
	

// P I S O S  H O T E L--------------------------------------------------
//Lectura Pisos Hotel
void arbolHotel::lecturaPisosHotel(){

  ifstream archivo;
  string w = ""; //constructor segun la descomposicion del texto
  int cont = 0;
  archivo.open("PisosHotel.txt",ios::in); //abre archivo en modo lectura
  while (!archivo.eof()){
  	string texto = ""; //almacena linea del archivo
  	w="";
  	cont = 0;
  	//componentes de cada piso
  	int codigopais;
  	int codhotel;
	int NumPiso;
	string nombre = "";
	int Habitaciones;
    getline(archivo,texto);
    
    for (auto rem : texto) 
   { 
   	   //cout<<texto<<endl; 
       if (rem==';') 
       { 
       		if (cont==0){
	   			istringstream(w) >> codigopais;
           		//almacena codigo de hotel
           		w=""; 
           		
            }
            if (cont==1){
            	istringstream(w) >> codhotel;
           		//almacena codigo de hotel
           		w=""; 
            		
			}
			if (cont==2){
            	istringstream(w) >> NumPiso;
            	//almacena numpiso
            	w="";			
			}
			if (cont==3){
            	nombre = nombre+w;
            	//Nombre del piso 
            	w="";		
			}
			
			cont++;
       } 
       
       else
       { 
           w=w+rem; 
       } 
   }  
  // Cantidad de habitaciones
   istringstream(w) >> Habitaciones;
   if(Paises.Validar(codigopais)==1)
   	verificarInsertarPisos(pais.getRaizPais(),codigopais,codhotel,NumPiso,nombre,Habitaciones);
	//Inserta el piso
   //Hotel.InsertarPisosHotelF(codhotel, NumPiso,nombre,Habitaciones);
   
   
} 
  
  archivo.close();
}


void arbolHotel::verificarInsertarPisos(pnodoPais R,int codPais, int codigoh,int NumPiso, string NombrePiso, int habitaciones){
	if(R==NULL){
		return;
	}
	else{
        if (R->codigoPais==codPais){
    		verificarHoteles(R->hoteles,codigoh,NumPiso, NombrePiso, habitaciones);
		}
        verificarInsertarPisos(R->Hizq,codPais,codigoh,NumPiso, NombrePiso, habitaciones);
        verificarInsertarPisos(R->Hder,codPais,codigoh,NumPiso, NombrePiso, habitaciones);
    }
}

//encontrar la agencia para insertar pisos
void arbolHotel::verificarHoteles(pnodoHotel R,int codigohotel,int NumPiso, string NombrePiso, int habitaciones){
	if(R==NULL){
		return;
	}
	else{//encontrar con la identificacion de hotel
        if (R->codigoh==codigohotel){
    		insertarBalanceadoPisos(R->PisosHotel,false, NumPiso, NombrePiso, habitaciones);	
		}
        verificarHoteles(R->izq,codigohotel,NumPiso, NombrePiso, habitaciones);
        verificarHoteles(R->der,codigohotel,NumPiso, NombrePiso, habitaciones);
    }
}

//Insertar en el arbol AVL de Pisos, una vez encontrado el pais y el hotel
void arbolHotel::insertarBalanceadoPisos(pnodoPiso &ra,bool Hh,int NumPiso, string NombrePiso, int habitaciones){
	pnodoPiso n1;
    
    if(ra==NULL){
    	
        ra=new nodoPiso(NumPiso, NombrePiso, habitaciones);
        UltimoPiso=ra;
        //cout<<UltimoPiso->habitaciones<<endl;
        Hh = true;
    }else{
        ra->piso;
        if(NumPiso<ra->piso){
        	
            insertarBalanceadoPisos(ra->izq, Hh, NumPiso, NombrePiso, habitaciones);
			
		if(Hh){
            switch(ra->piso){
                case 1: ra->FB=0;
                Hh = false;
                break;
                case 0: ra->FB  = -1;
                break;
                case -1: n1=ra->izq;
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
            if(NumPiso>ra->piso){
				insertarBalanceadoPisos(ra->der, Hh, NumPiso, NombrePiso, habitaciones);
				
            if(Hh){
                    switch(ra->FB){
                        case -1: ra->FB=0;
                        Hh = false;
                        break;
                        case 0: ra->FB=1;
                        break;
                        case 1:n1=ra->der;
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


//Rotaciones del Arbol ALV 

void arbolHotel::RotacionDobleDerecha(pnodoPiso n, pnodoPiso n1){
    pnodoPiso n2;
    n2=n1->izq;
    n->der = n2->izq;
    n2->izq=n;
    n1->izq=n2->der;
    n2->der=n1;

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

void arbolHotel::RotacionSimpleDerecha(pnodoPiso n, pnodoPiso n1){
    n->der=n1->izq;
    n1->izq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
}

void arbolHotel::RotacionDobleIzquierda(pnodoPiso n, pnodoPiso n1){
    pnodoPiso n2;
    n2=n1->der;
    n->izq = n2->der;
    n2->der=n;
    n1->der=n2->izq;
    n2->izq=n1;

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

void arbolHotel::RotacionSimpleIzquierda(pnodoPiso n, pnodoPiso n1){
    n->izq=n1->der;
    n1->der=n;

    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    n=n1;
}

// H A B I T A C I O N E S-----------------------------------------------------------

void arbolHotel::lecturaHabitaciones(){
  
  ifstream archivo;
  archivo.open("Habitaciones.txt",ios::in); //abre archivo en modo lectura
  while (!archivo.eof()){
  	string texto = ""; //almacena linea del archivo
  	string w = ""; //constructor segun la descomposicion del texto
  	int cont = 0;
  	//componentes de cada habitacion
  	int codpais;
  	int codhotel;
	int numpiso;
	int codigoHabitacion;
	string cuartos ="";
	int Numcamas;
	int Precio;
	string Estado = "";
  	
    getline(archivo,texto);
    
    for (auto rem : texto) 
   { 
   	   //cout<<texto<<endl; 
       if (rem==';') 
       { 
       		if (cont==0){
	   			istringstream(w) >> codpais;
           		//codigo de hotel
           		w=""; 
           		
            }
            if (cont==1){
            	istringstream(w) >> codhotel;
           		//codigo de hotel
           		w=""; 
			}
			if (cont==2){
            	istringstream(w) >> numpiso;
            	//Numero de Piso
            	w="";		
			}
			if (cont==3){
            	istringstream(w) >> codigoHabitacion;
            	//Codigo de Habitacion
            	w="";	
			}
			if (cont==4){
            	cuartos = cuartos+w;
            	//Tipo de Cuarto
            	w="";		
			}
			if (cont==5){
            	istringstream(w) >> Numcamas;
            	//Numero de camas
            	w="";		
			}
			if (cont==6){
            	istringstream(w) >> Precio;
            	//Precio 
            	w="";		
			}
			cont++;
       } 
       
       else
       { 
           w=w+rem; 
       } 
   }  
  // Estado, solo puede ser L, O , R
   Estado = Estado+w;
   if ((Estado=="L")||(Estado=="R")||(Estado=="O")){
   		if(Paises.Validar(codpais)==1){
   			verificarPais(pais.getRaizPais(),codpais,codhotel,numpiso,codigoHabitacion,cuartos,Numcamas,Precio,Estado);
		   }
	   
	   w="";
} 
}
  
  archivo.close();
}

void arbolHotel::verificarPais(pnodoPais R,int codPais, int codigoh,int NumPiso, int codigoHabitacion, string cuartos, int Numcamas, int Precio, string Estado){
	if(R==NULL){
		return;
	}
	else{
        if (R->codigoPais==codPais){
    		verificarHotelesH(R->hoteles,codigoh,NumPiso,  codigoHabitacion, cuartos,Numcamas, Precio, Estado);
		}
        verificarPais(R->Hizq,codPais,codigoh,NumPiso,  codigoHabitacion, cuartos,Numcamas, Precio, Estado);
        verificarPais(R->Hder,codPais,codigoh,NumPiso,  codigoHabitacion, cuartos,Numcamas, Precio, Estado);
    }
}

//encontrar la agencia para insertar pisos
void arbolHotel::verificarHotelesH(pnodoHotel R,int codigohotel,int NumPiso, int codigoHabitacion, string cuartos, int Numcamas, int Precio, string Estado){
	if(R==NULL){
		return;
	}
	else{//encontrar con la identificacion de hotel
        if (R->codigoh==codigohotel){
    		verificarPisos(R->PisosHotel, NumPiso, codigoHabitacion, cuartos,Numcamas, Precio, Estado);	
		}
        verificarHotelesH(R->izq,codigohotel,NumPiso, codigoHabitacion, cuartos,Numcamas, Precio, Estado);
        verificarHotelesH(R->der,codigohotel,NumPiso, codigoHabitacion, cuartos,Numcamas, Precio, Estado);
    }
}

//encontrar la agencia para insertar pisos
void arbolHotel::verificarPisos(pnodoPiso R,int NumPiso, int codigoHabitacion, string cuartos, int Numcamas, int Precio, string Estado){
	if(R==NULL){
		return;
	}
	else{//encontrar con la identificacion de hotel
        if (R->piso==NumPiso){
        	int suma = cantHab(R->Habitaciones,0);
        	
        	suma++;
        	if(suma <= R->habitaciones)
    			insertarNodoRojoNegro(codigoHabitacion, cuartos,Numcamas, Precio, Estado, R);	
    		else{
    			R->habitaciones = suma;
    			insertarNodoRojoNegro(codigoHabitacion, cuartos,Numcamas, Precio, Estado, R);
			}
			
		}
        verificarPisos(R->izq,NumPiso,codigoHabitacion, cuartos,Numcamas, Precio, Estado);
        verificarPisos(R->der,NumPiso,codigoHabitacion, cuartos,Numcamas, Precio, Estado);
    }
}


void arbolHotel::insertarNodoRojoNegro(int codigoHabitacion,string cuartos,int Numcamas,int Precio,string Estado, pnodoPiso u){
     pnodoHabitaciones p,q;
     UltimaHabitacion =new nodoHabitaciones(codigoHabitacion,cuartos, Numcamas, Precio, Estado,NULL,NULL,'r');
     pnodoHabitaciones t=UltimaHabitacion;
     UltimaHabitacion=t;
     p=u->Habitaciones;
     q=NULL;
     if(u->Habitaciones==NULL)
     {
           u->Habitaciones=t;
           t->padre=NULL;
     }
     else
     {
         while(p!=NULL)
         {
              q=p;
              if(p->codHabitacion<t->codHabitacion)
                  p=p->der;
              else if(p->codHabitacion>t->codHabitacion)
                  p=p->izq;
              else{
              	break;
			  }  
         }
         t->padre=q;
         if(q->codHabitacion<t->codHabitacion)
              q->der=t;
         else if (q->codHabitacion>t->codHabitacion)
              q->izq=t;
         else{
		 }
		 
     }
     insertarTio(t,u);
}

void arbolHotel::insertarTio(pnodoHabitaciones t, pnodoPiso o)
{
     pnodoHabitaciones u;
     if(o->Habitaciones==t)
     {
         t->color='b';
         return;
     }
     while(t->padre!=NULL&&t->padre->color=='r')
     {
           pnodoHabitaciones g=t->padre->padre;
           if(g->izq==t->padre)
           {
                        if(g->der!=NULL)
                        {
                              u=g->der;
                              if(u->color=='r')
                              {
                                   t->padre->color='b';
                                   u->color='b';
                                   g->color='r';
                                   t=g;
                              }
                        }
                        else
                        {
                            if(t->padre->der==t)
                            {
                                 t=t->padre;
                                 rotacionIzquierda(t,o);
                            }
                            t->padre->color='b';
                            g->color='r';
                            rotacionDerecha(g,o);
                        }
           }
           else
           {
                        if(g->izq!=NULL)
                        {
                             u=g->izq;
                             if(u->color=='r')
                             {
                                  t->padre->color='b';
                                  u->color='b';
                                  g->color='r';
                                  t=g;
                             }
                        }
                        else
                        {
                            if(t->padre->izq==t)
                            {
                                   t=t->padre;
                                   rotacionDerecha(t,o);
                            }
                            t->padre->color='b';
                            g->color='r';
                            rotacionIzquierda(g,o);
                        }
           }
           o->Habitaciones->color='b';
     }
}


void arbolHotel::rotacionIzquierda(pnodoHabitaciones p,pnodoPiso j)
{
     if(p->der==NULL)
           return ;
     else
     {
           pnodoHabitaciones y=p->der;
           if(y->izq!=NULL)
           {
                  p->der=y->izq;
                  y->izq->padre=p;
           }
           else
                  p->der=NULL;
           if(p->padre!=NULL)
                y->padre=p->padre;
           if(p->padre==NULL)
                j->Habitaciones=y;
           else
           {
               if(p==p->padre->izq)
                       p->padre->izq=y;
               else
                       p->padre->der=y;
           }
           y->izq=p;
           p->padre=y;
     }
}
void arbolHotel::rotacionDerecha(pnodoHabitaciones p,pnodoPiso j)
{
     if(p->izq==NULL)
          return ;
     else
     {
         pnodoHabitaciones y=p->izq;
         if(y->der!=NULL)
         {
                  p->izq=y->der;
                  y->der->padre=p;
         }
         else
                 p->izq=NULL;
         if(p->padre!=NULL)
                 y->padre=p->padre;
         if(p->padre==NULL)
               j->Habitaciones=y;
         else
         {
             if(p==p->padre->izq)
                   p->padre->izq=y;
             else
                   p->padre->der=y;
         }
         y->der=p;
         p->padre=y;
     }
}

// Recorrer
int arbolHotel::cantHab(pnodoHabitaciones R, int pos){
	cout<<endl;
	if(R==NULL){
        return 0;
    }else{
    	pos = pos+1;
        cantHab(R->izq, pos);
        cantHab(R->der,pos);
    }
    return pos;
}
// Insertar Menu
void arbolHotel::insertarHotel(){
	int  cantestrellas;
    string nombre;
    int codpais;
	bool repetido1 = false;	
	bool repetido2 = false;
	while(repetido1==false && repetido2==false){
        cout<<"\nIngrese el codigo del pais en que desea insertar: ";
        if(cin>>codpais){
			if(Paises.Validar(codpais)==1){
			
	        	if((existePais(pais.getRaizPais(),codpais)==3)||existePais(pais.getRaizPais(),codpais)==2){
	        		//Entra si el codigo no existe o no hay hoteles
	            	repetido1=true;
	            	repetido2=true;
	            	break;
				}
			
				}
			else{
				cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
				repetido2=true;
				break;
					}
		}
		else{
			cout<<"\nEl codigo de pais debe ser un numero entero."<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	if(repetido1 ==true){
				
		bool no_repetido = false;
	    int codhotel ;    
	    while(no_repetido==false){
	        cout<<"\nIngrese el codigo del Hotel que desea insertar: ";
	        if(cin>>codhotel){
	        	nodoHotel* RaizHotel = paisencontrado->hoteles;
			
	        	if((existeHotel(RaizHotel, codhotel)==0)){
	        		//Entra si el codigo no existe o no hay hoteles
	            	no_repetido=true;
	            	break;
				}
				else{
					cout<<"\nEste codigo de hotel ya esta registrado, favor ingresar otro distinto "<<endl;
				}
			}
			else{
				cout<<"\nEl codigo de hotel debe ser un numero entero."<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
	        
		
		}
		if(no_repetido == true){
		
			cout<<"\nIngrese el nombre del hotel que desea insertar: ";
			cin.ignore();
			getline(cin,nombre);
			bool estrellas = false;
			while(estrellas == false){
				cout<<"\nIngrese las estrellas del hotel a insertar: ";
			
				if(cin>>cantestrellas){
					break;
				}
				else{
					cout<<"\nLa cantidad de estrellas del hotel debe ser un numero entero: "<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					
				}
			}
			
						
		    verificarInsertarHotel(pais.getRaizPais(),codpais,codhotel,nombre,cantestrellas);
		    printf("\033[32m");
		  	cout << "\nHotel insertado con exito" << endl;
			printf("\033[0m");
		}
	}
}
	
void arbolHotel::insertarPisos(){
	int codpais;
	int codhotel;
	int  NumPiso;
    string nombre;
    int Habitaciones;
    bool no_repetido = false;
    bool existe_hotel = false;
   
	//Entra mientras existan hoteles
	bool repetido1 = false;	
	bool verificaH = false;
	while(repetido1==false){
        cout<<"\nIngrese el codigo del pais en que desea insertar: ";
        if(cin>>codpais){
			if(Paises.Validar(codpais)==1){
			
	        	if(existePais(pais.getRaizPais(),codpais)==2){
	        		//Entra si el codigo no existe o no hay hoteles
	            	repetido1=true;
	            	verificaH = true;
	            	break;
				}
				if((existePais(pais.getRaizPais(),codpais)==3)){
					cout<<"\nEste pais no posee hoteles por lo que no puede insertar pisos"<<endl;
					repetido1=true;
					break;
				}
				else{
					cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
				}
			}
			else{
				cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
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
	if (verificaH == true){
		
	    while(existe_hotel==false){
	        cout<<"\nIngrese el codigo del Hotel en el que desea insertar: ";
	        if(cin>>codhotel){
	        	nodoHotel* RaizHotel = paisencontrado->hoteles;
			
	    		if((existeHotel(RaizHotel, codhotel)==0)){
	            	cout<<"\nEste codigo de hotel no esta registrado, favor ingresar otro distinto "<<endl;
	            	cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				
				if((existeHotel(RaizHotel, codhotel)==2)||(existeHotel(RaizHotel, codhotel)==3)){
						//Solo pasa si existe el hotel, no importa si tiene pisos o no
					existe_hotel=true;
	           	 	break;
				}
			}
			else{
				cout<<"\nEl codigo de hotel debe ser un numero entero"<<endl;
				system("pause>nul"); // Pausa 
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
				}
			}
		no_repetido = false;
		while(no_repetido==false){
	    	cout<<"\nIngrese el numero del piso del Hotel que desea insertar: ";
	    	if(cin>>NumPiso){
	    		nodoPiso* RaizPisos = hotelencontrado->PisosHotel;
	    		if((existePiso(RaizPisos,NumPiso)==0)){
	    			//Pasa solo si
	        		no_repetido=true;
	        		break;
				}
				else{
					cout<<"\nEste numero del piso ya esta registrado, favor ingresar otro distinto "<<endl;
				}
			}
			else{
				cout<<"\nEl numero de piso debe ser un numero entero"<<endl;
				system("pause>nul"); // Pausa 
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
			}
		}
				
		cout<<"\nIngrese el nombre del piso que desea insertar: "<<endl;
		cin.ignore();
		getline(cin,nombre);
		bool cantidad_hab = false;
		while(cantidad_hab==false){
			cout<<"Ingrese la cantidad de habitaciones del hotel a insertar: ";
			if(cin>>Habitaciones){
				cantidad_hab = true;
				break;
			}
			else{
				cout<<"\nLa cantidad de habitaciones debe ser un numero entero"<<endl;
				system("pause>nul"); // Pausa 
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		
		}
				
		verificarInsertarPisos(pais.getRaizPais(),codpais,codhotel,NumPiso,nombre,cantidad_hab);
		                
		printf("\033[32m");
		cout << "\nPiso insertado con exito" << endl;
		printf("\033[0m");
				
      }
    
    }

void arbolHotel::insertarHabitacion(){
	int codhotel, codpais;
	int NumPiso;
	int codigoHabitacion;
	string cuartos;
	int Numcamas;
	int Precio;
	string Estado;
    bool no_repetido = false;
    bool existe_piso = false;
    bool existe_hotel = false;

   	bool repetido1 = false;	
	bool verificaH = false;
	while(repetido1==false){
        cout<<"\nIngrese el codigo del pais en que desea insertar: ";
        if(cin>>codpais){
        	if(Paises.Validar(codpais)==1){
	        	if(existePais(pais.getRaizPais(),codpais)==2){
	        		//Entra si el codigo no existe o no hay hoteles
	            	repetido1=true;
	            	verificaH = true;
	            	break;
				}
				if((existePais(pais.getRaizPais(),codpais)==3)){
					cout<<"\nEste pais no posee hoteles por lo que no puede insertar habitaciones"<<endl;
					repetido1=true;
					break;
				}
				else{
					cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
				}
			}
			else{
				cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
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
	if(verificaH==true){
		while(existe_hotel==false){
    	cout<<"\nIngrese el codigo del Hotel en que desea insertar: ";
    	if(cin>>codhotel){
    		//Valores que devuelve la funcion
			/*
			 0 -> No existe el codigo hotel
			 2-> Existe Hotel con pisos
			 3-> El hotel existe, pero no tiene pisos
			 */
			 nodoHotel* RaizHotel = paisencontrado->hoteles;
			if((existeHotel(RaizHotel, codhotel)==0)){
        		cout<<"\nEste codigo de hotel no esta registrado, favor ingresar otro distinto "<<endl;
        		cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if((existeHotel(RaizHotel, codhotel)==3)){
				cout<<"\nEn este hotel no existen pisos registradas"<<endl;
				break;
			}
			if((existeHotel(RaizHotel, codhotel)==2)){		
				existe_hotel=true;
       	 		break;
			}
		}
		else{
			cout<<"\nEl codigo de hotel debe ser un numero entero"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	
	}
	if(existe_hotel==true){
		existe_piso = false;
		while(existe_piso==false){
        	cout<<"\nIngrese el numero del piso del Hotel que desea insertar: ";
        	if(cin>>NumPiso){
	    	//Valores que devuelve la funcion
				/*
				 0 -> No existe el NumPiso
				 1-> Existe el NumPios
				 2-> La lista de pisos est[a vacia
				 3-> El piso existe, pero no tiene habitaciones
				 */
				 nodoPiso* RaizPisos = hotelencontrado->PisosHotel;
        		if((existePiso(RaizPisos,NumPiso)==0)){
        			cout<<"\nEste numero del piso no esta registrado, favor ingresar otro distinto "<<endl;
        			break;
				}
				if((existePiso(RaizPisos,NumPiso)==2)||(existePiso(RaizPisos,NumPiso)==3)){
					//Para ingresar habitaciones solo importa si el piso existe
						
					existe_piso=true;
            		break;
				}
				
			}
			else{
				cout<<"\nEl numero de piso debe ser un numero entero"<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		if(existe_piso == true){
		
			while(no_repetido==false){
        		cout<<"\nIngrese el codigo de habitacion: ";
        		if(cin>>codigoHabitacion){
        				//Valores que devuelve la funcion
					/*
					 0 -> No existe el habitacion
					 1-> Existe la habitacion
					 2-> No hay habitaciones
					 3-> Piso sin habitaciones
					 */
					 nodoHabitaciones* RaizHabitacion = pisoencontrado->Habitaciones;
        			if((existeHabitaciones(RaizHabitacion,codigoHabitacion)==0)){
            			no_repetido=true;
           				break;
                		
					}
					else{
						cout<<"\nEste codigo de habitacion ya esta registrado, favor ingresar otro distinto "<<endl;
						
					}
				}
				else{
					cout<<"\nEl codigo de habitacion debe ser un numero entero"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			cout<<"\nIngrese el tipo de cuarto que desea insertar: ";
			cin>>cuartos;
			bool numero_camas = false;
			while(numero_camas == false){
				cout<<"\nIngrese el numero de camas: ";
				if(cin>>Numcamas){
					numero_camas = true;
					break;
				}
				else{
					cout<<"\nEl numero de camas debe ser un numero entero"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			
			bool precio = false;
			while(precio == false){
				cout<<"\nIngrese el precio de la habitacion: ";
				if(cin>>Precio){
					precio = true;
					break;
				}
				else{
					cout<<"\nEl precio debe ser un numero entero"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			bool estado = false;
			while(estado==false){
				cout<<"\nIngrese el estado de la habitacion: ";
				cin>>Estado;
				if((Estado == "L" )||(Estado=="l")||(Estado=="R")||(Estado=="r")||(Estado=="O")||(Estado=="o")){
					if(Estado=="l"){
						Estado = "L";
					}
					if(Estado == "o"){
						Estado = "O";
					}
					if(Estado == "r"){
						Estado = "R";
					}
					estado==true;
					break;
				}
				else{
					cout<<"\nEl estado de la habitacion debe ser 'L' , 'R' u 'O'"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				}
			}		
				
	    	verificarPais(pais.getRaizPais(),codpais,codhotel,NumPiso,codigoHabitacion,cuartos,Numcamas,Precio,Estado);
			printf("\033[32m");
			cout << "\nHabitacion insertado con exito" << endl;
			printf("\033[0m");
	    	
			}
			
		}
		
	}
	
		
}

// Modificar
void arbolHotel::modificarHotel(int opcion, int verificar){
	
    int codpais;
	bool repetido1 = false;
	bool verifica = false;	
	while(verifica==false){
        cout<<"\nIngrese el codigo del pais en que desea modificar: ";
        if(cin>>codpais){
        	if(Paises.Validar(codpais)==1){
			
			
	        	if(existePais(pais.getRaizPais(),codpais)==2){
	        		//Entra si el codigo no existe o no hay hoteles
	            	repetido1=true;
	            	verifica=true;
	            	break;
				}
				if ((existePais(pais.getRaizPais(),codpais)==3)){
					cout<<"Este pais no tiene hoteles registrados"<<endl;
					verifica=true;
					break;
					
				}
				else{
					cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
				}
			}
			else{
				cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
				verifica = true;
			}
		}
		else{
			cout<<"\nEl codigo de pais debe ser un numero entero."<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	if(repetido1==true){
			
		bool no_repetido = false;
	    int codhotel ;    
	    while(no_repetido==false){
	        cout<<"\nIngrese el codigo del Hotel en que desea modificar: ";
	        if(cin>>codhotel){
	        	nodoHotel* RaizHotel = paisencontrado->hoteles;
			
	        	if((existeHotel(RaizHotel, codhotel)==2)||(existeHotel(RaizHotel, codhotel)==3)){
	        		//Entra si el codigo no existe o no hay hoteles
	            	no_repetido=true;
	            	break;
				}
				else{
					cout<<"\nEste codigo de hotel no esta registrado, favor ingresar otro distinto "<<endl;
				}
			}
			else{
				cout<<"\nEl codigo de hotel debe ser un numero entero."<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
	        
		
	}

		modificarhotelaux(paisencontrado->hoteles,codhotel,opcion,verificar);
		
		
	}

	
}

void arbolHotel::modificarhotelaux(pnodoHotel R, int hotel,int opcion_menu, int verificador){
	int  cantestrellas;
    string nombre;

     if(hotel<R->codigoh)
         modificarhotelaux(R->izq, hotel, opcion_menu, verificador);
     else if(hotel> R->codigoh)
         modificarhotelaux(R->der, hotel, opcion_menu, verificador);
     else{
     	hotelencontrado = R;
     	if (opcion_menu == 2)
     	{
     		if (verificador==1)
     		{
     			bool estrellas = false;
				while(estrellas == false){
					cout<<"\nIngrese las estrellas del hotel a modificar: ";
				
					if(cin>>cantestrellas){
						break;
					}
					else{
						cout<<"\nLa cantidad de estrellas del hotel debe ser un numero entero: "<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						
					}
				}
     			R->estrellas = cantestrellas;
     			cout<<" La nueva cantidad de estrellas del hotel "<<R->estrellas<<endl;
			 }
			 if (verificador==2){
			 	cout<<"\nIngrese el nombre del hotel que desea insertar: ";
				cin.ignore();
				getline(cin,nombre);
			 	R->nombrehotel=nombre;
			 	
			 }
     	
		 }
	 }

		
	}

void arbolHotel::modificarPisos(int opcion, int verificar){
	int codpais;
	int codhotel;
	int  NumPiso;

    bool no_repetido = false;
    bool existe_hotel = false;
   
	//Entra mientras existan hoteles
	bool repetido1 = false;	
	bool verifica = false;
	while(verifica==false){
        cout<<"\nIngrese el codigo del pais en que desea modificar: ";
        if(cin>>codpais){
        	if(Paises.Validar(codpais)==1){
			
			
	        	if(existePais(pais.getRaizPais(),codpais)==2){
	        		//Entra si el codigo no existe o no hay hoteles
	            	repetido1=true;
	            	verifica=true;
	            	break;
				}
				if ((existePais(pais.getRaizPais(),codpais)==3)){
					cout<<"Este pais no tiene hoteles registrados"<<endl;
					verifica=true;
					break;
					
				}
				else{
					cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
				}
			}
			else{
				cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
				verifica = true;
			}
		}
		else{
			cout<<"\nEl codigo de pais debe ser un numero entero."<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	if (repetido1 == true){
		
	    while(existe_hotel==false){
	        cout<<"\nIngrese el codigo del Hotel en el que desea modificar: ";
	        if(cin>>codhotel){
	        	nodoHotel* RaizHotel = paisencontrado->hoteles;
			
	    		if((existeHotel(RaizHotel, codhotel)==0)){
	            	cout<<"\nEste codigo de hotel no esta registrado, favor ingresar otro distinto "<<endl;
	            	cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				
				if((existeHotel(RaizHotel, codhotel)==2)){
						//Solo pasa si existe el hotel, no importa si tiene pisos o no
					existe_hotel=true;
	           	 	break;
				}
				if((existeHotel(RaizHotel, codhotel)==3)){
					break;
					
				}
			}
			else{
				cout<<"\nEl codigo de hotel debe ser un numero entero"<<endl;
				system("pause>nul"); // Pausa 
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
				}
			}
			
		if(existe_hotel == true){
		
			no_repetido = false;
			while(no_repetido==false){
		    	cout<<"\nIngrese el numero del piso del Hotel que desea modificar: ";
		    	if(cin>>NumPiso){
		    		nodoPiso* RaizPisos = hotelencontrado->PisosHotel;
		    		if((existePiso(RaizPisos,NumPiso)==0)){
		    			//Pasa solo si
		    			cout<<"\nEste numero del piso no esta registrado"<<endl;
		    			break;
		    			
	
					}
					else{
						
						no_repetido=true;
		        		break;
					}
				}
				else{
					cout<<"\nEl numero de piso debe ser un numero entero"<<endl;
					system("pause>nul"); // Pausa 
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
				}
			}
			if(no_repetido == true){
				modificarPisosaux(hotelencontrado->PisosHotel, NumPiso, opcion, verificar);
				
			}

					
	      }
	  }
	
}

void arbolHotel::modificarPisosaux(pnodoPiso R, int NumPiso,int opcion, int verificador ){
			
	 string nombre;
     int Habitaciones;
	cout <<endl;

     if(NumPiso<R->piso)
         modificarPisosaux(R->izq, NumPiso, opcion, verificador);
     else if(NumPiso> R->piso)
         modificarPisosaux(R->der, NumPiso, opcion, verificador);
     else{
     	pisoencontrado = R;
     	if(verificador==1){
     		
     		bool cantidad_hab = false;
     		cout<<R->habitaciones<<endl;
			while(cantidad_hab==false){
				cout<<"Ingrese la cantidad de habitaciones del hotel a modificar: ";
				if(cin>>Habitaciones){
					cantidad_hab = true;
					break;
				}
				else{
					cout<<"\nLa cantidad de habitaciones debe ser un numero entero"<<endl;
					system("pause>nul"); // Pausa 
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			
			}
			int suma = cantHab(R->Habitaciones, 0);
			if(suma<Habitaciones){
				R->habitaciones = Habitaciones;
			}
			else{
				cout<<"\nLa nueva cantidad de habitaciones no respeta la cantidad de habitaciones registradas"<<endl;
			}
			
		 }
		 else{
		 	cout<<"\nIngrese el nombre del piso que desea modificar: "<<endl;
			cin.ignore();
			getline(cin,nombre);
			R->Nombre = nombre;
		 }
	 }
		
}

void arbolHotel::modificarHabitacion(int opcion, int verificar){
	int codhotel, codpais;
	int NumPiso;
	int codigoHabitacion;
	
    bool no_repetido = false;
    bool existe_piso = false;
    bool existe_hotel = false;

   	bool repetido1 = false;	
	bool verifica = false;
	while(verifica==false){
        cout<<"\nIngrese el codigo del pais en que desea modificar: ";
        if(cin>>codpais){
        	if(Paises.Validar(codpais)==1){
			
			
	        	if(existePais(pais.getRaizPais(),codpais)==2){
	        		//Entra si el codigo no existe o no hay hoteles
	            	repetido1=true;
	            	verifica=true;
	            	break;
				}
				if ((existePais(pais.getRaizPais(),codpais)==3)){
					cout<<"Este pais no tiene hoteles registrados"<<endl;
					verifica=true;
					break;
					
				}
				else{
					cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
				}
			}
			else{
				cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
				verifica = true;
			}
		}
		else{
			cout<<"\nEl codigo de pais debe ser un numero entero."<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	if(repetido1==true){
			while(existe_hotel==false){
	    	cout<<"\nIngrese el codigo del Hotel en que modificar : ";
	    	if(cin>>codhotel){
	    		//Valores que devuelve la funcion
				/*
				 0 -> No existe el codigo hotel
				 2-> Existe Hotel con pisos
				 3-> El hotel existe, pero no tiene pisos
				 */
				 nodoHotel* RaizHotel = paisencontrado->hoteles;
				if((existeHotel(RaizHotel, codhotel)==0)){
	        		cout<<"\nEste codigo de hotel no esta registrado, favor ingresar otro distinto "<<endl;
	        		cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if((existeHotel(RaizHotel, codhotel)==3)){
					cout<<"\nEn este hotel no existen pisos registradas"<<endl;
					break;
				}
				if((existeHotel(RaizHotel, codhotel)==2)){		
					existe_hotel=true;
	       	 		break;
				}
			}
			else{
				cout<<"\nEl codigo de hotel debe ser un numero entero"<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		
		}
		if(existe_hotel==true){
			existe_piso = false;
			while(existe_piso==false){
	        	cout<<"\nIngrese el numero del piso del Hotel que desea modificar: ";
	        	if(cin>>NumPiso){
		    	//Valores que devuelve la funcion
					/*
					 0 -> No existe el NumPiso
					 1-> Existe el NumPios
					 2-> La lista de pisos est[a vacia
					 3-> El piso existe, pero no tiene habitaciones
					 */
					 nodoPiso* RaizPisos = hotelencontrado->PisosHotel;
	        		if((existePiso(RaizPisos,NumPiso)==0)){
	        			cout<<"\nEste numero del piso no esta registrado, favor ingresar otro distinto "<<endl;
	        			break;
					}
					if((existePiso(RaizPisos,NumPiso)==2)){
						//Para ingresar habitaciones solo importa si el piso existe
							
						existe_piso=true;
	            		break;
					}
					if((existePiso(RaizPisos,NumPiso)==3)){
						cout<<"\nEste numero de piso no posee habitaciones, por lo que no ouede utilizar la opcion"<<endl;
						break;
					}
					
				}
				else{
					cout<<"\nEl numero de piso debe ser un numero entero"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			if(existe_piso == true){
			
				while(no_repetido==false){
	        		cout<<"\nIngrese el codigo de habitacion: ";
	        		if(cin>>codigoHabitacion){
	        				//Valores que devuelve la funcion
						/*
						 0 -> No existe el habitacion
						 1-> Existe la habitacion
						 2-> No hay habitaciones
						 3-> Piso sin habitaciones
						 */
						 nodoHabitaciones* RaizHabitacion = pisoencontrado->Habitaciones;
	        			if((existeHabitaciones(RaizHabitacion,codigoHabitacion)==0)){
	            			cout<<"\nEste codigo de habitacion ya esta registrado, favor ingresar otro distinto "<<endl;
	                		
						}
						else{
							
							no_repetido=true;
	           				break;
							
						}
					}
					else{
						cout<<"\nEl codigo de habitacion debe ser un numero entero"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			modificarHabitacionaux(pisoencontrado->Habitaciones, codigoHabitacion, opcion, verificar);
		}
		
	}
		
	}

}

void arbolHotel::modificarHabitacionaux(pnodoHabitaciones R, int codhabitacion, int opcion, int verificar){
	string cuartos;
	int Numcamas;
	int Precio;
	string Estado;

     if(codhabitacion<R->codHabitacion)
          modificarHabitacionaux(R->izq, codhabitacion, opcion, verificar);
     else if(codhabitacion> R->codHabitacion)
         modificarHabitacionaux(R->der, codhabitacion, opcion, verificar);
     else{
     	if(verificar==1){
     		
     		cout<< "Tipo de cuarto actual -> "<<R->cuarto<<endl;
     		cout<<endl;
     		cout<<"\nIngrese el tipo de cuarto que desea modificar: ";
     		cin.ignore();
			getline(cin,cuartos);
			R->cuarto =cuartos;
			cout<< "Nuevo valor de tipo de cuarto -> "<<R->cuarto<<endl;
		 }
		 if(verificar==2){
		 	cout<< "Numero de camas actual -> "<<R->camas<<endl;
		 	cout<<endl;
		 	bool numero_camas = false;
			while(numero_camas == false){
				cout<<"\nIngrese el numero de camas: ";
				if(cin>>Numcamas){
					numero_camas = true;
					break;
				}
				else{
					cout<<"\nEl numero de camas debe ser un numero entero"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			R->camas = numero_camas;
			cout<<"Nuevo numero de camas "<<R->camas<<endl;
		 }
     	if(verificar==3){
     		cout<< "Precio actual de la habitacion -> "<<R->precio<<endl;
     		cout<<endl;
     		bool precio = false;
			while(precio == false){
				cout<<"\nIngrese el precio de la habitacion: ";
				if(cin>>Precio){
					precio = true;
					break;
				}
				else{
					cout<<"\nEl precio debe ser un numero entero"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			R->precio = Precio;
			cout<<"Nuevo precio "<<R->precio<<endl;
		 }
		if(verificar==4){
			cout<< "Estado actual de la habitacion -> "<<R->estado<<endl;
     		cout<<endl;
			bool estado = false;
			while(estado==false){
				cout<<"\nIngrese el estado de la habitacion: ";
				cin>>Estado;
				if((Estado == "L" )||(Estado=="l")||(Estado=="R")||(Estado=="r")||(Estado=="O")||(Estado=="o")){
					if(Estado=="l"){
						Estado = "L";
					}
					if(Estado == "o"){
						Estado = "O";
					}
					if(Estado == "r"){
						Estado = "R";
					}
					estado==true;
					break;
				}
				else{
					cout<<"\nEl estado de la habitacion debe ser 'L' , 'R' u 'O'"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				}
			}
			R->estado = Estado;
			cout<<"Nuevo Estado "<<R->estado<<endl;		
			
		}
		
		}
     	
	 }
    
//Reportes
void arbolHotel::Reportes(int verificar){
	if(verificar==1){
		recorrePais(pais.getRaizPais(),verificar, 0, 0, 0, 0);
	}
	if (verificar==2){
		int codpais;
		bool repetido1 = false;
		bool verifica = false;
		while(verifica==false){
	        cout<<"\nIngrese el codigo del pais en que desea consultar: ";
	        if(cin>>codpais){
	        	if(Paises.Validar(codpais)==1){
				
				
		        	if(existePais(pais.getRaizPais(),codpais)==2){
		        		//Entra si el codigo no existe o no hay hoteles
		            	repetido1=true;
		            	verifica=true;
		            	break;
					}
					if ((existePais(pais.getRaizPais(),codpais)==3)){
						cout<<"Este pais no tiene hoteles registrados"<<endl;
						verifica=true;
						break;
						
					}
					else{
						cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
					}
				}
				else{
					cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
					verifica = true;
				}
			}
			else{
				cout<<"\nEl codigo de pais debe ser un numero entero."<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		if(repetido1==true){
				
			bool no_repetido = false;
		    int codhotel ;    
		    while(no_repetido==false){
		        cout<<"\nIngrese el codigo del Hotel en que desea consultar: ";
		        if(cin>>codhotel){
		        	nodoHotel* RaizHotel = paisencontrado->hoteles;
				
		        	if((existeHotel(RaizHotel, codhotel)==2)||(existeHotel(RaizHotel, codhotel)==3)){
		        		//Entra si el codigo no existe o no hay hoteles
		            	no_repetido=true;
		            	break;
					}
					else{
						cout<<"\nEste codigo de hotel no esta registrado, favor ingresar otro distinto "<<endl;
					}
				}
				else{
					cout<<"\nEl codigo de hotel debe ser un numero entero."<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			
			}
		recorrePais(pais.getRaizPais(), verificar,codpais, codhotel,0,0);
			
		}
		
	}
	if (verificar==3){
		cout<<"Ultimo hotel insertado: "<<endl;
		cout<<"Nombre Hotel: "<< UltimoHotel->nombrehotel<<endl;
		cout<<"Codigo: "<<UltimoHotel->codigoh<<endl;
	}
	if(verificar==4|| verificar==44 || verificar==5){
		int codpais;
		int codhotel;
		int  NumPiso;
	
	    bool no_repetido = false;
	    bool existe_hotel = false;
	   
		//Entra mientras existan hoteles
		bool repetido1 = false;	
		bool verifica = false;
		while(verifica==false){
	        cout<<"\nIngrese el codigo del pais en que desea consultar: ";
	        if(cin>>codpais){
	        	if(Paises.Validar(codpais)==1){
				
				
		        	if(existePais(pais.getRaizPais(),codpais)==2){
		        		//Entra si el codigo no existe o no hay hoteles
		            	repetido1=true;
		            	verifica=true;
		            	break;
					}
					if ((existePais(pais.getRaizPais(),codpais)==3)){
						cout<<"Este pais no tiene hoteles registrados"<<endl;
						verifica=true;
						break;
						
					}
					else{
						cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
					}
				}
				else{
					cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
					verifica = true;
				}
			}
			else{
				cout<<"\nEl codigo de pais debe ser un numero entero."<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		if (repetido1 == true){
			
		    while(existe_hotel==false){
		        cout<<"\nIngrese el codigo del Hotel en el que desea consultar: ";
		        if(cin>>codhotel){
		        	nodoHotel* RaizHotel = paisencontrado->hoteles;
				
		    		if((existeHotel(RaizHotel, codhotel)==0)){
		            	cout<<"\nEste codigo de hotel no esta registrado, favor ingresar otro distinto "<<endl;
		            	cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						
					}
					
					if((existeHotel(RaizHotel, codhotel)==2)){
							//Solo pasa si existe el hotel, no importa si tiene pisos o no
						existe_hotel=true;
		           	 	break;
					}
					if((existeHotel(RaizHotel, codhotel)==3)){
						break;
						
					}
				}
				else{
					cout<<"\nEl codigo de hotel debe ser un numero entero"<<endl;
					system("pause>nul"); // Pausa 
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
					}
				}
				
			if(existe_hotel == true ){
				if ((verificar==4) || (verificar==5)){
				
					no_repetido = false;
					while(no_repetido==false){
				    	cout<<"\nIngrese el numero del piso del Hotel que desea consultar: ";
				    	if(cin>>NumPiso){
				    		nodoPiso* RaizPisos = hotelencontrado->PisosHotel;
				    		if((existePiso(RaizPisos,NumPiso)==0)){
				    			//Pasa solo si
				    			cout<<"\nEste numero del piso no esta registrado"<<endl;
				    			break;
				    			
			
							}
							else{
								
								no_repetido=true;
				        		break;
							}
						}
						else{
							cout<<"\nEl numero de piso debe ser un numero entero"<<endl;
							system("pause>nul"); // Pausa 
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
					
						}
					}
				}
				if(no_repetido == true){
					recorrePais(pais.getRaizPais(), verificar, codpais, codhotel, NumPiso,0);
					
				}
			
		      }
		      if(existe_hotel== true && verificar==44){
					recorrePais(pais.getRaizPais(), verificar, codpais, codhotel, 0,0);
				}
		  }
	}
	if(verificar==6){
		cout<<"Ultimo piso insertado: "<<endl;
		cout<<"Nombre Piso: "<<UltimoPiso->Nombre<<endl;
		cout<<"Codigo: "<<UltimoPiso->piso<<endl;
	}
	if (verificar==7 ||verificar==77){
		int codhotel, codpais;
		int NumPiso;
		int codigoHabitacion;
		
	    bool no_repetido = false;
	    bool existe_piso = false;
	    bool existe_hotel = false;
	
	   	bool repetido1 = false;	
		bool verifica = false;
		while(verifica==false){
	        cout<<"\nIngrese el codigo del pais en que desea consultar: ";
	        if(cin>>codpais){
	        	if(Paises.Validar(codpais)==1){
				
				
		        	if(existePais(pais.getRaizPais(),codpais)==2){
		        		//Entra si el codigo no existe o no hay hoteles
		            	repetido1=true;
		            	verifica=true;
		            	break;
					}
					if ((existePais(pais.getRaizPais(),codpais)==3)){
						cout<<"Este pais no tiene hoteles registrados"<<endl;
						verifica=true;
						break;
						
					}
					else{
						cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
					}
				}
				else{
					cout<<"\nEste codigo de pais no esta registrado, favor ingresar otro distinto "<<endl;
					verifica = true;
				}
			}
			else{
				cout<<"\nEl codigo de pais debe ser un numero entero."<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		if(repetido1==true){
				while(existe_hotel==false){
		    	cout<<"\nIngrese el codigo del Hotel en que consultar: ";
		    	if(cin>>codhotel){
		    		//Valores que devuelve la funcion
					/*
					 0 -> No existe el codigo hotel
					 2-> Existe Hotel con pisos
					 3-> El hotel existe, pero no tiene pisos
					 */
					 nodoHotel* RaizHotel = paisencontrado->hoteles;
					if((existeHotel(RaizHotel, codhotel)==0)){
		        		cout<<"\nEste codigo de hotel no esta registrado, favor ingresar otro distinto "<<endl;
		        		cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if((existeHotel(RaizHotel, codhotel)==3)){
						cout<<"\nEn este hotel no existen pisos registradas"<<endl;
						break;
					}
					if((existeHotel(RaizHotel, codhotel)==2)){		
						existe_hotel=true;
		       	 		break;
					}
				}
				else{
					cout<<"\nEl codigo de hotel debe ser un numero entero"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			
			}
			if(existe_hotel==true){
				existe_piso = false;
				while(existe_piso==false){
		        	cout<<"\nIngrese el numero del piso del Hotel que desea consultar: ";
		        	if(cin>>NumPiso){
			    	//Valores que devuelve la funcion
						/*
						 0 -> No existe el NumPiso
						 1-> Existe el NumPios
						 2-> La lista de pisos est[a vacia
						 3-> El piso existe, pero no tiene habitaciones
						 */
						 nodoPiso* RaizPisos = hotelencontrado->PisosHotel;
		        		if((existePiso(RaizPisos,NumPiso)==0)){
		        			cout<<"\nEste numero del piso no esta registrado, favor ingresar otro distinto "<<endl;
		        			break;
						}
						if((existePiso(RaizPisos,NumPiso)==2)){
							//Para ingresar habitaciones solo importa si el piso existe
								
							existe_piso=true;
		            		break;
						}
						if((existePiso(RaizPisos,NumPiso)==3)){
							cout<<"\nEste numero de piso no posee habitaciones, por lo que no ouede utilizar la opcion"<<endl;
							break;
						}
						
					}
					else{
						cout<<"\nEl numero de piso debe ser un numero entero"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				if(existe_piso == true && verificar==7){
				
					while(no_repetido==false){
		        		cout<<"\nIngrese el codigo de habitacion: ";
		        		if(cin>>codigoHabitacion){
		        				//Valores que devuelve la funcion
							/*
							 0 -> No existe el habitacion
							 1-> Existe la habitacion
							 2-> No hay habitaciones
							 3-> Piso sin habitaciones
							 */
							 nodoHabitaciones* RaizHabitacion = pisoencontrado->Habitaciones;
		        			if((existeHabitaciones(RaizHabitacion,codigoHabitacion)==0)){
		            			cout<<"\nEste codigo de habitacion no esta registrado, favor ingresar otro distinto "<<endl;
		            			break;
		                		
							}
							else{
								
								no_repetido=true;
		           				break;
								
							}
						}
						else{
							cout<<"\nEl codigo de habitacion debe ser un numero entero"<<endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					}
					if(no_repetido==true)
						recorrePais(pais.getRaizPais(), verificar, codpais, codhotel, NumPiso,codigoHabitacion);
				
			}
			if(existe_piso==true || verificar == 77)
				recorrePais(pais.getRaizPais(), verificar, codpais, codhotel, NumPiso,0);
			
			
		}
			
		}
		
	}
		

	if(verificar==8){
		cout<<"Ultima habitacion insertado: "<<endl;
		cout<<"Codigo: "<<UltimaHabitacion->codHabitacion<<endl;	
	}
	if(verificar==9){
		ReservacionesH.Mostrar();
		//recorrePais(pais.getRaizPais(), verificar, 0, 0, 0, 0);
	}
}

void arbolHotel::MostrarHabitaciones(pnodoHabitaciones R,int verificar, int codpais, int codhotel, int numpiso, int codhab){
	
	if(R==NULL){
        return;
    }else{
        MostrarHabitaciones(R->izq,verificar,codpais, codhotel, numpiso, codhab);
        if(verificar==77){
        	cout<<"Codigo Habitacion "<<R->codHabitacion<<endl;
			cout<<"Tipo de Cuarto: "<<R->cuarto<<endl;
			cout<<"Numero de Camas: "<<R->camas<<endl;
			cout<<"Precio: "<<R->precio<<endl;
			cout<<"Estado: "<<R->estado<<endl;
			cout<<endl;
		}
		if(verificar==7){
			if(codhab== R->codHabitacion){
				cout<<"Codigo Habitacion "<<R->codHabitacion<<endl;
				cout<<"Tipo de Cuarto: "<<R->cuarto<<endl;
				cout<<"Numero de Camas: "<<R->camas<<endl;
				cout<<"Precio: "<<R->precio<<endl;
				cout<<"Estado: "<<R->estado<<endl;
    			cout<<endl;
			}
		}
		if(verificar==9){
			if(R->estado == "R"){
				cout<<"Codigo Habitacion "<<R->codHabitacion<<endl;
    			cout<<endl;
			}
		}
        MostrarHabitaciones(R->der,verificar,codpais, codhotel, numpiso, codhab);
    }
}

void arbolHotel::MostrarPisos(pnodoPiso R,int verificar, int codpais, int codhotel, int numpiso, int codhab){
	
	if(R==NULL){
        return;
    }else{
        MostrarPisos(R->izq, verificar,codpais, codhotel, numpiso, codhab);
        if(verificar==4){
        	if(numpiso == R->piso ){
        		
        		cout<<"Codigo Piso "<<R->piso<<endl;
	        	cout<<"Nombre Piso "<<R->Nombre<<endl;
	        	
			}
		}
		if(verificar==5){
        	if(numpiso == R->piso ){
        		
        		cout<<"Codigo Piso "<<R->piso<<endl;
	        	cout<<"Habitaciones "<<R->habitaciones<<endl;
	        	
			}
		}
		if(verificar==44){
		
			cout<<"Codigo Piso "<<R->piso<<endl;
    		cout<<"Nombre Piso "<<R->Nombre<<endl;
    		cout<<"Cantidad Habitaciones "<<R->habitaciones<<endl;
			
    		
        	
		}
		if(verificar==7 || verificar ==77){
			if(R->piso = numpiso)
				MostrarHabitaciones(R->Habitaciones,verificar,codpais, codhotel, numpiso, codhab );	
		}
		if(verificar==9){
			MostrarHabitaciones(R->Habitaciones,verificar,codpais, codhotel, numpiso, codhab );
		}
        
        MostrarPisos(R->der, verificar,codpais, codhotel, numpiso, codhab);
    }
}

void arbolHotel::MostrarHoteles(pnodoHotel R, int verificar, int codpais, int codhotel, int numpiso, int codhab){
	//recorrido recursivo para el Arbol BB de Hotel
	if(R==NULL){
        return;
    }else{
        MostrarHoteles(R->izq, verificar,codpais, codhotel, numpiso, codhab);
        if(verificar==1){
        	
        	cout<<endl;
        	cout<<"Codigo Hotel "<<R->codigoh<<endl;
        	cout<<"Nombre Hotel "<<R->nombrehotel<<endl;
        	
		}
		if(verificar==2){
			if(codhotel == R->codigoh){
				
				cout<<"Codigo Hotel "<<R->codigoh<<endl;
        		cout<<"Estrellas "<<R->estrellas<<endl;
        		
			}
		}
		if(verificar==4 || verificar==44 || verificar==5 || verificar==7 || verificar ==77){
			if(codhotel == R->codigoh)
				MostrarPisos(R->PisosHotel,verificar,codpais, codhotel, numpiso, codhab);
		}
		if(verificar==9){
			MostrarPisos(R->PisosHotel,verificar,codpais, codhotel, numpiso, codhab);
		}
		
        
        MostrarHoteles(R->der, verificar,codpais, codhotel,  numpiso,  codhab);
    }
}

void arbolHotel::recorrePais(pnodoPais R, int verificar, int codpais, int codhotel, int numpiso, int codhab){//recorrido inorden recursivo para el arbol BB de Paises para llegar agencias
    if(R==NULL){
        return;
    }else{
        recorrePais(R->Hizq, verificar ,codpais, codhotel,  numpiso,  codhab);
        MostrarHoteles(R->hoteles, verificar,codpais, codhotel,  numpiso,  codhab);
    
        recorrePais(R->Hder, verificar,codpais, codhotel,  numpiso,  codhab);
    }
}
