n = int(raw_input())
ar = [int(_) for _ in raw_input().split()]

nF = 0
nZ = 0
for x in ar:
    if x == 5:
        nF+=1
    else:
        nZ+=1

if nZ >= 1:
    print '%s%s' % ('555555555'*(nF/9), ('0' if nF/9==0 else '0'*nZ))
else:
    print '-1'