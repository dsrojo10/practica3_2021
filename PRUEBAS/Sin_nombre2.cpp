#include <iostream>
#include <bitset>
#include <fstream>

using namespace std;

void binToStr(string); 

int main() {
  string cadena = "01000001011000100100001101100100";
  binToStr(cadena);
  
  return 0;
}

void binToStr(string cadena) {
  //ofstream archivo;
  //archivo.open("desencrip_str.txt",ios::out); //Abriendo archivo
  for (size_t i = 0; i < (cadena.size()-1); i+=8){
    string cadena1 = cadena.substr(i, 8);
    cout << char(stoi(cadena1, 0, 2));
    //archivo << char(stoi(cadena1, 0, 2));
    }
}

