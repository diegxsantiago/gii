# Práctica 1

__*Ejercicio 1*__

Cree el siguiente árbol de directorios a partir de un directorio de
su cuenta de usuario. Indique también cómo sería posible crear toda esa
estructura de directorios mediante una única orden *(mire las opciones de la
orden de creación de directorios mediante man mkdir)*.
```
$ mkdir ejercicio1 ejercicio1/Ejer1 ejercicio1/Ejer2 ejercicio1/Ejer3 ejercicio/Ejer1/Ejer21
```
Posteriormente realice las siguientes acciones:

*a) En `Ejer1` cree los archivos arch100.txt, filetags.txt,
practFS.ext y robet201.me.*
```
$ cd ejercicio1/Ejer1
$ touch arch100.txt filetags.txt ractFS.ext robet201.me
```
*b) En `Ejer21` cree los archivos robet202.me, ejer11sol.txt y blue.me.*
``` 
$ cd Ejer21
$ touch robet202.me ejer11sol.txt blue.me
```
*c) En `Ejer2` cree los archivos ejer2arch.txt, ejer2filetags.txt y readme2.pdf.*
```
$ cd ../../Ejer2
$ touch ejer2arch.txt ejer2filetags.txt readme2.pdf
```
*d) En `Ejer3` cree los archivos ejer3arch.txt, ejer3filetags.txt y readme3.pdf.*
```
$ cd ../Ejer3
$ touch ejer3arch.txt ejer3filetags.txt readme3.pdf
```
*e) ¿Podrían realizarse las acciones anteriores empleando una única orden? Indique cómo.*
```
$ touch ejercicio1/Ejer1/arch10.txt ejercicio1/Ejer1/filetags.txt ejercicio1/Ejer1/ractFS.ext ejercicio1/Ejer1/robet201.me
$ touch ejercicio1/Ejer1/Ejer21/robet202.me ejercicio1/Ejer1/Ejer21/ejer11sol.txt ejercicio1/Ejer1/Ejer21/blue.me
$ touch ejercicio1/Ejer2/ejer2arch.txt ejercicio1/Ejer2/ejer2filetags.txt rejercicio1/Ejer2/readme2.pdf
$ touch ejercicio1/Ejer3/ejer3arch.txt ejercicio1/Ejer3/ejer3filetags.txt ejercicio1/Ejer3/readme3.pdf
```

***

__*Ejercicio 2*__

Situados en el directorio `ejercicio1` creado anteriormente, realice las siguientes acciones:

*a) Mueva el directorio `Ejer21` al directorio `Ejer2`.*
```
$ mv Ejer1/Ejer21 Ejer2
```
*b) Copie los archivos de `Ejer1` cuya extensión tenga una __x__ al directorio `Ejer3`.*
```
$ cp Ejer1/*.*[x]* Ejer3
```
*c) Si estamos situado en el directorio `Ejer2` y ejecutamos la orden `ls -la ../Ejer3/*arch*`, ¿qué
archivo/s, en su caso, debería mostrar?*

> Los archivos del directorio `Ejer3` que contengan la cadena ordenada de caracteres "arch"


***

__*Ejercicio 3*__

Si estamos situados en el directorio `Ejer2`, indique la orden necesaria para listar sólo los nombres
de todos los archivos del directorio padre.
```
$ ls ..
```

***

__*Ejercicio 4*__

Liste los archivos que estén en su directorio actual y fíjese en alguno que no disponga de la fecha y
hora actualizada, es decir, la hora actual y el día de hoy. Ejecute la orden `touch` sobre dicho archivo y observe qué
sucede sobre la fecha del citado archivo cuando se vuelva a listar.

> La fecha se actualiza a la actual

***

__*Ejercicio 5*__

La organización del espacio en directorios es fundamental para poder localizar fácilmente aquello
que estemos buscando. En ese sentido, realice las siguientes acciones dentro de su directorio `home` (es el
directorio por defecto sobre el que trabajamos al entrar en el sistema)

*a) Obtenga en nombre de camino absoluto (pathname absoluto) de su directorio home. ¿Es el mismo que el
de su compañero/a?*

