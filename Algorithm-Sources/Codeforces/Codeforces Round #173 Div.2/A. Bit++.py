import sys
rl = lambda: sys.stdin.readline()

n = int(rl())

x = 0
for i in range(n):
	cmd = rl().strip()
	if cmd == 'X++' or cmd == '++X':
		x += 1
	else:
		x -= 1

print x