def search(n, now, selected, fSet, l):
	if now == n:
		#print l
		return 1
	
	if selected[now]:
		return search(n, now+1, selected, fSet, l)
	rtn = 0	
	for next in range(now+1, n):
		if not selected[next] and (now, next) in fSet:
			selected[now] = True
			selected[next] = True
			rtn += search(n, now+1, selected, fSet, l+[(now, next)])
			selected[now] = False
			selected[next] = False
	
	return rtn
			
import sys
rl = lambda: sys.stdin.readline()

nCase = int(rl())
for case in range(nCase):
	n, m = [int(num) for num in rl().strip().split()]
	fSet = set()
		
	line = rl().strip().split()
	if line:
		for fr, to in zip(line[0::2], line[1::2]):
			fSet.add((int(fr), int(to)))
			fSet.add((int(to), int(fr)))
	#print fSet
	print search(n, 0, [False]*n, fSet, [])