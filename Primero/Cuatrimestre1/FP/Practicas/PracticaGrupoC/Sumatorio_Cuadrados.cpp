#include <iostream>
#include "ClaseProgramaLPS.cpp"

using namespace std;

int main(){
   int n;
   Programa_LPS programa;
   
   do{
      cout << "Introducir entrada: ";
      cin >> n;
   }while (n <= 0);

   programa.Instruccion("INI",0,n+1,0);
   programa.Instruccion("INI",1,0,0);
   programa.Instruccion("INI",2,1,0);
   programa.Instruccion("MULT",3,2,2);
   programa.Instruccion("SUM",1,1,3);
   programa.Instruccion("INC",2,0,0);
   programa.Instruccion("IR<",2,0,3);
   programa.Instruccion("FIN",0,0,0);
   
   int error = programa.Ejecutar();
   
   if ( error == 0 )
      cout << "Sumatorio: " << programa.GetVar(1) << endl;
   else
      cout << "Programa detenido: existe error de sintaxis" << endl;
}
