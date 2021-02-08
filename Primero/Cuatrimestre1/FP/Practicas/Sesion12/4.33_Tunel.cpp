// Diego Santiago Ortiz

// Túnel

#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// Función PotenciaEntera
// Autor: Juan Carlos Cubero

double PotenciaEntera(double base, int exponente){
   //Observe que si exponente fuese cero, la variable potencia
   //se quedaría con 1,
   //lo que es correcto ya que base elevado a 0 es siempre 1
   //
   //Y observe que este comentario va dentro de la función ya que
   //es una descripción de la implementación

	double potencia;
	int exponente_positivo;

	if (base == 0 && exponente == 0)
		potencia = NAN;				// Devuelve NAN (Indeterminación)
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

// Función Redondea
// Autor: Juan Carlos Cubero

double Redondea(double real, int num_decimales){
   double real_redondeado;
   long long potencia_10;

   potencia_10 = PotenciaEntera(10, num_decimales);
   real_redondeado = round(real * potencia_10);
   real_redondeado = real_redondeado / potencia_10;

   return real_redondeado;
}

// Función EliminaUltimos
// Autor: Juan Carlos Cubero

string EliminaUltimos(string cadena, char a_borrar){
   // MUY IMPORTANTE: Las modificaciones que hagamos sobre cadena NO afectan
   // al parámetro actual.

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

// Clase FormateadorDoubles
// Autor: Juan Carlos Cubero

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
   // Constructor sin parámetros ("por defecto")
   // Usará para los datos miembro los valores especificados arriba, es decir:
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
   // Transforma el real en string, redondeándolo al número de
   // cifras decimales especificado en el correspondiente dato miembro
   
   // 1.23  1  1.2
   // 1.23  2  1.23
   // 1.23  3  1.23
   // 1.23 20  1.23
   // 1.25  1  1.3
   // 1.25  2  1.25
   
   string GetCadena(double real){
   // Algoritmo:
   //    Redondear el real al número de cifras decimales especificado
   //    Inicializar la cadena a to_string de la parte entera del real
   //    Añadir a la cadena un punto o una coma
   //    Transformar a string todos y cada uno de los dígitos
   //       de la parte real. Para ello, ir restándole
   //       al real su parte entera y sacar el primer
   //       dígito truncando el resultado de multiplicarlo por 10
   //       Transformar dicho dígito con to_string y añadirlo a la cadena

   // Supongamos num cifras decimales = 3
   // real = 12.345 -> trunc(real) = 12
   //    -> cadena = to_string(12) + "." -> "12."
   //    -> Redondea(12.345 - 12, 3) = 0.345
   //    -> (*10) -> real = 3.45
   //    -> (trunc) -> 3 -> to_string -> "3" -> cadena = "12.3"
   // -> Volver a hacer lo mismo con real = 3.45

   // Nota. Para evitar los problemas de precisión usamos la función Redondea.
   // 1.23 - 1 da como resultado 0.22999999999999998
   // Redondea(1.23 - 1, decimales >= 2) da como resultado 1.23

   // Si se especifican más dígitos de los que hay, el string
   // resultante contendrá ceros a la derecha, por lo que habrá que eliminarlos
   // 1.23 (con cinco decimales): -> "1.23000" -> "1.23"

   // Hemos establecido la constante MAX_DIGITOS_PRECISION_DOUBLE a 15
   // Preferiblemente, podríamos usar la constante DBL_DIG definida
   // en la biblioteca estándar <cfloat>

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

// Clase Instante
// Autor: Juan Carlos Cubero

class Instante{
private:    
   /*
   MUY IMPORTANTE:
      NO INCLUIMOS COMO DATO MIEMBRO NADA QUE SE PUEDA OBTENER A PARTIR
      DE LOS OTROS DATOS MIEMBRO,COMO POR EJEMPLO SEGUNDOS_TOTALES
      LO QUE HAREMOS SERÁ PROPORCIONAR UN MÉTODO QUE CALCULE SEGUNDOS_TOTALES
   */
   
   /*
   Sobre las ctes:
   
      Hemos decidido que las ctes SEG_1_MIN, MIN_1_HORA y HOR_1_DIA
      sean private ya que hemos supuesto que no se necesitan fuera de la clase.
      Pero podría darse el caso de que sí se necesitasen.
      Por ejemplo, si desde el main queremos hacer un filtro de entrada de datos para los
      minutos, por ejemplo, necesitaríamos saber el máximo (60)
      En este caso, podemos resolverlo de dos formas:
      
      a) Poner dichas ctes como ctes globales 
      
      b) Proporcionar métodos Get a la clase Instante 
         para que devuelva los valores de dichas ctes.
         El problema de esta opción es que no podríamos
         dimensionar un vector, por ejemplo, con estos valores
         ya que el valor devuelto por el método Get no sería un const.
         
      c) También se pueden poner las constantes SEG_1_MIN, MIN_1_HORA
         y HOR_1_DIA como datos miembros públicos: Sería la única excepción a la norma
         de usar siempre datos miembros privados.
         De esta forma, desde el main, si tenemos 
            Instante un_instante;
         podemos acceder a dichos datos miembros. 
         Se puede hacer de dos formas (pero siempre declarándolas como "static const"):
         
         i)  objeto.dato_miembro
            
             En nuestro ejemplo sería:
            
             instante.SEG_1_MIN
            
         ii) clase::dato_miembro
            
             En nuestro ejemplo sería:
   
             Instante::SEG_1_MIN
   */
         
   static const int  SEG_1_MIN = 60,
                     MIN_1_HORA = 60,
                     HOR_1_DIA = 24;  
   
   int hor = -1;
   int min = -1;
   int seg = -1;
   
   bool EsCorrectoSeg(int segundo){
      return 0 <= segundo && segundo < SEG_1_MIN;
   }
   bool EsCorrectoMin(int minuto){
      return 0 <= minuto && minuto < MIN_1_HORA;
   }
   bool EsCorrectoHor(int hora){
      return 0 <= hora  && hora < HOR_1_DIA;
   }
   bool EsCorrecto (int hora, int minuto, int segundo){
      return  EsCorrectoHor(hora) && 
              EsCorrectoMin(minuto) && 
              EsCorrectoSeg(segundo);
   }

public:
   // Incluimos un constructor sin parámetros para poder crear fácilmente vectores de objetos.
   // Al construir un objeto Instante llamando al constructor sin parámetros
   // éste se quedará como un "zombie". Lo identificaremos poniendo sus datos miembro
   // a -1 y proporcionando el método EsNulo()
   //    Instante un_instante;  <-  -1, -1, -1
   //    bool es_nulo = un_instante.EsNulo();   <- true
   Instante(){      
   }
   
   // Prec: las horas, minutos y segundos son correctos
   Instante(int hora, int minuto, int segundo){
      SetHoraMinutoSegundo(hora,  minuto,  segundo);
   }
   
   // Prec: los segundos son correctos
   Instante(int segundos_totales){
      SetSegundosTotales(segundos_totales);
   }

   int Hora(){
      return hor;
   }

   int Minuto(){
      return min;
   }

   int Segundo(){
      return seg;
   }

   void SetHoraMinutoSegundo(int hora, int minuto, int segundo){
      if (EsCorrecto(hora, minuto, segundo)){
         hor = hora;
         min = minuto;
         seg = segundo;
      }
   }

   void SetSegundosTotales(int segundos_totales){
      int minutos_enteros;
      const int SEG_1_DIA = SEG_1_MIN * MIN_1_HORA * HOR_1_DIA;
                                    
      if (segundos_totales < SEG_1_DIA){
         seg = segundos_totales % SEG_1_MIN;
         minutos_enteros  = segundos_totales / SEG_1_MIN;
         min  = minutos_enteros % MIN_1_HORA;
         hor  = minutos_enteros / MIN_1_HORA;
      }
   }

   void SumaleSegundos(int segundos_a_aniadir){
      if (segundos_a_aniadir > 0)
         SetSegundosTotales(
            SegundosTotales() 
            + 
            segundos_a_aniadir);       
   }
   
   void RestaleSegundos(int segundos_a_quitar){
      if (segundos_a_quitar > 0)
         SetSegundosTotales(
            SegundosTotales() 
            -
            segundos_a_quitar);
   }

   bool EsNulo(){
      return !EsCorrecto(hor, min, seg);  
   }

   int SegundosTotales(){
      return seg  +  SEG_1_MIN*(hor * MIN_1_HORA + min);
   }
   
   int MinutosTotales(){
      return trunc(MinutosTotalesDecimal());
   }

   double MinutosTotalesDecimal(){
      return 1.0 * SegundosTotales() / SEG_1_MIN;
   }

   double HorasTotalesDecimal(){
      return 1.0 * MinutosTotalesDecimal() / MIN_1_HORA;
   }

   string ToString(){
      return to_string(hor) + "h, " +
             to_string(min) + "\', " +
             to_string(seg) + "\'\'";
   }
};

// Clase Tunel
// Autor: Diego Santiago Ortiz

class Tunel{
private:
   static const int CAPACIDAD = 10000; // Caudal arbitrario máximo de vehículos
   static const int NULO = -1;
   double dist = 0;                    // Longitud del túnel
   string matriculas[CAPACIDAD];
   int entradas[CAPACIDAD],
       salidas[CAPACIDAD],
       util = 0;                       // Variable actualizable que controla en número de vehículos computados
       
   bool PosCorrecta(int posicion){
      return posicion >= 0 && posicion < CAPACIDAD;
   }
   
public:
   // Constructor con parámetros
   // Inicializa los valores de las entradas y las salidas a un valor NULO
   Tunel(double km){
      dist = km;
      for (int i=0 ; i < CAPACIDAD ; i++){
         entradas[i] = salidas[i] = NULO;
      }             
   }
   
   int GetUtilizados(){
      return util;
   }
   
   double GetDistancia(){
      return dist;
   }
   
   string GetMatricula(int posicion){
      return matriculas[posicion];
   }
   
   int GetEntrada(int posicion){
      int entrada = -1;
      
      if(PosCorrecta(posicion))
         entrada = entradas[posicion];
         
      return entrada;
   }
   
   int GetSalida(int posicion){
      int entrada = -1;
      
      if(PosCorrecta(posicion))
         return salidas[posicion];
         
      return entrada;
   }
   
   // Suponiendo que cada matrícula entra una única vez al tunel,
   // el método devuelve la posición de la primera aparición de la matrícula
   int GetPosMatricula(string matricula){
      bool encontrada = false;
      int posicion = util;
      
      for (int i=0 ; i < GetUtilizados() && !encontrada ; i++){ 
         if (matricula == GetMatricula(i)){
            posicion = i;
            encontrada = true;
         }    
      }
      
      return posicion;
   }
   
   bool Dentro(string matricula){    
      return GetEntrada(GetPosMatricula(matricula)) != NULO && GetSalida(GetPosMatricula(matricula)) == NULO;
   }
   
   void Entra(string matricula, int horas, int minutos, int segundos){
      Instante entrada(horas,minutos,segundos);
      
      if (PosCorrecta(util)){
         matriculas[util] = matricula;
         entradas[util] =  entrada.SegundosTotales();
         util++;    
      }
      
   }
   
   void Sale(string matricula, int horas, int minutos, int segundos){
      Instante salida(horas,minutos,segundos);
      
      if (Dentro(matricula)){
         matriculas[GetPosMatricula(matricula)] = matricula;
         salidas[GetPosMatricula(matricula)] =  salida.SegundosTotales();
      }
   }
   
   string VelocidadMedia(int posicion){
      const string DEL_DCHA_VELOCIDAD = " km/h";
      string velocidad = "No ha salido";
      
      if (!Dentro(GetMatricula(posicion))){
         Instante intervalo(GetSalida(posicion) - GetEntrada(posicion));
      
         FormateadorDoubles formato("",DEL_DCHA_VELOCIDAD);
         formato.SetNumeroDecimales(1);
         formato.SetSeparadorPunto();
         
         velocidad = formato.GetCadena(GetDistancia() / intervalo.HorasTotalesDecimal());
      }
        
      return velocidad;
   }

};

int main(){
   
   const char TERMINADOR = '#';
   char operacion;
   double distancia;
   string matricula;
   int horas,
       minutos,
       segundos;
   
   cin >> distancia;   
   Tunel tunel(distancia);
   
   cin >> operacion;
   
   while (operacion != TERMINADOR){
      cin >> matricula >> horas >> minutos >> segundos;
      
      if (operacion == 'E')
         tunel.Entra(matricula,horas,minutos,segundos);
      else if (operacion == 'S')
         tunel.Sale(matricula,horas,minutos,segundos);
         
      cin >> operacion;
   }
   
   
   for (int i=0 ; i < tunel.GetUtilizados() ; i++){
      
      cout << "\nMatrícula:\t" << tunel.GetMatricula(i)
           << "\nVelocidad:\t" << tunel.VelocidadMedia(i)
           << "\n";
   }
   
}
