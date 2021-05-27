#include <iostream>
#include <fstream>
#include <string>
#include <bitset> //PARA LA CONVERSION A BINARIO
//#include <string.h> //PARA QUE FUNCIONE EL strtok
//#include <stdlib.h> //PARA EL atoi & atof

using namespace std;

///////////////////////////FUNCIONES PARA CONVERTIR/////////////////////////////////////
void strToBin (string);//funcion que recibe un str y lo escribe en un archivo en binario
void binToStr(string, string);

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
void Metodo1 (string, string); //Funcion para el metodo1 de encriptacion <recibe el str a encriptar> y el nombre del archivo de salida
void dMetodo1 (string); //Funcion para desencriptar metodo1 <recibe el str a desencriptar>

void encriptar1(string, string); //recibe archivo de entrada y de salida.  con .txt
void desencriptar1(string, string); //recibe archivo de entrada y de salida. con .txt

////////////////////////////////FUNCIONES METODO 2/////////////////////////////////////////
void Metodo2 (string, string); //Funcion para el metodo1 de encriptacion <recibe el str a encriptar> y el nombre del archivo de salida
void dMetodo2 (string); //Funcion para desencriptar metodo1 <recibe el str a desencriptar>

void encriptar2(string, string); //recibe archivo de entrada y de salida.  con .txt
void desencriptar2(string, string); //recibe archivo de entrada y de salida. con .txt

///////////////////FUNCIONES PROPIAS PARA VERIFICAR UN CORRECTO DESARROLLO////////////////////
void Verificacion1(); //Función para encriptar y desencriptar metodo1
void Verificacion2(); //Función para encriptar y desencriptar metodo2

///////////////////////////////////////////////////////////////////////////////////////////////

////////////////////FUNCIONES APP BANCO/////////////////////////////////////
void appBanco();

void addRegister (); //Agregar registro
void readRegister(); //Leer todos los registros
void readRegister(string archivo); //[SOBRECARGADO]
void searchRegisterAdmin(); //Buscar un registro en especifico por clave (admin)
void searchRegisterAdmin(string archivo); //[SOBRECARGADO]
void deleteRegister(); //Eliminar registro especifico por clave
void deleteRegister(string archivo); //[SOBRECARGADO]
void editRegisterAdmin(); //Editar registro especifico por clave
void editRegisterAdmin(string archivo); //[SOBRECARGADO]

