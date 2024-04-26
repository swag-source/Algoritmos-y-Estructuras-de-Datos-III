import numpy as np

M = np.zeros((6, 13))  # Initialize M with zeros

def sumaDinamica(C, i, j):
    if j < 0 or i < 0:
        return False
    if j == 0:
        return i == 0
    if M[i, j] == 0:  # Check if the value has not been computed yet
        M[i, j] = sumaDinamica(C, i - 1, j) or (sumaDinamica(C, i - 1, j - C[i]) if i < len(C) else False)
    return M[i, j]

print(sumaDinamica([2, 3, 4, 5, 8], 5, 12))
