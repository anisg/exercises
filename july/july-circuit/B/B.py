#in
n=int(input())
A=[*map(int,input().split())]
m=int(input())
C=[*map(int,input().split())]

#solve
A.sort()
C.sort()
B = []
x = 0
for c in C:
	if c > A[n-1] and c-A[n-1] > C[0]-A[0]:
		break
	x += 1
while x < m:
	B.append(C[x]-A[n-1])
	x += 1

#out
s=""
for b in B:
	s += str(b) + " "
print(s.strip())
