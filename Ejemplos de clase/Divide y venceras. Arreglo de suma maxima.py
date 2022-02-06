def encontrarSubArregloQueCruza(A, inicio, mitad, fin):
    #Procesar de la mitad hacia el inicio.
    sumaMitadAInicioMax=float('-inf')
    suma=0
    for i in range(mitad, inicio-1, -1):
        suma=suma+A[i]
        if suma>sumaMitadAInicioMax:
            sumaMitadAInicioMax=suma
            indiceIzquierdo=i

    #Procesar de la mitad hacia el final.
    sumaMitadAlFinMax=float('-inf')
    suma=0
    for j in range(mitad+1, fin+1, 1):
        suma=suma+A[j]
        if suma>sumaMitadAlFinMax:
            sumaMitadAlFinMax=suma
            indiceDerecho=j
            
    return indiceIzquierdo, indiceDerecho, sumaMitadAInicioMax, sumaMitadAlFinMax


def subArregloSumaMax(A, inicio, fin):
    if inicio==fin:
        return A[inicio]
    else:
        mitad=(inicio+fin)//2
        iI, jI, sumaI=subArregloSumaMax(A, inicio, mitad)
        iD, jD, sumaD=subArregloSumaMax(A, mitad+1, fin)
        iC, jC, sumaC=encontrarSubArregloQueCruza(inicio, mitad, fin)

        if sumaI>sumaD and sumaI>sumaC:
            return iI, jI, sumaI
        elif sumaD>sumaI and sumaD>sumaC:
            return iD, jD, sumaD
        else:
            return iC, jC, sumaC


A={10,-2,5,-3,-4,15,-8}

i, j, sumaMax=subArregloSumaMax(A, 0, (len(A)-1))
        
        

    
