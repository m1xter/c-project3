#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

// NODO
struct Nodo{
	int dato;
	Nodo * siguiente;	
};
// COLA 
void insertarCola(Nodo *&,Nodo *&,int);
bool cola_vacia(Nodo * );
void eliminarCola(Nodo *&,Nodo *& ,int &n);
void buscarCola();
// PILA 
void agregarPila(Nodo *&,int dato);
void sacarPila(Nodo *&,int &dato  );
vector<string> contras(char  * cedula);
string invertir(string cedula);
void mostrarCola(Nodo *& frente);
bool comprobar(Nodo *& frente,Nodo *& fin,int &n);

int main(int argc, char** argv) {
	
	// para la pila 
	Nodo * pila = NULL;
	// para la cola 
	Nodo * frente = NULL;
	Nodo * fin = NULL;
	int op;
	char cedula[8]; 
	int cedu;	int dato;
	string ce,in;
	
	// cola para las cedulas en espera 
	// pila para los codigos definitivos;
	
	
	while(op !=5){
		system("cls");
		cout<<endl;
		cout<<"cola : ";
		mostrarCola(frente);		
		cout<<endl;
		cout<<"--------MENU--------"<<endl;		
		cout<<"1. incertar cedula a la cola "<<endl;
		cout<<"2. atender taquilla 1"<<endl;		
		cout<<"3. atender taquilla 2"<<endl;		
		cout<<"4. atender taquilla 3"<<endl;		
		cout<<"5. salir"<<endl;
		cout<<"Opcion:    ";
		cin>>op;
		
		switch(op){
			case 1:{
				cout<<"ingrese cedula: ";
				cin>>cedula;	
				vector<string> c = contras(cedula);
				
				
				 for(int i =0 ;i <3;i++){
				 	
					ce =  c[i];
					dato= stoi(ce); 	
					
				 	if(cola_vacia(frente) || comprobar(frente,fin,dato) == false){
				 		insertarCola(frente,fin,dato);	
				 		system("pause");
				 		break;					 		
					}
					if(comprobar(frente,fin,dato)){
						
						cout<< "la clave "<< dato <<" ya existe generando otra...."<<endl;
						
						in = invertir(ce);
						dato = stoi(in);
						
						
				 		if(comprobar(frente,fin,dato) == false){
				 			insertarCola(frente,fin,dato);	
					 		system("pause");
				 			break;				
						 }
				 		
					}
					
							
							 	
				 }
												
				
			}								
			break;
			case 2:{				
				for(int i =0;i<1;i++){
					eliminarCola(frente,fin,dato);
				}
				cout<<"se atendio al cliente en la taquilla 1"<<endl;
				cout<<"sacando clave de la cola..."<<endl;
			}
			break;
			case 3:{				
				for(int i =0;i<1;i++){
					eliminarCola(frente,fin,dato);
				}
				cout<<"se atendio al cliente en la taquilla 2"<<endl;
				cout<<"sacando clave de la cola..."<<endl;
			}
			break;
			case 4:{				
				for(int i =0;i<1;i++){
					eliminarCola(frente,fin,dato);
				}
				cout<<"se atendio al cliente en la taquilla 3"<<endl;
				cout<<"sacando clave de la cola..."<<endl;
			}
			break;
			
			
		}
		
	}
	
	
	 
	
	



	
getch();
return 0;	
}


vector<string> contras(char * cedula){
	string n0,n1,n2,n3,n4,n5,n6,n7,c1,c2,c3;
	n0 = cedula[0]; n1 = cedula[1]; n2 = cedula[2];
	c1 = n0+n1+n2;
	n3 = cedula[3]; n4 = cedula[4]; n5 = cedula[5];
	c2 = n3+n4+n5;
	n6 = cedula[6]; n7 = cedula[7];
	c3 = n5+n6+n7;
	
	vector<string> contras = {c1,c2,c3};
	
	return contras;
}




//funcion invertir cedula 
string  invertir(string cedula){
	
	char tem;
	int i,mitad,len;
	
	len = cedula.length();
	mitad  = len/2;
	for(int i =0 ;i<mitad;i++){
		tem = cedula[i];
		cedula [i] = cedula[len - 1 - i];
		cedula [len - i -1]  = tem;
	}
	
	return cedula;
}


// PILA 
void sacarPila(Nodo *&pila, int &n ){
	Nodo * aux = pila ;
	n = aux -> dato;
	pila = aux -> siguiente;
	delete aux;
}

void agregarPila(Nodo *&pila,int n){
	Nodo * nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo ;
	
	cout<<"el elemento "<< n << " ha sido agregado a pila correctamente "<<endl;
}

// COLA


void mostrarCola(Nodo *& frente){
	Nodo * actual = new Nodo();
	actual = frente;
	if(frente != NULL){
		while(actual != NULL){
			cout<< actual->dato<<" , ";
			actual = actual -> siguiente;
		}
	}else{
		cout<<"la cola esta vacia"<<endl;
	}
	
}

bool comprobar(Nodo *& frente,Nodo *& fin,int &n){
	Nodo * actual = new Nodo();
	actual = frente;
	bool encontrado = false;
	if(frente != NULL){
		while(actual != NULL && encontrado != true){			
			
			if(actual->dato == n){
				encontrado = true;
				return true;	
			}
			
			actual = actual -> siguiente;
		}
		if(!encontrado){
			return false;
		}
	}else{
		cout<<"la cola no exite"<<endl;
	}	
}




void eliminarCola(Nodo *& frente,Nodo *& fin, int &n){
	n = frente ->dato;
	Nodo * aux = frente;	
	if(frente == fin ){
		frente = NULL;
		fin == NULL;		
	}
	else{
		frente  = frente -> siguiente;		
	}	
	delete aux;
}


void insertarCola(Nodo *& frente ,Nodo *& fin,int n){
	Nodo * nuevo_nodo = new Nodo();
	
	nuevo_nodo -> dato = n;
	nuevo_nodo ->siguiente = NULL;
	if( cola_vacia(frente)){
		frente = nuevo_nodo;
	}else{
		fin -> siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
	
	cout<< "elemento " << n << " insertado a la cola"<<endl;
	
}

bool cola_vacia(Nodo * frente){
	return (frente == NULL) ? true : false;
}
