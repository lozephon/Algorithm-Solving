import sys
rl = lambda: sys.stdin.readline()

n = int(rl())
label = ''
x = 0
for i in range(n):
	p1, p2 = [int(t) for t in rl().split()]
	if abs(x+p1) <= abs(x-p2):
		x += p1
		label += 'A'
	else:
		x -= p2
		label += 'G'

if abs(x) <= 500:
	print label
else:
	print -1

