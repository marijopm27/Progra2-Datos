#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "listaReservasAgencia.h"
#include  "nodoReservas.h"
#include "Reservaciones.h"
#include "nodoListaPaises.h"
#include "ListaPaises.h"
#include "nodoHabitaciones.h"
#include "nodoPisosHotel.h"
#include "nodoHotel.h"
#include "nodoCarro.h"
#include "nodoTipoFlotilla.h"
#include "nodoAgencia.h"
#include "nodoPais.h"
#include "arbolPais.h"
#include "arbolHotel.h"
#include "arbolAgencia.h"
#include "arbolUsuario.h"


using namespace std;
void menu(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario,arbolHotel hotel);
int menu_reportesh(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario,arbolHotel hotel)
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
				
				hotel.Reportes(7);
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

int menu_lista(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario,arbolHotel hotel)
{
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
    

		cout << "\n\nQue desea hacer?" << endl;

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
                Paises.Datos(3);
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

//Menu ModificarHoteles-------------------------------------------------------- 
int menu_modificarh(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario,arbolHotel hotel)
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
int menu_insertarh(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario,arbolHotel hotel)
{
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
        

        cout << "\n\nQue desea insertar?" << endl;

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

int menu_hoteles(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario,arbolHotel hotel)
{
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
        

        cout << "\n\nBIENVENIDO ADMINISTRADOR DE HOTEL" << endl;

		cout << "\n\nQue desea hacer?" << endl;

        cout << "\n\n1. Insertar" << endl;
        cout << "2. Modificar" << endl;
        cout << "3. Reportes" << endl;
        cout << "4. Mantenimiento" << endl;
        cout << "5. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        if(cin>>opcion){
        
        switch (opcion) {
            case 1:
                // Opciones de insertar                
                
                //system("pause>nul"); // Pausa
                menu_insertarh(agencia, administradorH,administradorA,usuario,hotel);
                break;
                
            case 2:
                //Opciones de modificar               
                
                //system("pause>nul"); // Pausa 
				menu_modificarh(agencia, administradorH,administradorA,usuario,hotel);           
                break;
                
			case 3:
                //Opciones de Consulta               
                
                //system("pause>nul"); // Pausa 
				menu_reportesh(agencia, administradorH,administradorA,usuario,hotel);           
                break;

			case 4:
                //Opciones de Consulta               
                
                //system("pause>nul"); // Pausa 
				menu_lista(agencia, administradorH,administradorA,usuario,hotel);           
                break;
            
            case 5:
            	menu(agencia,administradorH,administradorA,usuario, hotel);
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

void validarAdministradorH(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario,arbolHotel hotel){
	cout<<endl;
	cout<<"Ingrese su codigo de Administrador de Hoteles: ";
	long double codigo;
	cin>>codigo;
	if (administradorH.validaAdministradorH(codigo,administradorH.raiz)){
		menu_hoteles(agencia, administradorH,administradorA,usuario,hotel);
	}
	else{
		cout<<endl;
		cout<<"Administrador no esta registrado"<<endl;
		menu(agencia, administradorH,administradorA,usuario,hotel);
	}
}

bool esUnNumero(string num)//funcion para saber si el string es un numero o letras 
{
  int tam=num.size();
  for(int i=0;i<tam;i++){
  	if(num[i]<48||num[i]>57){
		  return false;//no lo es
	}
  }
  return true;
} 

 void menuAgencia(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario,arbolHotel hotel){
 	cout<<endl;
	cout<<"Bienvenido al menu de administrador de Autos"<<endl;
	cout<<endl;
	cout<<"Que desea hacer?"<<endl;
	cout<<endl;
	cout<<"1-Insertar Agencia "<<endl;
	cout<<"2-Insertar TipoFlotilla"<<endl;
	cout<<"3-Insertar Carros"<<endl;
	cout<<"4-Modificar numero de carros en la Agencia"<<endl;
	cout<<"5-Modificar nombre de la Agencia"<<endl;
	cout<<"6-Modificar nombre de un Tipo Flotilla"<<endl;
	cout<<"7-Modificar cantidad de carros de un Tipo Flotilla"<<endl;//falta
	cout<<"8-Modificar numero de asientos de un carro"<<endl;
	cout<<"9-Modificar precio de un carro"<<endl;
	cout<<"10-Modificar estado de un carro"<<endl;
	cout<<"11-Consultar Agencias"<<endl;
	cout<<"12-Consultar Tipos Flotilla"<<endl;
	cout<<"13-Consultar cantidad de vehiculos de una agencia"<<endl;
	cout<<"14-Consultar cantidad de asientos de un carro"<<endl;
	cout<<"15-Consultar modelo de carro"<<endl;
	cout<<"16-Consultar ano de carro"<<endl;
	cout<<"17-Consultar precio"<<endl;
	cout<<"18-Consultar estado de un carro"<<endl;
	cout<<"19-Consultar carros"<<endl;
	cout<<"20-Ultima Agencia insertado"<<endl;
	cout<<"21-Ultimo Tipo Flotilla insertado"<<endl;
	cout<<"22-Ultimo carro insertada"<<endl;
	cout<<"23-Consultar reservaciones"<<endl;
	cout<<"24-Regresar al menu principal"<<endl;
	cout<<"25- Salir"<<endl;
	cout<<endl;
	cout<<"Digite una opcion: ";
	int opcion;
	cin>>opcion;
	if(opcion==1){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la nueva Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Escriba el nombre de la nueva Agencia: ";
		string nombre;
		getline(cin,nombre);
		cout<<"Escriba la cantidad de autos que almacena la Agencia: ";
		int cantidad;
		cin>>cantidad;
		cin.ignore();
		agencia.verificarInsertarAgencia(pais.getRaizPais(), codPais, identificacion, nombre,cantidad);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==2){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Escriba el codigo del nuevo TipoFlotilla : ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		cout<<"Escriba el nombre del nuevo TipoFlotilla: ";
		string nombre;
		getline(cin,nombre);	
		cout<<"Escriba la cantidad de carros del nuevo TipoFlotilla: ";
		int cantidad;
		cin>>cantidad;
		cin.ignore();
		//verificar y mandar mensaje si no existe
		agencia.verificarInsertarTipoFlotilla(pais.getRaizPais(),codPais, identificacion,codigo,nombre,cantidad);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==3){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Digite el codigo de Tipo Flotilla:";
		int codigo;
		cin>>codigo;
		cin.ignore();
		/*if(agencia.existeValidarCarros(identificacion, codigo)==false){
			cout<<"ERROR. No existe esa agencia o el Tipo Flotilla"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
		}else{*/
			cout<<"Datos para el nuevo carro"<<endl;
			cout<<"Escriba el numero de placa : ";
			int placa;
			cin>>placa;
			cin.ignore();
			cout<<"Escriba el modelo : ";
			string modelo;
			cin>>modelo;
			cin.ignore();
			cout<<"Escriba el numero de asientos : ";
			int numAsientos;
			cin>>numAsientos;
			cin.ignore();
			cout<<"Escriba el ano del carro : ";
			int ano;
			cin>>ano;
			cin.ignore();
			cout<<"Escriba el precio : ";
			int precio;
			cin>>precio;
			cin.ignore();
			cout<<endl;
			cout<<"R-Reservado"<<endl;
			cout<<"O-Ocupado"<<endl;
			cout<<"L-Libre"<<endl;
			cout<<"El estado del carro es: ";
			string estado;
			cin>>estado;
			cin.ignore();
			if(estado!="R"&&estado!="O"&&estado!="L"){
				cout<<"ERROR.Debe ser una de las 3 opciones"<<endl;
				menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
			}
			agencia.verificarInsertarCarroPais(pais.getRaizPais(),codPais,identificacion,codigo,placa,modelo,numAsientos,ano,precio,estado);
		//}
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==4){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		//verificar que exista el pais en la lista
		cout<<"Identificacion de la agencia: "<<endl;
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"La nueva cantidad: "<<endl;
		int cantidad;
		cin>>cantidad;
		cin.ignore();
		agencia.modificarCantidadCarrosA(pais.getRaizPais(),codPais,identificacion,cantidad);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==5){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		//verificar que exista el pais en la lista
		cout<<"Identificacion de la agencia: "<<endl;
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"El nuevo nombre de la agencia: "<<endl;
		string nombre;
		getline(cin,nombre);
		agencia.modificarNombreAgencia(pais.getRaizPais(),codPais,identificacion,nombre);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==6){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Escriba el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		agencia.modificarDatosFlotilla(pais.getRaizPais(),codPais,identificacion,codigo,1);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==7){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Escriba el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		agencia.modificarDatosFlotilla(pais.getRaizPais(),codPais,identificacion,codigo,2);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==8){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Escriba el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		cout<<"Escriba el numero de placa del carro: ";
		long double placa;
		cin>>placa;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,placa,1);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==9){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Escriba el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		cout<<"Escriba el numero de placa del carro: ";
		long double placa;
		cin>>placa;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,placa,2);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==10){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Escriba el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		cout<<"Escriba el numero de placa del carro: ";
		long double placa;
		cin>>placa;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,placa,3);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==11){
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		agencia.consultarAgencias(pais.getRaizPais(),codPais,1);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==12){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		agencia.consultarTipoFlotillas(pais.getRaizPais(),codPais,identificacion,1);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==13){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		agencia.consultarCantidadCarros(pais.getRaizPais(),codPais,identificacion);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==14){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Digite el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		cout<<"Digite el numero de placa: ";
		long double placa;
		cin>>placa;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,placa,4);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==15){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Digite el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		cout<<"Digite el numero de placa: ";
		long double placa;
		cin>>placa;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,placa,5);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==16){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Digite el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		cout<<"Digite el numero de placa: ";
		long double placa;
		cin>>placa;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,placa,6);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==17){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Digite el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		cout<<"Digite el numero de placa: ";
		long double placa;
		cin>>placa;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,placa,7);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==18){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Digite el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		cout<<"Digite el numero de placa: ";
		long double placa;
		cin>>placa;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,placa,8);
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==19){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Digite el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,0,0);
		menuAgencia(agencia,administradorH,administradorA,usuario, hotel);
	}
	else if(opcion==20){
		agencia.uAgencia();
		menuAgencia(agencia,administradorH,administradorA,usuario, hotel);
	}
	else if(opcion==21){
		agencia.uTipoFlotilla();
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
	else if(opcion==22){
		agencia.uCarro();
		menuAgencia(agencia,administradorH,administradorA,usuario, hotel);
	}
	else if(opcion==23){
		listaReservaA.Mostrar();
		menuAgencia(agencia,administradorH,administradorA,usuario, hotel);
	}
	else if(opcion==24){
		menu(agencia,administradorH,administradorA,usuario, hotel);
	}
	else if(opcion==25){
		return;
	}
	else{
		cout<<"ERROR, opcion no valida "<<endl;
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);
	}
 }


