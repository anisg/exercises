t = int(raw_input())

def pick(i, s, n):
	r = []
	if i >= s:
		return r
	x = i
	while (x < n):
		tmp = pick(x, s-1, n)
		if len(tmp) == 0:
			r.append([x])
		for t in tmp:
			r.append([x] + t)
		x += 1
	return r

def genComb(n):
	r = []
	for i in range(1, n):
		r.extend(pick(0, i, n))
	return r

for _t in range(t):
	N,P = map(int, raw_input().split(' '))
	for p in range(P):
		a,b = map(int, raw_input().split(' '))
	arr = genComb(3)
	print arr
