// Diego Santiago Ortiz

// Coronavirus

#include <iostream> 
#include <cctype>
using namespace std;  
   
int main(){    
   double bodyTemperature;
  	bool fever, difficultyBreathing, diabetes, cancer;
  	char opcion;
   
  	cout << "Detecci�n Aproximada de COVID-19\n\n\n"
        << "Introduzca la temperatura y a continuaci�n conteste S/N a las siguientes preguntas:\n\n"
        << "- �Tiene deficultades para respirar?\n"
        << "- �Es diab�tico?\n"
        << "- �Tiene alg�n tipo de c�ncer?\n\n";
        
   cin >> bodyTemperature;
  	fever = bodyTemperature >= 38;
   cin >> opcion;
  	difficultyBreathing = toupper(opcion) == 'S';
   cin >> opcion;
   diabetes = toupper(opcion) == 'S';
   cin >> opcion;
   cancer = toupper(opcion) == 'S';
   
	if (fever){
     	cout << "Cuarentena en su casa";
      	
      if (difficultyBreathing || diabetes || cancer)
     		cout << "Consulte autoridades locales";
	}else 
    	cout << "Test negativo";   
}
