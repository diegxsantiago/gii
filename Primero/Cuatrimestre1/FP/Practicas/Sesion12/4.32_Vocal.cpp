// Diego Santiago Ortiz

// Vocal

   bool EsVocal(int indice);
   /* Con esa cabecera, debería ser un MÉTODO de la clase, ya que hacer referencia a
   un elemento de secuencia de caracteres con el índice aportado como argumento. No podría 
   ser una función ya que necesitaría la referencia a una secuencia sobre la que aplicar el índice.
   Por otro lado, en este caso, debería ser un método privado por desempeñar una tarea muy específica
   que sirve como complementación al resto de métodos de la clase.
   */
   
   /* La llamada desde el programa principal sería algo así:
   
      SecuenciaCaracteres secuencia;
      int i;
      bool es_vocal = EsVocal(i);
   */
   
   
   bool EsVocal(char caracter)
   /* Lo más lógico es que, con esa cabecera, sea una FUNCIÓN GLOBAL ya que
   desempeña una función muy genérica no vinculado a ningún otro objeto, más que al propio char
   pasado como argumento.
   */
   
   /* La llamada desde el programa principal sería algo así:
   
      char a;
      bool es_vocal = EsVocal(a);
   */
   
