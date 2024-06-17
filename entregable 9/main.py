infty = float('inf')
import heapq as hq 

def costo(val1, val2) -> int:
    w = 0
    for i in range(len(val1[i])):
        w += min(abs(val1[i] - val2[i]), 10 - abs(val1[i] - val2[i]))
    return w


def PrimMST(grafo, n):
    res = 0
    c = 0
    visitados = [(n) * 0]
    hq = []
    hq.push((0,0))

    while(c < n):
        indice = hq[0][0]
        costo = hq[0][1]
        hq.pop()
        if(not(visitados[indice])):
            visitados[c] = 1
            for i in range(len(grafo[c])):
                hq.push(grafo[c][i])
                



    return res
    




def main():
    cantidadTests = input()
    i = 0
    while(i < cantidadTests):
        # Read input
        input_string = input()
        # Split input string by spaces
        split_input = input_string.split()
        
        # Extract the length of the array
        n = int(split_input[0])
        
        # Extract the numbers and convert them to integers
        claves = [int(x) for x in split_input[1:]]
        
        # calculo el v primero y luego calculo el menor costo del AGM  con prim. ∑ v + costo(AGM)
        valorInicial = infty

        casoCeros = "0000"

        v = infty
        for i in range(len(claves)):
            v = min(valorInicial, costo(int(casoCeros), claves[i]))
        
        grafo = []
        for i in range(n):
            j = i + 1
            for j in range(n):
                grafo[i].append(i,costo(claves[i], claves[j]))
                grafo[j].append(j,costo(claves[i], claves[j]))

        return v + PrimMST(grafo, n)