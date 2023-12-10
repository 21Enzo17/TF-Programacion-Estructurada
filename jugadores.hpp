#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

const int MAXJ=100;
typedef char tcad[50];
typedef struct tusuario{
        int id,monedas,ganadas;
        tcad nombre,apellido,nickname,passwd;
};

typedef tusuario tusuarios[MAXJ];

//FUNCIONES Y PROCEDIMIENTOS
void main_jugadores(tusuarios a, int &ocup,int &id); // Linea 41
void menu_jugadores(char &op); // Linea 110
void menu_modificacion(char &opc); // Linea 307
void menu_ranking(char &opc); // Linea 409
void logueo(tusuarios usuarios,int ocup,int &pos); // Linea 346
// Operaciones sobre el vector
void insertar(tusuarios a,int &ocup,tusuario nuevo); // Linea 200
void agregar(tusuarios a,int &ocup,tusuario nuevo); // Linea 365
void eliminar(tusuarios a, int &ocup,tcad buscado); // Linea 247
void listar(tusuarios a,int ocup); // Linea 234
int busq_bin(tusuarios a,int ocup,tcad nickname); // Linea 178
int busq_bin_rec(tusuarios a,int bajo,int alto,tcad buscado); // Linea 156
void ranking(tusuarios a,int ocup); // Linea 373
void insercion(tusuarios &a,int ocup, bool opcion ); // Linea 416
// Operaciones de usuario
void crear_usuario(tusuarios v, int ocup,tusuario &a); // Linea 119
void modificar(tusuarios a,int &ocup, tcad user); // Linea 315
void modificacion(tusuarios a,int ocup,tusuario &u); // Linea 265
void mostrar(tusuario a); // Linea 226
// Especiales
bool validar_contra(tcad passwd); // Linea 329
void minuscula(tcad &cad); // Linea 149

void main_jugadores(tusuarios a, int &ocup,int &id){ // Menu principal de Jugadores
	tcad admin,contrasena;
	int pos;
	bool valido;
	char opc;
	do{
		system("cls");
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
				break;
			}
		}
	}while(!valido);
    tusuario aux;
    tcad user;
    char op;
    do{
        system("cls");
        menu_jugadores(op);
        switch (op)
        {
        case '1':
            crear_usuario(a,ocup,aux);
            id++;
            aux.id=id;
            insertar(a,ocup,aux);
            break;
        case '2':
            cout<<"Ingrese el nickname del usuario a consultar/modificar: ";
            fflush(stdin);
            gets(user);
			do{
				cout<<"Desea consultar o modificar c/m: ";
				cin>>opc;
			}while(opc!='m' && opc!='c');
			if(opc=='m')
				modificar(a,ocup,user);
			else
				pos=busq_bin_rec(a,0,ocup,user);
				if(pos!=-1){
					mostrar(a[pos]);
				}else{
					cout<<"No se encontro el jugador"<<endl;
				}
				
            break;
        case '3':
            cout<<"Listando "<<ocup+1<<" usuarios:"<<endl;
            listar(a,ocup);
            break;
        case '4':
            cout<<"Ingrese el nickname del usuario a eliminar: ";
            fflush(stdin);
            gets(user);
            eliminar(a,ocup,user);
            break;
        case '5':
            cout<<"Saliendo"<<endl;
            break;
        default:
            break;
        }
        system("pause");
    }while(op!='5');
    

}
void menu_jugadores(char &op){ // Menu para la funcion main_jugadores
    cout<<"=====MENU JUGADORES===="<<endl;
    cout<<"1. Agregar Jugadores"<<endl;
    cout<<"2. Consultar/Modificar jugador (nickname)"<<endl;
    cout<<"3. Listar Jugadores"<<endl;
    cout<<"4. Eliminar Jugador"<<endl;
    cout<<"5. Salir"<<endl;
    cin>>op;
}

