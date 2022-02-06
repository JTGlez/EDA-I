def sumaAcumulada(A,n):
    S=[]
    S.append(A[0]) #Introduciendo el primer elemento al arreglo auxiliar.
    for i in range(1, n):
        S.append(A[i]+S[i-1]) #Introduccion del resto de elementos.
    return S
    
def encontrarArregloMax(A,n):
    S=sumaAcumulada(A,n)
    
    iMax=0
    jMax=0
    sumaMax=A[0]

    for i in range(0, n):
        for j in range (i,n):
            sumaIJ=S[j]-S[i]+A[i]
            if(sumaIJ>sumaMax):
                sumaMax=sumaIJ
                iMax=i
                jMax=j
        
    
    return iMax, jMax, sumaMax



A=[1,-2,3,4,-8,10]
suma=sumaAcumulada(A, len(A))
print(A)
print(suma)
(i,j,sumaMax)=encontrarArregloMax(A,len(A))

print(i)
print(j)
print(sumaMax)
