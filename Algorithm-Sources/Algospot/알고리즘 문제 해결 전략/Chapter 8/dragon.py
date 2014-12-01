# -1 : +, -2 : -, -3 : F
def solve(n, fr, to, isX): # X+YF or FX-Y
	#	print n, fr, to, isX

	if n == 0:
		if isX < 2: return 'X'
		else: return 'Y'
	elif n == -1:
		return '+'
	elif n == -2:
		return '-'
	elif n == -3:
		return 'F'

	rtn = ''
	if isX < 2:
		args = [n-1, -1, n-1, -3]
		sizes = [d[n-1], 1, d[n-1], 1]
	else:
		args = [-3, n-1, -2, n-1]
		sizes = [1, d[n-1], 1, d[n-1]]

	for i in xrange(4):
		#print 'i : %d, fr : %d, to : %d, sizes : %d' % (i, fr, to, sizes[i])
		
		if fr < sizes[i]:
			rtn += solve(args[i], fr if fr >= 0 else 0, to if to < sizes[i] else sizes[i]-1, i)

		fr -= sizes[i]
		to -= sizes[i]

		if to < 0:
			break

	return rtn

c = input()

d = [0]*50
d[0] = 1

for i in xrange(1, 50):
	d[i] = d[i-1]*2 + 2

for _ in '*'*c:
	n, p, l = [int(x) for x in raw_input().split()]
	print ('F' if p == 1 else '') + ('' if p+l-3 < 0 else solve(n, (p-2 if p-2 != -1 else 0), p+l-3, 0)) # 0 or 1 means X