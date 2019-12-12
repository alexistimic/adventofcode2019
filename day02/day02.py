#!/usr/bin/python3

import sys

def    addition(tab, index):

    first = tab[index + 1]
    second = tab[index + 2]
    third = tab[index + 3]
    first = tab[first]
    second = tab[second]
    tab[third] = first + second
    return(tab)

def    multiplication(tab, index):

    first = tab[index + 1]
    second = tab[index + 2]
    third = tab[index + 3]
    first = tab[first]
    second = tab[second]
    tab[third] = first * second
    return(tab)

### TODO - Factorize ####
def    part2():
    index = 0
    tab = []
    tab1 = []
    x = 2
    y = 2

    with open('input.txt') as f:
        tab = [int(item) for item in f.readline().split(",")]
    tab[1] = x
    tab[2] = y
    tab1 = tab.copy()
    while (x < 100 and y < 100):
        while (tab[index] != 99) and (index < len(tab)):
            if (tab[index] == 1):
                tab = addition(tab, index)
            if (tab[index] == 2):
                tab = multiplication(tab, index)
            try:
                index = index + 4
                gotdata = tab[index]
            except IndexError:
                print(tab)
                sys.exit()
        if (tab[0] == 19690720):
            break
        tab = tab1.copy()
        if (y == 99 and x != 99):
            x = x + 1
            y = 0
        elif (y != 99):
            y = y + 1
        else:
            break
        tab[2] = y
        tab[1] = x
        index = 0
    print(tab)

if "__name__" == "__main__":
    part1()
    part2()
