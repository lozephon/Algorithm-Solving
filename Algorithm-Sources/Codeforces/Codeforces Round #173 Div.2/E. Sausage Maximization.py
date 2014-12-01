import sys
import math
rl = lambda: sys.stdin.readline()

def solve(n, ar):
	bitMax = [0, -1]
	bitMaxSnd = [0, -1]
	xorResultFrom = 0
	tempXor = 0
	for i in range(n):
		t = int(math.log(ar[i], 2))+1
		tempXor ^= ar[i]
		if t > bitMax[0]:
			if bitMaxSnd[0] < bitMax[0]:
				bitMaxSnd[0] = bitMax[0]
				bitMaxSnd[1] = bitMax[1]
			bitMax[0] = t
			bitMax[1] = i
			xorResult = tempXor
	bitMax = [0, -1]
	bitMaxSnd = [0]
	tempXor = 0
	xorResultTo = 0
	for i in range(n, bitMax[1], -1):
		t = int(math.log(ar[i], 2))+1
		tempXor ^= ar[i]
		if t > bitMax[0]:
			if bitMaxSnd[0] < bitMax[0]:
				bitMaxSnd[0] = bitMax[0]
				bitMaxSnd[1] = bitMax[1]
			bitMax[0] = t
			bitMax[1] = i
			xorResult = tempXor

n = int(rl())

ar = [int(t) for t in rl().split()]
rtn1 = solve(n, ar)
ar.reverse()
rtn2 = solve(n, ar)
if rtn1 > rtn2:
	print rtn1
else:
	print rtn2
