#Implementación recursiva del algoritmo de Búsqueda Binaria para un arreglo ordenado.

def busquedaBinaria(A, v, inicio, fin):
  #La función Búsqueda Binaria  recibe un arreglo, el valor buscado, el indice inicial de arreglo y su posición final (n-1).
  
   if inicio<=fin:
     #Si se recibe un arreglo de más de un elemento, se procede a preguntar si el valor buscando se encuentra en el indice mitad.
       mitad=(inicio+fin)//2
       if v==A[mitad]:
           return mitad
    #Cuando la condición anterior no se cumple, se procede a preguntar si el valor buscado es menor al elemento ubicado en A[mitad]. Si lo anterior es cierto, se divide el arreglo por la mitad y se comienza a buscar recursivamente en la parte izquierda del arreglo partido.
       if v<A[mitad]:
           return busquedaBinaria(A,v,inicio,mitad)
       else:
    #Caso contrario, se toma la parte derecha del arreglo partido y se procede a seguir buscando recursivamente.
           return busquedaBinaria(A,v,mitad+1,fin)
 
   else:
    #Si el arreglo ingresado no posee el valor solicitado, la función devuelve el valor -1.
       return -1
 
 
A=[10,11,12,13,15,15,16,17,18,19]
v=19
inicio=0
 
indice=busquedaBinaria(A, v, inicio, len(A)-1)
print("El elemento buscado se encuentra en el índice:", indice)
