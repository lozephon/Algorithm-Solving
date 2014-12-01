def dfs(g, e, k):
	g[k] = True
	for to in e[k]:
		if not g[to]:
			dfs(g, e, to)

import sys
rl = lambda: sys.stdin.readline()

n, m = [int(a) for a in rl().split()]

g = dict()
e = dict()

for i in range(n):
	line = [int(a) for a in rl().split()]
	g['%d'%(i+1)] = False
	e['%d'%(i+1)] = []
	for to in line[1:]:
		if to not in g:
			g[to] = False
		if to not in e:
			e[to] = []
		e['%d'%(i+1)].append(to)
		e[to].append('%d'%(i+1))

if len(g) == n:
	print n
else:
	nVisit = 0
	for k in g:
		if not g[k]:
			nVisit += 1
			dfs(g, e, k)
	print nVisit-1

'''
def gnum(g, n):
	stk = []
	now = n
	while now != g[now]:
		stk.append(now)
		now = g[now]
	for i in stk:
		g[i] = now
	return now

def grouping(g, fr, to):
	if gnum(g, fr) < gnum(g, to):
		g[g[to]] = g[fr]
	else:
		g[g[fr]] = g[to]
#print g, repr(fr), '-', g[fr], to, '-', g[to]

import sys
rl = lambda: sys.stdin.readline()

n, m = [int(a) for a in rl().split()]

g = dict()

for i in range(n):
	line = [int(a) for a in rl().split()]
	g['%d'%(i+1)] ='%d'%(i+1)
	for to in line[1:]:
		if to not in g:
			g[to] = to
		grouping(g, '%d'%(i+1), to)

for k in g:
	gnum(g, k)

s = set()
for k in g:
	s.add(g[k])
print len(s)-1
'''