#!/usr/bin/python3.5


def    part1():

    tab = []
    y = 0

    f = open('input.txt')
    for line in f:
        tab.append(int(line))
    y = sum([y + int(value / 3 - 2) for value in tab])
    print(y)

def    part2():

    tab = []
    y = 0

    f = open('input.txt')
    for line in f:
        tab.append(int(line))
    for value in tab:
        while (int(value / 3 - 2) > 0):
            x = int(value / 3 - 2)
            y = y + x
            value = x
    print(y)

if __name__== "__main__":
    part1()
    part2()
