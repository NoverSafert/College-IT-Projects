''' Este programa fue realizado por José Damián 
con el propósito de realizar un comesolo.
'''
import random
#esta función me genera un número del 1 al 4 para poder seleccionar un orden de inicio
def random_num():
    num = random.randint(1,4)
    return num

#esta función me regresa el orden de inicio con un número dado
def start_order(n):
    switcher = {
        1: [[" ","0","1","2","3"], ["0","$", "$", "$", "$"], \
        ["1","$", "$", "$", "$"], ["2","$", "$", "$", "_"], \
        ["3","_", "$", "$", "_"]],

        2: [[" ","0","1","2","3"], ["0","_", "$", "$", "_"], \
        ["1","$", "$", "$", "$"], ["2","$", "_", "$", "$"], \
        ["3","$", "$", "$", "$"]],

        3: [[" ","0","1","2","3"], ["0","$", "$", "$", "_"], \
        ["1","$", "$", "$", "$"], ["2","_", "$", "$", "$"], \
        ["3","$", "$", "$", "$"]],

        4: [[" ","0","1","2","3"], ["0","$", "$", "$", "$"], \
        ["1","$", "$", "$", "_"], ["2","$", "$", "_", "$"], \
        ["3","$", "$", "$", "$"]],
    }
    return switcher[n]

#función para imprimir la matriz
def imprimir(orden):
    for ren in range(len(orden)):
        for line in range(len(orden[0])):
            print (orden[ren][line], end=" ")
        print()

#función para limitar los movimientos, checar si son legales
def limites(m, orde, c, r):
    if m == "w" and r > 2:
        if orde[r-1][c] == "$" and orde[r-2][c] == "_":
            return True
        else:
            return False
    elif m == "a" and c > 2:
        if orde[r][c-1] == "$" and orde[r][c-2] == "_":
            return True
        else:
            return False
    elif m == "s" and r < 3:
        if orde[r+1][c] == "$" and orde[r+2][c] == "_":
            return True
        else:
            return False
    elif m == "d" and c < 3:
        if orde[r][c+1] == "$" and orde[r][c+2] == "_":
            return True
        else:
            return False
    else:
        return False

#función para mover la ficha 
def mover(orden, reng, column, m):
    if m == "w":
        orden[reng][column] = "_"
        orden[reng-1][column] = "_"
        orden[reng-2][column] = "$"

    elif m == "a":
        orden[reng][column] = "_"
        orden[reng][column-1] = "_"
        orden[reng][column-2] = "$"

    elif m == "s":
        orden[reng][column] = "_"
        orden[reng+1][column] = "_"
        orden[reng+2][column] = "$"

    else:
        orden[reng][column] = "_"
        orden[reng][column+1] = "_"
        orden[reng][column+2] = "$"
    return orden

# función que realiza todo el juego 
def juego(orden):
    seguir = "s"
    while seguir == "s":
        ren = int(input("renglón? (0 a 3)\n")) +1
        col = int(input("columna? (0 a 3)\n")) +1
        mov = str(input("¿Hacia dónde se quiere mover? (w,a,s,d)\n"))
        mov_legal = limites(mov, orden, col, ren)
        if mov_legal == True:
            orden = mover(orden,ren, col, mov)
        imprimir(orden)
        seguir = str(input("¿Seguir Jugando? ([s] o [n])\n"))
        while seguir != "n" and seguir != "s":
            seguir = str(input("¿Seguir Jugando? ([s] o [n])\n"))
    ganaste(orden)

#función que imprime en la pantalla si ganaste y/o un agradecimiento por jugar
def ganaste(ord):
    cont_espacio = 0
    cont_ficha = 0
    for ren in range(len(ord)):
        for line in range(len(ord[0])):
            if ord[ren][line] == "$":
                cont_ficha += 1
            else:
                cont_espacio += 1
    if cont_ficha == 1 and cont_espacio == 15:
        print ("ganaste")
    print("Gracias por jugar")

#función para iniciar el programa
def main():
    num = random_num()
    orden = start_order(num)
    imprimir(orden)
    juego(orden)

main()