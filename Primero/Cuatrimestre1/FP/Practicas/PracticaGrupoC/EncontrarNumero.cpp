#include <iostream>
#include "ClaseProgramaLPS.cpp"
using namespace std;

int main(){
   int n;
   Programa_LPS programa;
   bool encontrado;
   
   for(int i=1; i<=5; i++){
      cout << "Introducir numero: ";
      cin >> n;
      programa.SetVar(i,n);
   }
 
   cout << "Introducir numero a buscar: ";
   cin >> n;
   
   programa.Instruccion("INI",6,n,0);
   programa.Instruccion("INI",7,0,0);
   programa.Instruccion("INI",8,0,0);
   programa.Instruccion("INI",9,5,0);
   programa.Instruccion("INC",8,0,0);
   programa.Instruccion("IR<",9,8,10);
   programa.Instruccion("IND",7,8,0);
   programa.Instruccion("IR=",6,7,9);
   programa.Instruccion("IR",4,0,0);
   programa.Instruccion("FIN",0,0,7);
   programa.Instruccion("EXIT",0,0,0);
   
   if (programa.Ejecutar() == 0)
	   cout << "El numero esta en la lista.";
	else   
	   cout << "El numero no aparece en la lista.";
}

  
