def solve(grid, n, m, blacks, rows, cols):
	if len(blacks) == 1:
		return 'YES'
	for i in range(len(blacks)):
		for j in range(i+1, len(blacks)):
			xx = [blacks[i][0], blacks[j][0]]; xx.sort()
			yy = [blacks[i][1], blacks[j][1]]; yy.sort()
			'''
			print xx, yy
			print cols[blacks[i][1]], rows[blacks[j][0]]
			print cols[blacks[j][1]], rows[blacks[i][0]]
			
			if cols[blacks[i][1]]:print 1
			if cols[blacks[i][1]][0] <= xx[0]: print 2
			if cols[blacks[i][1]][1] > xx[1]: print 3
			if rows[blacks[j][0]]: print 4
			if rows[blacks[j][0]][0] <= yy[0]: print 5
			if rows[blacks[j][0]][1] > yy[1]: print 6
			'''
			if cols[blacks[i][1]] and cols[blacks[i][1]][0] <= xx[0] and cols[blacks[i][1]][1] > xx[1] and \
				rows[blacks[j][0]] and rows[blacks[j][0]][0] <= yy[0] and rows[blacks[j][0]][1] > yy[1]:
				continue
			elif cols[blacks[j][1]] and cols[blacks[j][1]][0] <= xx[0] and cols[blacks[j][1]][1] > xx[1] and \
				rows[blacks[i][0]] and rows[blacks[i][0]][0] <= yy[0] and rows[blacks[i][0]][1] > yy[1]:
				continue
			else:
				return 'NO'
			'''
			xx[0] xx[1] blacks[i][1]
			blacks[j][0] yy[0] yy[1]
			
			xx[0] xx[1] blacks[j][1]
			blacks[i][0] yy[0] yy[1]
			
			notFound = False
			for x in range(xx[0], xx[1]+1):
				if grid[x][blacks[i][1]] == 'W':
					notFound = True
					break
			if not notFound:
				for y in range(yy[0], yy[1]+1):
					if grid[blacks[j][0]][y] == 'W':
						notFound = True
						break
			if not notFound:
				continue
			for x in range(xx[0], xx[1]+1):
				if grid[x][blacks[j][1]] == 'W':
					return 'NO'
			for y in range(yy[0], yy[1]+1):
				if grid[blacks[i][0]][y] == 'W':
					return 'NO'
			'''
	return 'YES'

import sys
rl = lambda: sys.stdin.readline()

n, m = [int(a) for a in rl().split()]
grid = []
blacks = []

rows = [[] for row in range(n)]
cols = [[] for col in range(m)]

isDisconnected = False

for row in range(n):
	line = rl().strip()
	grid.append(line)
	st = -1
	for col in range(m):
		if line[col] == 'B':
			if st == -1:
				blacks.append([row, col])
				st = col
				ed = col+1
			elif st == -2:
				isDisconnected = True
			else: ed = col+1
		else:
			if st >= 0:
				blacks.append([row, col-1])
				rows[row].append(st)
				rows[row].append(ed)
				st = -2
	if st >= 0:
		blacks.append([row, m-1])
		rows[row].append(st)
		rows[row].append(m)

for col in range(m):
	st = -1
	for row in range(n):
		if grid[row][col] == 'B':
			if st == -1:
				blacks.append([row, col])
				st = row
				ed = row+1
			elif st == -2:
				isDisconnected = True
			else: ed = row+1
		else:
			if st >= 0:
				blacks.append([row-1, col])
				cols[col].append(st)
				cols[col].append(ed)
				st = -2
	if st >= 0:
		blacks.append([n-1, col])
		cols[col].append(st)
		cols[col].append(n)

#print 'rows : ', rows
#print 'cols : ', cols
#print blacks
if isDisconnected:
	print 'NO'
else:
	print solve(grid, n, m, blacks, rows, cols)

'''
def solve(grid, n, m, blacks, x, y):
	dx = [[1], [0, 1], [0], [-1,-1], [-1], [0, -1], [0], [1, 1]]
	dy = [[0], [1, 1], [1], [0, 1], [0], [-1, -1], [-1], [0, -1]]

	for ddx, ddy in zip(dx, dy):
		bool isMatch = True
		for dddx, dddy in zip(ddx, ddy)
			nx = x + dddx
			ny = y + dddy
			if nx < 0 or nx >= n or ny < 0 or ny >= m or grid[nx][ny] == 'W':
				isMatch = False
				continue
		if not isMatch: continue

		

import sys
rl = lambda: sys.stdin.readline()

n, m = [int(a) for a in rl().split()]
grid = []

for row in range(n):
	line = rl().strip()
	grid.append(line)

for row in range(n):
	bool isSolved = False
	for col in range(n):
		if grid[row][col] == 'B'
			isSolved = True
			print solve(grid, n, m, row, col)
			break
	if isSolved:
		break
'''
'''
def solve(grid, n, m, blacks):
	if len(blacks) == 1:
		return 'YES'
	for i in range(len(blacks)):
		for j in range(i+1, len(blacks)):
			xx = [blacks[i][0], blacks[j][0]]; xx.sort()
			yy = [blacks[i][1], blacks[j][1]]; yy.sort()
			notFound = False
			for x in range(xx[0], xx[1]+1):
				if grid[x][blacks[i][1]] == 'W':
					notFound = True
					break
			if not notFound:
				for y in range(yy[0], yy[1]+1):
					if grid[blacks[j][0]][y] == 'W':
						notFound = True
						break
			if not notFound:
				continue
			for x in range(xx[0], xx[1]+1):
				if grid[x][blacks[j][1]] == 'W':
					return 'NO'
			for y in range(yy[0], yy[1]+1):
				if grid[blacks[i][0]][y] == 'W':
					return 'NO'

	return 'YES'

import sys
rl = lambda: sys.stdin.readline()

n, m = [int(a) for a in rl().split()]
grid = []
blacks = []

for row in range(n):
	line = rl().strip()
	grid.append(line)
	for col in range(m):
		if line[col] == 'B':
			blacks.append([row, col])

print solve(grid, n, m, blacks)
'''