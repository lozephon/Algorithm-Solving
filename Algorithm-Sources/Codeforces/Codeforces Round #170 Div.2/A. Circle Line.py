import sys
rl = lambda: sys.stdin.readline()

n = int(rl())
d = [int(a) for a in rl().split()]
st = [int(a)-1 for a in rl().split()]
st.sort()
s, t = st

#print n, d, s, t

len1 = 0
for i in range(s, t):
	len1 += d[i]
len2 = 0
i = t
while i != s:
	len2 += d[i]
	i = (i+1) % n

print min(len1, len2)