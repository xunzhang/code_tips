#! /usr/bin/python
# Filename: two_eggs.py
# DP problem:
# 	Transition equation: f[n] = min{ 1 + max{i-1, f[n-i]} } (i=1,2,3 ...n)
#	Boundary condition: f[0] = 0, f[1] = 1

n = int(raw_input("input floor num.\n"))
solution = [(0, 0), (1, 1)]
for i in range(2, n + 1):
  floor_indx, minNum = 0, n + 1
  for j in range(1, i + 1):
    tmp = 1 + max(j - 1, solution[i - j][1])
    if tmp < minNum:
      floor_indx, minNum = j, tmp
  solution.append((i, minNum))

print solution[n]
