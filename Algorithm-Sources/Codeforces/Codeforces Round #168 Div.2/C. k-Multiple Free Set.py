import sys
rl = lambda: sys.stdin.readline()

n, k = [int(a) for a in rl().split()]
ar = [int(a) for a in rl().split()]
ar.sort()

s = set()
for a in ar:
	s.add(a)

visited = set()
if k > 1:
	rtn = len(ar)
	for a in ar:
		if a not in visited:
			visited.add(a)
			now = a
			nVisited = 1
			while now*k in s:
				visited.add(now*k)
				now = now*k
				nVisited += 1
			rtn -= nVisited/2

else:
	rtn = len(ar)
print rtn