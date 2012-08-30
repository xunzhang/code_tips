#! /usr/bin/python
# Filename: m_eggs.py
# DP problem:
# 	Transition equation: f[n][m] = min{ 1 + max{f[i-1][m-1], f[n-i][m]} } (i=1,2,3 ...n)
#	Boundary condition: f[0][0] = 0, f[1][i] = 1, f[i][1] = i

n = int(raw_input("input floor num.\n"))
m = int(raw_input("input egg num.\n"))
# init 2d table
# floor_indx, minNum
solution = [[[-1, n + 1] for j in range(n + 1)] for i in range(m + 1)]

for k in range(n + 1):
  solution[0][k] = [-1, n + 1];

solution[0][0] = [0, 0]

for k in range(1, m + 1):
  solution[k][0] = [1, k]

print solution

# main loop
for i in range(1, m + 1):
  for j in range(2, n + 1):
    floor_indx, minNum = 0, n + 1
    for it in range(1, j + 1):
      tmp = 1 + max(solution[i - 1][it - 1][1], solution[i][j - it][1])
      if tmp < minNum:
        floor_indx, minNum = it, tmp
    solution[i][j] = [j, minNum]

print solution[m][n]
