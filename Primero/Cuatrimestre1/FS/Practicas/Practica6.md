# Práctica 6

3, 4 ,5 y 6

__*Ejercicio 3*__

Escribir un guion que nos dé el nombre del proceso del sistema que consume más memoria

```shell
#!/bin/bash

# -b: opción recomendada para la exportar la lista
# -n 1: para indicar una sola iteración

top -bn 1 > lista

# Para quedarnos únicamente con la lista en forma de tabla y no con los datos del principio

salida=$[$[`cat lista | wc -l`] - 7]

# Ordenación en base a la décima columna (donde se indica la memoria de cada proceso)

cat lista | tail -n $salida | sort -k 10 -o salida

# Salida de la última fila, donde, una vez ordenado el archivo, se encuentra el de mayor memoria
# Con la orden tr -s reemplazamos las apariciones consecutivas del caracter " " por un solo " "
# Con la orden cut conseguimos imprimir las partes de una línea deseadas
# Así, con -d " " establecemos el espacio como delimitador entre elementos
# Y con -f 13 seleccionamos el elemento 13 (delimitados por espacios) de la línea,
# que es el nombre del proceso en este caso

cat salida | tail -n 1 | tr -s " " " " | cut -d " " -f 13
```

***

__*Ejercicio 4*__

Escribir un guion que escriba números desde el 1 en adelante en intervalos de un segundo.
¿Cómo se podría, desde otro terminal, detener la ejecución de dicho proceso, reanudarlo y terminar definitivamente su
ejecución?

```shell
#!/bin/bash

i=0

while true; do
	echo $i
	sleep 1
	i=$[$i + 1]
done;

```

> Para detener la ejecución del proceso: 
```
kill -s STOP <pid>
```

> Para reaunudar la ejecución del proceso:
```
kill -s CONT <pid>
```

> Para terminar la ejecución del proceso:
```
kill -s TERM <pid>
```

> Donde `<pid>` es el ID del proceso correspondiente

***

__*Ejercicio 5*__ 

¿Se puede matar un proceso que se encuentra suspendido? En su caso, ¿cómo?

> Sí que se puede, utilizando el comando:

```shell
kill -9 %<pid>
```

> Donde `<pid>` es el ID del proceso correspondiente
***

__*Ejercicio 6*__

¿Qué debemos hacer a la orden `top` para que nos muestre sólo los procesos nuestros?

> Usar el comando:

```shell
top -u <nombre de usuario>
```

