def h(state):
    res = 0
    for i in range(1, 9):
        if state.index(i) != target.index(i):
            res += 1
    return res


def gen(state, m, b):
    temp = state[:]
    if m == "l":
        temp[b], temp[b - 1] = temp[b - 1], temp[b]
    if m == "r":
        temp[b], temp[b + 1] = temp[b + 1], temp[b]
    if m == "u":
        temp[b], temp[b - 3] = temp[b - 3], temp[b]
    if m == "d":
        temp[b], temp[b + 3] = temp[b + 3], temp[b]
    return temp


def possible_moves(state, visited_states):
    b = state.index(-1)
    d = []
    pos_moves = []
    if b <= 5:
        d.append("d")
    if b >= 3:
        d.append("u")
    if b % 3 > 0:
        d.append("l")
    if b % 3 < 2:
        d.append("r")
    for i in d:
        temp = gen(state, i, b)
        if not temp in visited_states:
            pos_moves.append(temp)
    return pos_moves


def search(src, target, visited_states, g):
    if src == target:
        return visited_states
    visited_states.append(src),
    adj = possible_moves(src, visited_states)
    scores = []
    selected_moves = []
    for move in adj:
        scores.append(h(move) + g)
    min_score = min(scores)
    for i in range(len(adj)):
        if scores[i] == min_score:
            selected_moves.append(adj[i])
    for move in selected_moves:
        if search(move, target, visited_states, g + 1):
            return visited_states
    return 0


def solve(src, target):
    visited_states = []
    res = search(src, target, visited_states, 0)

    if type(res) != type(int()):
        i = 0
        for state in res:
            display(state)
            i += 1
        display(target)
        print("Total moves made: ", i + 1)


def display(state):
    for i in range(9):
        if i % 3 == 0:
            print()
        if state[i] == -1:
            print(state[i], end="\t")
        else:
            print(state[i], end="\t")
    print(end="\n")


# define source and target states
src = [1, 2, 3, -1, 4, 5, 6, 7, 8]
target = [1, 2, 3, 4, 5, 8, -1, 6, 7]

print("A* method to solve 8 Puzzle")

print("Source State: ")
display(src)
print("Target State: ")
display(target)
print("Solving using A*: ")

solve(src, target)
