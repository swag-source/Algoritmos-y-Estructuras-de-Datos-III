import math as mp
def esMasIzquierda(lista):
    if len(lista) == 2:
        if lista[0] > lista[1]:
            return True
        else:
            return False
    izq = lista[:len(lista)//2]  # Corrección en la división de la lista
    der = lista[len(lista)//2:]  # Corrección en la división de la lista
    if esMasIzquierda(izq) and esMasIzquierda(der):  # Llamadas recursivas
        if sum(izq) > sum(der):
            return True
        else:
            return False
    return False  # Agregar una cláusula de retorno por defecto en caso de que ninguna condición se cumpla

print(esMasIzquierda([1,1,1,2]))
