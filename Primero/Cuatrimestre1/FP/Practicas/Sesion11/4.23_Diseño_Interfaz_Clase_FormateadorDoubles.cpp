// Diego Santiago Ortiz

// Diseño FormateadorDoubles

using namespace std;
#include <iostream>

double Potencia(double la_base, int el_exponente);

double Redondea(double real, int num_decim);

string EliminaUltimos(string original, char a_borrar);

string DoubleToString(double num, int cifras);

class FormateadorDoubles{
   private:
      string delimitador_izda,
             delimitador_decha;
      char separador;
      int precision;
   public:
      FormateadorDoubles();
      FormateadorDoubles(string del_izda, string del_decha, char sep, int prec);
      
      void SetDelIzda(string s);
      
      void SetDelDcha(string s);
      
      void SetPrecision(int p);
      
      void SetSeparador(char sep);
      
      string Formatea(double x);
};

int main(){
   
   string cadena;
   double num;
   FormateadorDoubles formato;
   
   cin >> num;
   cadena = formato.Formatea(num);
   
}

