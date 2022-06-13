/**
 * 重み付きUnionFind (WeightedUnionFind)
 * UnionFind + ノード間の距離を管理
 *
 * merge(x, y, w) : weight(y) = weight(x) + wとなるようにmerge
 *
 **/

template<class T>
struct WeightedUnionFind{
  VI parent;
  VI rank;
  vector<T> diffWeight;

  WeightedUnionFind(int n, T unity) {
    init(n, unity);
  }

  void init(int n, T unity) {
    parent.resize(n);
    rank.resize(n);
    diffWeight.resize(n);
    REP(i,n){
      parent[i] = i;
      rank[i] = 0;
      diffWeight[i] = unity;
    }
  }

  int root(int x) {
    if(parent[x] == x) return x;
    int r = root(parent[x]);
    diffWeight[x] += diffWeight[parent[x]];
    return parent[x] = r;
  }

  T getWeight(int x){
    root(x);
    return diffWeight[x];
  }

  bool isSame(int x, int y) {
    return root(x) == root(y);
  }

  bool merge(int x, int y, T w) {
    w += getWeight(x);
    w -= getWeight(y);
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(rank[x] < rank[y]) {
      swap(x, y);
      w = -w;
    }
    if(rank[x] == rank[y]) ++rank[x];
    parent[y] = x;
    diffWeight[y] = w;
    return true;
  }

  T diff(int x, int y){
    return getWeight(y) - getWeight(x);
  }

  int size(int x){
    return -parent[root(x)];
  }
};
