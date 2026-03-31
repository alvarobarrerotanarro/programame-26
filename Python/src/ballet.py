def caso_prueba() -> bool:
  ins = [int(z) for z in input().split(" ")]

  if ins[0] == 0:
    return False

  ins.pop(0)  
  i = 0
  j = len(ins) - 1
  imposible  = False

  while not imposible and i < j:
    if ins[i] > ins[i + 1]:
      if (ins[j] > ins[i + 1]):
        imposible = True
      else:
        tmp = ins[i] 
        ins[i] = ins[j]
        ins[j] = tmp

    i += 1
    j -= 1
  
  if not imposible:
    i = 1 
    while (not imposible and i < len(ins)):
      if (ins[i - 1] > ins[i]):
        imposible = True
      i += 1

  print("SI" if not imposible else "NO")

  return True

def main():
  while caso_prueba():
    pass

if __name__ == "__main__":
  main()