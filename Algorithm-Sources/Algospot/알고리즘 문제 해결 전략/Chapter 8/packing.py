# 7/12 자꾸 시간 초과 뜨는데 뭐가 문젠지 모르겠다. 정답중엔 1500ms로 통과한 코드가 있는데 ??
import sys
rl = lambda: sys.stdin.readline()

for _ in '*'*input():
	n, w = (int(a) for a in raw_input().split())
	items = []
	for _ in '*'*n:
		a, b, c = raw_input().split()
		items.append((a, int(b), int(c)))

	d = [[-1]*n for _ in '*'*(w+1)]
	p = [[-1]*n for _ in '*'*(w+1)]

	d[0][0] = 0
	p[0][0] = 0
	d[items[0][1]][0] = items[0][2]
	p[items[0][1]][0] = 0
	
	ans = 0
	ansPos = 0
	for i in xrange(1, n):
		for j in xrange(w+1):
			d[j][i] = d[j][i-1]
			p[j][i] = j
			if j-items[i][1] >= 0 and d[j-items[i][1]][i-1] != -1:
				if d[j-items[i][1]][i-1]+items[i][2] > d[j][i]:
					d[j][i] = d[j-items[i][1]][i-1]+items[i][2]
					p[j][i] = j-items[i][1]
			if ans < d[j][i]:
				ansPos = j
				ans = d[j][i]

	ansSet = []
	nowX = ansPos
	nowY = n-1
	for nowY in xrange(n-1, -1, -1):
		if p[nowX][nowY] != nowX:
			ansSet.append(nowY)
		nowX = p[nowX][nowY]
		nowY -= 1

	print ans, len(ansSet)
	for i in ansSet:
		print items[i][0]
