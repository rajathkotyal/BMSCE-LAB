"""
Rajath MK - 1BM18CS079
AI Lab Test 1
Batch - B2
Program Name : Implement Tic-tac-toe using 2-agent algorithm (Computer Vs Computer)
"""

import random

table = [" "] * 9
winStates = [ [0,1,2] ,[0,3,6], [6,7,8] , [2,4,6] ,  [1,4,7] ,  [3,4,5] ,  [2,5,8], [0,4,8]  ]

def DisplayTable():

    print("", table[0], " │", table[1], " │ ", table[2], " ")
    print("────┼────┼────")
    print("", table[3], " │", table[4], " │ ", table[5], " ")
    print("────┼────┼────")
    print("", table[6], " │", table[7], " │ ", table[8], " ")


def WinDraw(computer):
    for x in winStates:
        if table[x[0]]==table[x[1]] and table[x[1]]==table[x[2]] and table[x[0]]!=" ":
            print("\n"+computer+" has won the game")
            return 0
    for i in table:
        if i==" ":
            return 1

    print("\nIts a Draw Match")

def compWin(computer):
    n=-1

    for x in winStates:
        if (table[x[0]]==computer and table[x[1]]==computer) and checkPos(x[2])==1:
            n = x[2]
            break
        elif (table[x[1]]==computer and table[x[2]]==computer) and checkPos(x[0])==1:
            n = x[0]
            break
        elif (table[x[0]]==computer and table[x[2]]==computer) and checkPos(x[1])==1:
            n = x[1]
            break

    return n

def checkPos(pos):
    if(table[pos] == " "):
        return 1
    else:
        return 0

def block(computer):
    n = -1

    for x in winStates:
        if (table[x[0]]==computer and table[x[1]]==computer) and checkPos(x[2])==1:
            n = x[2]
            break
        elif (table[x[1]]==computer and table[x[2]]==computer) and checkPos(x[0])==1:
            n = x[0]
            break
        elif (table[x[0]]==computer and table[x[2]]==computer) and checkPos(x[1])==1:
            n = x[1]
            break

    return n

def Try(computer):
    n = -1

    for x in winStates:
        if table[x[0]]==computer and checkPos(x[2]==1) and checkPos(x[1]==1):
            if checkPos(x[2]==1):
                n = x[2]
                break
            elif checkPos(x[1]==1):
                n = x[1]
                break
        elif table[x[1]]==computer and checkPos(x[0]==1) and checkPos(x[2]==1):
            if checkPos(x[0]==1):
                n = x[0]
                break
            elif checkPos(x[2]==1):
                n = x[2]
                break
        elif table[x[2]]==computer and checkPos(x[0]==1) and checkPos(x[1]==1):
            if checkPos(x[0]==1):
                n = x[0]
                break
            elif checkPos(x[1]==1):
                n = x[1]
                break
    return n

def randomPos():
    while(1):
        n = random.randint(0,8)
        if checkPos(n)==1:
            return n


def algoPlay(x,y):
    n = compWin(x)

    if n==-1:
        n = block(y)

    if n==-1:
        n = Try(x)

    if n==-1:
        n = randomPos()

    print("->Symbol Inserted at : ",end="")
    print(n)
    table[n] = x


def play():
    DisplayTable()
    flag = 1
    while(flag):
        print("\n1st Computer Playing")
        algoPlay("X","O")
        DisplayTable()
        if WinDraw("Computer 1") == 1:
            print("\n2nd Computer Playing")
            algoPlay("O","X")
            DisplayTable()
            if WinDraw("Computer 2") == 0:
                flag = 0
        else:
            flag = 0

if __name__ == "__main__":
    play()
