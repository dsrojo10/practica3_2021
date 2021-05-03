//Lectura de un archivo de texto

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

string lectura();

int main() {
	
	cout << lectura();
	
	return 0;
}



string lectura(){
	ifstream fichero;
	string texto="",temporal="";
	fichero.open("cadena.txt",ios::in);
	if (!fichero.fail()){
	    while (!fichero.eof()){
	         getline(fichero, temporal);
	        texto += temporal+"\n";
	    }
	    fichero.close();
	}
	return texto;
}
