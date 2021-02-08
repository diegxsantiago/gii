# Práctica 5

1, 2, 3, 4, 5 y 9

__*Ejercicio1*__

Escriba un guion que acepte dos argumentos. El primero será el nombre de un directorio y el
segundo será un valor entero. El funcionamiento del guion será el siguiente: deberán anotarse en un archivo
denominado `archivosSizN.txt` aquellos archivos del directorio dado como argumento y que cumplan la
condición de tener un tamaño menor al valor aportado en el segundo argumento. Se deben tener en cuenta las
comprobaciones sobre los argumentos, es decir, debe haber dos argumentos, el primero deberá ser un directorio
existente y el segundo un valor entero.

```shell
#!/bin/bash

es_directorio=`test -d $1 && echo true || echo false`
es_entero=`echo $2 | grep -q "[0-9]\+" && echo true || echo false`

echo $es_directorio
echo $es_numero

if [ $# = 2 ]; then
	if [ $es_directorio == "true" ] && [ $es_entero == "true" ]; then
		find $1 -size -$2 > archivosSizN.txt;
	else
		echo "Parámetros en formato incorrecto"
	fi
else
	echo "Número incorrecto de parámetros.";
	echo "Número de parámetros esperados: 2";
fi
```

***

__*Ejercicio2*__

Escriba un guion que acepte el nombre de un directorio como argumento y muestre como resultado
el nombre de todos y cada uno de los archivos del mismo y una leyenda que diga __"Directorio"__, __"Enlace"__ o __"Archivo
regular"__, según corresponda. Incluya la comprobación necesaria sobre el argumento, es decir, determine si el
nombre aportado se trata de un directorio existente.

```shell
#!/bin/bash

es_directorio=`test -d $1 && echo true || echo false`

if [ $# -eq 1 ] ; then
	if [ $es_directorio == "true" ] ; then
		for i in `ls $1`
		do
			es_sub=`test -d $i && echo true || echo false`
			es_archivo=`test -f $i && echo true || echo false`
			es_enlace=`test -h $i && echo true || echo false`
			
			if [ $es_enlace == "true" ] ; then
				echo "Enlace : $i"
			elif [ $es_archivo == "true" ] ; then
				echo "Archivo regular : $i"
			elif [ $es_sub == "true" ] ; then
				echo "Directorio : $i"
			fi
		done
	else
		echo "No existe el directorio"
else
	echo "Número incorrecto de argumentos."
	echo "Número de argumentos esperados: 1"
fi
```

***

__*Ejercicio 3*__

Ejercicio 5.3. Escriba un guion en el que, a partir de la pulsación de una tecla, detecte la zona del teclado donde
se encuentre. Las zonas vendrán determinadas por las filas. La fila de los números `1, 2, 3, 4, ...` será la fila
1, las teclas donde se encuentra la `Q, W, E, R, T, Y, ...` serán de la fila 2, las teclas de la `A, S, D,
F, ...` serán de la fila 3 y las teclas de la `Z, X, C, V, ...` serán de la fila 4. La captura de la tecla se
realizará mediante la orden `read`.

```shell
#!/bin/bash

printf "Presione una tecla\n"
read tecla

case $tecla in
	º | 0-9 | \' | ¡) echo "Primera fila" ;;
	q | w | e | r | t | y | u | i | o | p | \` | + | ç ) echo "Segunda fila" ;;
	a | s | d | f | g | h | j | k | l | ñ | \ ́) echo "Tercera fila" ;;
	\< | z | x | c | v | b | n | m | , | . | -) echo "Cuarta fila" ;;
	*) echo "Otra línea" ;;
esac
```

__*Ejercicio 4*__

Escriba un guion que acepte como argumento un parámetro en el que el usuario indica el mes que
quiere ver, ya sea en formato numérico o usando las tres primeras letras del nombre del mes, y muestre el nombre
completo del mes introducido. Si el número no está comprendido entre 1 y 12 o las letras no son significativas del
nombre de un mes, el guion deberá mostrar el correspondiente mensaje de error.

```shell
#!/bin/bash

printf "Elija un mes\n"
read mes

case $mes in
	1 | Ene | ene) echo "Enero" ;;
	2 | Feb | feb) echo "Febrero" ;;
	3 | Mar | mar) echo "Marzo" ;;
	4 | Abr | abr) echo "Abril" ;;
	5 | May | may) echo "Mayo" ;;
	6 | Jun | jun) echo "Junio" ;;
	7 | Jul | jul) echo "Julio" ;;
	8 | Ago | ago) echo "Agosto" ;;
	9 | Sep | sep) echo "Septiembre" ;;
	10 | Oct | oct) echo "Octubre" ;;
	11 | Nov | nov) echo "Noviembre" ;;
	12 | Dic | dic) echo "Diciembre" ;;
	*) echo "Mes no válido" ;;
esac
```

***

__*Ejercicio 5*__

Escriba un guion que solicite un número hasta que su valor esté comprendido entre 1 y 10. Deberá
usar la orden `while` y, para la captura del número, la orden `read`.

```shell
#!/bin/bash

printf "Introduzca un número del 1 al 9\n"
read num
es_num=`test $num -gt 0 -a $num -lt 13 && echo true || echo false`;

while [ $es_num == "false" ]
do
	printf "Introduzca un número del 1 al 9\n"
	read num
	es_num=`test $num -gt 0 -a $num -lt 13 && echo true || echo false`;
done

echo "Correcto"
```

***

__*Ejercicio 9*__

Hacer un script en Bash denominado `newdirfiles` con los siguientes tres argumentos:

- `<dirname>` Nombre del directorio que, en caso de no existir, se debe crear para alojar en él los archivos
que se han de crear.

- `<num_files>` Número de archivos que se han de crear.

- `<basefilename>` Será una cadena de caracteres que represente el nombre base de los archivos.

Ese guion debe realizar lo siguiente:

- Comprobar que el número de argumentos es el correcto y que el segundo argumento tenga un valor
comprendido entre 1 y 99.

- Crear, en caso de no existir, el directorio dado en el primer argumento a partir del directorio donde se esté
situado y que posea permisos de lectura y escritura para el usuario `$USER`.

- Dentro del directorio dado en el primer argumento, crear archivos cuyos contenidos estarán vacíos y cuyos
nombres lo formarán el nombre dado como tercer argumento y un número que irá desde 01 hasta el
número dado en el segundo argumento.

```shell
#!/bin/bash

if [ $# -eq 3 ] ; then
	num_en_rango=`test $2 -gt 0 -a $2 -lt 100 && echo true || echo false`;
	if [ $num_en_rango == "true" ] ; then
		test -d $1 && chmod u+rw $1 || mkdir $1 && chmod u+rw $1;
		cd $1
		
		for i in `seq 1 1 $2`
		do
			if [ $i -lt 10 ] ; then
				touch $3"0"$i
			else
				touch $3$i
			fi
		done
		
		echo "Archivo(s) creado(s) correctamente."
	else
		echo "El segundo argumento no está dentro del rango [1-99]"
	fi
else
	echo "Número incorrecto de argumentos"
	echo "Número de argumentos esperados: 3"
	echo "Formato correcto: ./newdirfiles.sh <dirname> <num_files> <basefilename>"
fi
```
