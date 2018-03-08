#!/bin/python

#from __future__ import print_function

import os
import sys

#
# Complete the fillBoard function below.
#
def fillInit(A,n, m, x,y):
	for i in range(0, x):
		A[0][i] = -1
	for i in range(m-y,m):
		A[n-1][i] = -1

def printYeah(pieces):
	print "YES"
	print len(pieces)
	for ((x1,y1), (x2,y2)) in pieces:
		print y1+1,x1+1, y2+1,x2+1
	exit(0)

def setHori(A,n,m,x,y,pieces):
	if y+1 >= n:
		return False
	if not (A[y][x] == 0 and A[y+1][x] == 0):
		return False
	v = len(pieces)+1
	A[y][x] = v
	A[y+1][x] = v
	pieces.append( ((x,y),(x,y+1)) )
	return True

def unsetHori(A,n,m,x,y,pieces):
	if not (A[y][x] == len(pieces) and A[y+1][x] == len(pieces)):
		print "NO"
		exit(0)
	A[y][x] = 0
	A[y+1][x] = 0
	pieces.pop()
	return True

def setVerti(A,n,m,x,y,pieces):
	if x+1 >= m:
		return False
	if not (A[y][x] == 0 and A[y][x+1] == 0):
		return False
	v = len(pieces)+1
	A[y][x] = v
	A[y][x+1] = v
	pieces.append( ((x,y),(x+1,y)) )
	return True

def unsetVerti(A,n,m,x,y,pieces):
	if not (A[y][x] == len(pieces) and A[y][x+1] == len(pieces)):
		print "NO"
		exit(0)
	A[y][x] = 0
	A[y][x+1] = 0
	pieces.pop()
	return True

def backtrack(A, n,m, x,y, pieces, maxi):
	if maxi == len(pieces)*2:
		printYeah(pieces)
		return True
	if x == m:
		x = 0
		y += 1
	while y < n:
		if setHori(A,n,m,x,y,pieces):
			backtrack(A, n,m, x+1,y, pieces, maxi)
			unsetHori(A,n,m,x,y, pieces)
		if setVerti(A,n,m, x,y,pieces):
			backtrack(A, n,m, x+1,y, pieces, maxi)
			unsetVerti(A,n,m, x,y, pieces)
		x += 1
		if x == m:
			x = 0
			y += 1

def fillBoard(n, m, x, y):
	# Print the output as described in the output format section.
	maxi = n*m-(x+y)
	A = [[0 for a in range(m)] for b in range(n)]
	fillInit(A, n,m,x,y)

	backtrack(A, n,m, 0,0, [], maxi)
	print "NO"

if __name__ == '__main__':
    nmxy = raw_input().split()

    n = int(nmxy[0])

    m = int(nmxy[1])

    x = int(nmxy[2])

    y = int(nmxy[3])

    fillBoard(n, m, x, y)
