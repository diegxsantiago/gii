# Práctica 7

4, 5, 6, 7, 8 y 10

__*Ejercicio 4*__

Copie el contenido del makefile previo a un archivo llamado `makefileE` ubicado en el mismo
directorio en el que están los archivos de código fuente .cpp. Pruebe a modificar distintos archivos .cpp (puede
hacerlo usando la orden `touch` sobre uno o varios de esos archivos) y compruebe la secuencia de instrucciones
que se muestra en el terminal al ejecutarse la orden `make`. ¿Se genera siempre la misma secuencia de órdenes
cuando los archivos han sido modificados que cuando no? ¿A qué cree puede deberse tal comportamiento?

```shell
# Nombre archivo: makefileE
# Uso: make –f makefileE
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
# que utiliza el programa2.

programa2: main2.o factorial.o hello.o libmates.a
	g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates

main2.o: main2.cpp
	g++ -I./includes -c main2.cpp

factorial.o: factorial.cpp
	g++ -I./includes -c factorial.cpp

hello.o: hello.cpp
	g++ -I./includes -c hello.cpp

libmates.a: sin.o cos.o tan.o
	ar -rvs libmates.a sin.o cos.o tan.o

sin.o: sin.cpp
	g++ -I./includes -c sin.cpp

cos.o: cos.cpp
	g++ -I./includes -c cos.cpp

tan.o: tan.cpp
	g++ -I./includes -c tan.cpp
```

```shell
$ make -f makefileE
g++ -I./includes -c main2.cpp
g++ -I./includes -c factorial.cpp
g++ -I./includes -c hello.cpp
g++ -I./includes -c sin.cpp
g++ -I./includes -c cos.cpp
g++ -I./includes -c tan.cpp
ar -rvs libmates.a sin.o cos.o tan.o
r - sin.o
r - cos.o
r - tan.o
g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates
$ gedit hello.cpp
$ make -f makefileE
g++ -I./includes -c hello.cpp
g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates

```

> La salida de la orden `make` cambia en función de los archivos que hayamos modificado,
de manera que solo actualizan, compilan, etc, estos últimos.


***

__*Ejercicio 5*__

Obtener un nuevo `makefileF` a partir del makefile del ejercicio anterior que incluya además las
dependencias sobre los archivos de cabecera. Pruebe a modificar cualquier archivo de cabecera (usando la orden
touch) y compruebe la secuencia de instrucciones que se muestra en el terminal al ejecutarse la orden `make`.

```shell
# Nombre archivo: makefileF
# Uso: make -f makefileF
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
#              que utiliza el programa2.

programa2: main2.o factorial.o hello.o libmates.a
	g++ -L./ -o programa2 main.o factorial.o hello.o libmates.a

main2.o: main2.cpp ./includes/functions.h ./includes/mates.h 
	g++ -I./includes -c main2.cpp

factorial.o: factorial.cpp ./includes/functions.h
	g++ -I./includes -c factorial.cpp

hello.o: hello.cpp ./includes/functions.h
	g++ -I./includes -c hello.cpp

libmates.a: sin.o cos.o tan.o
	ar -rvs libmates.a sin.o cos.o tan.o

sin.o: sin.cpp ./includes/mates.h
	g++ -I./includes -c sin.cpp

cos.o: cos.cpp ./includes/mates.h
	g++ -I./includes -c cos.cpp

tan.o: tan.cpp ./includes/mates.h
	g++ -I./includes -c tan.cpp
```

> Al ejecutar la orden `make` se actualizan también los archivos de cabecera.

***

__*Ejercicio 6*__

Usando como base el archivo `makefileG`, sustituya la línea de orden de la regla cuyo objetivo es
`programa2` por otra en la que se use alguna de las variables especiales y cuya ejecución sea equivalente.


```shell
# Nombre archivo: makefileG
# Uso: make –f makefileG
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
# 	        que utiliza el programa2.

# Variable que indica el compilador que se va a utilizar
CC=g++

# Variable que indica el directorio en donde se encuentran los archivos de cabecera
INCLUDE_DIR= ./includes

# Variable que indica el directorio en donde se encuentran las bibliotecas
LIB_DIR= ./

programa2: main2.o factorial.o hello.o libmates.a
	$(CC) -L$(LIB_DIR) -o $@ $^
	
main2.o: main2.cpp
	$(CC) -I$(INCLUDE_DIR) -c main2.cpp
	
factorial.o: factorial.cpp
	$(CC) -I$(INCLUDE_DIR) -c factorial.cpp
	
hello.o: hello.cpp
	$(CC) -I$(INCLUDE_DIR) -c hello.cpp
	
libmates.a: sin.o cos.o tan.o
	ar -rvs libmates.a sin.o cos.o tan.o
	
sin.o: sin.cpp
	$(CC) -I$(INCLUDE_DIR) -c sin.cpp
	
cos.o: cos.cpp
	$(CC) -I$(INCLUDE_DIR) -c cos.cpp
	
tan.o: tan.cpp
	$(CC) -I$(INCLUDE_DIR) -c tan.cpp
```

***

__*Ejercicio 7*__

Utilizando como base el archivo `makefileG` y los archivos fuente asociados, realice los cambios
que considere oportunos para que, en la construcción de la biblioteca estática `libmates.a`, este archivo pase a
estar en un subdirectorio denominado `libs` y se pueda enlazar correctamente con el resto de archivos objeto.

