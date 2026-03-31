#include <iostream>
#include "soluciones.h"

/*
 * Tablero del juego de la vida Conway.
 */
static class Tablero
{
private:
  size_t filas;
  size_t columnas;
  char **datos;

public:
  constexpr static char CELDA_VIVA = 'O';
  constexpr static char CELDA_MUERTA = '.';

  Tablero(size_t filas, size_t columnas)
      : datos{nullptr}, filas{filas}, columnas{columnas}
  {
    datos = new char *[filas];
    for (size_t i = 0; i < filas; i++)
    {
      datos[i] = new char[columnas];
    }
  }

  /*
   * Constructor por copia.
   */
  Tablero(const Tablero &other)
  {
    filas = other.filas;
    columnas = other.columnas;

    datos = new char *[filas];
    for (size_t i = 0; i < filas; i++)
    {
      datos[i] = new char[columnas];
      for (size_t j = 0; j < columnas; j++)
      {
        datos[i][j] = other.datos[i][j];
      }
    }
  }

  /*
   * Genera el proximo tablero en el juego de la vida.
   */
  static Tablero ciclo(const Tablero &actual)
  {
    Tablero nuevoTablero{actual};
    size_t celdas_vivas;

    for (size_t i = 0; i < actual.filas; i++)
    {
      for (size_t j = 0; j < actual.columnas; j++)
      {
        celdas_vivas = actual.contarVivas(i, j);

        if (actual.datos[i][j] == CELDA_MUERTA && celdas_vivas == 3)
        {
          nuevoTablero.datos[i][j] = CELDA_VIVA;
        }
        else if (actual.datos[i][j] == CELDA_VIVA && celdas_vivas < 2 || celdas_vivas > 3)
        {
          nuevoTablero.datos[i][j] = CELDA_MUERTA;
        }
      }
    }

    return nuevoTablero;
  }

  /*
   * Permite construir un tablero leyendo desde la consola.
   */
  static Tablero rellenarTablero(size_t filas, size_t columnas)
  {
    Tablero tablero{filas, columnas};
    char ch = '\0';

    for (size_t i = 0; i < filas; i++)
    {
      for (size_t j = 0; j < columnas; j++)
      {
        // Ignora los caracteres whitespace
        std::cin >> ch;
        tablero.datos[i][j] = ch;
      }
    }

    return tablero;
  }

  /*
   * Asignacion por copia.
   */
  Tablero &operator=(const Tablero &other)
  {
    filas = other.filas;
    columnas = other.columnas;

    datos = new char *[filas];
    for (size_t i = 0; i < filas; i++)
    {
      datos[i] = new char[columnas];
      for (size_t j = 0; j < columnas; j++)
      {
        datos[i][j] = other.datos[i][j];
      }
    }

    return *this;
  }

  size_t get_filas() const
  {
    return filas;
  }

  size_t get_columnas() const
  {
    return columnas;
  }

  /*
   * Permite ver el contenido del tablero.
   */
  void imprimir() const
  {
    for (size_t i = 0; i < filas; i++)
    {
      for (size_t j = 0; j < columnas; j++)
      {
        std::cout << datos[i][j];
      }
      std::cout << '\n';
    }
  }

  /*
   * Cuenta el numero de celdas vivas en las ocho alrededor de (fila, columna).
   * Sobrepasar unextremo implica volver a principio.
   */
  size_t contarVivas(size_t fila, size_t columna) const
  {
    size_t contador = 0;
    size_t fila_actual = (fila + (filas - 1)) % filas;
    size_t columna_actual;

    for (size_t i = 0; i < 3; i++)
    {
      // Hay que resetear la columna actual por cada fila.
      columna_actual = (columna + (columnas - 1)) % columnas;

      for (size_t j = 0; j < 3; j++)
      {
        if ((fila_actual != fila || columna_actual != columna) && datos[fila_actual][columna_actual] == CELDA_VIVA)
        {
          contador++;
        }

        columna_actual = (columna_actual + 1) % columnas;
      }

      fila_actual = (fila_actual + 1) % filas;
    }

    return contador;
  }

  /*
   * Libera la memoria de punteros.
   */
  virtual ~Tablero()
  {
    if (datos != nullptr)
    {
      for (size_t i = 0; i < filas; i++)
      {
        if (datos[i] != nullptr)
        {
          delete datos[i];
        }
      }

      delete datos;
    }
  }
};

/*
 * Rellena un tablero, aplica el numero de ciclos especificado y lo imprime.
 */
static bool casoPrueba()
{
  size_t filas, columnas, ciclos;
  std::cin >> filas;
  std::cin >> columnas;
  std::cin >> ciclos;

  if (filas + columnas + ciclos == 0)
  {
    return false;
  }

  auto tablero = Tablero::rellenarTablero(filas, columnas);
  for (size_t i = 0; i < ciclos; i++)
  {
    tablero = Tablero::ciclo(tablero);
  }

  tablero.imprimir();
  std::cout << "===" << '\n';

  return true;
}

/*

# Casos de prueba

3 7 1
.......
.O.OOO.
.......
5 5 4
.....
..O..
...O.
.OOO.
.....


*/

void lanzadores::juego_de_la_vida()
{
  while (casoPrueba())
    ;
}