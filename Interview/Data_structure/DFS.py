#! /usr/bin/python
# Filename: DFS.py
graph = {'u': ['x', 'v'],
	'v': ['y'],
	'y': [],
	'x': ['v'],
	'w': ['y', 'z'],
	'z': ['z']}

graph2 = {'a': ['b'], 'b': ['c'], 'c': []}

parent = {}
color = {}
d = {}
f ={}

def DFS():
  global time
  time = 0
  for node in graph.keys():
    parent[node] = 'NIL'
    color[node] = 0
  for node in graph.keys(): 
    if color[node] == 0:
      DFS_VISIT(node)

def DFS_VISIT(u):
  global time
  print u
  color[u] = 1
  time = time + 1
  d[u] = time
  for v in graph[u]:
    if color[v] == 0:
      parent[v] = u
      DFS_VISIT(v)
  color[u] = 2
  time = time + 1
  f[u] = time

if __name__ == '__main__':
  DFS()
  print d
  print f
