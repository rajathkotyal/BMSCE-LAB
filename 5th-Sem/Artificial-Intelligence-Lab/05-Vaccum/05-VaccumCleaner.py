def clean(floor,row,col):
    i,j,m,n=row,col,len(floor),len(floor[0])
    goRight=goDown=True
    cleaned = [not any(f) for f in floor]
    while not all(cleaned):
        while any(floor[i]):
            printfloor(floor,i,j)
            if floor[i][j]:
                floor[i][j]=0
                printfloor(floor,i,j)
            if not any(floor[i]):
                cleaned[i]=True
                break
            if j == n-1:
                j-=1
                goRight=False
            elif j==0:
                j+=1
                goRight=True
            else:
                j+=1 if goRight else -1
        if all(cleaned):
            break
        if i == m-1:
            i-=1
            goDown=False
        elif i==0:
            i+=1
            goDown=True
        else:
            i+=1 if goDown else -1
        if cleaned[i]:
            printfloor(floor,i,j)

def printfloor(floor,row,col):
    for r in range(len(floor)):
        for c in range(len(floor[r])):
            if r==row and c==col:
                print(f" *{floor[r][c]}* ", end = '')
            else:
                print(f"  {floor[r][c]}  ", end = '')
        print(end="\n")
    print(end="\n")

floor = [[1, 0, 0],
         [0, 1, 0],
         [1, 0, 1]]

clean(floor, 0, 0)
