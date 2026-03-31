
def caso_prueba() -> None:
  num = int(input())
  print(f"{(num + 1) // 2} {num // 2}")

def main():
  casos = int(input())
  for _ in range(casos):
    caso_prueba()

if __name__ == "__main__":
  main()