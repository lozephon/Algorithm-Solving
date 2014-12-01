import sys
rl = lambda: sys.stdin.readline()

nMax = 101

d = [[-1] * nMax for a in range(nMax)]
for i in range(1, nMax):
	d[i][i] = 1

ans = [1]*nMax

for n in range(2, nMax):
	for k in range(1, n):
		d[n][k] = 0
		for i in range(1, n-k+1):
			#print '(%d, %d) (%d, %d)' % (n, k, n-k, i)
			d[n][k] += d[n-k][i]*(abs(k-i)+1+(min(k, i)-1)*2)
		ans[n] += d[n][k]
	ans[n] %= 10000000
'''
for i in range(1, nMax):
	for j in range(1, nMax):
		print d[i][j],
	print
'''
for a in range(int(rl())):
	num = int(rl())
	print ans[num]

# 생각해보니 row는 필요없음. 복잡도는 O(n^3)