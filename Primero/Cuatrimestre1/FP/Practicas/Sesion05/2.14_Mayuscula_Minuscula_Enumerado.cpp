// Diego Santiago Ortiz

// Mayúscula a minúscula usando el tipo de dato enumerado

#include <iostream>
using namespace std;

enum class TipoLetra {mayuscula, minuscula, no_alfabetico};

int main(){
   
   char letra_convertida, letra_original;
  	const int DISTANCIA_MAY_MIN = 'a'-'A';
	TipoLetra tipo_letra;
	
   cout << "Introduzca una letra --> ";
  	cin >> letra_original;
	
	letra_convertida = letra_original;
   	
	if ((letra_original >= 'A') && (letra_original <= 'Z')){
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;
      tipo_letra = TipoLetra::mayuscula;
   }else if ((letra_original >= 'a') && (letra_original <= 'z')){
      letra_convertida = letra_original - DISTANCIA_MAY_MIN;
      tipo_letra = TipoLetra::minuscula;
	}else
    	tipo_letra = TipoLetra::no_alfabetico;
    	
   if (tipo_letra == TipoLetra::mayuscula)
    	cout << "La letra era una mayúscula. Una vez convertida es " << letra_convertida << ".";
   else if (tipo_letra == TipoLetra::minuscula)
    	cout << "La letra era minúscula. Una vez convertida es " << letra_convertida << ".";
   else if (tipo_letra == TipoLetra::no_alfabetico)
   	cout << "El carácter no era una letra.";

}
