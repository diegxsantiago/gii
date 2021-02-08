// Diego Santiago Ortiz

// Truncamiento

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	int n;
	double r, r_trunc, orden_trunc;
	
	cout << "Introduzca el numero real 'r': ";
	cin >> r;
	cout << "Introduzca el numero de cifras decimales a truncar 'n': ";
	cin >> n;
	
	orden_trunc = pow(10,n);
	
	r_trunc = r * orden_trunc;
	r_trunc = trunc(r_trunc);
	r_trunc = r_trunc / orden_trunc;
	
	cout << "El numero truncado es: " << r_trunc;
	 
}
