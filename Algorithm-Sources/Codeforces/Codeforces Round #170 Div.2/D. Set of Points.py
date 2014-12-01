import sys
rl = lambda: sys.stdin.readline()

n, m = [int(a) for a in rl().split()]

if m < 5 and m*2 == n:
	print -1
else:
	x = 0
	y = 0
	dx = n
	for i in range(m):
		print x, y
		x += dx
		y += 1
		dx-=1
	if n>m:
		print 0, -1
	x = 0
	y = -1
	dx = n
	for i in range(n-m-1):
		x += dx
		y -= 1
		dx-=1
		print x, y