//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Formateador de doubles

#include <cmath>
using namespace std;

/*
   Funciones:
   
      double PotenciaEntera(double base, int exponente)
      double Redondea(double real, int num_decimales)
      string EliminaUltimos(string cadena, char a_borrar)
   
   Clases:
      
      class FormateadorDoubles
      public:
         FormateadorDoubles()  // <- Por defecto ser� con "" a izda y dcha, con punto como separador decimal y con 2 cifras decimales
         FormateadorDoubles(string delimitador_izda,
                            string delimitador_dcha,
                            int num_decimales_a_mantener)
         void SetSeparadorPunto()
         void SetSeparadorComa()
         void SetNumeroDecimales(int num_decimales_a_mantener)
         string GetCadena(double real)
*/

/*
Esquema:
   
   Decisiones que se han tomado en el dise�o de esta soluci�n:   
   
   Se han incluido como funciones las siguientes, 
   ya que son funciones gen�ricas que trabajan
   sobre tipos de datos simples:
      
      double PotenciaEntera(...)
      double Redondea(...)
      string EliminaUltimos(...)
   
   Se ha creado la clase FormateadorDoubles atendiendo a lo siguiente:   
   
   - La clase proporciona un constructor sin par�metros por lo que:   
      =  Los separadores izda y dcha se asignar�n por defecto a ""
      =  El n�mero de decimales se asignar� por defecto a 2
      =  El separador por defecto entre la parte entera y la decimal ser� el punto
   
   - La clase tambi�n proporciona un constructor con par�metros para especificar:   
      =  Los separadores
      =  El n�mero de decimales
      
   - Una vez construido el objeto, se permitir� cambiar el separador 
     y el n�mero de decimales a trav�s de m�todos:
   
      =  Como s�lo hay dos posibilidades para especificar el separador, es mucho
         mejor usar dos m�todos:      
            void SetSeparadorComa()
            void SetSeparadorPunto()            
         que un m�todo del tipo:         
            void SetSeparador(char caracter);   // :-( �Dejamos demasiadas posibilidades!
      
      = Para cambiar el n�mero de decimales:      
            void SetNumeroDecimales(int num_decimales)
*/

double PotenciaEntera(double base, int exponente){
   //Observe que si exponente fuese cero, la variable potencia
   //se quedar�a con 1,
   //lo que es correcto ya que base elevado a 0 es siempre 1
   //
   //Y observe que este comentario va dentro de la funci�n ya que
   //es una descripci�n de la implementaci�n

	double potencia;
	int exponente_positivo;

	if (base == 0 && exponente == 0)
		potencia = NAN;				// Devuelve NAN (Indeterminaci�n)
	else{
		exponente_positivo = abs(exponente);
		potencia = 1;

		for (int i = 1; i <= exponente_positivo; i++)
			potencia = potencia * base;
	}

	if (exponente < 0)
		potencia = 1/potencia;

	return potencia;
}


double Redondea(double real, int num_decimales){
   double real_redondeado;
   long long potencia_10;

   potencia_10 = PotenciaEntera(10, num_decimales);
   real_redondeado = round(real * potencia_10);
   real_redondeado = real_redondeado / potencia_10;

   return real_redondeado;
}

string EliminaUltimos(string cadena, char a_borrar){
   // MUY IMPORTANTE: Las modificaciones que hagamos sobre cadena NO afectan
   // al par�metro actual.

   while (! cadena.empty() && cadena.back() == a_borrar)
      cadena.pop_back();

   /*
   Otra forma:

      int ultimo = cadena.size() - 1;

      while (ultimo >= 0 && cadena[ultimo] == a_borrar){
         cadena.erase(ultimo);
         ultimo--;
      }
   */
   return cadena;
}


class FormateadorDoubles{
private:
   enum class SeparadorDecimal {PUNTO, COMA};  // <- Podemos definir un tipo enumerado PRIVADO
   string izda    = "";  // Valor por defecto. Se puede cambiar en el constructor pero no una vez creado el objeto
   string dcha    = "";  // Valor por defecto. Se puede cambiar en el constructor pero no una vez creado el objeto
   int decimales  = 2;   // Valor por defecto. Se puede cambiar una vez creado el objeto
   SeparadorDecimal separador = SeparadorDecimal::PUNTO;   // Valor por defecto. Se puede cambiar una vez creado el objeto
   
