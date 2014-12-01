def compare(x, y):
	if isBig[(x,y)]:
		return -1
	return 1

def dfs(start, now, isVisited, value):
	isVisited[now] = True
	for next in e[now]:
		if not isVisited[next[0]]:
			newV = value
			newV *= next[1]
			newV /= next[2]
			if newV == float(1):
				isBig[(v[start], v[next[0]])] = v[start] < v[next[0]]
			else:
				isBig[(v[start], v[next[0]])] = newV < float(1)
			dfs(start, next[0], isVisited, newV)

nCase = int(raw_input())

for t in range(nCase):
	global n, nV, v, e, names, isBig
	n = int(raw_input())
	nV = 0
 	v = {}
	e = [[] for row in range(20)]
	names = set()
	isBig = {}
	
	for i in range(n):
		line = raw_input().split()
		if line[0] not in names:
			names.add(line[0])
			v[line[0]] = nV
			v[nV] = line[0]
			nV+=1
		if line[2] not in names:
			names.add(line[2])
			v[line[2]] = nV
			v[nV] = line[2]
			nV+=1
		
		e[v[line[0]]].append([v[line[2]], float(line[1]), float(line[3])])
		e[v[line[2]]].append([v[line[0]], float(line[3]), float(line[1])])

#		for name in v:
#			print name, v[name]
#		for row in e[:nV]:
#			print row
		for name in names:
			isVisited = [False for row in range(nV)]
			dfs(v[name], v[name], isVisited, float(1))

#		for isbig in isBig:
#			print isbig, isBig[isbig]

	for name in sorted(list(names), cmp=compare):
		print name,
	if t != nCase-1:
		print