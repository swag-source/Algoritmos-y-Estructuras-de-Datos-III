import numpy as np
import math

A = [[2, 7, 4, 8], 
    [1, 2, 4, 9],
    [3, 9, 1, 8],
    [5, 6, 2, 4]] 

def sumaNmatriz(A, n):
    if(n == 1):
        return A
    if(n == 2):
        return sumaNmatriz(A,1) + np.power(A, 2)
    else:
        if(n % 2 == 0):
            return sumaNmatriz(A, n/2) * sumaNmatriz(A, n/2) + sumaNmatriz(A, n - 1)
        else:
            return sumaNmatriz(A, n//2) * sumaNmatriz(A, (n+1)//2) + sumaNmatriz(A, n - 1)

