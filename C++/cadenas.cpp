// C++.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "soluciones.h"

void casoPrueba() {
	int eslabones;
	std::cin >> eslabones;
	std::cout << ((eslabones + 1) / 2) << ' ' << (eslabones / 2) << '\n';
}

void lanzadores::cadenas() {
	int n;
	std::cin >> n;

	while (n-- > 0) {
		casoPrueba();
	}
}