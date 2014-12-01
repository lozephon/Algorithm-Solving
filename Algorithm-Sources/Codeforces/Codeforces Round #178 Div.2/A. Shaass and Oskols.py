import sys
rl = lambda: sys.stdin.readline()

n = int(rl())
a = [0] + [int(t) for t in rl().strip().split()] + [0]
m = int(rl())

for i in range(m):
	x, y = [int(t) for t in rl().strip().split()]
	a[x-1] += y-1
	a[x+1] += a[x]-y
	a[x] = 0

for t in a[1:-1]:
	print t