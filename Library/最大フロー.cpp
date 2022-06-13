template<class V> struct MaxFlow { // Dinic O(V^2E)
  struct edge{
    int to, reve;
    V cap;
    edge(int t, int r, V c) : to(t), reve(r), cap(c) {}
  };
  int MV;
  vector<vector<edge>> E;
  vector<int> itr, lev;
  MaxFlow(int n){
    init(n);
  }
  MaxFlow() { }

  void init(int n){
    MV=n;
    itr=vector<int>(MV),lev = vector<int>(MV);
    E = vector<vector<edge>>(MV);
  }

  void addEdge(int x, int y, V cap, bool undir = false) {
    E[x].push_back(edge(y, (int)E[y].size(), cap));
    E[y].push_back(edge(x, (int)E[x].size() - 1, undir ? cap : 0));
  }

  void bfs(int cur) {
    REP(i, MV) lev[i] = -1;
    queue<int> q;
    lev[cur] = 0;
    q.push(cur);
    while (q.size()) {
      int v = q.front(); q.pop();
      for (auto e : E[v]) if (e.cap>0 && lev[e.to]<0) lev[e.to] = lev[v] + 1, q.push(e.to);
    }
  }

  V dfs(int from, int to, V cf){
    if(from == to) return cf;
    for(; itr[from]<E[from].size(); itr[from]++) {
      edge* e = &E[from][itr[from]];
      if (e->cap>0 && lev[from]<lev[e->to]) {
        V f = dfs(e->to, to, min(cf, e->cap));
        if(f>0){
          e->cap-=f;
          E[e->to][e->reve].cap+=f;
          return f;
        }
      }
    }
    return 0;
  }

  V maxFlow(int from, int to) {
    V fl = 0, tf;
    while(1){
      bfs(from);
      if(lev[to] < 0) return fl;
      REP(i, MV) itr[i]=0;
      while((tf = dfs(from, to, numeric_limits<V>::max()))>0) fl += tf;
    }
  }
};
