// 1) Primer ejemplo:

int ValorAbsoluto(int entero){
	if (entero < 0)
		entero = -entero;
	else	
		return entero;
}

// En este ejemplo, en caso de que entero sea menor que 0, la funci�n no tendr� return. Para solucionarlo:

int ValorAbsoluto(int entero){
	if (entero < 0)
		entero = -entero;
	
	return entero;
}

// 2) Segundo ejemplo:

bool EsPositivo(int valor){
	if (valor > 0)
		return true;
}

// En este ejemplo, la funci�n no tendr� return en caso de que 'valor' sea negativo. Para solucionarlo:

bool EsPositivo(int valor){
	return valor > 0;
}

// 3) Tercer ejemplo:

long ParteEntera(double real){
	int parte_entera;
	parte_entera = trunc(real);
	return parte_entera;
}

// Esta funci�n no presentar� ning�n problema en cuanto a su ejecuci�n. El error reside en la elecci�n del tipo de dato que devuelve la funci�n, 
// puesto que siempre ser� un entero y por tanto no es necesario un long.
// Para solucionarlo:

int ParteEntera(double real){
	int parte_entera;
	parte_entera = trunc(real);
	return parte_entera;
}
