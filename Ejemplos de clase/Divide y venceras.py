def busquedaBinaria2(A, v, inicio, fin):
    
    if inicio<=fin:
        mitad=(inicio+fin)//2
        if v==A[mitad]:
            return mitad
        if v<A[mitad]:
            return busquedaBinaria2(A,v,inicio,mitad)
        else:
            return busquedaBinaria2(A,v,mitad+1,fin)

    else:
        return -1


A=[10,11,12,13,15,15,16,17,18,19]
v=16
inicio=0
fin=9
indice=-1

busquedaBinaria2(A, v, inicio, fin)
