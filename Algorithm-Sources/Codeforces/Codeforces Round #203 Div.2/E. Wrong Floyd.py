#20131018 Non-marked를 사이에 두고 나머지끼리 edge를 다 이어버리는 식으로 구현. NM이 하나일때 최고 n*(n-1)/2 - (n-2)개 가능. NM 하나당 가능한 edge 추가

n, m, k = [int(_) for _ in raw_input().split()]
a = [int(_) for _ in raw_input().split()]
v = [_ for _ in range(1, n+1) if _ not in a]

def setAdd(e, a, b):
    e.add((min(a,b), max(a,b)))

if k == n:
    print -1
    exit()

maxEdge = n*(n-1)/2 - (n-2) + len(v) - 1

if maxEdge < m:
    print -1
    exit()

c = set()
for to in a + v[1:]:
    setAdd(c, v[0], to)

m -= n - 1

e = set()

vs = a[1:] + v[1:]

for i in range(len(vs)):
    for j in range(i+1, len(vs)):
        setAdd(e, vs[i], vs[j])

for to in v[1:]:
    setAdd(e, a[0], to)

for edge in c:
    print edge[0], edge[1]

e = list(e)
for i in range(m):
    print e[i][0], e[i][1]




