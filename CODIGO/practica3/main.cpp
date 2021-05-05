#include <iostream>
#include <fstream>
#include <string>
#include <bitset> //PARA LA CONVERSION A BINARIO
#include <string.h> //PARA QUE FUNCIONE EL strtok
#include <stdlib.h> //PARA EL atoi & atof

using namespace std;

///////////////////////////FUNCIONES PARA CONVERTIR/////////////////////////////////////
void strToBin (string);//funcion que recibe un str y lo escribe en un archivo en binario
void binToStr(string);

//////////////////////////FUNCIONES MANEJO DE ARCHIVOS/////////////////////////////////////
string lectura(string); //funcion que recibe el nombre del archivo y carga en un string todo lo que hay

/////////////////////////FUNCIONES PARA INVERTIR Y CONTAR 0's & 1's//////////////////////////////////
/*Las funciones para invertir reciben dos canedas iguales, ya que el algorimo necesita tener una copia,
 * ya que esa es la que modifica*/
int contarCeros(string);
int contarUnos(string);
string invAll(string,string&); //Funcion que recibe la cadena a invertir <recibe la cadena y su copia>
string inv2(string,string&); //Funcion que inverte cada 2 bits <recibe la cadena y su copia>
string inv3(string,string&); //funcion que invierte cada 3 bits <recibe la cadena y su copia>

////////////////////////////////FUNCIONES METODO 1/////////////////////////////////////////
void Metodo1 (string); //Funcion para el metodo1 de encriptacion <recibe el str a encriptar>
void dMetodo1 (string); //Funcion para desencriptar metodo1 <recibe el str a desencriptar>

void encriptacion1(string, string); //Funcion para encriptar recibe el nombre del archivo <nombrecadena.txt>
void desencriptacion1(string, string); //Funcion para desencriptar recibe nombres de archivos de entrada y salida

///////////////////FUNCIONES PROPIAS PARA VERIFICAR UN CORRECTO DESARROLLO////////////////////
void Verificacion1(); //Función para encriptar y desencriptar metodo1 recibe <nombrecadena.txt>

///////////////////////////////////////////////////////////////////////////////////////////////

////////////////////FUNCIONES APP BANCO/////////////////////////////////////
void addRegister (); //Agregar registro
void readRegister(); //Leer todos los registros
void searchRegister(); //Buscar un registro en especifico por clave
void deleteRegister(); //Eliminar registro especifico por clave
void editRegister(); //Editar registro especifico por clave



////////////VARIABLES GLOBALES (PARA LA APP)///////////////////////////////
int cedula, clave, opcion;
float saldo;

///////////////// INICIO DEL MAIN //////////////////////////////////////

int main(){

    int opcion;
    cout << "1. Metodo 1" << endl;
    cout << "2. Metodo 2" << endl;
    cout << "3. Cajero" << endl;
    cout << "Seleccione una opcion: ";cin >> opcion;
    switch (opcion) {

    case 1: {
        Verificacion1();
        break;
    }

    case 2: {
        break;
    }

    case 3: {
        while(true) {

                cout << "\n1. Registrar Usuario" << endl;
                cout << "2. Mostrar Usuarios" << endl;
                cout << "3. Buscar Usuario" << endl;
                cout << "4. Eliminar Usuario" << endl;
                cout << "5. Editar Usuario" << endl;
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
        break;
    }

    return 0;
}

//////////////FUNCIONES PARA CONVERTIR/////////////////////////
void strToBin (string cadena){
  ofstream archivo;
  archivo.open("bin.txt",ios::out); //Abriendo archivo
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


///////////FUNCIONES PARA INVERTIR Y CONTAR 0&1's////////////////
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

////////////FUNCIONES METODO 1 (ENCRIPTADO Y DESENCRIPTADO)/////////
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

/////////FUNCIONES QUE USO PARA VERIFICAR UN CORRECTO DESARROLLO////
void Verificacion1() {
    string archivoIn, archivoOut;
    cout << "Ingrese el nombre del archivo a convertir: "; cin >> archivoIn;//cadena.txt

    encriptacion1(archivoIn, "encriptado1.txt");

    cout << "Ingrese el nombre del archivo encriptado: "; cin >> archivoIn; //encriptado1.txt
    cout << "Ingrese el nombre donde guardar el desencriptado: "; cin >> archivoOut; //desencriptado1.txt

    desencriptacion1(archivoIn, archivoOut);
}

void encriptacion1(string Narchivo, string Narchivo2) {
    string myString = lectura(Narchivo); //Cargamos cadena a convertir a binario
    strToBin(myString); //Invocamos la funcion
    string cadena = lectura("bin.txt"); //Cargamos el binario ya convertido (el cual fue escrito en el archivo prueba.txt)
    Metodo1(cadena);
    cadena = lectura(Narchivo2); //encriptado.txt
}

void desencriptacion1(string Narchivo, string Narchivo2) {
    string cadena = lectura(Narchivo);
    dMetodo1(cadena);
    cadena = lectura(Narchivo2); //Cargamos el archivo binario ya desencriptado, antes de convertirlo a string de nuevo
    cout << cadena;
    binToStr(cadena);  //Invocamos la funcion que convierte de bin(str) a caracter(str)
}



//////////////////FUNCIONES APP BANCO////////////////////////
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
