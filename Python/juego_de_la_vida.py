from sys import stdin
from typing import Optional

def next_int() -> int:
  """
  Agarra el siguiente token en el stream e intenta convertirlo en un numero.
  """ 

  cont = True 
  ch = ""
  num_str = ""

  # Ignore space characters
  while cont:
    ch = stdin.read(1) 
    if not ch.isspace():
      num_str += ch
    elif ch.isspace() and len(num_str) > 0:
      cont = False
  
  return int(num_str)


def next_ch() -> str: 
  """
  Retorna el primer caracter no vacio dentro del stream de entrada.
  """ 

  ch = " "
  while ch.isspace():
    ch = stdin.read(1) 
  return ch


class Tablero:
  CELDA_VIVA = "O"
  CELDA_MUERTA = "."

  def __init__(self, rows: int, columns: int):
    self.rows = rows
    self.columns = columns

    self._data: list[list[str]] = list()
    for _ in range(rows):
      # Redimension de columa
      columna: list[str] = list()   
      for _ in range(columns):
        columna.append(".") 
      
      # Redimiension de fila
      self._data.append(columna)

  @classmethod
  def ciclo(cls, tablero: Optional["Tablero"]) -> Optional["Tablero"]:
    if not isinstance(tablero, Tablero):
      raise TypeError("Tablero is expected.")
    
    nuevo = tablero.copy()
    for i in range(tablero.rows):
      for j in range(tablero.columns):
        vivas = tablero.contar_vivas(i, j) 

        if tablero._data[i][j] == Tablero.CELDA_MUERTA and vivas == 3:
          nuevo._data[i][j] = Tablero.CELDA_VIVA
        elif tablero._data[i][j] == Tablero.CELDA_VIVA and (vivas < 2 or vivas > 3):
          nuevo._data[i][j] = Tablero.CELDA_MUERTA
    
    return nuevo

  @classmethod
  def rellenar_tablero(cls, rows: int, columns: int):
    tablero = Tablero(rows, columns)

    for i in range(rows):
      for j in range(columns):
        tablero._data[i][j] = next_ch()

    return tablero

  def copy(self):
    tablero = Tablero(self.rows, self.columns)
    for i in range(self.rows):
      for j in range(self.columns):
        tablero._data[i][j] = self._data[i][j]
    return tablero
  
  def contar_vivas(self, fila: int, columna: int) -> int:
    contador = 0
    fila_actual = (fila + (self.rows - 1)) % self.rows

    # Revisamos la regilla 3 x 3.

    for _ in range(3):
      columna_actual = (columna + (self.columns - 1)) % self.columns

      for _ in range(3):
        if (fila_actual != fila or columna_actual != columna) and self._data[fila_actual][columna_actual] == Tablero.CELDA_VIVA:
          contador += 1

        columna_actual = (columna_actual + 1) % self.columns

      fila_actual = (fila_actual + 1) % self.rows

    return contador
  
  def __str__(self):  
    result = ""
    for i in range(self.rows):
      result += "".join(self._data[i])
      result += '\n'
    return result.strip()
      
def caso_prueba() -> bool:
  filas = next_int()   
  columnas = next_int()
  ciclos = next_int()

  if filas + columnas + ciclos == 0:
    return False

  tablero = Tablero.rellenar_tablero(filas, columnas)

  for _ in range(ciclos):
    tablero = Tablero.ciclo(tablero)
  
  print(tablero)
  print("===")

  return True

def main():
  while caso_prueba():
    pass

if __name__ == "__main__":
  main() 