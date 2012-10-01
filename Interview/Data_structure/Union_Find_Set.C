/* Union_Find_Set.C */
/* M union-find ops on N objects takes at least c(N+MlgN) array accesses(can be improved to N+Ma(M, N), but no linear-time algorithm exists). */
#include <iostream>
#include <vector>

class Quick_Find_UF {
public:
  
  Quick_Find_UF(int n) {
    id.resize(n);
    for(int i = 0; i < n; ++i)
      id[i] = i;
  }
  
  void Union(int p, int q) {
    int pid = id[p];
    int qid = id[q];
    for(int i = 0; i < id.size(); ++i)
      if(id[i] == pid) id[i] = qid;
  }
  
  bool Connected(int p, int q) {
    return id[p] == id[q];
  }
  
private:
  std::vector<int> id;
};


class Quick_Union_UF {
public:
   
  Quick_Find_UF(int n) {
    id.resize(n);
    for(int i = 0; i < n; ++i)
      id[i] = i;
  }
  
  void Union(int p, int q) {
    int proot = root(p);
    int qroot = root(q);
    id[proot] = qroot;
  }
  
  bool Connected(int p, int q) {
    return root(p) == root(q);
  }
  
private:
  std::vector<int> id;
  int root(int indx) {
    while(indx != id[indx]) { indx = id[indx]; }
    return indx;
  }

};


class Weighted_Quick_Union_UF{
public:
   
  Weighted_Quick_Find_UF(int n) {
    id.resize(n);
    sz.resize(n);
    for(int i = 0; i < n; ++i) {
      id[i] = i;
      sz[i] = 1;
    }
  }
  
  void Union(int p, int q) {
    int proot = root(p);
    int qroot = root(q);
    if(sz[proot] > sz[qroot]) { root[qroot] = proot; sz[proot] += sz[qroot]; }
    else { root[proot] = qroot; sz[qroot] += sz[proot]; }
  }
  
  bool Connected(int p, int q) {
    return root(p) == root(q);
  }
  
private:
  std::vector<int> id;
  
  std::vector<int> sz;
  
  int root(int i) {
    while(i != id[i]) { 
      id[i] = id[id[i]]; 
      i = id[i]; 
    }
    /* another method but a little complicated!
    std::vector<int> visited;
    while(i != id[i]) { i = id[i]; visited.append(i); }
    while(!visited.empty()) { id[visited.top()] = i; visited.pop(); }
    */
    return i;
  } 

};


/* client code */
int main(int argc, char* argv[])
{
  std::istream in;
  int n = in >> n;
  Quick_Find_UF uf(n);
  while(!in.empty()) {
    int p = in.read();
    int q = in.read();
    if(!uf.connected) {
      uf.Union(p, q);
    }
  } // end of while
  return 0;
}
