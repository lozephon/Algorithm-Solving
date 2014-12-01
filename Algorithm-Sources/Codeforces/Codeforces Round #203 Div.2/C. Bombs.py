n = int(raw_input())
bombs = []
nOp = 0
for _ in xrange(n):
    x, y = [int(_) for _ in raw_input().split()]
    if abs(x) and abs(y):
        nOp += 6
    else:
        nOp += 4
    bombs.append([x, y])
bombs.sort(key = lambda(x): abs(x[0])+abs(x[1]))
#print bombs
print nOp
for x, y in bombs:
    if x > 0:
        print 1, abs(x), 'R'
    if x < 0:
        print 1, abs(x), 'L'
    if y > 0:
        print 1, abs(y), 'U'
    if y < 0:
        print 1, abs(y), 'D'
    print 2
    if x > 0:
        print 1, abs(x), 'L'
    if x < 0:
        print 1, abs(x), 'R'
    if y > 0:
        print 1, abs(y), 'D'
    if y < 0:
        print 1, abs(y), 'U'
    print 3
