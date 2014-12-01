from itertools import izip

def add(a, b, k):
	"return a * 10^k + b"
	if a != [0]:
		c = [0]*k + a
	else:
		c = list(a)
	if len(a) < len(b):
		return add(b, c, 0)
	for i, v in enumerate(izip(c, b)):
		c[i] = v[0] + v[1]
	#normalize(c)
	return c

def normalize(a):
	a.append(0)
	for i, x in enumerate(a[:-1]):
		if a[i] > 9:
			a[i+1] += a[i] / 10
			a[i] = a[i] % 10
	while a[-1] == 0 and len(a) > 1:
		a.pop()

def sub(a, b):
	"return a-b" # assume a >= b
#	print 'sub', a, b
	c = list(a)
	for i, v in enumerate(izip(c, b)):
		if v[0] >= v[1]:
			c[i] = v[0] - v[1]
		else:
			j = i+1
			while c[j] == 0:
				c[j] = 9
				j += 1
			c[j] -= 1
			c[i] = 10 + v[0] - v[1]
	while c[-1] == 0 and len(c) > 1:
		c.pop()
#	print 'sub - a : %s, b : %s, c : %s' % (''.join([str(ch) for ch in reversed(a)]),''.join([str(ch) for ch in reversed(b)]),''.join([str(ch) for ch in reversed(c)]))
	return c

def karatsuba(a, b):
#	print a, b
	if len(a) < len(b):
		return karatsuba(b,a)
	if len(a) == 0 or len(b) == 0:
		return [0]
	if len(a) < 2:
		sa = int(''.join([str(ch) for ch in reversed(a)]))
		sb = int(''.join([str(ch) for ch in reversed(b)]))
		return list(reversed([int(ch) for ch in str(sa * sb)]))
	k = len(a)/2
	a0 = a[:k]
	a1 = a[k:]
	b0 = b[:min(len(b), k)]
	b1 = b[min(len(b), k):]
	if b1 == []: b1 = [0]
	z0 = karatsuba(a0, b0)
	z2 = karatsuba(a1, b1)
	z1 = karatsuba(add(a0, a1, 0), add(b0, b1, 0))
	z1 = sub(sub(z1, z0), z2)
	ret = z0
	ret = add(z1, ret, k)
	ret = add(z2, ret, k*2)
#	print 'rtn ', ret
#	print 'a : %s, b : %s, rtn : %s' % (''.join([str(ch) for ch in reversed(a)]),''.join([str(ch) for ch in reversed(b)]),''.join([str(ch) for ch in reversed(ret)]))
	return ret

import sys
rl = lambda: sys.stdin.readline()

c = int(rl())

for i in xrange(c):
	m = rl().strip()
	f = rl().strip()
	mt = []
	ft = []
	for j in m:
		if j == 'M':
			mt = [1] + mt
		else:
			mt = [0] + mt
	for j in f:
		if j == 'M':
			ft += [1]
		else:
			ft += [0]
	ans = 0
	normalize(mt)
	normalize(ft)
	#	print karatsuba(mt, ft)
	for x in karatsuba(mt, ft)[len(m):len(m)+(len(f)-len(m)+1)]:
		if x != 0:
			ans += 1
	print len(f)-len(m)+1 - ans
	