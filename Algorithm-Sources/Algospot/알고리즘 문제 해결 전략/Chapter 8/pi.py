import sys
rl = lambda : sys.stdin.readline()

caseNum = int(rl())

def diff(l):
	l = list(reversed(l))
	rtn = [10, 10, 10]
	if l[0] == l[1] and l[1] == l[2]:
		rtn[0] = 1
		if len(l) > 3 and l[2] == l[3]:
			rtn[1] = 1
			if len(l) == 5 and l[3] == l[4]:
				rtn[2] = 1
	elif l[0] == l[1]-1 and l[1] == l[2]-1:
		rtn[0] = 2
		if len(l) > 3 and l[2] == l[3]-1:
			rtn[1] = 2
			if len(l) == 5 and l[3] == l[4]-1:
				rtn[2] = 2
	elif l[0] == l[1]+1 and l[1] == l[2]+1:
		rtn[0] = 2
		if len(l) > 3 and l[2] == l[3]+1:
			rtn[1] = 2
			if len(l) == 5 and l[3] == l[4]+1:
				rtn[2] = 2
	elif l[0] == l[2]:
		rtn[0] = 4
		if len(l) > 3 and l[1] == l[3]:
			rtn[1] = 4
			if len(l) == 5 and l[2] == l[4]:
				rtn[2] = 4
	elif l[0] - l[1] == l[1] - l[2]:
		rtn[0] = 5
		if len(l) > 3 and l[2] - l[3] == l[1] - l[2]:
			rtn[1] = 5
			if len(l) == 5 and l[2] - l[3] == l[3] - l[4]:
				rtn[2] = 5
	return rtn

for c in range(caseNum):
	ar = [int(i) for i in rl().strip()]
	d = [0] * len(ar)
	d[0:2] = [-1]*2
	d[2:5] = diff(list(reversed(ar[:5])))
	#	print d
	for i in range(5, len(ar)):
		#	print ar[i-4:i+1], diff(ar[i-4:i+1])
		#print d[i-5:i-2], [d[i-5:i-2][k] + diff(ar[i-4:i+1])[k] for k in range(3) if d[i-5:i-2][k] != -1]
		rtn = diff(ar[i-4:i+1])
		d[i] = 9999999999
		#		if d[i] > d[i-5] + rtn[0] and d[i-5] != -1: d[i] = d[i-5] + rtn[0]
		#if d[i] > d[i-4] + rtn[1] and d[i-4] != -1: d[i] = d[i-4] + rtn[1]
	#if d[i] > d[i-3] + rtn[2] and d[i-3] != -1: d[i] = d[i-3] + rtn[2]

	#print d
	print d[len(ar)-1]

# python으로 해서 그런가 1초안에 동작 안한다 -_-;