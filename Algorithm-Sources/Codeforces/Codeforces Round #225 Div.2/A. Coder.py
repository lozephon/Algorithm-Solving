n = int(raw_input())
if n == 1:
    print 1
    print 'C'
else:
    ans = n * (n/2) + (n / 2 + 1) * (n % 2)
    fl = '%s%s' % ('C.' * (n/2), 'C' if n % 2 == 1 else '')
    sl = '%s%s' % ('.C' * (n/2), '.' if n % 2 == 1 else '')
    line = '%s\n%s\n' % (fl, sl)
    print ans
    print (line * (n/2))[:-1]
    if n % 2 == 1:
        print fl