> Situados en home"
```
$ pwd
```
*b) Cree un directorio para cada asignatura en la que se van a realizar prácticas de laboratorio y, dentro de
cada directorio, nuevos directorios para cada una de las prácticas realizadas hasta el momento.*
```
$ mkdir FP CA ALEM FFT FS FS/Practica1 FP/Practica0 FP/Practica1 FP/Practica2 CA/Practica1 FFT/Practica1 FFT/Practica2
```
*c) Dentro del directorio de la asignatura fundamentos del software (llamado __FS__) y dentro del directorio
creado para esta práctica, copie los archivos `hosts` y `passwd` que se encuentran dentro del directorio
`/etc.`*
```
$ cp ../../../../etc/hosts Practica1
```
d) Muestre el contenido de cada uno de los archivos.
```
$ cat hosts
$ cat passwd
```

***

__*Ejercicio 6*__

Ejercicio 1.6. Situados en algún lugar de su directorio principal de `usuario` (directorio `HOME`), cree los directorios
siguientes: `Sesion.1`, `Sesion.10`, `Sesion.2`, `Sesion.3`, `Sesion.4`, `Sesion.27`, `Prueba.1` y
`Sintaxis.2` y realice las siguientes tareas:
´´´
$ mkdir Sesion.1 Sesion.10 Sesion.2 Sesion.3 Sesion.4 Sesion.27 Prueba.1 Sintaxis.2
´´´
*a) Borre el directorio `Sesion.4`*
```
$ rmdir Sesion.4
```
*b) Liste todos aquellos directorios que empiecen por Sesion. y a continuación tenga un único carácter*
```
$ ls Sesion.?
```
c) Liste aquellos directorios cuyos nombres terminen en .1
```
$ ls *.1
```
d) Liste aquellos directorios cuyos nombres terminen en .1 o .2
```
$ ls *.{1,2}
```
e) Liste aquellos directorios cuyos nombres contengan los caracteres si
```
$ ls *[si]*
```
f) Liste aquellos directorios cuyos nombres contengan los caracteres si y terminen en .2
```
$ ls *[si]*.2
```

***

__*Ejercicio 7*__

Desplacémonos hasta el directorio `/bin`, genere los siguientes listados de archivos (siempre de la
forma más compacta y utilizando los metacaracteres apropiados):

*a) Todos los archivos que contengan sólo cuatro caracteres en su nombre*
```
$ ls ????
```
*b) Todos los archivos que comiencen por los caracteres __d__, __f__.*
```
$ ls {d,f}*
```
*c) Todos los archivos que comiencen por las parejas de caracteres __sa__, __se__, __ad__.*
```
$ ls {sa,se,ad}*
```
*d) Todos los archivos que comiencen por __t__ y acaben en __r__.*
```
$ ls t*r
```

***

__*Ejercicio 8*__

Liste todos los archivos que comiencen por __tem__ y terminen por __.gz__ o __.zip__:

*a) De tu directorio `HOME`.*
```
$ ls ../home/diego/tem*{gz,zip}
```
*b) Del cirectorio actual.*
```
$ ls tem*{gz,zip}
```
*c) ¿Hay alguna diferencia en el resultado de su ejecución? Razone la respuesta.*

> Sí, puesto que a pesar de que la búsqueda es la misma, los directorios en los que se ejecuta
no tienen por qué ser idénticos y por tanto los resultados no tiene por qué coincidir.

***

__*Ejercicio 9*__

Muestre del contenido de un archivo regular que contenga texto:

*a) Las 10 primeras líneas.*
```
$ head --lines=10 hosts
```
*b) Las 5 últimas líneas*.*
```
$ tail --lines=5 hosts
```

***

__*Ejercicio_10*__

Cree un archivo empleando para ello cualquier editor de textos y escriba en el mismo varias
palabras en diferentes líneas. A continuación trate de mostrar su contenido de manera ordenada empleando
diversos criterios de ordenación.

> Por ejemplo, orden alfabético de los archivos
```
$ cat *[a-z]*
```

***

__*Ejercicio 11*__

¿Cómo podría ver el contenido de todos los archivos del directorio actual que terminen en __.txt__
o __.c__?
```
$ cat *.{txt,c}
```
