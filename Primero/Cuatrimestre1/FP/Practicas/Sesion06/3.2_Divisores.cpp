// Diego Santiago Ortiz

// Divisores

#include <iostream> 
using namespace std;  
   
int main(){    
   
	const int MAX_DIVISORES = 100;
	int entero,
		 ultimo_divisor,
		 num_divisores = 0,
		 divisores[MAX_DIVISORES];

   do{
      cout << "Introduce un numero entero mayor estricto que 0: ";
      cin >> entero;
   }while(entero <= 0);

   ultimo_divisor = entero / 2;
   
   for (int i=2 ; i <= ultimo_divisor ; i++){
      if (entero % i == 0){
      	divisores[num_divisores] = i;
      	num_divisores++;
		}
   }
   
   for (int j=0 ; j < num_divisores ; j++)
   	cout << divisores[j] << " ";
}
