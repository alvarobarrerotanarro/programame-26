#include <iostream>
#include <cctype>
#include <map>
#include "soluciones.h"

/*
* En la solucion de java existia un metodo para eliminar
* espacios sobre una cadena ya existente, esto es claramente
* mas eficiente.
*/
static std::string leer_sin_espacios() {
	std::string linea{};
	char ch = '\0';

	do {
		std::cin.read(&ch, 1);
		if (!std::isspace(ch)) {
			linea += ch;
		}
	} while (ch != '\n');

	return linea;
}

/*
* Utilidades de mapas propias.
*/

template <typename T, typename U>
U get_or_default(std::map<T, U>& m, const T& k, U d) {
	if (m.contains(k)) {
		return m.at(k);
	}

	return d;
}

template <typename T, typename U>
bool compare_map(std::map<T, U>& first, std::map<T, U> second)
{
	U first_value, second_value;
	bool comparation = true;

	if (first.size() != second.size()) {
		return false;
	}

	for (auto it = first.cbegin(); comparation && it != first.cend(); it++) {
		first_value = it->second;
		second_value = get_or_default(second, it->first, 0);

		if (first_value != second_value) {
			comparation = false;
		}
	}

	return comparation;
}

static void casoPrueba() {
	int contador = 0;

	std::string primeraLinea = leer_sin_espacios();
	std::string segundaLinea = leer_sin_espacios();

	// La frecuencia de cada letra en la segunda linea.
	std::map<char, int> segundaFrecuencia{};
	std::map<char, int> cadaFrecuencia{};

	// Alimentamos la segunda frecuencia.
	for (auto it = segundaLinea.cbegin(); it != segundaLinea.cend(); it++) {
		segundaFrecuencia[*it] = get_or_default(segundaFrecuencia, *it, 0) + 1;
	}

	for (int i = 0; i <= primeraLinea.size() - segundaLinea.size(); i++) {
		cadaFrecuencia.clear();

		// Contabilizamos la frecuencia del slice actual.
		for (auto it = primeraLinea.cbegin() + i;
			it != primeraLinea.cbegin() + i + segundaLinea.size(); it++) {
			cadaFrecuencia[*it] = get_or_default(cadaFrecuencia, *it, 0) + 1;
		}

		// Comparo las palabras bajo el criterio: Misma frecuencia de todas las mismas
		// letras en cualquier orden
		if (compare_map(segundaFrecuencia, cadaFrecuencia)) {
			contador++;
		}
	}

	std::cout << contador << '\n';
}

void lanzadores::reinaldo() {
	int n;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (n-- > 0) {
		casoPrueba();
	}
}