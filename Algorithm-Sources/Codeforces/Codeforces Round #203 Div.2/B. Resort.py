# 20131004 Tricky, dfs
n = int(raw_input())
type = [int(_) for _ in raw_input().split()]
track = [int(_) for _ in raw_input().split()]

nEdge = [0] * (n)
edges = [-1] * (n)
visited = [False] * (n)
nPath = [0] * (n)

for i in xrange(n):
    if track[i] == 0: continue
    nEdge[track[i]-1] += 1
    edges[track[i]-1] = i

for i in xrange(n):
    now = i
    value = 1
    nodes = [now]
    while type[now] == 0:
        if visited[now]:
            if nPath[now] == -1:
                value = -1
            else:
                value += nPath[now]-1
            break
        
        visited[now] = True
        
        if nEdge[now] > 1:
            value = -1
            break
    
        if edges[now] != -1:
            now = edges[now]
            value += 1
            nodes.append(now)
        else:
            value = -1
            break
    
    if value == -1:
        for x in nodes:
            nPath[x] = value
    for x in nodes:
        visited[x] = True
    nPath[i] = value
#    print
#    print nPath

maxIdx = -1
maxValue = 0
for i in xrange(n):
    if nEdge[i] < 2:
        if maxIdx == -1 or maxValue < nPath[i]:
            if nPath[i] == 1 and type[i] == 0:
                continue
            maxIdx = i
            maxValue = nPath[i]

print maxValue
if maxValue > 0:
    now = maxIdx
    print now+1,
    while type[now] == 0:
        now = edges[now]
        if now == -1:
            break
        print now+1,

    print