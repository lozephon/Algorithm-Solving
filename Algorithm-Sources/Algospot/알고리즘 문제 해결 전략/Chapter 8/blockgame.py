from itertools import izip

n = 5
c = int(input())

def rotate(i, j, type):
    if type == 0:
        return i*n + (n-1) - j
    elif type == 1:
        return ((n-1)-i)*n + j
    elif type == 2:
        return ((n-1)-i)*n + (n-1) - j
    elif type == 3:
        return j*n + i
    elif type == (n-1):
        return ((n-1)-j)*n + i
    elif type == n:
        return j*n + (n-1) - i
    elif type == 6:
        return ((n-1)-j)*n + (n-1) - i
    return i*n + j

dx = [[0, 1], [0, 0], [0, 1, 1], [1, 1, 0], [0, 1, 0], [0, 1, 0]]
dy = [[0, 0], [0, 1], [0, 0, 1], [0, 1, 1] ,[0, 1, 1], [0, 0, 1]]

moves = []

def makeMoves():
    for i in xrange(n):
        for j in xrange(n):
            for a, b in izip(dx, dy):
                state = 0
                poss = True
                for k in xrange(len(a)):
                    ii = i + a[k]
                    jj = j + b[k]
                    if ii >= n or jj >= n:
                        poss = False
                        break
                    state |= (1 << (ii*n + jj))
                if poss:
                    moves.append(state)

def solve(state):
    '''
    states = [0]*8
    for i in range(n):
        for j in range(n):
            if (state & (1 << (i*n + j))):
                for k in xrange(8):
                    states[k] |= 1 << rotate(i, j, k)
    
    for s in states:
        if s in d: return d[s]
    / 8 vs * 25
    '''
    
    if d[state] != -1: return d[state]
    
    for move in moves:
        if not (state & move):
            if not solve(state | move):
                d[state] = 1
                return d[state]

    d[state] = 0
    return d[state]

def printState(state):
    for i in xrange(n):
        for j in xrange(n):
            print 1 if (state & (1 << (i*n + j))) else 0,
        print
    print

d = [-1]*(1<<25)
makeMoves()
for _ in xrange(c):
    state = 0
    for _ in xrange(n):
        for ch in raw_input():
            state = (state << 1) + (1 if ch == '#' else 0)

    print 'WINNING' if solve(state) else 'LOSING'
