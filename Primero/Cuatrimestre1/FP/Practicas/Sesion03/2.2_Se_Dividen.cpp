// Diego Santiago Ortiz

// Se dividen

#include <iostream>
using namespace std;

int main(){
	
	bool se_dividen;
	int num1, num2;
	
	cout << "Introduzca los numeros a comprobar: ";
	cin >> num1 >> num2;
	
	se_dividen = num1%num2 == 0 || num2%num1 == 0;
	
	if (se_dividen)
		cout << "Uno de ellos divide al otro";
	else
		cout << "Ninguno divide al otro";
	 
}
