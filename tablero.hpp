#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;




const int FIL=2,COL=3,MAX=100;
typedef struct tnumero{
                    int numero,rangop,rangon,monedas;
                    bool paridad,primo,cuadrado, fibonacci;
};
typedef tnumero tablero[FIL][COL];
typedef int tauxiliar[MAX];
// tablero y numeros
void generar_tablero(tablero tablero); // Linea 26
int gen_numero(int cifras); // Linea 80 
void gen_rango(int &rangon,int &rangop,int num,int min,int max); // Linea 136
void mostrar_num(tnumero num); // Linea 70
void mostrar_tablero(tablero tablero); // Linea 62
// pistas booleanos 
bool primo(int numero); // Linea 109
bool fibo(int num); // Linea 124

void generar_tablero(tablero tablero){ // Este procedimiento setea todos los valores y genera numeros aleatorios
    int i,j,q=2;
    for(i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            tablero[i][j].numero=gen_numero(q);
			tablero[i][j].monedas=q*7;
            tablero[i][j].paridad=tablero[i][j].numero%2==0;
            tablero[i][j].cuadrado=sqrt(tablero[i][j].numero)==trunc(sqrt(tablero[i][j].numero));
            tablero[i][j].fibonacci=fibo(tablero[i][j].numero);
            tablero[i][j].primo=primo(tablero[i][j].numero);
            switch (q)
            {
				case 2:
					gen_rango(tablero[i][j].rangon,tablero[i][j].rangop,tablero[i][j].numero,10,99);
					break;
				case 3:
					 gen_rango(tablero[i][j].rangon,tablero[i][j].rangop,tablero[i][j].numero,300,499);
					break;
				case 4:
					gen_rango(tablero[i][j].rangon,tablero[i][j].rangop,tablero[i][j].numero,5400,5599);
					break;
				case 5:
					gen_rango(tablero[i][j].rangon,tablero[i][j].rangop,tablero[i][j].numero,25000,99999);
					break;
				case 6:
					gen_rango(tablero[i][j].rangon,tablero[i][j].rangop,tablero[i][j].numero,500000,999999);
					break;
				case 7:
					gen_rango(tablero[i][j].rangon,tablero[i][j].rangop,tablero[i][j].numero,1000000,9999999);
					break;
            }

            q++;
        }
    }
}
void mostrar_tablero(tablero tablero){ // Procedimiento que muestra el tablero
    int i,j;
    for(i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            mostrar_num(tablero[i][j]);
        }
    }
}
void mostrar_num(tnumero num){ // Este procedimiento muestra el registro de numero
    cout<<"==============================="<<endl;
    cout<<"Numero: "<<num.numero<<endl;
	cout<<"Monedas: "<<num.monedas<<endl;
    cout<<"Rango: ["<<num.numero-num.rangon<<";"<<num.numero+num.rangop<<"]"<<endl;
	cout << "Es Par: " << (num.paridad ? "Si" : "No") << endl;
	cout << "Es Cuadrado: " << (num.cuadrado ? "Si" : "No") << endl;
	cout << "Es Primo: " << (num.primo ? "Si" : "No") << endl;
	cout << "Es Fibonacci: " << (num.fibonacci ? "Si" : "No") << endl;
}
int gen_numero(int cifras){ // Funcion de generacion de numeros random, genera desde 2 digitos hasta 7
    int num,aux1,aux2;
    switch (cifras){
    case 2:
        num=10 + rand()%(100-10);
        break;
    case 3:
        num=300 + rand()%(500-300);
        break;
    case 4:
        num=5400 + rand()%(5600-5400);
        break;
    case 5:
        num=25000 + rand()%(100000-25000);
        break;
    case 6: // A partir de aqui, tenemos el problema de generacion, los numeros aleatorios se limitan
        aux1=500 + rand()%(1000-500);
        aux2=100+rand()%(1000-100);
        num=aux1*1000+aux2; // Se unen dos numeros de 3 cifras para generar el de 6 cifras
        break;
    case 7:
        aux1=1000 + rand()%(10000-1000);
        aux2=100+rand()%(1000-100);
        num=aux1*1000+aux2; // Se unen dos numeros 1 de 3 cifras y otro de 4 para generar 7 cifras
        break;
    }
    return num;
}

bool primo(int numero){ // Funcion de comprobacion de un numero primo mediante la Criba de Erastotenes
    if(numero<=1)
        return false;
    if(numero <=3)
        return true;
    if(numero%2==0 || numero%3==0)
        return false;
    int limite = sqrt(numero)+1;
    for(int i=5;i<=limite;i=i+6){
        if(numero%i==0 || numero%(i+2)==0)
            return false;
    }
    return true;
}

bool fibo(int num){ // Funcion de comprobacion de un numero Fibo, mediante metodo tradicional
    int a=1,b=1,c;
    bool pertenece=false;
    while(b<=num && !pertenece){
        if(b==num)
            pertenece=true;
        c=b;
        b=a+b;
        a=c;
    }
    return pertenece;
}
void gen_rango(int &rangon,int &rangop,int num,int min,int max){ // Procedimiento de generacion de rango asimetrico dentro de limites.
	int resto;
    do{
        do{
		    rangon=0 + rand()%(51-0);
			
        }while(num-rangon<min);
		resto=100-rangon;
        do{
            rangop=0 + rand()%(resto-0);
        }while(num+rangop>max);
    }while(rangon+rangop<50);
}
void mostrarAux(tauxiliar a,int ocup){
    if(ocup==-1){
		cout<<"No hay numeros coincidentes"<<endl;
	}else{
		if(ocup==0){
			cout<<a[ocup]<<", ";
		}else{
			mostrarAux(a,ocup-1);
			cout<<a[ocup]<<", ";
		}
	}
}
