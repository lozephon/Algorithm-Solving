import re
import sys
rl = lambda: sys.stdin.readline()

c = int(rl())
for i in range(c):
	f = rl().strip()
	r = '^'
	for ch in f:
		if ch == '*':
			r += '.*'
		elif ch == '?':
			r += '.'
		else:
			r += ch
	r += '$'
	m = []
	n = int(rl())
	for i in range(n):
		file = rl().strip()
		if re.findall(r, file) != []:
			m.append(file)
	m.sort()
	for file in m:
		print file