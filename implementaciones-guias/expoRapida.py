import math as m
def expoRapida(a : int, b: int):
    if b == 1:
        return a
    elif b == 0:
        return 1
    else:
        if b%2 == 0:
            return expoRapida(a, b//2) * expoRapida(a, b//2)
        else:
            tmp = expoRapida(a, b//2) * expoRapida(a, b//2)
            return a * tmp

print(expoRapida(5, 3))
print(expoRapida(5, 4))
