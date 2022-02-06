def sumaRecursivaArreglo(A, inicio, fin):
    if inicio == fin:
        return A[inicio]
    else:
        mitad=(inicio+fin)//2
        return sumaRecursivaArreglo(A, inicio, mitad)+ sumaRecursivaArreglo(A, mitad+1, fin)

    
A=[-2, 7, -10, 6]

sumaTotal=sumaRecursivaArreglo(A, 0, len(A)-1)

print(sumaTotal)


