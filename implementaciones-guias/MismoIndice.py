def mismoIndice(i, lista):
    if len(lista) == 1:
        return lista[0] == 1
    m = len(lista) // 2
    if m + i > lista[m]:
        return mismoIndice(m + i, lista[m:])
    elif m + i < lista[m]:
        return mismoIndice(i, lista[:m])
    else:
        return True

print(mismoIndice(5, [-4, -1, 2, 4, 7]))