void validarAdministradorA(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario,arbolHotel hotel){
	cout<<endl;
	cout<<"Ingrese su codigo de Administrador de Autos: ";
	long double codigo;
	cin>>codigo;
	if (administradorA.validaAdministradorA(codigo,administradorA.raiz)){
		menuAgencia(agencia,administradorH,administradorA,usuario,hotel);	
	}
	else{
		cout<<endl;
		cout<<"Administrador no esta registrado"<<endl;
		menu(agencia, administradorH,administradorA,usuario,hotel);
	}
}


void menuUsuario(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario,arbolHotel hotel, long double numIden){
	cout<<endl;
	cout<<"Bienvenido al menu Usuario"<<endl;
	cout<<endl;
	cout<<"1.Consultar Hoteles"<<endl;
	cout<<"2.Consultar Pisos de un hotel"<<endl;
	cout<<"3.Consultar habitaciones de un hotel de un piso"<<endl;
	cout<<"4.Consultar Agencias"<<endl;
	cout<<"5.Consultar Flotilla de una agencia"<<endl;
	cout<<"6.Consultar carros de una agencia de una flotilla"<<endl;
	cout<<"7-Consultar Paises"<<endl;
	cout<<"8-Reservacion"<<endl;
	cout<<"9.Salir"<<endl;
	cout<<"10.Regresar Menu Principal"<<endl;
	cout<<endl;
	cout<<"Digite una opcion:";
	int opcion;
	cin>>opcion;
	cin.ignore();
	cout<<endl;
	if(opcion==1){
		hotel.Reportes(1);
		menuUsuario(agencia,administradorH,administradorA,usuario, hotel,numIden); 
		
	}
	else if(opcion==2){
		hotel.Reportes(44);
		menuUsuario(agencia,administradorH,administradorA,usuario, hotel,numIden); 
	}
	else if(opcion==3){
		hotel.Reportes(77);
		menuUsuario(agencia,administradorH,administradorA,usuario, hotel,numIden); 
		
		
	}
	else if(opcion==4){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuUsuario(agencia,administradorH,administradorA,usuario,hotel, numIden);
		}
		agencia.consultarAgencias(pais.getRaizPais(),codPais,1);
		menuUsuario(agencia,administradorH,administradorA,usuario, hotel,numIden);
	}
	else if(opcion==5){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuUsuario(agencia,administradorH,administradorA,usuario,hotel, numIden);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		agencia.consultarTipoFlotillas(pais.getRaizPais(),codPais,identificacion,1);
		cout<<endl;
		menuUsuario(agencia,administradorH,administradorA,usuario, hotel, numIden);
	}
	else if(opcion==6){
		cout<<endl;
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuUsuario(agencia,administradorH,administradorA,usuario,hotel, numIden);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Digite el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,0,0);

		menuUsuario(agencia,administradorH,administradorA,usuario, hotel,numIden); 

	}
	else if(opcion==7){
		Paises.Mostrar();
		menuUsuario(agencia,administradorH,administradorA,usuario, hotel,numIden); 
	}
	else if(opcion==8){
		cout<<endl;
		cout<<"1-Hoteles"<<endl;
		cout<<"2-Agencia"<<endl;
		cout<<"3-Todo Incluido"<<endl;
		cout<<"Digite una opcion:";
		int opcionR;
		cin>>opcionR;
		if(opcionR==1){
			hotel.verificarDatos(numIden,1);
			menuUsuario(agencia,administradorH,administradorA,usuario, hotel,numIden); 
		}
		else if(opcionR==2){
			cout<<endl;
			cout<<"Digite el codigo de pais: ";
			int codPais;
			cin>>codPais;
			cin.ignore();
			if(Paises.Validar(codPais)==0){
				cout<<"No existe el pais"<<endl;
				menuUsuario(agencia,administradorH,administradorA,usuario,hotel, numIden);
			}
			cout<<"Digite la identificacion de la Agencia: ";
			int identificacion;
			cin>>identificacion;
			cin.ignore();
			cout<<"Digite el codigo del TipoFlotilla: ";
			int codigo;
			cin>>codigo;
			cin.ignore();
			cout<<"Digite el numero de placa: ";
			long double placa;
			cin>>placa;
			cin.ignore();
			if(agencia.existeCarrosDatos(pais.getRaizPais(),codPais,identificacion,codigo,placa)){
				cout<<"Se realizo la reservacion"<<endl;
				listaReservaA.InsertarFinal(codPais,identificacion,codigo,placa,numIden);
				menuUsuario(agencia,administradorH,administradorA,usuario,hotel, numIden);
			}else{
				cout<<"No existe carro con esos datos o ya esta reservado"<<endl;
				menuUsuario(agencia,administradorH,administradorA,usuario,hotel, numIden);
			}
				
		}
		else if(opcionR==3){
			cout<<endl;
			cout<<"Digite el codigo de pais: ";
			int codPais;
			cin>>codPais;
			cin.ignore();
			if(Paises.Validar(codPais)==0){
				cout<<"No existe el pais"<<endl;
				menuUsuario(agencia,administradorH,administradorA,usuario,hotel, numIden);
			}
			cout<<"Digite la identificacion de la Agencia: ";
			int identificacion;
			cin>>identificacion;
			cin.ignore();
			
			//pedir dato codHotel
			cout<<"Digite el codigo de hotel: ";
			int codhotel;
			cin>>codhotel;
			//cin.ignore();
			hotel.existePais(pais.getRaizPais(),codPais);
			if(hotel.existeHotel(hotel.paisencontrado->hoteles, codhotel)==3){
				cout<<"Este hotel no tiene pisos por lo que no puede reservar"<<endl;
			}
			if(agencia.agenciaenPais(pais.getRaizPais(),codPais,identificacion)==1 && hotel.existeHotel(hotel.paisencontrado->hoteles, codhotel)==2){
				cout<<"Los 2 datos se encuentran en el mismo pais puede hacer la reservacion"<<endl;
				cout<<"Digite el codigo del TipoFlotilla: ";
				int codigo;
				cin>>codigo;
				cin.ignore();
				cout<<"Digite el numero de placa: ";
				long double placa;
				cin>>placa;
				cin.ignore();
				if(agencia.existeCarrosDatos(pais.getRaizPais(),codPais,identificacion,codigo,placa)){
					cout<<"Se realizo la reservacion"<<endl;
					listaReservaA.InsertarFinal(codPais,identificacion,codigo,placa,numIden);
					
					int NumPiso;
					int codigoHabitacion;
					bool existe_piso = false;
					bool no_repetido = false;
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
							 nodoPiso* RaizPisos = hotel.hotelencontrado->PisosHotel;
			        		if((hotel.existePiso(RaizPisos,NumPiso)==0)){
			        			cout<<"\nEste numero del piso no esta registrado, favor ingresar otro distinto "<<endl;
			        			break;
							}
							if((hotel.existePiso(RaizPisos,NumPiso)==2)){
								//Para ingresar habitaciones solo importa si el piso existe
									
								existe_piso=true;
			            		break;
							}
							if((hotel.existePiso(RaizPisos,NumPiso)==3)){
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
								 nodoHabitaciones* RaizHabitacion = hotel.pisoencontrado->Habitaciones;
			        			if((hotel.existeHabitaciones(RaizHabitacion,codigoHabitacion)==0)){
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
						if(hotel.habitacionencontrada->estado=="L" ){
							ReservacionesH.InsertarFinal(numIden,codigoHabitacion,"h");
							hotel.habitacionencontrada->estado = "R";
						}
						else{
							cout<<"La habitacion  ya esta ocupada"<<endl;
						}
						
					}
					menuUsuario(agencia,administradorH,administradorA,usuario,hotel, numIden);
				}
				
				else{
					cout<<"No existe carro con esos datos o ya esta reservado"<<endl;
					menuUsuario(agencia,administradorH,administradorA,usuario,hotel, numIden);
				}

			}else{
				cout<<"No estan en el mismo pais"<<endl;
				menuUsuario(agencia,administradorH,administradorA,usuario,hotel, numIden);
			}
		}
		else{
			cout<<"ERROR, al selecionar opcion"<<endl;
			menuUsuario(agencia,administradorH,administradorA,usuario, hotel,numIden);
		}
		
	}
	else if(opcion==9){
		return;
	}
	else if(opcion==10){
		menu(agencia,administradorH,administradorA,usuario, hotel);
	}
	else{
		
		cout<<"Opcion no valida"<<endl;
			menuUsuario(agencia,administradorH,administradorA,usuario, hotel,numIden); 
	}
}

