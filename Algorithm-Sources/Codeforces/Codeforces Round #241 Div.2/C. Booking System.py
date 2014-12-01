n = int(raw_input())
ar = []
for i in xrange(n):
    c, p = [int(_) for _ in raw_input().split()]
    ar += [[p, c, i+1]]
k = int(raw_input())
t = [[int(_), i+1] for i, _ in enumerate(raw_input().split())]

ar.sort(reverse=True)
t.sort()

print ar
print t

def bi(num, t):
    bot = 0
    top = len(t)-1
    while bot < top - 1:

        mid = (top+bot)/2
        if t[mid] < num:
            bot = mid
        else:
            top = mid
    return top

ans = []
ansSum = 0

for i in xrange(n):
    idx = bi(ar[i][1], t)
    ans += [[ar[i][2], t[idx]]]

print ans