
def caso_prueba():
  ins = tuple(float(z) for z in input().split(" "))
  print(round(ins[0] * ins[1] / 100))

def main():
  n = int(input())
  for _ in range(n):
    caso_prueba()

if __name__ == "__main__":
  main()