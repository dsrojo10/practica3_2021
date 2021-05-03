#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

string lectura(string); //funcion que recibe el nombre del archivo y carga en un string todo lo que hay
void strToBin (string);//funcion que recibe un str y lo escribe en un archivo en binario
void binToStr(string cadena); 
int contarCeros(string cadena);
int contarUnos(string cadena);
//LAS FUNCIONES PARA INVERTIR RECIBEN DOS CADENAS IGUALES YA QUE EL ALGORITMO
//NECESITA TENER UNA COPIA PARA INVERTIR ESA COPIA
string invAll(string,string&); //Funcion que recibe la cadena a invertir <recibe la cadena y su copia>
string inv2(string,string&); //Funcion que inverte cada 2 bits <recibe la cadena y su copia>
string inv3(string,string&); //funcion que invierte cada 3 bits <recibe la cadena y su copia>
void Metodo1 (string); //Funcion para el metodo1 de encriptacion <recibe el str a encriptar>
void dMetodo1 (string); //Funcion para desencriptar metodo1 <recibe el str a desencriptar>

int main(){
	
	string myString = lectura("cadena.txt"); //Cargamos cadena a convertir a binario
	strToBin(myString); //Invocamos la funcion
	string cadena = lectura("prueba.txt"); //Cargamos el binario ya convertido (el cual fue escrito en el archivo prueba.txt) 
	Metodo1(cadena); 
	cadena = lectura("encriptado1.txt");
	dMetodo1(cadena);
	cadena = lectura("desencriptado1.txt"); //Cargamos el archivo binario ya desencriptado, antes de convertirlo a string de nuevo
    cout << cadena;
	binToStr(cadena);  
	
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

void binToStr(string cadena) {
  ofstream archivo;
  archivo.open("Desencrip_Str.txt",ios::out); //Abriendo archivo
  for (int i=0; i<int(cadena.size());i+=8){
  	if(cadena[i]!='\n'){
  		string cadena1 = cadena.substr(i, 8);
    	cout << char(bitset<8>(cadena1).to_ulong());
    	archivo << char(bitset<8>(cadena1).to_ulong());
	  }
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

string invAll(string cadena, string& cadena2){
  for(int i=0;i<int(cadena.size());i++){
    if(cadena[i]=='0') cadena2[i]='1';
    else if(cadena[i]=='1') cadena2[i]='0';
  }
  return cadena2;
}

string inv2(string cadena, string& cadena2){
  for(int i=1;i<int(cadena.size());i+=2){
    if(cadena[i]=='0') cadena2[i]='1';
    else if(cadena[i]=='1') cadena2[i]='0';
  }
  return cadena2;
}

string inv3(string cadena, string& cadena2){
  for(int i=2;i<int(cadena.size());i+=3){
    if(cadena[i]=='0') cadena2[i]='1';
    else if(cadena[i]=='1') cadena2[i]='0';
  }
  return cadena2;
}

void Metodo1 (string cadena){
    int n;
    cout << "Ingrese el numero para las particiones: "; cin >> n;
    cout << cadena << endl;
    ofstream archivo;
  	archivo.open("encriptado1.txt",ios::out); //Creamos archivo para guardar la encriptación

    string cadena1 = cadena.substr(0, n);
    string cadena2 = cadena1;
    int unos=contarUnos(cadena1); int ceros=contarCeros(cadena1);
    cout << invAll(cadena1,cadena2);
    archivo << invAll(cadena1,cadena2);
    for (int i=n; i<int(cadena.size());i+=n){
      string cadena1 = cadena.substr(i, n);
      string cadena2 = cadena1;
      if(unos==ceros){
      	cout << invAll(cadena1,cadena2);
        archivo << invAll(cadena1,cadena2);
	  }
        
      else if(ceros>unos){
	    cout << inv2(cadena1,cadena2);
        archivo << inv2(cadena1,cadena2);
	  }
      else if(unos>ceros){
      	cout << inv3(cadena1,cadena2);
        archivo << inv3(cadena1,cadena2);
	  }
      unos=contarUnos(cadena1); ceros=contarCeros(cadena1);
    }
    cout << endl;
    archivo << endl;
}

void dMetodo1 (string cadena){
	//En la desencriptacion no evaluamos en la vieja, si no que evaluamos en la que acabo de ser convertida 
    int n;
    cout << "Ingrese el numero para las particiones: "; cin >> n;
    cout << cadena << endl;
    ofstream archivo;
  	archivo.open("desencriptado1.txt",ios::out); //Creamos archivo para guardar la encriptación

    string cadena1 = cadena.substr(0, n);
    string cadena2 = cadena1;
    cout << invAll(cadena1,cadena2);
    archivo << invAll(cadena1,cadena2);
    int unos=contarUnos(cadena2); int ceros=contarCeros(cadena2);
    for (int i=n; i<int(cadena.size());i+=n){
      string cadena1 = cadena.substr(i, n);
      string cadena2 = cadena1;
      if(unos==ceros){
      	cout << invAll(cadena1,cadena2);
        archivo << invAll(cadena1,cadena2);
	  }
        
      else if(ceros>unos){
	    cout << inv2(cadena1,cadena2);
        archivo << inv2(cadena1,cadena2);
	  }
      else if(unos>ceros){
      	cout << inv3(cadena1,cadena2);
        archivo << inv3(cadena1,cadena2);
	  }
      unos=contarUnos(cadena2); ceros=contarCeros(cadena2);
    }
    cout << endl;
    archivo << endl;
}




