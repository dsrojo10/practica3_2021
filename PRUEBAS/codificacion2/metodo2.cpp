#include <iostream>
#include <string>

using namespace std;


//Prototipos
void encriptar2(string);

int main() {
	
  string cadena = "01000001011000100100001101100100";
  encriptar2(cadena);
  
  return 0;
}

void encriptar2(string cadena) {

  int n=4;
  cout << "cadena original: " << cadena << endl;
  cout << "Ingrese el numero de particiones: ";
  cin >> n;
  
  cout << "cadena codificada: ";

  for(int i=0;i<int(cadena.size());i+=n){
	//Dividimos la cadena original en segmentos de tamaño n
    string cadena1 = cadena.substr(i, n);
    if (cadena1.size()<n) //En caso de que el segmento sea menor a n, vaciamos el segmento para no tener errores
      cadena1 = "0000000000000000000000000000000000"; 
    cadena1 = cadena.substr(i, n);
    
    // cout << endl << cadena1.size() << endl;
  
	//Hacemos la encriptacion sobre la misma variable llamada cadena
    int j=0;
	//i es un variable que va creciendo constantemente ya que recorre toda la cadena general
	//j es una varibale que siempre va de 0 a 3, ya que recorre el segmento de cadena
    cadena[i] = cadena1[j+n-1];
      for(int x=0;x<(n-1);x++){
        cadena[i+x+1] = cadena1[j+x];
      }
    }
    //Basicamente esto es lo que hacemos cuando n=4:
    /////////copiamos el ultimo en el primero///////////
    //cadena[i] = cadena1[j+n-1];
    ////////el resto los movemos una posicion adelante///////
    // cadena[i+1] = cadena1[j];
    // cadena[i+2] = cadena1[j+1];
    // cadena[i+3] = cadena1[j+2];
  
	//Imprimimos de nuevo cadena para verificar encriptacion
  cout << cadena;
	
}
