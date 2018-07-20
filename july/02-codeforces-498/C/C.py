#parsing
n=int(input())
A=[*map(int,input().split())]

#solution
l=0
r=n-1
a=A[l]
b=A[r]
m=0
while l != r:
	if a < b:
		l += 1
		a += A[l]
	elif a > b:
		r -= 1
		b += A[r]
	else:
		m = a
		l += 1
		a += A[l]
print(m)
