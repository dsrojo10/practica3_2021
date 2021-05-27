#include <iostream>
#include <string>

using namespace std;

void Dmetodo2(string);

int main() {

  //string cadena = "00101000001100010010100100110010"; //n=4
  string cadena = "00100100101100000010000111110000"; //n=5
  // string cadena = "00100000101100010010000110110010"; //n=7
  cout << cadena.size();
  Dmetodo2(cadena);
  
  return 0;
}

void Dmetodo2(string cadena){
  string cadena2 = cadena; //copia para devolver
  cout << "cadena codificada: " << cadena << endl;
  int n=4;
  cout << "Ingrese el numero de particiones: ";
  cin >> n;

  cout << "cadena decodificada: ";
  int i=0, x=0;

  for(i=0;i<int(cadena.size());i+=n){
    	//Dividimos la cadena original en segmentos de tamaño n
    string cadena1 = cadena.substr(i, n);
    if (cadena1.size()<n) { //En caso de que el segmento sea menor a n, vaciamos el segmento para no tener errores
      cadena1 = "0000000000000000000000000000000000000000000000000000"; 
      cadena1 = cadena.substr(i, n); //y volvemos a tomar el segmento despues de la limpieza
      }

   //DECODIFICACIÓN
    int j=0;
    cadena2[i+n-1]=cadena1[j];
    for(x=0;x<(n-1);x++)
     cadena2[i+x]=cadena1[j+x+1];
  }
  cout << cadena.size() << endl << cadena2.size();
  if (cadena.size()!=cadena2.size()){
    cadena2[cadena.length()-1]='0';
  }
  cout << cadena2;
}
