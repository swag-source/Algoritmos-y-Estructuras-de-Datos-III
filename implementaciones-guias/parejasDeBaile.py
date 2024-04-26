def parejasDeBaile(a,b):
    sol = 0
    ## introduzco el caso base
    if(len(a) == 0 or len(b) == 0):
        return 0
    
    # determinar la recursión:
    if(abs(a[0] - b[0]) <= 1):
        sol = 1 + parejasDeBaile(a[1:], b[1:])
    else:
        if(a[0] < b[0]):
            # hago el "tail" de la lista a y lo comparo con la b original
            sol = parejasDeBaile(a[1:], b)
        else:
            # hago el "tail" de la lista b y lo comparo con la a original
            sol = parejasDeBaile(a, b[1:])

    return sol

print(parejasDeBaile([1,4,5,8,10], [2, 3, 7]))


# función recursiva:
#                     |  0   si |a| = 0 o |b| = 0
#                     |
#                     |  1 + parejasDeBaile(tail(a), tail(b))   si |a_{0} - b_{0}| <= 1
#parejasDeBaile(a,b)= | 
#                     |  parejasDeBaile(tail(a), b) si a_{0} < b_{0}
#                     |
#                     |  parejasDeBaile(a, tail(b)) si no

    
