#El siguiente programa utilizará datos de tipo abstracto en Python.
#Modelará el problema de las actividades y el recurso exclusivo.

class Actividad:
    def __init__(self,c,f): #Método constructor de las actividades.
        self.comienzo=c
        self.fin=f          #Declaración de las propiedades de inicio y fin de cada actividad.
    
    def __leq__(self,other): #Less or equal define que representa que una actividad sea mas grande que otra.
        if self.fin<=other.fin:
            return self
        else:
            return other
        



def seleccionVoraz(A):
    A.sort()
    S=[]
    S.append(A[0])

    for i in range(1, len(A)):
        if A[i].comienzo>=S[-1].fin:
            S.append(A[i])                          #S[-1] arroja el ultimo elemento añadido de una lista
    




A=[]

A.append(Actividad(1,3))
A.append(Actividad(2,5))
A.append(Actividad(4,7))
A.append(Actividad(1,8))
A.append(Actividad(5,9))
A.append(Actividad(8,10))
A.append(Actividad(9,11))
A.append(Actividad(11,14))
A.append(Actividad(13,16))

