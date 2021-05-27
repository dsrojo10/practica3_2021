#include <iostream>
#include <string>
#include <fstream>
#include <bitset> //PARA LA CONVERSION A BINARIO

using namespace std;


//Prototipos

///////////////////////////FUNCIONES PARA CONVERTIR/////////////////////////////////////
void strToBin (string);//funcion que recibe un str y lo escribe en un archivo en binario
void binToStr(string, string);

//////////////////////////FUNCIONES MANEJO DE ARCHIVOS/////////////////////////////////////
string lectura(string); //funcion que recibe el nombre del archivo y carga en un string todo lo que hay

////////////////////////////////FUNCIONES METODO 2/////////////////////////////////////////
void Metodo2 (string, string); //Funcion para el metodo1 de encriptacion <recibe el str a encriptar> y el nombre del archivo de salida
void dMetodo2 (string); //Funcion para desencriptar metodo1 <recibe el str a desencriptar>

void encriptar2(string, string); //recibe archivo de entrada y de salida.  con .txt
void desencriptar2(string, string); //recibe archivo de entrada y de salida. con .txt

///////////////////FUNCIONES PROPIAS PARA VERIFICAR UN CORRECTO DESARROLLO////////////////////
void Verificacion2(); //Función para encriptar y desencriptar metodo1 recibe <nombrecadena.txt>

int main() {

//  string cadena = "01000001011000100100001101100100";
//  string archOut = "encriptado2.txt";
//  Metodo2(cadena, archOut);
//  //dMetodo2(cadena);

    Verificacion2();
  return 0;
}


//////////////FUNCIONES PARA CONVERTIR/////////////////////////
void strToBin (string cadena){
  ofstream archivo;
  archivo.open("binario.txt",ios::out); //Abriendo archivo
  for (size_t i = 0; i < (cadena.size()-1); ++i){ //**Acá vamos a restar un ciclo para no codificar el salto de linea
    archivo << bitset<8>(cadena.c_str()[i]);
    //cout << bitset<8>(cadena.c_str()[i]); //Impresion por consola para verificar.
  }
  archivo.close();
}

void binToStr(string cadena, string archOut) {
  ofstream archivo;
  archivo.open(archOut.c_str(),ios::out); //Abriendo archivo
  for (int i=0; i<int(cadena.size());i+=8){
    if(cadena[i]!='\n'){
        string cadena1 = cadena.substr(i, 8);
        cout << char(bitset<8>(cadena1).to_ulong());
        archivo << char(bitset<8>(cadena1).to_ulong());
      }
    }
    archivo.close();
    cout << endl;
}


//////////////FUNCIONES PARA MANEJO DE ARCHIVOS//////////////////
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



void Metodo2(string cadena, string archOut) {
  int n;
  cout << "cadena original: " << cadena << endl;
  cout << "\nIngrese el numero de particiones: "; cin >> n;
  ofstream archivo;
  archivo.open(archOut.c_str(),ios::out); //Creamos archivo para guardar la encriptación

  cout << "cadena codificada: ";

  for(int i=0;i<int(cadena.size());i+=n){
    //Dividimos la cadena original en segmentos de tamaño n
    string cadena1 = cadena.substr(i, n);
    if (int(cadena1.size())<n) //En caso de que el segmento sea menor a n, vaciamos el segmento para no tener errores
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
  cout<<cadena<<endl;
  archivo<<cadena<<endl;
}

void dMetodo2(string cadena){
  string cadena2 = cadena; //copia para devolver
//  cout << "\ncadena codificada: " << cadena << endl;
  int n=4;
  cout << "\nIngrese el numero de particiones: ";
  cin >> n;
  ofstream archivo;
  archivo.open("desencriptado2.txt",ios::out); //Creamos archivo para guardar la encriptación

  cout << "cadena decodificada: ";
  int i=0, x=0;

  for(i=0;i<int(cadena.size());i+=n){
        //Dividimos la cadena original en segmentos de tamaño n
    string cadena1 = cadena.substr(i, n);

   //DECODIFICACIÓN
    int j=0;
    cadena2[i+n-1]=cadena1[j];
    for(x=0;x<(n-1);x++)
      if(cadena1[j+x+1] != '\0'){ //verificar que el siguiente caracter no sea el final de la cadena
        cadena2[i+x]=cadena1[j+x+1];
      }
  }
//  cout << cadena.size() << endl << cadena2.size();
  cout << cadena2 << endl;
  archivo << cadena2 << endl;
}

void Verificacion2() {
    string archivoIn1, archivoOut1;
    string archivoIn2, archivoOut2;
    cout<<"\tRECUERDE QUE TODOS LOS ARCHIVOS DEBEN LLEVAR .txt AL FINAL"<<endl;
    cout << "Ingrese el nombre del archivo a encriptar:"; cin >> archivoIn1;
    cout << "Ingrese el nombre del archivo donde guardar el encriptado:"; cin >> archivoOut1;
    encriptar2(archivoIn1, archivoOut1);

    cout << "Ingrese el nombre del archivo a desencriptar: "; cin >> archivoIn2;
    cout << "Ingrese el nombre del archivo donde guardar el desencriptado:"; cin >> archivoOut2;
    desencriptar2(archivoIn2, archivoOut2);
    // estos dos remove se usan en caso de no querer dejar registro, si se quiere verificar los archivos se comentan
//    remove("desencriptado2.txt");
//    remove(archivoOut1.c_str());
}

void encriptar2 (string archivoIn, string archivoOut) {
//	archivoIn="cadena.txt";
    string myString = lectura(archivoIn); //Cargamos cadena a convertir a binario
    strToBin(myString); //Invocamos la funcion
    string cadena = lectura("binario.txt"); //Cargamos el binario ya convertido (el cual fue escrito en el archivo prueba.txt)
    remove("binario.txt");
//	archivoOut="encriptado1.txt";
    Metodo2(cadena, archivoOut);
}

void desencriptar2 (string archivoIn, string archivoOut) {
    //archivoIn = "encriptado1.txt";
    string cadena = lectura(archivoIn);
    dMetodo2(cadena);
    cadena = lectura("desencriptado2.txt"); //Cargamos el archivo binario ya desencriptado, antes de convertirlo a string de nuevo
    cout << cadena;
    //archivoOut="Desencrip_Str.txt";
    binToStr(cadena, archivoOut);  //Invocamos la funcion que convierte de bin(str) a caracter(str)
}
