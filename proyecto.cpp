#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "nodoListaPaises.h"
#include "ListaPaises.h"
#include "nodoCarro.h"
#include "nodoTipoFlotilla.h"
#include "nodoAgencia.h"
#include "nodoPais.h"
#include "arbolPais.h"
#include "arbolAgencia.h"
#include "arbolUsuario.h"
#include "listaReservasAgencia.h"


using namespace std;
void menu(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario);

void validarAdministradorH(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario){
	cout<<endl;
	cout<<"Ingrese su codigo de Administrador de Hoteles: ";
	long double codigo;
	cin>>codigo;
	if (administradorH.validaAdministradorH(codigo,administradorH.raiz)){
		cout<<"entro";
		//menuAdministradorH(administracion, hoteles);	
	}
	else{
		cout<<endl;
		cout<<"Administrador no esta registrado"<<endl;
		menu(agencia, administradorH,administradorA,usuario);
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

 void menuAgencia(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario){
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
	cout<<"23-Regresar al menu principal"<<endl;
	cout<<"24- Salir"<<endl;
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
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==2){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==3){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
				menuAgencia(agencia,administradorH,administradorA,usuario);
			}
			agencia.verificarInsertarCarroPais(pais.getRaizPais(),codPais,identificacion,codigo,placa,modelo,numAsientos,ano,precio,estado);
		//}
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==4){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==5){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==6){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==7){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==8){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==9){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==10){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==11){
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
		}
		agencia.consultarAgencias(pais.getRaizPais(),codPais,1);
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==12){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		agencia.consultarTipoFlotillas(pais.getRaizPais(),codPais,identificacion,1);
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==13){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
		}
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		agencia.consultarCantidadCarros(pais.getRaizPais(),codPais,identificacion);
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==14){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==15){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==16){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==17){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==18){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==19){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		if(Paises.Validar(codPais)==0){
			cout<<"No existe el pais"<<endl;
			menuAgencia(agencia,administradorH,administradorA,usuario);
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
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==20){
		agencia.uAgencia();
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==21){
		agencia.uTipoFlotilla();
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==22){
		agencia.uCarro();
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==23){
		menu(agencia,administradorH,administradorA,usuario);
	}
	else if(24){
		return;
	}
	else{
		cout<<"ERROR, opcion no valida "<<endl;
		menuAgencia(agencia,administradorH,administradorA,usuario);
	}
 }


void validarAdministradorA(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario){
	cout<<endl;
	cout<<"Ingrese su codigo de Administrador de Autos: ";
	long double codigo;
	cin>>codigo;
	if (administradorA.validaAdministradorA(codigo,administradorA.raiz)){
		menuAgencia(agencia,administradorH,administradorA,usuario);	
	}
	else{
		cout<<endl;
		cout<<"Administrador no esta registrado"<<endl;
		menu(agencia, administradorH,administradorA,usuario);
	}
}

void menuUsuario(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario){
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
		
	}
	else if(opcion==2){
		
	}
	else if(opcion==3){
		
	}
	else if(opcion==4){
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		agencia.consultarAgencias(pais.getRaizPais(),codPais,1);
		menuUsuario(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==5){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		agencia.consultarTipoFlotillas(pais.getRaizPais(),codPais,identificacion,1);
		cout<<endl;
		menuUsuario(agencia,administradorH,administradorA,usuario);
	}
	else if(opcion==6){
		cout<<endl;
		cout<<"Digite el codigo de pais: ";
		int codPais;
		cin>>codPais;
		cin.ignore();
		cout<<"Digite la identificacion de la Agencia: ";
		int identificacion;
		cin>>identificacion;
		cin.ignore();
		cout<<"Digite el codigo del TipoFlotilla: ";
		int codigo;
		cin>>codigo;
		cin.ignore();
		agencia.modificacionConsultasCarro(pais.getRaizPais(),codPais,identificacion,codigo,0,0);
		menuUsuario(agencia,administradorH,administradorA,usuario); 
	}
	else if(opcion==7){
		//paises
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
			//hotel reservacion
		}
		else if(opcionR==2){
			//
		}
		else if(opcionR==3){
			
		}
		else{
			cout<<"ERROR, al selecionar opcion"<<endl;
			menuUsuario(agencia,administradorH,administradorA,usuario);
		}
		
	}
	else if(opcion==9){
		return;
	}
	else if(opcion==10){
		menu(agencia,administradorH,administradorA,usuario);
	}
	else{
		cout<<"Opcion no valida"<<endl;
		menuUsuario(agencia,administradorH,administradorA,usuario) ; 
	}
}

void validarUsuario(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario){
	cout<<endl;
	cout<<"Ingrese su codigo de Usuario: ";
	long double codigo;
	cin>>codigo;
	if (usuario.validaUsuario(codigo,usuario.raiz)){
		menuUsuario(agencia,administradorH,administradorA,usuario);	
	}
	else{
		cout<<endl;
		cout<<"Usuario no esta registrado"<<endl;
		menu(agencia, administradorH,administradorA,usuario);
	}
}

void menu(arbolAgencia agencia,ArbolAdministradorH administradorH,ArbolAdministradorA administradorA,ArbolUsuario usuario){
	cout<<endl;
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
		validarAdministradorH(agencia, administradorH,administradorA,usuario);	
	}
	else if(opcion=="2"){
		validarAdministradorA(agencia, administradorH,administradorA,usuario);	
	}
	else if(opcion=="3"){
		validarUsuario(agencia, administradorH,administradorA,usuario);	
	}
	else if(opcion=="4"){
		//manteniemiento
	}
	else{
		cout<<"Opcion no valida"<<endl;
		cout<<endl;
		menu(agencia, administradorH,administradorA,usuario);
	}
}


int main(){
	Paises.leerArchivoPais();
	pais.leerArchivoPais();
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
	
	//entrada al menu
	menu(agencia,administradorH,administradorA,usuario);
	
	return 0;
}
