#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "nodoListaPaises.h"
#include "ListaPaises.h"
#include  "nodoReservas.h"
#include "Reservaciones.h"

#include "nodoTipoFlotilla.h"
#include "nodoAgencia.h"

#include "nodoHabitaciones.h"
#include "nodoPisosHotel.h"
#include "nodoHotel.h"

#include "nodoPais.h"


#include "arbolPais.h"
#include "arbolHotel.h"
#include "arbolAgencia.h"



using namespace std;

//-----------------------------------------------------------------------------------MENUS----------------------------------------------------------------------------------------------------
int menu_reportesh(arbolHotel hotel, arbolPais pais)
{
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
        

        cout << "\n\nQue desea Consultar?" << endl;

        cout << "\n\nHoteles" << endl;

        cout << "1. Consultar Hoteles" << endl;
        cout << "2. Consultar Estrellas de un hotel" << endl;
        cout << "3. Consultar Ultimo hotel insertado" << endl;

        cout << "\n\nPisos" << endl;

        cout << "4. Consultar Pisos" << endl;
        cout << "5. Consultar Cantidad de habitaciones" << endl;
        cout << "6. Consultar Ultimo piso insertado" << endl;

        cout << "\n\nHabitaciones" << endl;

        cout << "7. Consultar Habitaciones" << endl;
        cout << "8. Consultar Ultima habitacion insertada" << endl;
        cout << "9. Consultar Reservaciones"<< endl;
    
        cout << "\n\n10. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        if(cin>>opcion){
		
        switch (opcion) {
            case 1:
                //Consultar Hoteles
				//Imprime todos los hoteles
				
				hotel.Reportes(1);
				
				
  				system("pause>nul"); // Pausa
  				break;
                
            case 2:
                //Consultar Estrellas de un Hotel
				//solicita codigo de hotel 
				
				            
                hotel.Reportes(2);
  				system("pause>nul"); // Pausa
  				break;
                
            case 3:
                //Consultar ultimo hotel insertado              
                hotel.Reportes(3);
                system("pause>nul"); // Pausa            
                break;
                
            case 4:
                //Consultar Pisos
				//solicita codigo de hotel 
				
				hotel.Reportes(4);
				
				
                system("pause>nul"); // Pausa
                break;
                
            case 5:
                //Consultar Cantidad de habitaciones de un piso 
				//solicita codigo de hotel y Numero de piso   
				
				         
                hotel.Reportes(5);
  				
  				system("pause>nul"); // Pausa
  				break;
                
            case 6:
                //Ultimo piso insertado              
                hotel.Reportes(6);
                system("pause>nul"); // Pausa            
                break;
                
          	case 7:
                //Consultar Habitaciones Especificas
				//solicita codigo de hotel y Numero de piso 
				
				hotel.Reportes(77);
                system("pause>nul"); // Paua
                break;
                
            case 8:
                //Consultar ultima habitacion insertada               
                hotel.Reportes(8);
                system("pause>nul"); // Pausa            
                break;
            case 9:
            //Consultar ultima habitacion insertada               
            hotel.Reportes(9);
            system("pause>nul"); // Pausa            
            break;
        }  
	}
	else{
		cout<<"Favor ingresar el numero correspondiente a la opcion"<<endl;
		system("pause>nul"); // Pausa 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
	}
            
    } while (opcion != 10);            //opción de SALIDA        
    return 0;
   
}

//Menu ModificarHoteles-------------------------------------------------------- 
int menu_modificarh(arbolHotel hotel, arbolPais pais)
{
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
        
        
        cout << "\n\nQue desea Modificar?" << endl;

        cout << "\n\nHoteles" << endl;

        cout << "1. Modificar Estrellas" << endl;
        cout << "2. Modificar Nombre de hotel" << endl;

        cout << "\n\nPisos" << endl;

        cout << "3. Modificar Cantidad de habitaciones" << endl;
        cout << "4. Modificar Nombre de piso" << endl;

        cout << "\n\nHabitaciones" << endl;

        cout << "5. Modificar TipoCuarto" << endl;
        cout << "6. Modificar Numero de camas" << endl;
        cout << "7. Modificar Precio" << endl;
        cout << "8. Modificar Estado del cuarto" << endl;
    
        cout << "\n\n9. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        if(cin>>opcion){
	
        
        switch (opcion) {
            case 1:
                //Modificar Estrellas
				//Solicita el codigo de hotel                
                
				hotel.modificarHotel(2,1);
                system("pause>nul"); // Pausa
                break;
                
            case 2:
                //Modificar Nombre de hotel 
				//Solicita el codigo de hotel               
                hotel.modificarHotel(2,2);

				 
                system("pause>nul"); // Pausa
                break;
                
            case 3:
                //Modificar cantidad de habitaciones
				//Solicita el codigo de hotel y numero de piso              
                
				hotel.modificarPisos(2,1);
                system("pause>nul"); // Pausa
                break;
                
            case 4:
                //Modificar Nombre de piso  
				//Solicita el codigo de hotel y numero de piso
				
        
                hotel.modificarPisos(2,2);
                system("pause>nul"); // Pausa
                break;
                
            case 5:
                //Modificar Tipo de cuarto   
				//Solicita el codigo de hotel y numero de piso            
                hotel.modificarHabitacion(2,1);
                system("pause>nul"); // Pausa
                break;
                
            case 6:
                //Modificar numero de camas  
				//Solicita el codigo de hotel y numero de piso        
                hotel.modificarHabitacion(2,2);
                system("pause>nul"); // Pausa            
                break;
                
          	case 7:
                //Modificar Precio 
				//Solicita el codigo de hotel y numero de piso             
                hotel.modificarHabitacion(2,3);
                system("pause>nul"); // Pausa
                break;
                
            case 8:
                //Modificar Estado del cuarto
				//Solicita el codigo de hotel y numero de piso               
                hotel.modificarHabitacion(2,4);
                system("pause>nul"); // Pausa            
                break;
        }     
	}
	else{
		cout<<"Favor ingresar el numero correspondiente a la opcion"<<endl;
		system("pause>nul"); // Pausa 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
	}
            
    } while (opcion != 9);           //opción de SALIDA        
    return 0;
   
}

