#include <iostream>
#include <stack>
#include "soluciones.h"

/*
 * Retorna true en caso de que ch sea una letra mayuscula.
 */
static bool isletter(char ch)
{
  return ch >= 65 && ch <= 90;
}

/*
 * Retorna true en caso de que el caracter sea un digito.
 */
static bool isdigit(char ch)
{
  return ch - '0' >= 0 && ch - '0' <= 9;
}

static size_t longitudCadena(const std::string &cadena)
{
  std::stack<size_t> sumas{};
  size_t factor = 1;
  sumas.push(0);

  for (auto it = cadena.cbegin(); it != cadena.cend(); it++)
  {
    if (isletter(*it))
    {
      size_t &top = sumas.top(); // obtencion por referencia
      top++;
    }
    else if (isdigit(*it))
    {
      factor = *it - '0';

      // Nuevo contador para el siguiente nivel de anidacion.
      sumas.push(0);
    }
    else if (*it == ']')
    {
      // Eliminacion del contador para el nivel actual de anidacion.
      size_t sumando = sumas.top() * factor;
      sumas.pop();

      size_t &top = sumas.top(); // obtencion por referencia
      top += sumando;
    }
  }

  /*

    Si la cadena esta correctamente formada, tras el cierre del ultimo corchete deberia quedar un unico digito con el contador superior a todos los niveles de anidacion.

  */
  return sumas.top();
}

/*

## Casos de prueba

Cadenas de ADN en notacion comprimida.

```
TTT
TTT2[TT]
TTT3[T]
TTT3[TTT3[TTT]TTT]
```

*/
static bool casoPrueba()
{
  std::string cadena;
  std::cin >> cadena;

  if (!std::cin.good())
  {
    return false;
  }

  std::cout << longitudCadena(cadena) << '\n';

  return true;
}

void lanzadores::cadena_adn()
{
  while (casoPrueba())
    ;
}