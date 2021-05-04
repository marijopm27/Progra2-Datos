#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "nodoTipoFlotilla.h"
#include "nodoAgencia.h"
#include "nodoPisosHotel.h"
#include "nodoHotel.h"
#include "nodoPais.h"


#include "arbolPais.h"
#include "arbolHotel.h"
#include "arbolAgencia.h"



using namespace std;

//-----------------------------------------------------------------------------------MENUS----------------------------------------------------------------------------------------------------
int menu_reportesh()
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
    
        cout << "\n\n9. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        if(cin>>opcion){
		
        switch (opcion) {
            case 1:
                //Consultar Hoteles
				//Imprime todos los hoteles
				
				
				
  				//system("pause>nul"); // Pausa
  				break;
                
            case 2:
                //Consultar Estrellas de un Hotel
				//solicita codigo de hotel 
				
				            
                
  				//system("pause>nul"); // Pausa
  				break;
                
            case 3:
                //Consultar ultimo hotel insertado              
                
                //system("pause>nul"); // Pausa            
                break;
                
            case 4:
                //Consultar Pisos
				//solicita codigo de hotel 
				
				
				
				
                //system("pause>nul"); // Pausa
                break;
                
            case 5:
                //Consultar Cantidad de habitaciones de un piso 
				//solicita codigo de hotel y Numero de piso   
				
				         
                
  				
  				//system("pause>nul"); // Pausa
  				break;
                
            case 6:
                //Ultimo piso insertado              
                
                system("pause>nul"); // Pausa            
                break;
                
          	case 7:
                //Consultar Habitaciones Especificas
				//solicita codigo de hotel y Numero de piso 
				
				          
                
                //system("pause>nul"); // Paua
                break;
                
            case 8:
                //Consultar ultima habitacion insertada               
                
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
            
    } while (opcion != 9);            //opción de SALIDA        
    return 0;
   
}

//Menu ModificarHoteles-------------------------------------------------------- 
int menu_modificarh()
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
                

                system("pause>nul"); // Pausa
                break;
                
            case 2:
                //Modificar Nombre de hotel 
				//Solicita el codigo de hotel               
                

				 
                system("pause>nul"); // Pausa
                break;
                
            case 3:
                //Modificar cantidad de habitaciones
				//Solicita el codigo de hotel y numero de piso              
                

                system("pause>nul"); // Pausa
                break;
                
            case 4:
                //Modificar Nombre de piso  
				//Solicita el codigo de hotel y numero de piso
				
        
                
                system("pause>nul"); // Pausa
                break;
                
            case 5:
                //Modificar Tipo de cuarto   
				//Solicita el codigo de hotel y numero de piso            
                
                system("pause>nul"); // Pausa
                break;
                
            case 6:
                //Modificar numero de camas  
				//Solicita el codigo de hotel y numero de piso        
                
                system("pause>nul"); // Pausa            
                break;
                
          	case 7:
                //Modificar Precio 
				//Solicita el codigo de hotel y numero de piso             
                
                system("pause>nul"); // Pausa
                break;
                
            case 8:
                //Modificar Estado del cuarto
				//Solicita el codigo de hotel y numero de piso               
                
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


//Menu EliminarHoteles---------------------------------------------------------- 
int menu_eliminarh()
{
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez

        cout << "\n\nQue desea eliminar?" << endl;

        cout << "\n\n1. Eliminar Hotel" << endl;
        cout << "2. Eliminar Piso" << endl;
        cout << "3. Eliminar Habitacion" << endl;
        cout << "4. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        if(cin>>opcion){
        
        switch (opcion) {
            case 1:
                //Eliminar Hotel    
				          
                //system("pause>nul"); // Pausa
                break;
                
            case 2:
                //Eliminar Piso
				//Solicita Codigo de hotel               

                system("pause>nul"); // Pausa
                break;
                
            case 3:
                //Eliminar Habitacion   
				//Solicita Codigo de hotel y Numero de piso            

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
    } while (opcion != 4);            //opción de SALIDA        
    return 0;
   
}

//Menu InsertarHoteles-------------------------------------------------------- 
int menu_insertarh()
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
					

                system("pause>nul"); // Pausa
                break;
                
                }   
            case 2:
               //Insertar Piso   
               //solicita el codigo de hotel
			   //Pide CodigoHotel,NumPiso,Nombre,Cantidad de Habitaciones          
               //VALIDA QUE NO SE REPITAN LOS NUMEROS DE PISO  
               {
					


                system("pause>nul"); // Pausa
                break;
                }  
        
            case 3:
                //Insertar Habitacion 
                //Solicita CodHotel,NumPiso
				//Pide CodigoHotel,NumPiso,CodigoHabitacion,TipodeCuarto,NumCamas,Precio;Estado               
                //VALIDA QUE NO SE REPITAN LOS CODIGOS DE HABITACION 
                {
					

				
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


int main(){

	pais.leerArchivoPais();
	pais.InordenR(pais.getRaizPais());
	
	arbolAgencia agencia;
	arbolHotel hotel;
	hotel.lecturaHoteles();
	InordenHotel(pais.getRaizPais());
	cout<<endl;
	hotel.lecturaPisosHotel();
	menu_insertarh();
	
	//agencia.leerArchivoAgencias();
	//agencia.leerArchivoTipoFlotilla();
	//InordenAgencia(pais.getRaizPais());
	
	return 0;
}
