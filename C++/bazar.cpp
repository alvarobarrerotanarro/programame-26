#include <iostream>
#include "soluciones.h"

static bool casoPrueba() {
	int libras, precioDolares, precioEuros;

	std::cin >> libras;
	std::cin >> precioDolares;
	std::cin >> precioEuros;

	if (libras == 0 && precioDolares == 0 && precioEuros == 0) {
		return false;
	}

	int billetesDolar = libras / precioDolares;
	int billeteLibra = 0;
	int pagoLibras, vueltasLibras;
	bool pagado = false;

	while (!pagado && billetesDolar <= 10000) {
		pagoLibras = billetesDolar * precioDolares;
		vueltasLibras = pagoLibras - libras;

		if (vueltasLibras >= 0 && vueltasLibras % precioEuros == 0) {
			pagado = true;
			billeteLibra = vueltasLibras / precioEuros;
		}
		else {
			billetesDolar++;
		}
	}

	std::cout << billetesDolar << ' ' << billeteLibra << '\n';

	return true;
}

void lanzadores::bazar() {
	while (casoPrueba())
		;
}