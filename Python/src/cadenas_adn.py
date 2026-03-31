from typing import TypeVar, Generic

T = TypeVar("T")
class Stack(Generic[T]):
  def __init__(self):
    self._head = 0
    self._data: list[T] = [] 
  
  def size(self) -> int:
    return self._head

  def top(self) -> T:
    if self.size() == 0:
      raise Exception("Empty stack")

    return self._data[self._head - 1]

  def push(self, e: T) -> None:
    # Redimensionar
    if self._head >= len(self._data):
      self._data.append(e)
    else: # Colocar en la pos
      self._data[self._head] = e
    
    self._head += 1
  
  def pop(self) -> None:
    self._head -= 1
  
  def __str__(self):
    contenido = "" 
    for i in range(self._head):
      contenido += str(self._data[i]) 
    return f"Stack[{contenido}]" 
  

def longitud_cadena(cadena: str) -> int:
  sumas: Stack[int] = Stack() 
  factor = 1 
  sumas.push(0)

  for ch in cadena: 
    if ch.isalpha():
      valor = sumas.top()
      sumas.pop()
      sumas.push(valor + 1)
    elif ch.isdigit():
      factor = int(ch)
      sumas.push(0) 
    elif ch == "]":
      sumando = sumas.top() * factor
      sumas.pop()

      valor = sumas.top()
      sumas.pop()
      sumas.push(valor + sumando)

  return sumas.top()

def caso_prueba() -> bool:
  cadena: str = ""

  try:
    cadena = input()
  except EOFError:
    return False 
  
  print(longitud_cadena(cadena)) 
  
  return True


def main():
  while  caso_prueba():
    pass

if __name__ == "__main__":
  main()