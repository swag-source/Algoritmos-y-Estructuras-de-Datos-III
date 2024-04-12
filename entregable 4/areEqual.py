def main():
    palabra1 = input()
    palabra2 = input()
    if palabra1 == palabra2 or areEqual(palabra1, palabra2):
        print ("YES")
    else:
        print ("NO")

def areEqual(a, b):
    if len(a) == 1 and len(b) == 1:
        if a == b:
            return True
        else:
            return False
    else:
        if len(a) % 2 == 0:
            mitad = len(a) // 2
            a1, a2 = a[:mitad], a[mitad:]
            b1, b2 = b[:mitad], b[mitad:]
            return (areEqual(a1, b2) and areEqual(a2, b1) or areEqual(a1, b1) and areEqual(a2, b2))
        else:
            if(a == b):
                return True
            else:
                return False
        
if __name__ == "_main_":
    main()