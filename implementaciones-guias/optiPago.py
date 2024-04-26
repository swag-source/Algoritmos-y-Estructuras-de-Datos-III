infinity = float("inf")

def main():
    billetes = [5, 10, 25, 30]
    costo = 40
    print(optiPago(billetes, len(billetes), costo))

def optiPago(billetes, i, j):
    if len(billetes) == 0 and j > 0:
        return (infinity, infinity)
    elif len(billetes) != 0 and j <= 0:
        return (len(billetes), 0)
    else:
        # Remove the ith element from the list of billetes
        opciones = min(
            (optiPago(billetes[:i] + billetes[i+1:], i - 1, j - billetes[i])[0], optiPago(billetes[:i] + billetes[i+1:], i - 1, j - billetes[i])[1] + 1),
            (optiPago(billetes[:i] + billetes[i+1:], i - 1, j)[0], optiPago(billetes[:i] + billetes[i+1:], i - 1, j)[1])
        )
        return opciones

main()
