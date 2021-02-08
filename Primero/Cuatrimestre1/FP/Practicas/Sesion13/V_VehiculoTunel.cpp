

class VehiculoTunel{
private:
   string   matricula;
   Instante entrada;
   Instante salida;

   bool EsCorrectaMatricula(string matricula_vehiculo){
      return matricula_vehiculo.size() <= 8;
   }

public:
   // Si vamos a crear vectores de Vehiculos, tenemos que proporcionar
   // un constructor sin parámetros 
   VehiculoTunel(){
   }

   VehiculoTunel(string matricula_vehiculo,
                Instante entrada_vehiculo,
                Instante salida_vehiculo
                )
   {
      SetMatricula(matricula_vehiculo);
      SetInstanteEntrada(entrada_vehiculo);
      SetInstanteSalida(salida_vehiculo);
   }

   string Matricula(){
      return matricula;
   }

   Instante InstanteEntrada(){
      return entrada;
   }

   Instante InstanteSalida(){
      return salida;
   }

   void SetMatricula(string matricula_vehiculo){
      if (EsCorrectaMatricula(matricula_vehiculo))
         matricula = matricula_vehiculo;
   }

   void SetInstanteEntrada(Instante entrada_vehiculo){
      entrada = entrada_vehiculo;
   }

   void SetInstanteSalida(Instante salida_vehiculo){
      salida = salida_vehiculo;
   }
};

