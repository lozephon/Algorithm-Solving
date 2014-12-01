n, m, k = [int(x) for x in raw_input().split()]

arr = []
for _ in xrange(n):
    ar = [int(x) for x in raw_input().split()]
    arr.append(ar)

ans = []

for i in xrange(m-1):
    check = False
    tempAns = set()
    for l in xrange(n):
        v = arr[l][i]
        idx = i
        for j in xrange(i+1, m):
            if k == 0 and v > arr[l][j]:
                v = arr[l][j]
                idx = j
            elif k == 1 and v < arr[l][j]:
                v = arr[l][j]
                idx = j
        if idx != i:
            check = True
            if k == 0:
                tempAns.add((i, idx))
            else:
                tempAns.add((idx, i))

    for a, b in tempAns:
        ans.append((a+1, b+1))
        for l in xrange(n):
            if arr[l][a] > arr[l][b]:
                arr[l][a], arr[l][b] = arr[l][b], arr[l][a]


print len(ans)
for a, b in ans:
    print a, b