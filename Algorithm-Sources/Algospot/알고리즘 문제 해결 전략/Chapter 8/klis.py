maxInt = 0x7fffffff + 100
c = input()

def evalE(n):
	if e[n] == -1:
		e[n] = 0
		for i in path[n]:
			e[n] += evalE(i)
			if e[n] > maxInt:
				e[n] = maxInt
				return e[n]
	return e[n]

def solve(sList, ansList, k):
	for i in sList:
		if evalE(i) == 1 and evalE(i) == k:
			if path[i][0] == i:
				for x in ansList + [ar[i]]:
					print x,
				print
				return
			solve(path[i], ansList + [ar[i]], k)
			return
		elif evalE(i) >= k:
			solve(path[i], ansList+[ar[i]], k)
			return
		else:
			k -= evalE(i)

for _ in '*'*c:
	n, k = [int(_) for _ in raw_input().split()]
	ar = [int(_) for _ in raw_input().split()]

	d = [1]*n
	p = [None]*n

	for i in xrange(1, n):
		subAr = [(x, y) for x, y in enumerate(d[:i]) if ar[x] < ar[i]]
		if len(subAr) != 0:
			maxV = max(subAr, key=lambda _: _[1])

			p[i] = [x for x, y in subAr if y == maxV[1]]
			if len(p[i]) == 0:
				p[i] = None
			else:
				d[i] = maxV[1]+1

	path = [[] for _ in xrange(n)]

	ans = max(d)
	print ans

	if ans == 1:
		ar.sort()
		print ar[k-1]

	e = [-1]*n
	for i in xrange(n):
		if d[i] == ans:
			path[i].append(i)
			e[i] = 1

	for i in xrange(n-1, -1, -1):
		if p[i] != None and len(path[i]) > 0:
			for idx in p[i]:
				path[idx].append(i)

	sList = [_ for _ in xrange(n) if p[_] == None and len(path[_]) > 0]
	sList.sort(key=lambda _: ar[_])

	solve(sList, [], k)
