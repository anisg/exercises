#parsing
n=int(input())
A=[*map(int,input().split())]

#solution
r = 0
for a in A:
	r += a

print(r)
