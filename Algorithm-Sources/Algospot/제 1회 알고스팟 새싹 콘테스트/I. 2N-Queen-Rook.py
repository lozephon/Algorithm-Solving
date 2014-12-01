nCase = int(raw_input())
def setRook(ai, aj, ar):
	for i in range(n):
		if ar[i][aj] == 1:
			return False
		ar[i][aj] = -1
	for j in range(n):
		if ar[aj][j] == 1:
			return False
		ar[ai][j] = -1
	ar[ai][aj] = 1
	print 'Rook', ai, aj
	return True

def setQueen(ai, aj, ar):
	if ar[ai][aj] != 0:
		return False
	
	ij = [[ai, aj]] * 4
	di = [-1, 1, -1, 1]
	dj = [-1, -1, 1, 1]
	for i in range(4):
		while ij[i][0] >= 0 and ij[i][0] < n and ij[i][1] >= 0 and ij[i][1] < n:
			print '-', ij[i][0], ij[i][1], ar[ij[i][0]][ij[i][1]]
			if ar[ij[i][0]][ij[i][1]] == 1:
				return False
			ar[ij[i][0]][ij[i][1]] = -1
			ij[i][0] += di[i]
			ij[i][1] += dj[i]
	ar[ai][aj] = 1
	print 'Queen', ai, aj
	return True

def dfs(row, array, nR, nQ):
	if row == n:
		global ans
		ans+=1
		print 'get one'
		return

	for i in range(n):
		print row, i, '-', array[row][i], nR, nQ
		print '-int---'
		print array
		print '-out---'

		if array[row][i] == 0:
			newAr = list(array[:])
			if setRook(row, i, newAr):
				print '----'
				print newAr
				print '----'
				if nR > 0:
					dfs(row+1, tuple(newAr), nR-1, nQ)
				newAr[row][i] = 0
				if setQueen(row, i, newAr) and nQ > 0:
					dfs(row+1, tuple(newAr), nR, nQ-1)
				print '--------'
				print newAr
				print '--------'

global ans, n

for c in range(nCase):
	ans = 0
	n = int(raw_input())*2

	array = [[0 for col in range(n)] for row in range(n)]
	dfs(0, tuple(array[:]), n/2, n/2)
	print array

	print ans