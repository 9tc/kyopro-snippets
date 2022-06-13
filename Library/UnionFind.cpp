struct UnionFind {
  VI parent;
  VI rank;

  UnionFind(int n) {
    init(n);
  }

  void init(int n) {
    parent.resize(n);
    rank.resize(n);
    REP(i,n){
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int root(int x) {
    if(parent[x] == x) return x;

    return parent[x] = root(parent[x]);
  }

  bool isSame(int x, int y) {
    return root(x) == root(y);
  }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(rank[x] < rank[y]) swap(x, y);
    if(rank[x] == rank[y]) ++rank[x];
    parent[y] = x;
    return true;
  }
};
