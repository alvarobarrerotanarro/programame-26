#include <iostream>
#include <cmath>
#include "soluciones.h"

/*
 * Cuenta el numero de bolas que es necesario para representar un numero en una base.
 */
std::size_t contar_bolas(std::size_t num, std::size_t base)
{
	std::size_t total = 0;
	std::size_t digito;
	std::size_t num_actual = num;

	do
	{
		digito = num_actual % base;
		num_actual /= base;

		total += digito;
	} while (num_actual > 0);

	return total;
}

/*
 * Cuenta el numero de separadores (paralelas de un abaco) que han sido necesarias abarcar para representar el digito en la base especificada.
 */
std::size_t contar_separadores(std::size_t num, std::size_t base)
{
	std::size_t separadores = 0;
	// Normalmente decimos que el 10 en base 10 tiene dos digitos, en este caso queremos que el 10 en base 10 cuente como uno.
	std::size_t num_actual = std::max(static_cast<std::size_t>(0), num - 1);

	do
	{
		separadores++;
		num_actual /= base;
	} while (num_actual > 0);

	return separadores;
}

static void casoPrueba()
{
	std::size_t min_base = 2;
	std::size_t record = -1; // El entero sin signo mas grande.
	std::size_t actual;

	int num;
	std::cin >> num;

	for (int i = 2; i <= 10; i++)
	{
		actual = contar_bolas(num, i) + contar_separadores(num, i);
		if (actual < record)
		{
			record = actual;
			min_base = i;
		}
	}

	std::cout << min_base << '\n';
}

/*

# Casos de prueba

4
2
9
12
40

*/
void lanzadores::numero_sin_digitos()
{
	int n;
	std::cin >> n;

	while (n-- > 0)
	{
		casoPrueba();
	}
}