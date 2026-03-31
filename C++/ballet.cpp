#include <iostream>
#include "soluciones.h"

static bool casoPrueba()
{
  int n;
  int tmp_pos;
  bool imposible = false;
  std::cin >> n;

  if (!std::cin.good() || n == 0)
  {
    return false;
  }

  int *alturas = new int[n];
  for (int i = 0; i < n; i++)
  {
    std::cin >> alturas[i];
  }

  for (size_t i = 0, j = n - 1; !imposible && i < j; i++, j--)
  {
    if (alturas[i] > alturas[i + 1])
    {
      if (alturas[j] > alturas[i + 1])
      {
        imposible = true;
      }
      else
      {
        tmp_pos = alturas[i];
        alturas[i] = alturas[j];
        alturas[j] = tmp_pos;
      }
    }
  }

  for (size_t i = 1; !imposible && i < n; i++)
  {
    if (alturas[i - 1] > alturas[i])
    {
      imposible = true;
    }
  }

  if (imposible)
  {
    std::cout << "NO\n";
  }
  else
  {
    std::cout << "SI\n";
  }

  delete alturas;
  return true;
}

void lanzadores::ballet()
{
  while (casoPrueba())
    ;
}