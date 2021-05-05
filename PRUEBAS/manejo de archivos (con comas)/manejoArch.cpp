#include <iostream>
#include <fstream>
#include <string.h> //PARA QUE FUNCIONE EL strtok
#include <stdlib.h> //PARA EL atoi & atof


using namespace std;

//VARIABLES GLOBALES
int clave, opcion;
char nombre[30];
float sueldo;

//FUNCIONES PROPIAS
void addRegister (); //Agregar registro
void readRegister(); //Leer todos los registros
void searchRegister(); //Buscar un registro en especifico por clave
void deleteRegister(); //Eliminar registro especifico por clave
void editRegister(); //Editar registro especifico por clave

int main() {


    while(true) {

        cout << "\n1. Guardar" << endl;
        cout << "2. Leer" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Eliminar" << endl;
        cout << "5. Editar" << endl;
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


void addRegister () {
    ofstream Guardar;
    Guardar.open("Fichero.txt", ios::app); // app para no se sobreescriba...

    cout << "Ingrese el nombre: ";
    cin.getline(nombre,30);
    cin.getline(nombre,30);//**DUPLICADA** [Muy importante para que no pase al siguiente sin el dato]
    cout << "Ingrese clave: "; cin >> clave;
    cout << "Ingrese sueldo: "; cin >> sueldo;
    Guardar << nombre << ',' << clave << ',' << sueldo <<endl;
    Guardar.close();
}

void readRegister() {
    ifstream Leer;
    Leer.open("Fichero.txt");
    char linea[100];
    Leer.getline(linea,sizeof(linea));
    cout << endl;
    while (!Leer.eof()){

        for(int i=0;i<3;i++){
            char *puntero;
            if(i==0){//Nombre

                puntero = strtok(linea, ",");
                strcpy(nombre, puntero); //NOMBRE = PUNTERO
            }
            if(i==1){//Clave
                puntero = strtok(NULL, ",");
                clave = atoi(puntero); //atoi para convertir a entero
            }

            if(i==2){//Sueldo
                puntero = strtok(NULL, ",");
                sueldo = atof(puntero); //atof para convertir a flotante
            }
        }

        cout << "Nombre: " << nombre << endl;
        cout << "Clave: " << clave << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << endl;
        Leer.getline(linea,sizeof(linea));
    }
    Leer.close();
}

void searchRegister() {
    ifstream Leer;
    int Bclave;
    char linea[100];
    Leer.open("Fichero.txt");
    bool encontrado = false;
    Leer.getline(linea,sizeof(linea));
    cout << "Ingrese clave a buscar: "; cin >> Bclave;
    cout << endl;

    while (!Leer.eof()) {
        for(int i=0;i<3;i++){
            char *puntero;
            if(i==0){//Nombre

                puntero = strtok(linea, ",");
                strcpy(nombre, puntero); //NOMBRE = PUNTERO
            }
            if(i==1){//Clave
                puntero = strtok(NULL, ",");
                clave = atoi(puntero); //atoi para convertir a entero
            }

            if(i==2){//Sueldo
                puntero = strtok(NULL, ",");
                sueldo = atof(puntero); //atof para convertir a flotante
            }
        }

        if(clave==Bclave){
            encontrado = true;
            cout << "Nombre: " << nombre << endl;
            cout << "Clave: " << clave << endl;
            cout << "Sueldo: " << sueldo << endl;
            cout << endl;
        }
        Leer.getline(linea,sizeof(linea));
    }
    if(encontrado==false){
        cout << "\nClave no encontrada.\n\n";
    }
    Leer.close();
}

void deleteRegister() {
    ifstream Leer;
    ofstream Temp;
    Leer.open("Fichero.txt");
    Temp.open("Temp.txt");
    int Bclave;
    bool encontrado = false;
    char linea[100];
    Leer.getline(linea,sizeof(linea));
    cout << "Ingrese clave a eliminar: "; cin >> Bclave;
    while (!Leer.eof()) {

        for(int i=0;i<3;i++){
            char *puntero;
            if(i==0){//Nombre

                puntero = strtok(linea, ",");
                strcpy(nombre, puntero); //NOMBRE = PUNTERO
            }
            if(i==1){//Clave
                puntero = strtok(NULL, ",");
                clave = atoi(puntero); //atoi para convertir a entero
            }

            if(i==2){//Sueldo
                puntero = strtok(NULL, ",");
                sueldo = atof(puntero); //atof para convertir a flotante
            }
        }

        if(clave==Bclave){
            encontrado = true;
            cout << "\nNombre: " << nombre << endl;
            cout << "Clave: " << clave << endl;
            cout << "Sueldo: " << sueldo << endl;
            cout << endl;
            cout << "Eliminado...\n\n";
        }
        else{
            Temp << nombre << ',' << clave << ',' << sueldo <<endl;
        }
        Leer.getline(linea,sizeof(linea));
    }
    if(encontrado==false){
        cout << "\nClave no encontrada.\n\n";
    }
    Leer.close();
    Temp.close();
    remove("Fichero.txt"); //ELIMINAR FICHERO
    rename("Temp.txt","Fichero.txt"); //RENOMBRAMOS A TEMP -> COMO FICHERO
}

void editRegister() {
    ifstream Leer;
    ofstream Temp;
    Leer.open("Fichero.txt");
    Temp.open("Temp.txt");
    int Bclave;
    float Nsueldo;
    bool encontrado = false;
    char linea[100];
    Leer.getline(linea,sizeof(linea));
    cout << "Ingrese clave a modificar: "; cin >> Bclave;
    while (!Leer.eof()) {

        for(int i=0;i<3;i++){
            char *puntero;
            if(i==0){//Nombre

                puntero = strtok(linea, ",");
                strcpy(nombre, puntero); //NOMBRE = PUNTERO
            }
            if(i==1){//Clave
                puntero = strtok(NULL, ",");
                clave = atoi(puntero); //atoi para convertir a entero
            }

            if(i==2){//Sueldo
                puntero = strtok(NULL, ",");
                sueldo = atof(puntero); //atof para convertir a flotante
            }
        }

        if(clave==Bclave){
            encontrado = true;
            cout << "\nNombre: " << nombre << endl;
            cout << "Clave: " << clave << endl;
            cout << "Sueldo: " << sueldo << endl;
            cout << endl;
            cout << "Ingrese nuevo sueldo: "; cin >> Nsueldo;
            cout << "\nModificado...\n";
            Temp << nombre << ',' << clave << ',' << Nsueldo <<endl;
        }
        else{
            Temp << nombre << ',' << clave << ',' << sueldo <<endl;
        }
        Leer.getline(linea,sizeof(linea));
    }
    if(encontrado==false){
        cout << "\nClave no encontrada.\n\n";
    }
    Leer.close();
    Temp.close();
    remove("Fichero.txt"); //ELIMINAR FICHERO
    rename("Temp.txt","Fichero.txt"); //RENOMBRAMOS A TEMP -> COMO FICHERO
}