void searchRegisterUser(); //Buscar un registro en especifico por cedula y clave (usuario)
void searchRegisterUser(string archivo); //[SOBRECARGADO]
void editRegisterUser(); //Editar registro especifico por cedula y clave
void editRegisterUser(string archivo); // [SOBRECARGADO]
void editPasswordUser(); //Editar clave de registro en especifico por cedula y clave


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
        //desencriptacion1("sudo.txt","verificacion.txt");
        break;
    }

    case 2: {
        Verificacion2();
        break;
    }

    case 3: {

        appBanco();

        }
        break;
    }

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
void Metodo1 (string cadena, string archOut){
    int n;
    cout << "Ingrese el numero para las particiones: "; cin >> n;
    cout << cadena << endl;
    ofstream archivo;
    archivo.open(archOut.c_str(),ios::out); //Creamos archivo para guardar la encriptación

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

////////////FUNCIONES METODO 2 (ENCRIPTADO Y DESENCRIPTADO)/////////
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


/////////FUNCIONES QUE USO PARA VERIFICAR UN CORRECTO DESARROLLO////
void Verificacion1() {
    string archivoIn, archivoOut;
    cout << "Ingrese el nombre del archivo a encriptar:"; cin >> archivoIn;
    cout << "Ingrese el nombre del archivo donde guardar el encriptado:"; cin >> archivoOut;
    encriptar1(archivoIn, archivoOut);

    cout << "Ingrese el nombre del archivo a desencriptar: "; cin >> archivoIn;
    cout << "Ingrese el nombre del archivo donde guardar el desencriptado:"; cin >> archivoOut;
    desencriptar1(archivoIn, archivoOut);
}

void encriptar1 (string archivoIn, string archivoOut) {
//	archivoIn="cadena.txt";
    string myString = lectura(archivoIn); //Cargamos cadena a convertir a binario
    strToBin(myString); //Invocamos la funcion
    string cadena = lectura("binario.txt"); //Cargamos el binario ya convertido (el cual fue escrito en el archivo prueba.txt)
    remove("binario.txt");
//	archivoOut="encriptado1.txt";
    Metodo1(cadena, archivoOut);
}

void desencriptar1 (string archivoIn, string archivoOut) {
    //archivoIn = "encriptado1.txt";
    string cadena = lectura(archivoIn);
    dMetodo1(cadena);
    cadena = lectura("desencriptado1.txt"); //Cargamos el archivo binario ya desencriptado, antes de convertirlo a string de nuevo
    cout << cadena;
    //archivoOut="Desencrip_Str.txt";
    binToStr(cadena, archivoOut);  //Invocamos la funcion que convierte de bin(str) a caracter(str)
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

//////////////////FUNCIONES APP BANCO////////////////////////

void appBanco(){
    int opcion2;
    cout << "1. Ingresar como admin (debe tener clave)" << endl;
    cout << "2. Ingresar como usuario (debe estar registrado)" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: "; cin >> opcion2;

    switch (opcion2) {

    case 1:{
    string password;
    cout << "Ingrese su clave: "; cin>>password;
    cout << "Las particiones deben ser 5..." << endl;
    desencriptar1("sudo.txt","odus.txt"); //odus es sudo al reves, archivo temp donde guardo el mensaje desencriptado
    string cadena = lectura("odus.txt");
    remove("odus.txt"); //ELIMINAR FICHERO
    bool flag = true;
    for(int i=0;i<int(cadena.size()-1);i++){
        if(cadena[i]!=password[i]){
            flag = false;
        }
    }
    if(flag==true){
        while(true) {
            cout << "\n1. Registrar Usuario" << endl;
            cout << "\n2. Mostrar Usuarios" << endl;
            cout << "\n3. Buscar Usuario" << endl;
            cout << "\n4. Eliminar Usuario" << endl;
            cout << "\n5. Editar Usuario" << endl;
            cout << "Ingrese opcion: ";
            cin >> opcion;

            switch(opcion) {
            case 1:{
                int flag = 0;
                do{
                    addRegister();
                    cout << "Desea agregar otro usuario?" << endl;
                    cout << "0. SI         1. NO\n"; cin >> flag;
                }
                while(flag==0);
                ofstream Temp;
                Temp.open("Temp.txt");
                encriptar1("FicheroBanco.txt", "Temp.txt");
                Temp.close();
                remove("FicheroBanco.txt"); //ELIMINAR FICHERO
                rename("Temp.txt","FicheroBanco.txt"); //RENOMBRAMOS A TEMP -> COMO FICHERO
                break;
            }

            case 2:{
                ofstream Temp;
                Temp.open("Temp.txt");
                desencriptar1("FicheroBanco.txt", "Temp.txt");
                readRegister("Temp.txt");
                break;
            }

            case 3:{
                ofstream Temp;
                Temp.open("Temp.txt");
                desencriptar1("FicheroBanco.txt", "Temp.txt");
                searchRegisterAdmin("Temp.txt");
                remove("FicheroBanco.txt");
                encriptar1("Temp.txt","FicheroBanco.txt");
                break;
            }

            case 4:{
                ofstream Temp;
                Temp.open("Temp.txt");
                desencriptar1("FicheroBanco.txt", "Temp.txt");
                deleteRegister("Temp.txt");
                encriptar1("Temporal.txt","FicheroBanco.txt");
                remove("Temp.txt");
                remove("Temporal.txt");
                break;
            }

            case 5:
                ofstream Temp;
                Temp.open("Temp.txt");
                desencriptar1("FicheroBanco.txt", "Temp.txt");
                editRegisterAdmin("Temp.txt");
                encriptar1("Temporal.txt","FicheroBanco.txt");
                remove("Temp.txt");
                remove("Temporal.txt");
                break;
            }
            remove("Temp.txt"); //Borramos el desencriptado para que no quede registro.
        }
    }
    else if(flag==false){
        cout << "\nCLAVE INVALIDA\n...";
    }

    break;
    }

    case 2:{
        int opcion2;
        cout << "\n1. Consultar saldo\n";
        cout << "\n2. Retirar\n";
        cout << "\n3. Cambiar clave\n";
        cout << "\nSeleccione una opcion:"; cin >> opcion2;

        switch (opcion2) {

        case 1:{
            ofstream Temp;
            Temp.open("Temp.txt");
            desencriptar1("FicheroBanco.txt", "Temp.txt");
            searchRegisterUser("Temp.txt");
            encriptar1("Temporal.txt","FicheroBanco.txt");
            remove("Temp.txt");
            remove("Temporal.txt");
            break;
        }

        case 2:{
            ofstream Temp;
            Temp.open("Temp.txt");
            desencriptar1("FicheroBanco.txt", "Temp.txt");
            editRegisterUser("Temp.txt");
            encriptar1("Temporal.txt","FicheroBanco.txt");
            remove("Temp.txt");
            remove("Temporal.txt");
            break;
        }
        case 3:
            editPasswordUser();
            break;

        }
        break;
    }
    }
}

void addRegister () { //Añadir registro (admin)
    ofstream Guardar;
    Guardar.open("FicheroBanco.txt", ios::app); // app para no se sobreescriba...
    cout << "Ingrese cedula: "; cin >> cedula;
    cout << "Ingrese clave: "; cin >> clave;
    cout << "Ingrese saldo: "; cin >> saldo;
    Guardar << cedula << ' ' << clave << ' ' << saldo <<endl;
    Guardar.close();
}

void readRegister() { //Leer registros (admin)
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

void readRegister(string archivo) { //Leer registros (admin) [SOBRECARGADO]
    ifstream Leer;
    Leer.open(archivo.c_str());
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
    //remove(archivo.c_str());
}

void searchRegisterAdmin() { //Buscar registro (admin)
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

void searchRegisterAdmin(string archivo) { //Buscar registro (admin)
    ifstream Leer;
        int Bcedula;
        Leer.open(archivo.c_str());
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

void deleteRegister() { //Borrar registro (admin)
    ifstream Leer;
    ofstream Temp;
    Leer.open("FicheroBanco.txt");
    Temp.open("Temporal.txt");
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
    rename("Temporal.txt","FicheroBanco.txt"); //RENOMBRAMOS A TEMP -> COMO FICHERO
}

void deleteRegister(string archivo) { //Borrar registro (admin) [SOBRECARGADO]
    ifstream Leer;
    ofstream Temp;
    Leer.open(archivo.c_str());
    Temp.open("Temporal.txt");
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
    remove(archivo.c_str()); //ELIMINAR FICHERO
    rename("Temporal.txt",archivo.c_str()); //RENOMBRAMOS A TEMP -> COMO FICHERO
}

void editRegisterAdmin() { //Editar registro (admin)
    ifstream Leer;
    ofstream Temp;
    Leer.open("FicheroBanco.txt");
    Temp.open("Temporal.txt");
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
    rename("Temporal.txt","FicheroBanco.txt"); //RENOMBRAMOS A TEMP -> COMO FICHERO
}

void editRegisterAdmin(string archivo) { //Editar registro (admin) [SOBRECARGADO]
    ifstream Leer;
    ofstream Temp;
    Leer.open(archivo);
    Temp.open("Temporal.txt");
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
}

void searchRegisterUser() { //Buscar registro (usuario) cobro 1000 pesos
    ifstream Leer;
    ofstream Temp;
    Leer.open("FicheroBanco.txt");
    Temp.open("Temporal.txt");
    int Bcedula, Bclave;
    bool encontrado = false;
    Leer >> cedula;
    cout << "Ingrese cedula: "; cin >> Bcedula;
    while (!Leer.eof()) {
        Leer >> clave >> saldo;
        if(cedula==Bcedula){
            cout << "Ingrese su clave: "; cin >> Bclave;
            encontrado = false;
            if(clave==Bclave){
                encontrado = true;
                cout << "\nCedula: " << cedula << endl;
                cout << "Clave: " << clave << endl;
                cout << "Saldo: " << saldo << endl;
                cout << endl;
                Temp << cedula << ' ' << clave << ' ' << saldo - 1000 <<endl;


            }
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
    rename("Temporal.txt","FicheroBanco.txt"); //RENOMBRAMOS A TEMP -> COMO FICHERO
}

void searchRegisterUser(string archivo) { //[SOBRECARGADO]
    ifstream Leer;
    ofstream Temp;
    Leer.open(archivo.c_str());
    Temp.open("Temporal.txt");
    int Bcedula, Bclave;
    bool encontrado = false;
    Leer >> cedula;
    cout << "Ingrese cedula: "; cin >> Bcedula;
    while (!Leer.eof()) {
        Leer >> clave >> saldo;
        if(cedula==Bcedula){
            cout << "Ingrese su clave: "; cin >> Bclave;
            encontrado = false;
            if(clave==Bclave){
                encontrado = true;
                cout << "\nCedula: " << cedula << endl;
                cout << "Clave: " << clave << endl;
                cout << "Saldo: " << saldo << endl;
                cout << endl;
                Temp << cedula << ' ' << clave << ' ' << saldo - 1000 <<endl;


            }
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
}

void editRegisterUser() {//Editar registro especifico por cedula y clave
    ifstream Leer;
    ofstream Temp;
    Leer.open("FicheroBanco.txt");
    Temp.open("Temporal.txt");
    int Bcedula, Bclave;
    float Nsaldo;
    bool encontrado = false;
    Leer >> cedula;
    cout << "Ingrese cedula: "; cin >> Bcedula;
    while (!Leer.eof()) {
        Leer >> clave >> saldo;
        if(cedula==Bcedula){
            cout << "Ingrese su clave: "; cin >> Bclave;
            encontrado = false;
            if(clave==Bclave){
                encontrado = true;
                cout << "\nCedula: " << cedula << endl;
                cout << "Clave: " << clave << endl;
                cout << "Saldo: " << saldo << endl;
                cout << endl;
                cout << "Cuanto desea retirar: "; cin >> Nsaldo;
                if(Nsaldo<saldo){ //Verificar que el saldo sea suficiente
                    Temp << cedula << ' ' << clave << ' ' << saldo - Nsaldo <<endl;
                    cout << "\nEntregando dinero...\n";
                    cout << "\nSaldo disponible despues de transaccion: " << saldo - Nsaldo - 1000 << endl;

                }
                else if(Nsaldo>saldo){
                    Temp << cedula << ' ' << clave << ' ' << saldo <<endl;
                    cout << "SALDO INSUFICIENTE...\n";
                }
            }
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
//    remove("FicheroBanco.txt"); //ELIMINAR FICHERO
//    rename("Temporal.txt","FicheroBanco.txt"); //RENOMBRAMOS A TEMP -> COMO FICHERO
}

void editRegisterUser(string archivo) {// [SOBRECARGADO]
    ifstream Leer;
    ofstream Temp;
    Leer.open(archivo.c_str());
    Temp.open("Temporal.txt");
    int Bcedula, Bclave;
    float Nsaldo;
    bool encontrado = false;
    Leer >> cedula;
    cout << "Ingrese cedula: "; cin >> Bcedula;
    while (!Leer.eof()) {
        Leer >> clave >> saldo;
        if(cedula==Bcedula){
            cout << "Ingrese su clave: "; cin >> Bclave;
            encontrado = false;
            if(clave==Bclave){
                encontrado = true;
                cout << "\nCedula: " << cedula << endl;
                cout << "Clave: " << clave << endl;
                cout << "Saldo: " << saldo << endl;
                cout << endl;
                cout << "Cuanto desea retirar: "; cin >> Nsaldo;
                if(Nsaldo<saldo){ //Verificar que el saldo sea suficiente
                    Temp << cedula << ' ' << clave << ' ' << saldo - Nsaldo - 1000 <<endl;
                    cout << "\nEntregando dinero...\n";
                    cout << "\nSaldo disponible despues de transaccion: " << saldo - Nsaldo - 1000 << endl;

                }
                else if(Nsaldo>saldo){
                    Temp << cedula << ' ' << clave << ' ' << saldo <<endl;
                    cout << "SALDO INSUFICIENTE...\n";
                }
            }
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
}

void editPasswordUser(){ //Editar clave de usuario especifico por cedula y clave
    ifstream Leer;
    ofstream Temp;
    Leer.open("FicheroBanco.txt");
    Temp.open("Temporal.txt");
    int Bcedula, Bclave, Nclave, Nclave2; //Bclave = clave a buscar... Nclave = nueva clave
    bool encontrado = false;
    Leer >> cedula;
    cout << "Ingrese cedula: "; cin >> Bcedula;
    while (!Leer.eof()) {
        Leer >> clave >> saldo;
        if(cedula==Bcedula){
            cout << "Ingrese su clave: "; cin >> Bclave;
            encontrado = false;
            if(clave==Bclave){
                encontrado = true;
                cout << "\nCedula: " << cedula << endl;
                cout << "Clave: " << clave << endl;
                cout << "Saldo: " << saldo << endl;
                cout << endl;
                cout << "Ingrese su nueva clave: "; cin >> Nclave;
                cout << "Ingrese otra vez su nueva clave: "; cin >> Nclave2;

                if(Nclave==Nclave2){ //Verificar que el saldo sea suficiente
                    Temp << cedula << ' ' << Nclave << ' ' << saldo <<endl;
                    cout << "\nLA CLAVE FUE CAMBIADA CON EXITO...\n";
                }
                else if(Nclave!=Nclave2){
                    cout << "LAS CLAVES NO COINCIDEN...\n";
                    Temp << cedula << ' ' << clave << ' ' << saldo <<endl;
                }
            }
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
    rename("Temporal.txt","FicheroBanco.txt"); //RENOMBRAMOS A TEMP -> COMO FICHERO
}