//Menu InsertarHoteles-------------------------------------------------------- 
int menu_insertarh(arbolHotel hotel, arbolPais pais)
{
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
        
        printf("\033[32m");
        cout << "\n\nQue desea insertar?" << endl;
        printf("\033[0m");
        cout << "\n\n1. Insertar Hotel" << endl;
        cout << "2. Insertar Piso" << endl;
        cout << "3. Insertar Habitacion" << endl;
        cout << "4. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        if(cin>>opcion){
        
        switch (opcion) {
            case 1:
                //Insertar Hotel 
				//Pide Codigo,Nombre,Cantidad de estrellas 
				//VALIDA QUE NO SE REPITAN LOS CODIGOS DE HOTEL      
				 {
				hotel.insertarHotel();
				
				//InordenHotel(pais.getRaizPais());
				system("pause>nul"); // Pausa
                break;
                
                }   
            case 2:
               //Insertar Piso   
               //solicita el codigo de hotel
			   //Pide CodigoHotel,NumPiso,Nombre,Cantidad de Habitaciones          
               //VALIDA QUE NO SE REPITAN LOS NUMEROS DE PISO  
               {
               	hotel.insertarPisos();

                system("pause>nul"); // Pausa
                break;
                }  
        
            case 3:
                //Insertar Habitacion 
                //Solicita CodHotel,NumPiso
				//Pide CodigoHotel,NumPiso,CodigoHabitacion,TipodeCuarto,NumCamas,Precio;Estado               
                //VALIDA QUE NO SE REPITAN LOS CODIGOS DE HABITACION 
                {
					hotel.insertarHabitacion();

                system("pause>nul"); // Pausa
                break;
                
                }
                
        }   
	}
	else{
		cout<<"Favor ingresar el numero correspondiente a la opcion"<<endl;
		system("pause>nul"); // Pausa 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
	}
    } while (opcion != 4);            //opción de SALIDA        
    return 0;
   
}

int menu_hoteles(arbolHotel hotel, arbolPais pais)
{
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
        
        printf("\033[7;1;36m");
        cout << "\n\nBIENVENIDO ADMINISTRADOR DE HOTEL" << endl;
        printf("\033[0m");
        printf("\033[32m");
		cout << "\n\nQue desea hacer?" << endl;
		printf("\033[0m");
        cout << "\n\n1. Insertar" << endl;
        cout << "2. Modificar" << endl;
        cout << "3. Reportes" << endl;
        cout << "4. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        if(cin>>opcion){
        
        switch (opcion) {
            case 1:
                // Opciones de insertar                
                
                //system("pause>nul"); // Pausa
                menu_insertarh(hotel,pais);
                break;
                
            case 2:
                //Opciones de modificar               
                
                //system("pause>nul"); // Pausa 
				menu_modificarh(hotel,pais);           
                break;
                
			case 3:
                //Opciones de Consulta               
                
                //system("pause>nul"); // Pausa 
				menu_reportesh(hotel,pais);           
                break;


        }     
	}
	else{
		cout<<"Favor ingresar el numero correspondiente a la opcion"<<endl;
		system("pause>nul"); // Pausa 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
	}
    } while (opcion != 4);            // En vez de 5 pones el número de la opción de SALIDA        
    return 0;
}

int menu_lista()
{
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
    
        printf("\033[32m");
		cout << "\n\nQue desea hacer?" << endl;
		printf("\033[0m");
        cout << "\n\n1. Insertar" << endl;
        cout << "2. Eliminar" << endl;
        cout << "3. Modificar" << endl;
        cout << "4. Reportes" << endl;
        cout << "5. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        if(cin>>opcion){
        
        switch (opcion) {
            case 1:
                // Opciones de insertar                
                Paises.Datos(1);
                system("pause>nul"); // Pausa
                
                break;
                
            case 2:
                //Opciones de modificar               
                Paises.Datos(2);
                system("pause>nul"); // Pausa 
         
                break;
                
			case 3:
                //Opciones de Consulta               
                Paises.Datos(2);
                system("pause>nul"); // Pausa 
				         
                break;
            case 4:
	            //Opciones de modificar               
	            Paises.Mostrar(); 
	        	system("pause>nul"); // Pausa 
				     
	            break;
                


        }     
	}
	else{
		cout<<"Favor ingresar el numero correspondiente a la opcion"<<endl;
		system("pause>nul"); // Pausa 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
	}
    } while (opcion != 5);            // En vez de 5 pones el número de la opción de SALIDA        
    return 0;
}
int main(){
	Paises.leerArchivoPais();

	pais.leerArchivoPais();
	pais.InordenR(pais.getRaizPais());
	
	arbolAgencia agencia;
	arbolHotel hotel;
	
	hotel.lecturaHoteles();
	//InordenHotel(pais.getRaizPais());
	cout<<endl;
	hotel.lecturaPisosHotel();
	cout<<endl;
	hotel.lecturaHabitaciones();
	
	system("pause>nul"); // Pausa

	
	menu_hoteles(hotel, pais);
	

	return 0;
}
