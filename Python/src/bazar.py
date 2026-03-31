from sys import stdin

def next_int() -> int:
  cont = True
  num_str = ""
  ch = ""

  while cont:
    ch = stdin.read(1)
    if ch.isnumeric():
      num_str += ch
    else:
      cont = False
  
  return int(num_str)

def caso_prueba() -> bool:
  libras = next_int()
  precio_dolar = next_int()
  precio_euro = next_int()

  if libras + precio_dolar + precio_euro == 0:
    return False

  billetes_dolar = libras // precio_dolar 
  billetes_libra = 0
  pagado = False

  while not pagado and billetes_dolar <= 10_000:
    pago_libras = billetes_dolar * precio_dolar 
    vueltas_libras = pago_libras - libras

    if vueltas_libras >= 0 and vueltas_libras % precio_euro == 0:
        billetes_libra = vueltas_libras // precio_euro
        pagado = True
    else:
      billetes_dolar += 1 
  
  print(f"{billetes_dolar} {billetes_libra}")

  return True

def main():
  while caso_prueba():
    pass

if __name__ == "__main__":
  main()
