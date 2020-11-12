import numpy

board = numpy.zeros((3, 3))

for i in range(1, 4):
    for j in range(1, 4):
        board[i - 1][j - 1] = str(i * 10 + j)

"""
[[11. 12. 13.]
 [21. 22. 23.]
 [31. 32. 33.]]
"""

def checkWin(position, x):
    row, col = position

    win = numpy.array([x, x, x])

    # check row
    if (board[row - 1] == win).all():
        return [1, x]

    # check col
    if ([board[0][col - 1], board[1][col - 1], board[2][col - 1]] == win).all():
        return [1, x]

    # check diag
    if [row, col] in [[0, 0], [0, 2], [1, 1], [2, 0], [2, 2]]:

        # check \ diag
        if ([board[0, 0], board[1, 1], board[2, 2]] == win).all():
            return [1, x]

        # check / diag
        if ([board[0, 2], board[1, 1], board[2, 0]] == win).all():
            return [1, x]

    return [0, x]


def inputPosition(x):
    while True:
        pos = int(input("Position:"))

        col = int(pos % 10)
        pos = pos / 10
        row = int(pos % 10)

        if board[row - 1][col - 1] not in [0, 1]:
            board[row - 1][col - 1] = x
            return [row, col]

        else:
            print("Choose an empty position!")


def AIinputPosition(x):
    # check if theres a slot to win
    for row in range(1, 4):
        for col in range(1, 4):
            if board[row - 1][col - 1] not in [0, 1]:
                temp = board[row - 1][col - 1]
                board[row - 1][col - 1] = 0

                if checkWin([row, col], 0) == [1, 0]:
                    return [row, col]
                else:
                    board[row - 1][col - 1] = temp

    # check if theres a slot for the human to win
    for row in range(1, 4):
        for col in range(1, 4):
            if board[row - 1][col - 1] not in [0, 1]:
                temp = board[row - 1][col - 1]
                board[row - 1][col - 1] = 1

                if checkWin([row, col], 1) == [1, 1]:
                    board[row - 1][col - 1] = 0
                    return [row, col]
                else:
                    board[row - 1][col - 1] = temp

    #corner
    for [row, col] in [[0, 0], [0, 2], [1, 0], [1, 2], [2, 0], [2, 2]]:
        if board[row - 1][col - 1] not in [0, 1]:
            board[row - 1][col - 1] = 0
            return [row, col]

    # check center
    for [row, col] in [1, 1]:
        if board[row - 1][col - 1] not in [0, 1]:
            board[row - 1][col - 1] = 0
            return [row, col]

    #empty
    for row in range(1, 4):
        for col in range(1, 4):
            if board[row - 1][col - 1] not in [0, 1]:
                board[row - 1][col - 1] = 0
                return [row, col]


for j in range(1, 10):
    i = j % 2
    print(board)

    if i == 1:
        print("\nHUMAN")
        position = inputPosition(i)
    else:
        print("\nAI")
        position = AIinputPosition(i)

    hasWon = checkWin(position, i)

    if hasWon[0] == 1:
        print(board)
        if hasWon[1] == 1:
            print("HUMAN IS THE WINNER")
        else:
            print("AI IS THE WINNER")
        exit(1)


print("DRAW MATCH")
exit(1)
