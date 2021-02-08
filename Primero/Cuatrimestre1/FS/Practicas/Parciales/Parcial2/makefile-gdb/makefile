# Variable para el compilador que se va a utilizar
	CC=g++

# Variable que indica el directorio en donde se encuentran los archivos de cabecera
	INCLUDE_DIR= ./includes

mitad: main.o suma.o division.o
	$(CC) -o mitad main.o suma.o division.o
      
main.o: main.cpp $(INCLUDE_DIR)/funciones.h
	$(CC) -I$(INCLUDE_DIR) -c main.cpp
      
suma.o: suma.cpp $(INCLUDE_DIR)/funciones.h
	$(CC) -I$(INCLUDE_DIR) -c suma.cpp
      
division.o: division.cpp $(INCLUDE_DIR)/funciones.h
	$(CC) -I$(INCLUDE_DIR) -c division.cpp
	

