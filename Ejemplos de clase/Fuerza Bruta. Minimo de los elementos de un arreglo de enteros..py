def elementoMinimo(A):
    minimo=A[0]

    for i in range(1, len(A)):
        if A[i]<minimo:
            minimo=A[i]

    return minimo
            


A=[5, -2, 20, 7, 14, 2]
minimo=elementoMinimo(A)
print(A)
print(minimo)

