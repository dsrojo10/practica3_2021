#include <iostream>
#include <string>

using namespace std;

int contarCeros(string cadena);
int contarUnos(string cadena);
//LAS FUNCIONES PARA INVERTIR RECIBEN DOS CADENAS IGUALES YA QUE EL ALGORITMO
//NECESITA TENER UNA COPIA PARA INVERTIR ESA
string invAll(string, string); //Funcion que recibe la cadena a invertir (recibe la cadena y su copia)
string inv2(string, string); //Funcion que inverte cada 2 bits
string inv3(string, string); //funcion que invierte cada 3 bits
void Metodo1 (string);


int main() {

    string cadena = "01000001011000100100001101100100";
    Metodo1(cadena);

    return 0;
}

int contarCeros(string cadena){
  int ceros = 0;
  for(int i=0;i<int(cadena.size());i++){
    if(cadena[i]=='0')  ceros++;
  }
  return ceros;
}

int contarUnos(string cadena){
  int unos = 0;
  for(int i=0;i<int(cadena.size());i++){
    if(cadena[i]=='1') unos++;
  }
  return unos;
}

string invAll(string cadena, string cadena2){
  for(int i=0;i<int(cadena.size());i++){
    if(cadena[i]=='0') cadena2[i]='1';
    else if(cadena[i]=='1') cadena2[i]='0';
  }
  return cadena2;
}

string inv2(string cadena, string cadena2){
  for(int i=1;i<int(cadena.size());i+=2){
    if(cadena[i]=='0') cadena2[i]='1';
    else if(cadena[i]=='1') cadena2[i]='0';
  }
  return cadena2;
}

string inv3(string cadena, string cadena2){
  for(int i=2;i<int(cadena.size());i+=3){
    if(cadena[i]=='0') cadena2[i]='1';
    else if(cadena[i]=='1') cadena2[i]='0';
  }
  return cadena2;
}

void Metodo1 (string cadena){
    cout << cadena << endl;

    string cadena1 = cadena.substr(0, 4);
    string cadena2 = cadena1;
    int unos=contarUnos(cadena1); int ceros=contarCeros(cadena1);
    cout << invAll(cadena1,cadena2);
    for (int i=4; i<int(cadena.size());i+=4){
      string cadena1 = cadena.substr(i, 4);
      string cadena2 = cadena1;
      if(unos==ceros)
        cout << invAll(cadena1,cadena2);
      else if(ceros>unos)
        cout << inv2(cadena1,cadena2);
      else if(unos>ceros)
        cout << inv3(cadena1,cadena2);
      unos=contarUnos(cadena1); ceros=contarCeros(cadena1);
    }
    cout << endl;
}

