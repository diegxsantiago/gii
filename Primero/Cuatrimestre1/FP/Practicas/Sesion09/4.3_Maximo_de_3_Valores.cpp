// Diego Santiago Ortiz

// Máximo de tres números

#include <iostream>
using namespace std;

// Calcula el máximo entre dos números
double Max2(double num1, double num2){
   if(num1 > num2)
      return num1;
   else
      return num2;
}

double Max3(double num1, double num2, double num3){
   return Max2(Max2(num1,num2),num3);
}

int main(){
	
	double num1,
          num2,
          num3;
	double maximo;
	
	cout << "MAXIMO DE TRES NUMEROS"
        << "\nIntroduzca 3 numeros: ";
	cin >> num1 >> num2 >> num3;
	
	maximo = Max3(num1,num2,num3);
	
	cout << "El maximo es: " << maximo;
}
