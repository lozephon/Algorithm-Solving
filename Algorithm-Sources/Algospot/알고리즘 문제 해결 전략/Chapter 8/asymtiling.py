import sys
rl = lambda: sys.stdin.readline();

d = [0]*101
d[0] = 0
d[1] = 1
d[2] = 2
for a in range(3, 101):
	d[a] = (d[a-2]+d[a-1]) % 1000000007
for a in range(int(rl())):
	n = int(rl())
	if n == 2:
		print 0
	elif n % 2:
		print (d[n]-d[n/2]+1000000007) % 1000000007
	else:
		print (d[n]-d[n/2]-d[n/2-1]+1000000007) % 1000000007