void crear_usuario(tusuarios v, int ocup,tusuario &a){ // Este procedimiento permite crear un usuario
    int repite;
    bool valida;
    cout<<"Ingrese el nombre del usuario: ";
    fflush(stdin);
    gets(a.nombre);
    cout<<"Ingrese el Apellido del usuario: ";
    fflush(stdin);
    gets(a.apellido);
    do{
        cout<<"Ingrese el nickname del usuario: ";
        fflush(stdin);
        gets(a.nickname);
        repite=busq_bin_rec(v,0,ocup,a.nickname);
        if(repite!=-1){
            cout<<"Se repite el nickname ingrese nuevamente"<<endl;
        }
    }while(repite!=-1);
    do{
        cout<<"Ingrese la contrasena: ";
        fflush(stdin);
        gets(a.passwd);
        valida=validar_contra(a.passwd);
        if(!valida)
            cout<<"La contrasena debe tener 6 caracteres incluyendo, al menos, una minuscula, una mayuscula y un digito."<<endl;
    }while(!valida);
    
    a.ganadas=0;
    a.monedas=0;
}
void minuscula(tcad &cad){  
    //Este procedimiento transforma una cadena a minuculas
    int i;
    for(i=0;i<=strlen(cad);i++){
        cad[i]=tolower(cad[i]);
    }
}
int busq_bin_rec(tusuarios a,int bajo,int alto,tcad buscado){ // Busqueda Binaria recursiva, comparamos todo en minusculas
	int central;
	tcad aux1,aux2;
	strcpy(aux2,buscado);
	minuscula(aux2);
	if(bajo>alto){
		return -1;
	}else{
		central=(alto+bajo)/2;
		strcpy(aux1,(a[central].nickname));
		minuscula(aux1);
		if(strcmp(aux1,aux2)==0){
			return central;
		}else{
			if(strcmp(aux1,aux2)>0){
				return busq_bin_rec(a,bajo,central-1,buscado);
			}else{
				return busq_bin_rec(a,central+1,alto,buscado);
			}
		}
	}
} 
int busq_bin(tusuarios a,int ocup,tcad nickname){ // Dejamos inutilizada esta funcion por usar la forma recursiva
    int alto=ocup,bajo=0,central,pos=-1;
    tcad aux1,aux2;
    strcpy(aux2,nickname);
    minuscula(aux2);
    while(bajo<=alto && pos==-1){
        central=(alto+bajo)/2;
        strcpy(aux1,(a[central].nickname));
        minuscula(aux1);
        if(strcmp(aux1,aux2)==0){
            pos=central;
        }else{
            if(strcmp(aux1,aux2)>0){
                alto=central-1;
            }else{
                bajo=central+1;
            }
        }
    }
    return pos;
}

void insertar(tusuarios a,int &ocup,tusuario nuevo){ // Procedimiento insertar, inserta segun nick de menor a mayor y desplaza segun posicion
    int i=0,j;
    tcad aux1,aux2;
    if(ocup==MAX-1){
        cout<<"Vector lleno"<<endl;
    }else{
        strcpy(aux2,nuevo.nickname);
        minuscula(aux2);
        strcpy(aux1,a[i].nickname);
        minuscula(aux1);
        while(i<=ocup && strcmp(aux1,aux2)<0){
            i++;
            strcpy(aux1,a[i].nickname);
            minuscula(aux1);
            
        }
        j=ocup;
        while(j>=i){
            a[j+1]=a[j];
            j--;
        }
        ocup++;
        a[i]=nuevo;
    }
    
}
void mostrar(tusuario a){ // Procedimiento auxiliar que muestra los datos de un usuario
    cout<<"============================"<<endl;
    cout<<"ID:"<<a.id<<endl;
    cout<<"Nickname: "<<a.nickname<<endl;
    cout<<"Nombre y Apellido: "<<a.nombre<<" "<<a.apellido<<endl;
    cout<<"Partidas Ganadas: "<<a.ganadas<<endl;
    cout<<"Monedas: "<<a.monedas<<endl;    
}
void listar(tusuarios a,int ocup){ // Procedimiento para listar recursivamente
    if(ocup==-1){
        cout<<"No hay ususarios para listar"<<endl;
    }else{
        if(ocup==0){
            mostrar(a[ocup]);
        }else{
            listar(a,ocup-1);
            mostrar(a[ocup]);
        }
    }
}

void eliminar(tusuarios a, int &ocup,tcad buscado){ // Este procedimiento busca un usuario y lo elimina, desplazando posiciones
    int i;
    if(ocup==-1){
        cout<<"VECTOR VACIO, no se elimina nada"<<endl;
    }else{
        i=busq_bin_rec(a,0,ocup,buscado);
        if(i!=-1){
            while(i<ocup){
            a[i]=a[i+1];
            i++;
            }
            ocup--;
            cout<<"BORRADO CON EXITO"<<endl;
        }else{
            cout<<"NO SE ENCONTRO EL USUARIO"<<endl;
        }
    }
}
void modificacion(tusuarios a,int ocup,tusuario &u){ // Este procedimiento nos muestra un menu de modificacion de usuario.
    char opc;
    tcad aux;
    bool valida;
    do{
        menu_modificacion(opc);
        switch (opc)
        {
            case '1':
                cout<<"Ingrese el nombre: ";
                fflush(stdin);
                gets(u.nombre);
                break;
            case '2':
                cout<<"Ingrese el apellido: ";
                fflush(stdin);
                gets(u.apellido);
                break;
            case '3':
                do{
                    cout<<"Ingrese su contrasena nueva: ";
                    fflush(stdin);
                    gets(aux);
                    valida=validar_contra(aux);
                    if(!valida)
                        cout<<"La contrasena debe tener 6 caracteres incluyendo, al menos, una minuscula, una mayuscula y un digito."<<endl;
                }while(!valida);
                strcpy(u.passwd,aux);
                break;
            case '4':
                break;
                cout<<"DATOS NUEVOS: "<<endl;
                mostrar(u);
                cout<<"Contrasena: "<<u.passwd<<endl;
            default:
                cout<<"Elija una opcion correcta!"<<endl;
                break;
        }
    }while(opc!='4');
}

