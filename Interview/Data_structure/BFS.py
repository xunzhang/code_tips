#! /usr/bin/python
# Filename: BFS.py
graph = {'v': ['r'],
	'r': ['v', 's'],
	's': ['r', 'w'],
	'w': ['s', 't', 'x'],
	'x': ['w', 't', 'u', 'y'],
	't': ['w', 'x', 'u'],
	'y': ['x', 'u'],
	'u': ['t', 'x', 'y']}

parent = {}
color = {}
dist = {}
GQueue = []

def BFS(G, root):
  for i in G.keys():
    parent[i] = 'NIL'
    color[i] = 0
    dist[i] = 0
  color[root] = 1 
  GQueue.append(root)
  while len(GQueue) > 0:
    u = GQueue.pop(0)
    for v in G[u]:
      if color[v] == 0:
        parent[v] = u
        color[v] = 1
        dist[v] = dist[u] + 1   
        GQueue.append(v)
    color[u] = 2
    print u

if __name__ == '__main__':
  BFS(graph, 's')
  print dist
