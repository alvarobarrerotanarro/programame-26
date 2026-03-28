
#include <iostream>
#include "soluciones.h"

static bool casoPrueba() {
	int n;
	int min;
	int max;

	int temp;
	bool encendido = false;
	int minutos = 0;

	std::cin >> n;
	std::cin >> min;
	std::cin >> max;

	if (n == 0 && min == 0 && max == 0) {
		return false;
	}

	for (int i = 0; i < n; i++) {
		std::cin >> temp;

		if (encendido && temp >= max) {
			encendido = false;
		}
		else if (encendido || temp < min) {
			encendido = true;
			minutos++;
		}
	}

	std::cout << minutos << '\n';

	return true;
}

void lanzadores::termostato() {
	while (casoPrueba())
		;
}