#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

string lectura(string); //funcion que recibe el nombre del archivo y carga en un string todo lo que hay
void strToBin (string);//funcion que recibe un str y lo escribe en un archivo en binario
int contarCeros(string cadena);
int contarUnos(string cadena);

int main(){
	
	string myString = lectura("cadena.txt");
	strToBin(myString); //Invocamos la funcion
	string cadena = lectura("prueba.txt"); 
	for (int i=0; i<(cadena.size()-1);i+=4){ // -1 ciclo para no tener en cuenta el salto de linea final
    string cadena1 = cadena.substr(i, 4);
    cout << cadena1 << endl;
    cout << "La cantidad de 0 es: " << contarCeros(cadena1) << endl;
    cout << "La cantidad de 1 es: " << contarUnos(cadena1) << endl;
    cout << "La cantidad de #'s es: " << cadena1.size() << endl;
    cout << endl << endl;
  }
  
	return 0;
}

void strToBin (string cadena){
  ofstream archivo;
  archivo.open("prueba.txt",ios::out); //Abriendo archivo
  for (size_t i = 0; i < (cadena.size()-1); ++i){ //**Acá vamos a restar un ciclo para no codificar el salto de linea
    archivo << bitset<8>(cadena.c_str()[i]);
    //cout << bitset<8>(cadena.c_str()[i]); //Impresion por consola para verificar.
  }
  archivo.close();
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

int contarCeros(string cadena){
  int ceros = 0;
  for(int i=0;i<cadena.size();i++){
    if(cadena[i]=='0')  ceros++;
  }
  return ceros;
}

int contarUnos(string cadena){
  int unos = 0;
  for(int i=0;i<cadena.size();i++){
    if(cadena[i]=='1') unos++;
  }
  return unos;
}
