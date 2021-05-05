#include <iostream>
#include <fstream>


using namespace std;

//VARIABLES GLOBALES
int cedula, clave, opcion;
float saldo;

//FUNCIONES PROPIAS
void addRegister (); //Agregar registro
void readRegister(); //Leer todos los registros
void searchRegister(); //Buscar un registro en especifico por clave
void deleteRegister(); //Eliminar registro especifico por clave
void editRegister(); //Editar registro especifico por clave

int main() {	
	
	
	while(true) {
		
		cout << "\n1. Registrar usuario" << endl;
		cout << "2. Mostrar todos los usuarios" << endl;
		cout << "3. Buscar usuario" << endl;
		cout << "4. Eliminar usuario" << endl;
		cout << "5. Editar usuario (cambiar saldo)" << endl;
		cout << "Ingrese opcion: ";
		cin >> opcion;
		
		switch(opcion) {
			
			case 1: {
				addRegister();
				break;
			}
			
			case 2: {
				readRegister();
				break;
			}
			
			case 3: {
				searchRegister(); 				
				break;
			}
			
			case 4: {
				deleteRegister();				
				break;
			}
			
			case 5: {
				editRegister();
				break;
			}
		}
	}
}


void addRegister () {
	ofstream Guardar;
	Guardar.open("FicheroBanco.txt", ios::app); // app para no se sobreescriba...
				
	cout << "Ingrese cedula: "; cin >> cedula;
	cout << "Ingrese clave: "; cin >> clave;
	cout << "Ingrese saldo: "; cin >> saldo;
	Guardar << cedula << ' ' << clave << ' ' << saldo <<endl;
	Guardar.close();
}

void readRegister() {
	ifstream Leer;
	Leer.open("FicheroBanco.txt");
	Leer >> cedula;
	cout << endl;
	while (!Leer.eof()){
		Leer >> clave >> saldo;
		cout << "Cedula: " << cedula << endl;
		cout << "Clave: " << clave << endl;
		cout << "Saldo: " << saldo << endl;
		cout << endl;
		Leer >> cedula;
	}
	Leer.close();
}

void searchRegister() {
	ifstream Leer;
	int Bcedula;
	Leer.open("FicheroBanco.txt");
	bool encontrado = false;
	Leer >> cedula;
	cout << "Ingrese cedula a buscar: "; cin >> Bcedula;
	cout << endl;
	while (!Leer.eof()) {
		Leer >> clave >> saldo;
		if(cedula==Bcedula){
			encontrado = true;
			cout << "Cedula: " << cedula << endl;
			cout << "Clave: " << clave << endl;
			cout << "Saldo: " << saldo << endl;
			cout << endl;
		}
		Leer >> cedula;
	}
	if(encontrado==false){
		cout << "\nCedula no encontrada.\n\n";
	}	
	Leer.close();
}

void deleteRegister() {
	ifstream Leer;
	ofstream Temp;
	Leer.open("FicheroBanco.txt");
	Temp.open("Temp.txt");
	int Bcedula;
	bool encontrado = false;
	Leer >> cedula;
	cout << "Ingrese cedula a eliminar: "; cin >> Bcedula;
	while (!Leer.eof()) {
		Leer >> clave >> saldo;
		if(cedula==Bcedula){
			encontrado = true;
			cout << "\nCedula: " << cedula << endl;
			cout << "Clave: " << clave << endl;
			cout << "Saldo: " << saldo << endl;
			cout << "\nEliminado...\n\n";
		}
		else{
			Temp << cedula << ' ' << clave << ' ' << saldo <<endl;
		}
		Leer >> cedula;
	}
	if(encontrado==false){
		cout << "\nClave no encontrada.\n\n";
	}	
	Leer.close();
	Temp.close();
	remove("FicheroBanco.txt"); //ELIMINAR FICHERO
	rename("Temp.txt","FicheroBanco.txt"); //RENOMBRAMOS A TEMP -> COMO FICHERO
}

void editRegister() {
	ifstream Leer;
	ofstream Temp;
	Leer.open("FicheroBanco.txt");
	Temp.open("Temp.txt");
	int Bcedula;
	float Nsaldo;
	bool encontrado = false;
	Leer >> cedula;
	cout << "Ingrese cedula del usuario a modificar: "; cin >> Bcedula;
	while (!Leer.eof()) {
		Leer >> clave >> saldo;
		if(cedula==Bcedula){
			encontrado = true;
			cout << "\nCedula: " << cedula << endl;
			cout << "Clave: " << clave << endl;
			cout << "Saldo: " << saldo << endl;
			cout << endl;
			cout << "Ingrese nuevo saldo: "; cin >> Nsaldo;
			cout << "\nModificado...\n";			
			Temp << cedula << ' ' << clave << ' ' << Nsaldo <<endl;
		}
		else{
			Temp << cedula << ' ' << clave << ' ' << saldo <<endl;
		}
		Leer >> cedula;
	}
	if(encontrado==false){
		cout << "\nCedula no encontrada.\n\n";
	}	
	Leer.close();
	Temp.close();
	remove("FicheroBanco.txt"); //ELIMINAR FICHERO
	rename("Temp.txt","FicheroBanco.txt"); //RENOMBRAMOS A TEMP -> COMO FICHERO
}
