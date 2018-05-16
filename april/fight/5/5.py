T = int(raw_input())

def solve(n, a):
	d = {}
	for i in range(0, n):
		if not a[i] in d:
			d[a[i]] = 1
		else:
			d[a[i]] += 1
	best = -1
	bestArr = []
	for k, v in d.iteritems():
		if v > best:
			bestArr = [k]
			best = v
		elif v == best:
			bestArr.append(k)
	return sorted(bestArr, reverse=True)

for _ in range(0, T):
	n = int(raw_input())
	a = map(int, raw_input().split())
	arr = solve(n, a)
	s = ""
	for a in arr:
		s += str(a) + " "
	print(s.strip())
