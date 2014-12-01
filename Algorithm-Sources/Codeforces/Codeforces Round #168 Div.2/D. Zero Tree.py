import sys
rl = lambda: sys.stdin.readline()

def dfs(n, e, v, now, visited):
	moves = 0
	pos = [[0,0]]
	neg = [[0,0]]

	m = 0
	maxpos = 0
	maxneg = 0
	
	nexts = []
	for next in e[now]:
		if not visited[next]:
			nexts.append(next)
	
	stck = [now]
	while len(nexts) == 1:
		now = nexts[0]
		nexts = []
		stck.append(now)
		visited[now] = True
		for next in e[now]:
			if not visited[next]:
				nexts.append(next)

	for next in nexts:
		visited[next] = True
		rtn = dfs(n, e, v, next, visited)
		moves += rtn[0]
		if rtn[1] > 0:
			pos.append([rtn[1], rtn[2]])
		elif rtn[1] < 0:
			neg.append([rtn[1], rtn[2]])
		maxpos = max(maxpos, rtn[4])
		maxneg = min(maxneg, rtn[5])

	pos.sort(key=lambda o: o[0])
	neg.sort(key=lambda o: o[0], reverse=True)
				
	moves += abs(pos[-1][1])+abs(neg[-1][1])

	vSum = -v[now]
	move = -(pos[-1][0]+neg[-1][0]+v[now])

	stck.reverse()
	#print stck

	m = v[now]-maxpos-maxneg

	if not nexts:
		if v[now] > 0:
			maxpos = v[now]
		else:
			maxneg = v[now]
	else:
		if m > 0:
			maxpos += m
		else:
			maxneg += m

	#print now, v[now], vSum, moves, move, m, maxpos, maxneg
	for p in stck[1:]:
		moves += abs(move)
		move = -(vSum+v[p])
		vSum = -v[p]

		m = v[p]-maxpos-maxneg
		if m > 0:
			maxpos += m
		else:
			maxneg += m
		
		#print p, v[p], vSum, moves, move, m, maxpos, maxneg

	#print now, v[now], vSum, moves, move, m, maxpos, maxneg
	return [moves, vSum, move, m, maxpos, maxneg]

n = int(rl())
e = [[] for a in range(n)]
for i in range(n-1):
	a, b = [int(a)-1 for a in rl().split()]
	e[a].append(b)
	e[b].append(a)
v = [int(a) for a in rl().split()]

visited = [False for a in range(n)]
visited[0] = True
rtn = dfs(n, e, v, 0, visited)
#print rtn[0]+abs(rtn[2])
print rtn[4]-rtn[5]

'''
import sys
rl = lambda: sys.stdin.readline()

def dfs(n, e, v, now, visited):
	moves = 0
	
	pos = [[0,0]]
	neg = [[0,0]]

	nexts = []
	for next in e[now]:
		if not visited[next]:
			nexts.append(next)

	stck = [now]
	while len(nexts) == 1:
		now = nexts[0]
		nexts = []
		stck.append(now)
		visited[now] = True
		for next in e[now]:
			if not visited[next]:
				nexts.append(next)

#	if not nexts:
#		moves += abs(v[now])
	for next in nexts:
		visited[next] = True
		rtn = dfs(n, e, v, next, visited)
		#moves += rtn[0]
		if rtn[1] > 0:
			pos.append([rtn[1], rtn[2]])
		elif rtn[1] < 0:
			neg.append([rtn[1], rtn[2]])

	pos.sort(key=lambda o: o[0])
	neg.sort(key=lambda o: o[0], reverse=True)

	moves += abs(pos[-1][1])+abs(neg[-1][1])

	vSum = -v[now]
	move = -(pos[-1][0]+neg[-1][0]+v[now])
	
	stck.reverse()

	for p in stck[1:]:
		moves += abs(move)
		move = -(vSum+v[p])
		vSum = -v[p]
		print p, v[p], vSum, moves, move

	print now, v[now], vSum, moves, move
	return [moves, vSum, move]

n = int(rl())
e = [[] for a in range(n)]
for i in range(n-1):
	a, b = [int(a)-1 for a in rl().split()]
	e[a].append(b)
	e[b].append(a)
v = [int(a) for a in rl().split()]

visited = [False for a in range(n)]
visited[0] = True
rtn = dfs(n, e, v, 0, visited)
print rtn[0]+abs(rtn[2])
'''
'''
#!/usr/bin/python
from collections import deque

n = int(raw_input())
g = [[] for i in xrange(n)]
for _ in xrange(n-1):
	a, b = [int(i)-1 for i in raw_input().split()]
	g[a].append(b)
	g[b].append(a)

v = map(int, raw_input().split())
root, used, p = [[] for i in xrange(n)], [False] * n, [-1] * n

queue = deque([0])
while len(queue) > 0:
	c = queue.popleft()
	used[c] = True
	for i in g[c]:
		if not used[i]:
			root[c].append(i)
			queue.append(i)
			p[i] = c

pos, neg = [0] * n, [0] * n
for i in xrange(n):
	used[i] = False
	if len(root[i]) == 0:
		queue.append(i)

while len(queue) > 0:
	c = queue.popleft()
	used[c] = True
	
	max1, max2 = 0, 0
	for i in root[c]:
		max1 = max(max1, pos[i])
		max2 = max(max2, neg[i])
	
	pos[c] = max1
	neg[c] = max2
	s = v[c] - max1 + max2
	
	if s > 0:
		pos[c]+=s
	else:
		neg[c]+=-s
	
	print "c : %d, v[c] : %d, max1 : %d, max2 : %d, pos[c] : %d, neg[c] : %d, s : %d" % (c, v[c], max1, max2, pos[c], neg[c], s)
	
	if p[c] != -1:
		canAdd = True
		for i in root[p[c]]:
			if not used[i]:
				canAdd = False
				break
		if canAdd:
			queue.append(p[c])

print (pos[0] + neg[0])
'''