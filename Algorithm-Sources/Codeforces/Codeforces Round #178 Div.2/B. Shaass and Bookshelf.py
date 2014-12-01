import sys
rl = lambda: sys.stdin.readline()

n = int(rl())

b = []
for i in range(n):
	w, t = [int(t) for t in rl().strip().split()]
	b.append((w,t))

#b.sort(key=lambda x: (float(x[1])/x[0], -x[0]))
b.sort(key=lambda x: (x[1]-(x[0]-1), -x[0]))
#print b
s = sum([x[0] for x in b])
h = 0
now = 0
while s-b[now][0] >= h+b[now][1]:
	s -= b[now][0]
	h += b[now][1]
	now += 1

print s
