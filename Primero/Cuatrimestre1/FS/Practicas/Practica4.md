# Práctica 4

1, 3, 4, 5, 9, 10, 12, 13, 14 y 16

__*Ejercicio 1*__

Utilizando una variable que contenga el valor entero 365 y otra que guarde el número del día actual
del año en curso, realice la misma operación del ejemplo anterior usando cada una de las diversas
formas de cálculo comentadas hasta el momento, es decir, utilizando `expr`, `$(( ... ))` y `$[ ... ]`.

```
$ declare DIAS=365; D_ACTUAL=`date +%j`
$ echo “Faltan $(( (DIAS - D_ACTUAL) / 7 )) semanas hasta el fin de año”
“Faltan 8 semanas hasta el fin de año”
$ echo “Faltan $[ (DIAS - D_ACTUAL) / 7 ] semanas hasta el fin de año”
“Faltan 8 semanas hasta el fin de año”
```

***

__*Ejercicio 3*__

Utilizando el operador de división, ponga un caso concreto donde se aprecie que la asignación
abreviada es equivalente a la asignación completa, es decir, que x/=y equivale a x=x/y.

```
$ x=20
$ y=5
$ echo $[x/y]
4
$ echo $[x=x/y]
4
$ x=20
$ y=5
$ echo $[x/=y]
4
```

***

__*Ejercicio 4*__


Compruebe qué ocurre si en el ejemplo anterior utiliza comillas dobles o simples para acotar todo lo que sigue a la orden `echo`. ¿Qué sucede si se acota entre comillas dobles solamente la expresión aritmética que se quiere calcular?, ¿y si se usan comillas simples?

```
$ echo 6/5|bc -l
1.20000000000000000000
$ echo "6/5|bc -l"
6/5|bc -l
$ echo '6/5|bc -l'
6/5|bc -l
$ echo "6/5"|bc -l
1.20000000000000000000
$ echo '6/5'|bc -l
1.20000000000000000000
```

***

__*Ejercicio 5*__
Calcule con decimales el resultado de la expresión aritmética `(3-2)/5`. Escriba todas las
expresiones que haya probado hasta dar con una respuesta válida. Utilizando una solución válida, compruebe qué sucede cuando la expresión aritmética se acota entre comillas dobles; ¿qué ocurre si se usan comillas simples?, ¿y si se ponen apóstrofos inversos?

```
$ echo $[(3-2)/5]
0
$ echo $[(3-2)/5|bc -l]
0
$ echo $[(3-2)/5]|bc -l
0
$ echo $[(3-2)]/5|bc -l
.20000000000000000000
$ echo “$[(3-2)]/5”|bc -l
.20000000000000000000
$ echo '$[(3-2)]/5'|bc -l
(standard_in) 1: illegal character: $
(standard_in) 1: syntax error
(standard_in) 1: syntax error
$ echo `$[(3-2)]/5`|bc -l
bash: 1/5: No existe el archivo o el directorio
```

***

__*Ejercicio 9*__

Haciendo uso de las órdenes conocidas hasta el momento, construya un guion que admita dos
parámetros, que compare por separado si el primer parámetro que se le pasa es igual al segundo, o es menor, o es
mayor, y que informe tanto del valor de cada uno de los parámetros como del resultado de cada una de las
evaluaciones mostrando un 0 o un 1 según corresponda

```shell
#!/bin/bash

echo "Primer numero:" $1;
echo "Segundo numero:" $2;

echo "El primero número es menor que el segundo:" $(( $1<$2 ));
echo "El primero número es mayor que el segundo:" $(( $1>$2 ));
echo "Los números son iguales:" $(( $1==$2 ));
```

***

__*Ejercicio 10*__

Usando `test`, construya un guion que admita como parámetro un nombre de archivo y realice las
siguientes acciones: asignar a una variable el resultado de comprobar si el archivo dado como parámetro es plano
y tiene permiso de ejecución sobre él; asignar a otra variable el resultado de comprobar si el archivo es un enlace
simbólico; mostrar el valor de las dos variables anteriores con un mensaje que aclare su significado. Pruebe el
guion ejecutándolo con `/bin/cat` y también con `/bin/rnano`.

