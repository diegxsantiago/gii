// 1) Primer ejemplo:

int ValorAbsoluto(int entero){
	if (entero < 0)
		entero = -entero;
	else	
		return entero;
}

// En este ejemplo, en caso de que entero sea menor que 0, la función no tendrá return. Para solucionarlo:

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

// En este ejemplo, la función no tendrá return en caso de que 'valor' sea negativo. Para solucionarlo:

bool EsPositivo(int valor){
	return valor > 0;
}

// 3) Tercer ejemplo:

long ParteEntera(double real){
	int parte_entera;
	parte_entera = trunc(real);
	return parte_entera;
}

// Esta función no presentará ningún problema en cuanto a su ejecución. El error reside en la elección del tipo de dato que devuelve la función, 
// puesto que siempre será un entero y por tanto no es necesario un long.
// Para solucionarlo:

int ParteEntera(double real){
	int parte_entera;
	parte_entera = trunc(real);
	return parte_entera;
}
