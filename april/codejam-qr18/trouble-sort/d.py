from random import randint
from copy import copy

def rand(n):
	return randint(0, n)

def troublesort(arr):
	done = False
	while not done:
		done = True
		for i in range(0, len(arr)-2):
			if arr[i] > arr[i + 2]:
				arr[i], arr[i + 2] = arr[i + 2], arr[i]
				done = False

def isReallyTroubleSolvable(arr):
	a = copy(arr)
	troublesort(a)
	print "troublesorted:", a
	if sorted(a) == a:
		return True
	for i in range(0, len(a)-1):
		if a[i] > a[i + 1]:
			return i
	raise ValueError('A very specific bad thing happened.')

def isTroubleSolvable(arr):
	even = [arr[x] for x in range(0, len(arr), 2)]
	odd = [arr[x] for x in range(1, len(arr), 2)]
	even = sorted(even)
	odd = sorted(odd)
	print "have:"
	print even
	print odd
	i = 0
	io = 0
	while i < len(even):
		if io < len(odd):
			print "odds test:", even[i], ">", odd[io]
		if io < len(odd) and even[i] > odd[io]:
			return io + i
		if i + 1 < len(even):
			print "even test:", odd[io], ">", even[i+1]
		if i + 1 < len(even) and odd[io] > even[i + 1]:
			return io + i + 1
		i += 1
		io += 1
	return True

def generateTests(n=1):
	arrs = []
	for i in range(n):
		cs = randint(3, 10000)
		arr = []
		for c in range(cs):
			arr.append(rand(100000))
		arrs.append(arr)
	return arrs

arrs = generateTests(10)
for arr in arrs:
	print arr
	r = isReallyTroubleSolvable(arr)
	r2 = isTroubleSolvable(arr)
	print r, r2
	if r != r2:
		print ("OUPS")
		break
