
def makeDic(board, i, j, x, y, wordDic, n, word):
    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1, 0, 1, -1, 1, -1, 0, 1]
    for a, b in zip(dx, dy):
		xx = x+a; yy = y+b
		if xx >= 0 and xx < 5 and yy >= 0 and yy < 5:
			newWord = word + board[xx][yy]
			if (newWord, i, j) in wordDic:
				if (xx, yy) not in wordDic[(newWord, i, j)]:
					wordDic[(newWord, i, j)].append((xx, yy))
			else:
				wordDic[(newWord, i, j)] = [(xx, yy)]
			if n+1 <= 2:
				makeDic(board, i, j, xx, yy, wordDic, n+1, newWord)

def bfs(fr, to, x, y, wordDic):
	if (word[fr:to], x, y) in wordDic:
		q = wordDic[(word[fr:to], x, y)]
		for nx, ny in q:
			fr2 = to-1
			if len(word[fr2:]) <= 2:
				if (word[fr2:], nx, ny) in wordDic:
					return True
			else:
				to2 = fr + 2
				if bfs(fr2, to2, nx, ny, wordDic):
					return True
	return False

import sys
rl = lambda: sys.stdin.readline()
	
nCase = int(rl())

for case in range(nCase):
	board = [[ch for ch in rl().strip()] for i in range(5)]
	wordDic = {}

	for i in range(5):
		for j in range(5):
			wordDic[(board[i][j], i,j)] = [(i,j)]
			makeDic(board, i, j, i, j, wordDic, 0, board[i][j])
	
	nWord = int(rl())
	for i in range(nWord):
		word = rl().strip()
		isWord = "NO"
		
		if len(word) <= 2:		
			for i in range(5):
				for j in range(5):
					if (word, i, j) in wordDic:
						isWord = "YES"
						break
				if isWord == "YES":
					break
		else:
			for i in range(5):
				for j in range(5):
					if board[i][j] == word[0]:
						if bfs(0, 2, i, j, wordDic):
							isWord = "YES"
							break
				if isWord == "YES":
					break
		
		print word, isWord
