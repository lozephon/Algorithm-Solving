temp = int(raw_input())

files = set()
for i in range(temp):
	line = raw_input()
	line = line.split('/')[-1][:-4]
	line = line.lower()
	f1 = line.split('_')
	f2 = line.split('. ')
	if len(f1) == 3:
		files.add(tuple(f1[1:]))
	elif len(f2) == 2:
		files.add(tuple(f2[1].split(' - ')))
	elif len(f1) == 2:
		files.add(tuple(f1))
	else:
		files.add(tuple(line.split(' - ')))
#	print line

print len(files)
