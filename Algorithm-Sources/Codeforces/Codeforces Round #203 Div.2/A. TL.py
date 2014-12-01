# 20131004 easy peasy
n, m = [int(_) for _ in raw_input().split()]
ns = [int(_) for _ in raw_input().split()]
ms = [int(_) for _ in raw_input().split()]
ns.sort()
ms.sort()

ans = max(ns[0]*2, ns[len(ns)-1])
print ans if ans < ms[0] else -1
