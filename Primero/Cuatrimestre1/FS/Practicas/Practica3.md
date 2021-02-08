# Práctica 3

1, 3, 5, 6, 7, 9, 10, 13 y 14

__*Ejercicio 1*__

Escriba, al menos, cinco variables de entorno junto con el valor que tienen.

> Con la orden `env` obtenemos, entre otras, las siguientes variables de entorno:

`LESSOPEN=| /usr/bin/lesspipe %s`
`USER=diego`
`GNOME_TERMINAL_SERVICE=:1.132`
`DISPLAY=:0`
`SHLVL=1`

***

__*Ejercicio 3*__

Compruebe qué ocurre en las expresiones del ejemplo anterior si se quitan las comillas dobles del
final y se ponen después de los dos puntos. ¿Qué sucede si se sustituyen las comillas dobles por comillas simples?

> Si se quitan las comillas dobles del final y se ponen después de los dos puntos se queda colgado
y no responde para ambas expresiones 

> Si se sustituyen las comillas dobles por comillas simples se queda colgado para la primera expresión. 
En cambio, para la segunda imprime todo lo que hay entre las comillas simples pero no ejecuta la instrucción `ls -l`

***

__*Ejercicio 5*__

Construya un guion que acepte como argumento una cadena de texto (por ejemplo, su nombre) y
que visualice en pantalla la frase `Hola` y el nombre dado como argumento.

```shell
#!/bin/bash

echo "Hola $1"
```


***

__*Ejercicio 6*__

Varíe el guion anterior para que admita una lista de nombres.

```shell
#!/bin/bash

echo "Hola $*"
```

***

__*Ejercicio 7*__

Cree tres variables llamadas `VAR1`, `VAR2` y `VAR3` con los siguientes valores respectivamente `hola`,
`adios` y `14`.

*a) Imprima los valores de las tres variables en tres columnas con 15 caracteres de ancho.*
```
$ printf "%15s %15s %15s \n" $VAR1 $VAR2 $VAR3
```
*b) ¿Son variables locales o globales?*

> Son variables locales

*c) Borre la variable VAR2.*
```
$ unset VAR3
```
*d) Abra otra ventana de tipo terminal, ¿puede visualizar las dos variables restantes?*

> No, ya que las variables son locales

*e) Cree una variable de tipo vector con los valores iniciales de las tres variables.*
```
$ vector=($VAR1 $VAR2 $VAR3)
```
*f) Muestre el segundo elemento del vector creado en el apartado e.*
```
$ echo ${vector[1]}
```

***

__*Ejercicio 9*__

Indique la línea de orden necesaria para buscar todos los archivos a partir del directorio home de
usuario (`$HOME`) que tengan un tamaño menor de un bloque. ¿Cómo la modificaría para que además imprima el
resultado en un archivo que se cree dentro del directorio donde nos encontremos y que se llame `archivosP`?
```
$ find $HOME -size -1 > archivosP
```

***

__*Ejercicio 10*__

Indique cómo buscaría todos aquellos archivos del directorio actual que contengan la palabra
__ejemplo__.
```
$ find ejemplo *
```

***

__*Ejercicio 13*__

Indique cómo contabilizar el número de ficheros de la propia cuenta de usuario que no tengan
permiso de lectura para el resto de usuarios.
```
$ find ~ ! -perm o+r | wc -l
```

***

__*Ejercicio 14*__

Modifique el ejercicio 8 de forma que, en vez de un alias, sea un guion llamado `numE` el que
devuelva el número de archivos que existen en el directorio que se le pase como argumento.
```shell
#!/bin/bash

echo $(ls -l | wc -l)
```
