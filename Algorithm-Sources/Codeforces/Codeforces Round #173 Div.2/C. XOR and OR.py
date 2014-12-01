import sys
rl = lambda: sys.stdin.readline()

a = rl().strip()
b = rl().strip()

asum = sum([1 if t == '1' else 0 for t in a])
bsum = sum([1 if t == '1' else 0 for t in b])
if len(a) == len(b) and asum > 0 and bsum > 0:
	print 'YES'
elif a == b:
	print 'YES'
else:
	print 'NO'