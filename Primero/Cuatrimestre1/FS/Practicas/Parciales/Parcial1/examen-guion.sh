#!/bin/bash

if [ "$#" == "3" ]; then
	declare -i CONTADOR=`find $1 -writable | wc -l`;
	printf "\nNúmero de archivos del directorio con permiso de escritura: %d \n" $CONTADOR;
	man $2 > ayuda;
	head --lines=10 ayuda;
	grep $3 ayuda > resultado;
else
	printf "Número de argumentos incorrecto: %d" $#;
	printf "\nEjecución correcta: ./examen-guion <nombre_directorio> <comando> <palabra>\n";
fi;
