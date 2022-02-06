"""Algoritmo de fuerza bruta: Si bien la idea en general la comprendo, la implementación me parece confusa; aunque eso también es atribuible a mi relativa inexperiencia con Python. Como comentario adicional cabe remarcar que al escribir "AAA" como contraseña, el programa arroja un error; como ya se lo había comentado. 
"""

from string import ascii_letters , digits
from itertools import product

#Concatenar letas y dígitos en una sola cadena
caracteres = ascii_letters+digits

def buscador(con):
    
    #Archivo con todas las combinaciones generadas
    archivo = open("combinaciones.txt", "w")
    
    if 3<= len(con) <= 4:
        for i in range(3,5):
            for comb in product(caracteres, repeat = i):
                #Se utiliza join() para concatenar los caracteres regresado por la función product().
                #Como join necesita una cadena inicial para hacer la concatenación, se pone una cadena vacía
                #al principio
                prueba = "".join(comb)
                #Escribiendo al archivo cada combinación generada
                archivo.write( prueba + "\n"  )
                if  prueba == con:
                    print('Tu contraseña es {}'.format(prueba))
                    #Cerrando el archivo
                    archivo.close()
                    break
    else:
        print('Ingresa una contraseña que contenga de 3 a 4 caracteres')
from time import time
t0 = time() 
con = 'H0l4'
buscador(con)

"""Algoritmo ávido: Este código me pareció mucho más entendible que el anterior. Como se comentó en clase, la solución que puede brindar este algoritmo no siempre es la más óptima en casos específicos.

"""

def cambio(cantidad, denominaciones):
    resultado = []
    while (cantidad > 0):
        if (cantidad >= denominaciones[0]):
            
            num = cantidad // denominaciones[0]
            cantidad = cantidad - (num * denominaciones[0])
            resultado.append([denominaciones[0], num])
        denominaciones = denominaciones[1:]  #Se va consumiendo la lista de denominaciones
    return resultado
#Pruebas del algoritmo
print (cambio(1000, [500, 200, 100, 50, 20, 5, 1]))

print (cambio(500, [500, 200, 100, 50, 20, 5, 1]))

print (cambio(300, [50, 20, 5, 1]))

print (cambio(200, [5]))

print (cambio(98, [50, 20, 5, 1]))

print (cambio(98, [5, 20, 1, 50]))


"""Insertion Sort: El código me pareció completamente ilegible en un inicio, principalmente a la ambiguedad que tiene en su escritura. La explicación en clase ayudó mucho a comprender la idea general del algoritmo, aunque remarco, la implementación hecha me parece muy complicada de entender por su pobre claridad.

"""

def insertionSort(n_lista):
    for index in range(1,len(n_lista)):
        actual = n_lista[index]
        posicion = index
        print("valor a ordenar = {}".format(actual))
        while posicion>0 and n_lista[posicion-1]>actual:
            n_lista[posicion]=n_lista[posicion-1]
            posicion = posicion-1           
        n_lista[posicion]=actual
        print(n_lista)
        print() 
    return n_lista
# Datos de entrada
lista = [21, 10, 0, 11, 9, 24, 20, 14, 1]
print("lista desordenada {}".format(lista))
insertionSort(lista)
print("lista ordenada {}".format(lista))


"""Quick Sort (Divide y vencerás): Este algoritmo fue más sencillo de comprender que el anterior; aunque sigue sufriendo de tener una implementación de variables con nombres ambiguos. Personalmente, esta forma de resolver el problema del arreglo me agradó bastante por su gran eficiencia computacional y por partir de una idea recursiva y bastante simple. 

"""

def quicksort(lista):
    quicksort_aux(lista,0,len(lista)-1)

def quicksort_aux(lista,inicio, fin):
    if inicio < fin:

        pivote = particion(lista,inicio,fin)

        quicksort_aux(lista, inicio, pivote-1)
        quicksort_aux(lista, pivote+1, fin)
def particion(lista, inicio, fin):
    #Se asigna como pivote en número de la primera localidad
    pivote = lista[inicio]
    print("Valor del pivote {}".format(pivote))
    #Se crean dos marcadores 
    izquierda = inicio+1
    derecha = fin
    print("Índice izquierdo {}".format(izquierda))
    print("Índice derecho {}".format(derecha))

    
    bandera = False
    while not bandera:
        while izquierda <= derecha and lista[izquierda] <= pivote:
            izquierda = izquierda + 1
        while lista[derecha] >= pivote and derecha >=izquierda:
            derecha = derecha -1
        if derecha < izquierda:
            bandera= True
        else:
            temp=lista[izquierda]
            lista[izquierda]=lista[derecha]
            lista[derecha]=temp
            
    print(lista)


    temp=lista[inicio]
    lista[inicio]=lista[derecha]
    lista[derecha]=temp
    return derecha
lista = [21, 10, 0, 11, 9, 24, 20, 14, 1]
print("lista desordenada {}".format(lista))
quicksort(lista)
print("lista ordenada {}".format(lista))