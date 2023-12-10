#include <iostream>
#include <stdlib.h>
using namespace std;

// Menu de Juego
void menu_juego(tusuario jugador,int monedas,int vidas); // Linea 73

// Pistas
void pistaP(tauxiliar &aux1,int &ocupA, tnumero numero,int pista, int &monedas); // Linea 84
void pista2(tauxiliar &a,tnumero num,int &ocup, int min,int max); // Linea 138
void pista3(tauxiliar &a,int ocupA, tnumero num); // Linea 161
void pista4(tauxiliar &a,int &ocupA, tnumero num); // Linea 178
void pista5(tauxiliar &a,int ocupA, tnumero num); // Linea 200

void main_jugar(tusuario &jugador,tablero tablero){ // Procedimiento principal de juego
	tauxiliar aux1,aux2;
	int ocupA,ocupB;
	char opc;
	int vidas=5,i,j,monedas=0,pista=1,intento;
	bool perdio=false,adivino=false;
	for(i=0;i<FIL && !perdio;i++){
		for(j=0;j<COL && !perdio;j++){
			vidas=5;
			monedas=monedas+tablero[i][j].monedas;
			pista=1;
			while(vidas>0 && !adivino){
				system("cls");
				menu_juego(jugador,monedas,vidas);
				cin>>opc;
				switch(opc){
				case '1':
					cout<<"Ingrese el numero: (0 si desea volver): ";
					cin>>intento;
					if(intento!=0){
						if(tablero[i][j].numero==intento){
							adivino=true;
							cout<<"Adivinaste!"<<endl;
						}else{
							cout<<"No adivinaste"<<endl;
							vidas--;
						}
					}else{
						cout<<"Te arrepentiste no se te restara nada"<<endl;
					}
					break;
				case '2':
					pistaP(aux1,ocupA,tablero[i][j],pista,monedas);
					pista++;
					break;
				default:
					cout<<"Seleccione una opcion valida"<<endl;
					break;
				}
				system("pause");
			}
			if(vidas==0)
				perdio=true;
			else
				adivino=false;
		}
	}
	if(!perdio){
		jugador.ganadas++;
		jugador.monedas=jugador.monedas+monedas;
		cout<<"Ganaste, bien jugado!"<<endl;
	}else{
		cout<<"Perdiste!, buena suerte la proxima"<<endl;
	}
	system("pause");
	
}

void menu_juego(tusuario jugador,int monedas,int vidas){ // Procedimiento para mostrar los datos de la partida
	int i;
	char corazon=03;
	cout<<endl<<"Nickname: "<<jugador.nickname<<" - Vidas: ";
	for(i = 0; i < vidas; i++){
        cout << corazon;
    }
	cout<<" - Monedas: "<<monedas<<endl;
	cout<<"1. Arriesgar"<<endl;
	cout<<"2. Pista"<<endl;
}
void pistaP(tauxiliar &aux1,int &ocupA, tnumero numero,int pista, int &monedas){ 
	switch(pista){ // Procedimiento para llamar a las pistas, tambien resta las monedas y calcula el primer rango
		case 1:
			if(monedas>=2){
				cout<<"El numero esta en el intervalo ["<<numero.numero-numero.rangon<<","<<numero.rangop+numero.numero<<"]"<<endl;
				monedas=monedas-2;
			}else{
				cout<<"No tienes suficientes monedas"<<endl;
			}
			
			break;
		case 2:
			if(monedas>=3){
				pista2(aux1,numero,ocupA,numero.numero-numero.rangon,numero.rangop+numero.numero);
				monedas=monedas-3;
				
			}else{
				cout<<"No tienes suficientes monedas"<<endl;
			}
			break;
			
		case 3:
			if(monedas>=4){
				pista3(aux1,ocupA,numero);
				monedas=monedas-4;
			}else{
				cout<<"No tienes suficientes monedas"<<endl;
			}
			break;
		case 4:
			if(monedas>=5){
				pista4(aux1,ocupA,numero);
				monedas=monedas-5;
			}else{
				cout<<"No tienes suficientes monedas"<<endl;
			}			
			break;
		case 5:
			if(monedas>=6){
				pista5(aux1,ocupA,numero);
				monedas=monedas-6;
			}else{
				cout<<"No tienes suficientes monedas"<<endl;
			}
			break;
		default:
				cout<<"No le quedan pistas por pedir"<<endl;
			break;
			
		break;		
	}
	cout<<endl;
}

void pista2(tauxiliar &a,tnumero num,int &ocup, int min,int max){ // Pista 2, carga segun paridad los numeros en un vector auxiliar
	ocup=-1;
	int i;
	for(i=min;i<=max;i++){
		if(num.paridad){
			if(i%2==0){
				ocup++;
				a[ocup]=i;
			}
		}else{
			if(i%2!=0){
				ocup++;
				a[ocup]=i;
			}
		}
	}
	if(num.paridad){
		cout<<"Pista 1, el numero es par"<<endl;
	}else{
		cout<<"Pista 1, el numero impar"<<endl;
	}
	mostrarAux(a,ocup);
}
void pista3(tauxiliar &a,int ocupA,tnumero num){ // Pista 3, recorre el vector de la segunda pista y muestra los valores que cumplan la condicion de primalidad
	int i;
	if(num.primo){
		cout<<"Pista 2, el numero es primo"<<endl;
	}else{
		cout<<"Pista 2, el numero es compuesto"<<endl;
	}
	for(i=0;i<=ocupA;i++){
		if(num.primo){
			if(primo(a[i]))
				cout<<a[i]<<", ";
		}else{
			if(!primo(a[i]))
				cout<<a[i]<<", ";
		}
	}
}
void pista4(tauxiliar &a,int &ocupA,tnumero num){ // Pista 4, recorre el vector de la pista 2, mostrando cuadrados o no cuadrados.
	int i;
	float raiz;
	if(num.cuadrado){
		cout<<"Pista 3, el numero es cuadrado"<<endl;
	}else{
		cout<<"Pista 3, el numero no es cuadrado"<<endl;
	}
	for(i=0;i<=ocupA;i++){
		raiz=sqrt(a[i]);
		if(num.cuadrado){
			if(raiz==trunc(raiz)){
				cout<<a[i]<<", ";
			}
		}else{
			if(raiz!=trunc(raiz)){
				cout<<a[i]<<", ";
			}
		}
	}
}

void pista5(tauxiliar &a,int ocupA, tnumero num){ // Pista 5, recorre el vector de la primera pista mostrando numeros fibo o no fibo.
	int i;
	if(num.fibonacci){
		cout<<"Pista 4, el numero es fibo"<<endl;
	}else{
		cout<<"Pista 4, el numero no es fibo"<<endl;
	}
	for(i=0;i<=ocupA;i++){
		if(num.fibonacci){
			if(fibo(a[i])){
				cout<<a[i]<<", ";
			}
		}else{
			if(!fibo(a[i])){
				cout<<a[i]<<", ";
			}
		}
	}
}