void menu_modificacion(char &opc){ // Este es el menu para el procedimiento modificacion
    cout<<"=====MENU MODIFICACION====="<<endl;
    cout<<"1. Modificar nombre"<<endl;
    cout<<"2. Modificar apellido"<<endl;
    cout<<"3. Modificar contrasena"<<endl;
    cout<<"4. Confirmar cambios"<<endl;
    cout<<"Ingrese su opcion: ";
    cin>>opc;
}
void modificar(tusuarios a,int &ocup, tcad user){ // Este procedimiento busca y llama al procedimiento modificacion para modificar un usuario
    int i;
    if(ocup==-1){
        cout<<"Vector vacio"<<endl;
    }else{
        i=busq_bin_rec(a,0,ocup,user);
        if(i!=-1){
            modificacion(a,ocup,a[i]);
        }else{
            cout<<"No se encontro ninguna coincidencia"<<endl;
        }
    }
}

bool validar_contra(tcad passwd){ // Esta funcion comprueba min, may, digito y 6 caracteres exactos
    int i;
    bool min=false,may=false,dig=false;
    if(strlen(passwd)==6){
        for(i=0;i<=strlen(passwd);i++){
            if(passwd[i]>='a' && passwd[i]<='z')
                min=true;
            if(passwd[i]>='A' && passwd[i]<='Z')
                may=true;
            if(passwd[i]>='0' && passwd[i]<='9')
                dig=true;
        }
    }
    return min && may && dig;
}

void logueo(tusuarios usuarios,int ocup, int &pos){ // Este procedimiento busca un usuario y se loguea
    tcad aux;
    do{
        cout<<"Ingrese el nickname del usuario: ";
        fflush(stdin);
        gets(aux);
        pos=busq_bin_rec(usuarios,0,ocup,aux);
        if(pos==-1)
            cout<<"No se encontro el usuario"<<endl;
    }while(pos==-1);
    do{
        cout<<"Ingrese la contrasena: ";
        fflush(stdin);
        gets(aux);
        if(strcmp(usuarios[pos].passwd,aux)==0)
            cout<<"Contrasena correcta Ingresando"<<endl;
        else
            cout<<"Contrasena incorrecta, reingrese"<<endl;
    }while(strcmp(usuarios[pos].passwd,aux)!=0);
}
void agregar(tusuarios a,int &ocup,tusuario nuevo){ // Agrega un elemento al final de un vector
    if(ocup==MAX-1){
        cout<<"Ranking lleno"<<endl;
    }else{
        ocup++;
        a[ocup]=nuevo;
    }
}
void ranking(tusuarios a,int ocup){ // Aqui simplemente cargamos todos los que tengan 1 o mas victorias y luego ordenamos segun opcion
	tusuarios ranking;
    int ocupR=-1,i;
    char opc;
    for(i=0;i<=ocup;i++){
        if(a[i].ganadas>0){
            agregar(ranking,ocupR,a[i]);
        }
    }
    do{
		system("cls");
		menu_ranking(opc);
        switch (opc)
        {
        case '1':
            insercion(ranking,ocupR,true);
			cout<<"Ordenado:"<<endl;
            listar(ranking,ocupR);
            break;
        case '2':
            insercion(ranking,ocupR,false);
			cout<<"Ordenado:"<<endl;
            listar(ranking,ocupR);
            break;
        case '3':
            cout<<"Saliendo.."<<endl;
            break;
        default:
            cout<<"Seleccione una opcion valida"<<endl;
            break;
        }
		system("pause");
    }while(opc!='3');
}

void menu_ranking(char &opc){ // menu para ranking
    cout<<"Menu Ranking"<<endl;
    cout<<"1. Ranking por monedas"<<endl;
    cout<<"2. Ranking por victorias"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Ingrese su opcion"<<endl;
    cin>>opc;
}
void insercion(tusuarios &a,int ocup, bool opcion ){ // Procedimiento de ordenacion por insercion
    int i,j;
    tusuario aux;
    for(i=1;i<=ocup;i++){
        aux=a[i];
        j=i-1;
        if(opcion){ // ordenar por monedas
            while(j>=0 && aux.monedas>a[j].monedas){
                a[j+1]=a[j];
				j--;
            }
        }else{ // ordenar por victorias
            while(j>=0 && aux.ganadas>a[j].ganadas){
                a[j+1]=a[j];
				j--;
            }
        }
        a[j+1]=aux;
    }
}
