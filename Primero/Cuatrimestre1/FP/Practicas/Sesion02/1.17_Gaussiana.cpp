// Diego Santiago Ortiz

// Gaussiana

#include <iostream>
#include <cmath>
using namespace std;

int main(){

	const double PI = 6 * asin(0.5);
	double mi, sigma, x, gaussiana;
	
	cout << "Introduzca MI: ";
	cin >> mi;
	cout << "Introduzca SIGMA: ";
	cin >> sigma;
	cout << "Introduzca una abcisa: ";
	cin >> x;
	
	gaussiana = exp(-0.5 * pow((x - mi) / sigma,2)) / (sigma * sqrt(2 * PI));
	
	cout << "Gaussiana: " << gaussiana;
	
}