```shell
# Nombre archivo: makefileG
# Uso: make –f makefileG
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
# que utiliza el programa2.

# Variable que indica el compilador que se va a utilizar
	CC=g++

# Variable que indica el directorio en donde se encuentran los archivos de cabecera
	INCLUDE_DIR= ./includes

# Variable que indica el directorio en donde se encuentran las bibliotecas
	LIB_DIR= ./libs

programa2: main2.o factorial.o hello.o $(LIB_DIR)/libmates.a
	$(CC) -L$(LIB_DIR) -o $@ factorial.o hello.o $(LIB_DIR)/libmates.a
      	
main2.o: main2.cpp
	$(CC) -I$(INCLUDE_DIR) -c main2.cpp
	
factorial.o: factorial.cpp
	$(CC) -I$(INCLUDE_DIR) -c factorial.cpp
	
hello.o: hello.cpp
	$(CC) -I$(INCLUDE_DIR) -c hello.cpp
	
$(LIB_DIR)/libmates.a: sin.o cos.o tan.o
	ar -rvs libmates.a sin.o cos.o tan.o
	
sin.o: sin.cpp
	$(CC) -I$(INCLUDE_DIR) -c sin.cpp
	
cos.o: cos.cpp
	$(CC) -I$(INCLUDE_DIR) -c cos.cpp
	
tan.o: tan.cpp
	$(CC) -I$(INCLUDE_DIR) -c tan.cpp
```

***

__*Ejercicio 8*__

Busque la variable predefinida de `make` que almacena la utilidad del sistema que permite construir
bibliotecas. Recuerde que la orden para construir una biblioteca estática a partir de una serie de archivos objeto es
`ar` (puede usar la orden grep para filtrar el contenido; no vaya a leer línea a línea toda la salida). Usando el
archivo `makefileG`, sustituya la orden `ar` por su variable correspondiente.

> Primero, ejecutamos el siguiente comando para encontrar la variable que almacena `ar`

`make -p | grep ar`

> A continuación la sustituimos en el lugar que corresponda

```shell
# Nombre archivo: makefileG
# Uso: make –f makefileG
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
# que utiliza el programa2.

# Variable que indica el compilador que se va a utilizar
	CC=g++

# Variable que indica el directorio en donde se encuentran los archivos de cabecera
	INCLUDE_DIR= ./includes

# Variable que indica el directorio en donde se encuentran las bibliotecas
	LIB_DIR= ./libs

programa2: main2.o factorial.o hello.o $(LIB_DIR)/libmates.a
	$(CC) -L$(LIB_DIR) -o $@ factorial.o hello.o $(LIB_DIR)/libmates.a
      	
main2.o: main2.cpp
	$(CC) -I$(INCLUDE_DIR) -c main2.cpp
	
factorial.o: factorial.cpp
	$(CC) -I$(INCLUDE_DIR) -c factorial.cpp
	
hello.o: hello.cpp
	$(CC) -I$(INCLUDE_DIR) -c hello.cpp
	
libmates.a: sin.o cos.o tan.o
	$(AR) -rvs libmates.a sin.o cos.o tan.o
	
sin.o: sin.cpp
	$(CC) -I$(INCLUDE_DIR) -c sin.cpp
	
cos.o: cos.cpp
	$(CC) -I$(INCLUDE_DIR) -c cos.cpp
	
tan.o: tan.cpp
	$(CC) -I$(INCLUDE_DIR) -c tan.cpp
```

***

__*Ejercicio 10*__

Con la siguiente especificación de módulos escriba un archivo denominado `makefilePolaca` que
automatice el proceso de compilación del programa final de acuerdo a la siguiente descripción:

- Compilador: `gcc` o `g++`
- Archivos cabecera: `calc.h` (ubicado en un subdirectorio denominado cabeceras)
- Archivos fuente: `main.c` `stack.c` `getop.c` `getch.c`
- Nombre del programa ejecutable: `calculadoraPolaca`
- Además, debe incluir una regla denominada `borrar`, sin dependencias, cuya funcionalidad sea la de eliminar los
archivos objeto y el programa ejecutable

```shell
# Nombre archivo: makefilePolaca
# Uso: make –f makefilePolaca
# Descripción: Mantiene todas las dependencias entre los módulos que utiliza el calculadoraPolaca.

# Variable que indica el compilador que se va a utilizar
	CC=g++

# Variable que indica el directorio en donde se encuentran los archivos de cabecera
	INCLUDE_DIR= ./cabeceras

calculadoraPolaca: main.o stack.o getop.o getch.o
	$(CC) -L./ -o $@ $^
      
main.o: main.c $(INCLUDE_DIR)/calc.h
	$(CC) -I$(INCLUDE_DIR) -c $<
      
stack.o: stack.c $(INCLUDE_DIR)/calc.h
	$(CC) -I$(INCLUDE_DIR) -c $<
      
getop.o: getop.c $(INCLUDE_DIR)/calc.h
	$(CC) -I$(INCLUDE_DIR) -c $<
      
getch.o: getch.c $(INCLUDE_DIR)/calc.h
	$(CC) -I$(INCLUDE_DIR) -c $<
      
borrar:
	rm *.o calculadoraPolaca
```