   void SetDelimitadores(string delimitador_izda, string delimitador_dcha){
      izda = delimitador_izda;
      dcha = delimitador_dcha;
   }
   
public:
   // Constructor sin par�metros ("por defecto")
   // Usar� para los datos miembro los valores especificados arriba, es decir:
   // Delimitadores izda y dcha: "", 2 cifras decimales y el punto como separador   
   FormateadorDoubles(){      
   }   
   
   FormateadorDoubles(string delimitador_izda,
                      string delimitador_dcha)
   {
      SetDelimitadores(delimitador_izda, delimitador_dcha);
   }
   
   FormateadorDoubles(string delimitador_izda,
                      string delimitador_dcha,
                      int num_decimales_a_mantener)
      :FormateadorDoubles(delimitador_izda, delimitador_dcha)
   {
      SetNumeroDecimales(num_decimales_a_mantener);
   }
   
   void SetSeparadorPunto(){
      separador = SeparadorDecimal::PUNTO;
   }
   void SetSeparadorComa(){
      separador = SeparadorDecimal::COMA;
   }

   void SetNumeroDecimales(int num_decimales_a_mantener){
      if (num_decimales_a_mantener >= 0)
         decimales = num_decimales_a_mantener;
   }
   
   //---------------------------------------------------------------------
   // string GetCadena(double real)
   // Transforma el real en string, redonde�ndolo al n�mero de
   // cifras decimales especificado en el correspondiente dato miembro
   
   // 1.23  1  1.2
   // 1.23  2  1.23
   // 1.23  3  1.23
   // 1.23 20  1.23
   // 1.25  1  1.3
   // 1.25  2  1.25
   
   string GetCadena(double real){
   // Algoritmo:
   //    Redondear el real al n�mero de cifras decimales especificado
   //    Inicializar la cadena a to_string de la parte entera del real
   //    A�adir a la cadena un punto o una coma
   //    Transformar a string todos y cada uno de los d�gitos
   //       de la parte real. Para ello, ir rest�ndole
   //       al real su parte entera y sacar el primer
   //       d�gito truncando el resultado de multiplicarlo por 10
   //       Transformar dicho d�gito con to_string y a�adirlo a la cadena

   // Supongamos num cifras decimales = 3
   // real = 12.345 -> trunc(real) = 12
   //    -> cadena = to_string(12) + "." -> "12."
   //    -> Redondea(12.345 - 12, 3) = 0.345
   //    -> (*10) -> real = 3.45
   //    -> (trunc) -> 3 -> to_string -> "3" -> cadena = "12.3"
   // -> Volver a hacer lo mismo con real = 3.45

   // Nota. Para evitar los problemas de precisi�n usamos la funci�n Redondea.
   // 1.23 - 1 da como resultado 0.22999999999999998
   // Redondea(1.23 - 1, decimales >= 2) da como resultado 1.23

   // Si se especifican m�s d�gitos de los que hay, el string
   // resultante contendr� ceros a la derecha, por lo que habr� que eliminarlos
   // 1.23 (con cinco decimales): -> "1.23000" -> "1.23"

   // Hemos establecido la constante MAX_DIGITOS_PRECISION_DOUBLE a 15
   // Preferiblemente, podr�amos usar la constante DBL_DIG definida
   // en la biblioteca est�ndar <cfloat>

      const int MAX_DIGITOS_PRECISION_DOUBLE = 15;
      int parte_entera;
      int num_digitos_precision;
      string cadena_separador;
      string cadena = "";  // No es necesario. C++ inicializa los string a ""

      if (real < 0)
         cadena = "-";

      real = abs(real);
      real = Redondea(real, decimales);
      parte_entera = trunc(real);
      cadena = cadena + to_string(parte_entera);
      num_digitos_precision = cadena.size();

      if (real != parte_entera
         && decimales > 0
         && num_digitos_precision < MAX_DIGITOS_PRECISION_DOUBLE){

         if (separador == SeparadorDecimal::PUNTO)
            cadena_separador = ".";
         else
            cadena_separador = ",";

         cadena = cadena + cadena_separador;

         for (int i = 0; i < decimales && num_digitos_precision < MAX_DIGITOS_PRECISION_DOUBLE; i++){
            real = Redondea(real - parte_entera, decimales);
            real = real * 10;
            parte_entera = trunc(real);
            cadena = cadena + to_string(parte_entera);
            num_digitos_precision++;
         }

         while (cadena.back() == '0')
            cadena.pop_back();
      }

      cadena = izda + cadena + dcha;

      return cadena;
   }
};


