#include <iostream>
#include <algorithm>
#include "soluciones.h"

static bool casoPrueba() {
	int n;
	std::cin >> n;

	if (n == 0) {
		return false;
	}

	// Rellenamos los datos
	int* edificios = new int[n];
	int cada_edificio;

	for (int i = 0; i < n; i++) {
		std::cin >> cada_edificio;
		edificios[i] = cada_edificio;
	}
	std::sort(edificios, edificios + n);

	// Contando el numero minimo de saltos

	int manzanas = 0;
	int saltos = 0;

	for (int i = n - 1; i >= 0 && manzanas < n; i--)
	{
		manzanas += edificios[i];
		saltos++;
	}

	if (manzanas < n) {
		std::cout << "IMPOSIBLE" << '\n';
	}
	else {
		std::cout << saltos << '\n';
	}

	return true;
}

/*
* Me parece que hay un problema de interpretacion con el ejercicio
* si bien en el escenario:
*
* 5 2 4 1 1 1
*
* Podemos ordenar: 1 1 1 2 4
*
* y sumar 2 + 6, que es > 5 (dos sumandos alcanzan sobrepasando el 5)
*
* la suma que mejor se ajusta seria: 4 + 1 = 5 porque esta pegado del 5 (y da la casualidad que la misma cantidad de sumandos, de ahi la confusion)
*/
void lanzadores::spiderman() {
	while (casoPrueba())
		;
}