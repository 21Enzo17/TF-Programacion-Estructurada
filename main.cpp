#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "tablero.hpp"
#include "jugadores.hpp"
#include "juego.hpp"
using namespace std;

void menu(char &opc);

main(){ // Procedimiento principal, se encarga de manejar todo el programa principal
    tusuarios a;
    tablero tablero;
	bool cargado=false,valido;
    char opc;
    int ocupJ=-1,id=-1,jugador,pos=-1;
	tcad admin,contrasena;
    srand(time(NULL));
    do{
        system("cls");
        menu(opc);
        switch (opc)
        {
        case '1':
            main_jugadores(a,ocupJ,id);
            break;
        case '2':
            generar_tablero(tablero);
			cout<<"Desea mostrar el tablero? (Solo para usuarios admin) s/n"<<endl;
			cin>>opc;
			if(opc=='s'){
				do{
					cout<<"Ingrese el usuario administrador: ";
					fflush(stdin);
					gets(admin);
					cout<<"Ingrese la contrasena: ";
					fflush(stdin);
					gets(contrasena);
					valido=strcmp(admin,"admin")==0 && strcmp(contrasena,"apu2008")==0;
					if(!valido){
						cout<<"Error en el login, desea seguir intentado o salir s/n"<<endl;
						cin>>opc;
						if(opc=='n'){
							valido=true;
						}
					}else{
						mostrar_tablero(tablero);
					}
				}while(!valido);
			}
			cargado=true;
            system("pause");
            break;
        case '3':
			if(cargado && ocupJ!=-1){
				logueo(a,ocupJ,pos);
				main_jugar(a[pos],tablero);
				cargado=false;
			}else{
				cout<<"Para jugar debe cargar al menos un usuario y generar el tablero de juego"<<endl;
				system("pause");
			}
			
            break;
        case '4':
            if(ocupJ>=0){
                ranking(a,ocupJ);
            }else{
                cout<<"No tiene jugadores cargados, no podemos mostrar un ranking"<<endl;
				system("pause");
            }
            break;
        case '5':
			cout<<"Saliendo, Gracias por jugar!"<<endl;
			system("pause");
            break;
//		case '7':
//			jugador=logueo(a,ocupJ);
//			cout<<"Simulando Victoria"<<endl;
//			a[jugador].monedas=a[jugador].monedas+200;
//			a[jugador].ganadas++;
//			break;
//		case '8':
//			jugador=logueo(a,ocupJ);
//			cout<<"Simulando Victoria"<<endl;
//			a[jugador].monedas=a[jugador].monedas+10;
//			a[jugador].ganadas=a[jugador].ganadas+12;
//			break;
        default:
			cout<<"Introduzca una opcion valida"<<endl;
			system("pause");
            break;
        }
        
    }while(opc!='5');

}

void menu(char &opc){ // Menu principal, muestra todas las opciones del programa
    cout<<"##### Menu Ahorcadito Numerico #####"<<endl;
    cout<<"1. Gestion de Jugadores"<<endl;
    cout<<"2. Generacion del Tablero"<<endl;
    cout<<"3. Jugar"<<endl;
    cout<<"4. Ranking de Jugadores"<<endl;
    cout<<"5. Salir"<<endl;
	cout<<"Ingrese su opcion: ";
    cin>>opc;
}
