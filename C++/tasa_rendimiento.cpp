
#include <iostream>
#include "soluciones.h"

static void casoPrueba() {
	int alumnos;
	int tasa;
	std::cin >> alumnos;
	std::cin >> tasa;
	std::cout << (alumnos * tasa / 100) << '\n';
}

void lanzadores::tasa_rendimiento() {
	int n;
	std::cin >> n;
	while (n-- > 0) {
		casoPrueba();
	}
}