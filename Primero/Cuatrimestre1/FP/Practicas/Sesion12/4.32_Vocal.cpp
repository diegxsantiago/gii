// Diego Santiago Ortiz

// Vocal

   bool EsVocal(int indice);
   /* Con esa cabecera, deber�a ser un M�TODO de la clase, ya que hacer referencia a
   un elemento de secuencia de caracteres con el �ndice aportado como argumento. No podr�a 
   ser una funci�n ya que necesitar�a la referencia a una secuencia sobre la que aplicar el �ndice.
   Por otro lado, en este caso, deber�a ser un m�todo privado por desempe�ar una tarea muy espec�fica
   que sirve como complementaci�n al resto de m�todos de la clase.
   */
   
   /* La llamada desde el programa principal ser�a algo as�:
   
      SecuenciaCaracteres secuencia;
      int i;
      bool es_vocal = EsVocal(i);
   */
   
   
   bool EsVocal(char caracter)
   /* Lo m�s l�gico es que, con esa cabecera, sea una FUNCI�N GLOBAL ya que
   desempe�a una funci�n muy gen�rica no vinculado a ning�n otro objeto, m�s que al propio char
   pasado como argumento.
   */
   
   /* La llamada desde el programa principal ser�a algo as�:
   
      char a;
      bool es_vocal = EsVocal(a);
   */
   
