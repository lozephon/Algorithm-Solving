m, n = [int(_) for _ in raw_input().split()]
cs = [0]*n

for _ in xrange(m):
    ts = [int(_) for _ in raw_input().split()]
    cs[0] += ts[0]
    for i in xrange(1,n):
        cs[i] = max(cs[i], cs[i-1]) + ts[i]
    print cs[n-1],
print