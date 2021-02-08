// Diego Santiago Ortiz

// Mayor nota media

#include <iostream>
using namespace std;

int main(){

	int cod_alumno = 0,
		 mejor_alumno,
		 num_notas = 0;
	double notas,
			 media,
			 mejor_media = 0;
	
	cout << "Introduzca el codigo del alumno: ";
	cin >> cod_alumno;
	mejor_alumno = cod_alumno;
	
	while (cod_alumno != 0){
		cout << "Introduzca las notas: ";
		cin >> notas;
		
		while (notas != -1){
			num_notas ++;
			media += notas;
			cin >> notas;
		}
		
		media /= num_notas;
		
		if (media > mejor_media){
			mejor_media = media;
			mejor_alumno = cod_alumno;
		}
		
		media = 0;
		num_notas = 0;
		cin >> cod_alumno;
	};
	
	cout << "Codigo del mejor alumno: " << mejor_alumno;
	cout << "Nota media del mejor alumno: " << mejor_media; 
}
