#include <iostream>
#include <bitset>
#include <fstream>

using namespace std;
void binToStr(string); //Funcion que recibe un 
string lectura(string); //funcion que recibe el nombre del archivo y carga en un string todo lo que hay


int main() {


  string cadena = lectura("desencriptado1.txt");
  cout << cadena;
  binToStr(cadena);
  
    return 0;
}

void binToStr(string cadena) {
  ofstream archivo;
  archivo.open("desencrip_str.txt",ios::out); //Abriendo archivo
  for (size_t i = 0; i < (cadena.size()-1); i+=8){
  	if(cadena[i]!='\n'){
  		string cadena1 = cadena.substr(i, 8);
    	cout << char(stoi(cadena1, 0, 2));
    	archivo << char(stoi(cadena1, 0, 2));
	  }
    
    }
}

string lectura(string cadena){
	ifstream fichero;
	string texto="",temporal="";
	fichero.open(cadena.c_str(),ios::in);
	if (!fichero.fail()){
	    while (!fichero.eof()){
	         getline(fichero, temporal);
	        texto += temporal+"\n";
	    }
	    fichero.close();
	}
	return texto;
}