```shell
#!/bin/bash

plano_ejecutable=`test -f $1 && test -x $1 && echo "El archivo es plano y ejecutable" || echo "El archivo no es plano y ejecutable"`; 

simbolico=`(test -h $1) && echo "El archivo es simbólico" || echo "El archivo no es simbólico"`;

echo $plano_ejecutable;
echo $simbolico;
```

__*Ejercicio 12*__

Responda a los siguientes apartados:

*a) Razone qué hace la siguiente orden:*
```
if test -f ./sesion5.pdf ; then 
    printf “El archivo ./sesion5.pdf existe\n”;
fi
```

> Comprueba que existe un archivo llamado `sesion5.pdf` en el directorio actual y que es __plano__.
En ese caso, imprime un mensaje diciendo que, efectivamente, existe.

*b) Añada los cambios necesarios en la orden anterior para que también muestre
un mensaje de aviso en caso de no existir el archivo.
(Recuerde que, para escribir de forma legible una orden que ocupe más de una línea,
puede utilizar el carácter “\” como final de cada línea que no sea la última.)*
```
if test -f ./sesion5.pdf ; then
    printf “El archivo ./sesion5.pdf existe\n”;
else
    printf “El archivo ./sesion5.pdf no existe\n”;
fi
```

*c) Sobre la solución anterior, añada un bloque elif para que, cuando no exista el archivo ./sesion5.pdf,
compruebe si el archivo /bin es un directorio. Ponga los mensajes adecuados para conocer el resultado en cada caso posible.*

```
if test -f ./sesion5.pdf ; then
    printf “El archivo ./sesion5.pdf existe\n”;
elif test -d /bin ; then 
    printf “/bin es un directorio”; 
else 
    printf “El archivo ./sesion5.pdf no existe\n”; 
fi
```

*d) Usando como base la solución del apartado anterior, construya un guion que sea capaz de hacer lo mismo
pero admitiendo como parámetros la ruta relativa del primer archivo a buscar y la ruta absoluta del
segundo. Pruébelo con los dos archivos del apartado anterior.*

```shell
#!/bin/bash

if test -f $1 ; then
	printf “El archivo $1 existe\n”;
elif test -d $2 ; then
	printf “El archivo $1 no existe y $2 es un directorio”; 
else 
	printf “El archivo $1 no existe\n”; fi;
```

***

__*Ejercicio 13*__

Construya un guion que admita como argumento el nombre de un archivo o directorio y que
permita saber si somos el propietario del archivo y si tenemos permiso de lectura sobre él.

```shell
#!/bin/bash

if test -o $1; then
	printf "Somos el propietario del archivo";
else
	printf "No somos el propietario del archivo";
	
if test -r $1; then
	printf "Tenemos permiso de lectura sobre el archivo";
else
	printf "No tenemos permiso de lectura sobre el archivo";
```

***

__*Ejercicio 14*__

Escriba un guion que calcule si el número de días que faltan hasta fin de año es múltiplo de cinco
o no, y que comunique el resultado de la evaluación. Modifique el guion anterior para que admita la opción `-h` de
manera que, al ejecutarlo con esa opción, muestre información de para qué sirve el guion y cómo debe ejecutarse.

```shell
#!/bin/bash

if [ "$1" == "-h" ]; then
	echo "El programa comprueba si el número de días restantes para el final de año es múltiplo de 5 o no";
else
	if test $(( $(( 365 - $(date +%j) )) % 5 )) == 0; then
		echo "Es múltiplo";
	else
		echo "No es múltiplo";
	fi;
fi;
```

***

__*Ejercicio 16*__

Haciendo uso del mecanismo de cauces y de la orden `echo`, construya un guion que admita un
argumento y que informe si el argumento dado es una única letra, en mayúsculas o en minúsculas, o es algo
distinto de una única letra.

```shell
#!/bin/bash

if test `echo $1 | grep "[a-Z]"`; then
	echo "Es una letra";
else
	echo "Es algo distinto a una letra";
fi;
```
