// Diego Santiago Ortiz

// Expresiones lógicas

a) char tipo_radar;
cin >> tipo_radar;
if (tipo_radar == 'F' && tipo_radar == 'f')
...

La expresión lógica siempre va a ser falsa ya que una misma variable
nunca va a ser igual a dos valores distintos

b) double velocidad;
cin >> velocidad;
if (velocidad > 100 && velocidad < 70)
cout << "\nVelocidad fuera del rango";

De nuevo la expresión lógica evaluada en la estructura condicional siempre
va a ser falsa ya que las condiciones propuestas para el AND son incompatibles,
ya que un número no puede ser mayor que 100 y a la vez menor que 70

c) double velocidad;
cin >> velocidad;
if (velocidad > 100 || velocidad > 110)
cout << "Velocidad excesiva";

El programa funcionaría pero el código no es del todo correcto. En realidad, no es 
necesario añadir la condición velocidad > 110, ya que si velocidad > 100, ya está contemplada
con la condición velocidad > 100
