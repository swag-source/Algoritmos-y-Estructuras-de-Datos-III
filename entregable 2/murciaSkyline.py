# Creamos una clase para cada Skyline el cual tendrá edificios dentro.
from typing import List


class SkyLine:
    def __init__(self, cantidadEdificios, caso):
        self.edificios = []
        self.caso = caso

    def agregar_edificio(self, edificio):
        self.edificios.append(edificio)

# Creamos la clase edificio para almacenar el alto y el ancho individualmente.
class Edificio:
    def __init__(self, altura, ancho):
        self.altura = altura
        self.ancho = ancho

## fin de las clases ##

## principo del código main ##
def main():
    # La primera línea del input es la cantidad de casos de test
    cantidadCasos = int(input())

    # inicializamos la lista de todos los skylines
    skyLinesTotales = [] #[Skyline1, ..., SkylineN]

    for caso in range(cantidadCasos):
        # La primera línea del input del caso, es la cantidad de edificios en el skyline
        cantidadEdificios = int(input())

        alturas = []
        anchos = []

        # instancia del skyline actual
        skyLinesTotales.append(SkyLine(cantidadEdificios, caso + 1))

        datos_altura_linea = input().split()
        datos_ancho_linea = input().split()

        # Iteración sobre la cantidad de edificios que tenemos
        for j in range(cantidadEdificios):
            alturas.append(int(datos_altura_linea[j]))
            anchos.append(int(datos_ancho_linea[j]))
            edif = Edificio(alturas[j], anchos[j])
            skyLinesTotales[caso].agregar_edificio(edif)

        # esto me va a devolver algo del estilo:
        # skyLinesTotales = [[edificio1, ..., edificioM] = skyLine0, ..., (edificio1, ..., edificioM') = skyLine[#cantidadDeCasos]]
    
    # una vez que terminamos de tomar el input, podemos trabajar con el arreglo de skylines.
    for i in range(cantidadCasos):
        int maxCreciente = maximoCreciente(skyLinesTotales[i])
        int maxDecreciente = maximoDecreciente(skyLinesTotales[i])

        if(maxCreciente > maxDecreciente):
            return 0
        else:
            return 1


def maximoCreciente(Skyline : List[SkyLine]) -> int:
    suma = 0
    for i in range(1, len(SkyLine)):
        for j in range(i):
            if (Skyline[i].altura > Skyline[j].altura):
                suma += Skyline[i].ancho







        

def mayorSubseqCreciente(skyline : List[Edificio]) -> int:
    return 0


def mayorSubseqDecreciente(skyline : List[Edificio]) -> int:
    return 0