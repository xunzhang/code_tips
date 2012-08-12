#! /usr/bin/python
# Filename : ge_nself.py
# Notice the traps of O(n^2)

# input size
n = raw_input("input size\n")
# init list A
A = [i+2 for i in range(int(n))] 
# main body
# init list B
B = [A[i] for i in range(int(n))]
# format B as [12345, 2345, 345, 45, 5]
for i in range(1, int(n)):
	B[int(n)-1-i] *= B[int(n)-i]
# format A as [1, 12, 123, 1234, 12345]
for i in range(1, int(n)):
	A[i] *= A[i-1]
# assign the result
for i in range(1, int(n) - 1):
	B[i] = A[i-1] * B[i+1]
B[int(n)-1] = A[int(n)-2] 
# prin the result
print B
