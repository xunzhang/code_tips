#! /usr/bin/python
# Filename: KMP.py

a = 'abababaababacb'
b = 'ababacb'

n = len(a)
m = len(b)
p = [0 for i in range(m+1)]
a += '+'
b += '+'

print a
print b

# init p
p[1] = 0
j = 0
for i in range(2, m+1):
  while j > 0 and b[j+1] != b[i]:
    j = p[j]
  if b[j+1] == b[i]:
    j = j + 1
  p[i] = j

# main loop
j = 0
for i in range(1, n + 1):
  while j > 0 and a[i] != b[j+1]:
    j = p[j]
  if b[j+1] == a[i]:
    j = j + 1
  if j == m:
    print 'find it in:'
    print i - m
    j = p[j] # more results
    