void validarUsuario(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario, arbolHotel hotel){
	cout<<endl;
	cout<<"Ingrese su codigo de Usuario: ";
	long double codigo;
	cin>>codigo;
	if (usuario.validaUsuario(codigo,usuario.raiz)){
		menuUsuario(agencia,administradorH,administradorA,usuario, hotel, codigo);	
	}
	else{
		cout<<endl;
		cout<<"Usuario no esta registrado"<<endl;
		menu(agencia, administradorH,administradorA,usuario, hotel);
	}
}

void menu(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario, arbolHotel hotel){
	cout<<endl;
	system("cls");        // Para limpiar la pantalla
	cout<<"Bienvenido al sistema "<<endl;
	cout<<endl;
	cout<<"Que tipo de usuario es usted?"<<endl;
	cout<<endl;
	cout<<"1-Administrador Hotel"<<endl;
	cout<<"2-Administrador Agencia"<<endl;
	cout<<"3-Usuario"<<endl;
	cout<<"4-Mantenimientos de paises"<<endl;
	cout<<endl;
	cout<<"Escoja el tipo de usuario: ";
	string opcion;
	cin>>opcion;
	cin.ignore();
	if (opcion=="1"){
		validarAdministradorH(agencia, administradorH,administradorA,usuario, hotel);	
	}
	else if(opcion=="2"){
		validarAdministradorA(agencia, administradorH,administradorA,usuario,hotel);	
	}
	else if(opcion=="3"){
		validarUsuario(agencia, administradorH,administradorA,usuario,hotel);		
	}
	else if(opcion=="4"){
		menu_lista(agencia, administradorH,administradorA,usuario,hotel);
		menu(agencia, administradorH,administradorA,usuario,hotel);
	}
	else{
		cout<<"Opcion no valida"<<endl;
		cout<<endl;
		menu(agencia, administradorH,administradorA,usuario,hotel);
	}
}


int main(){
	pais.leerArchivoPais();
	Paises.leerArchivoPais();
	arbolAgencia agencia;
	agencia.leerArchivoAgencias();
	agencia.leerArchivoTipoFlotilla();
	agencia.leerArchivoCarros();
	//InordenAgencia(pais.getRaizPais());
	
	//arboles usuarios y sus archivos
	ArbolAdministradorH administradorH;
	ArbolAdministradorA administradorA;
	ArbolUsuario usuario;
	usuario.leerArchivoUsuarios();
	administradorA.leerArchivoAdministradorA();
	administradorH.leerArchivoAdministradorH();
	arbolHotel hotel;
	
	hotel.lecturaHoteles();
	//InordenHotel(pais.getRaizPais());
	cout<<endl;
	hotel.lecturaPisosHotel();
	cout<<endl;
	hotel.lecturaHabitaciones();
	//entrada al menu

	menu(agencia,administradorH,administradorA,usuario, hotel);
	
	return 0;
}
