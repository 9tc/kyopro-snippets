struct DoublingLowestCommonAncestor{
  const int LOG;
  VI dep;
  const Graph &g;
  VVI table;

  DoublingLowestCommonAncestor(const Graph &g): g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())){
    table.assign(LOG, VI(g.size(), -1));
  }

  void dfs(int idx, int par, int d){
    table[0][idx] = par;
    dep[idx] = d;
    for(auto &to: g[idx]){
      if(to != par) dfs(to, idx, d + 1);
    }
  }

  void build(){
    dfs(0, -1, 0);
    for(int k = 0; k + 1 < LOG; 　++k){
      REP(i, table[k].size()){
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    REPR(i,LOG){
      if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
    }
    if(u == v) return u;
    REPR(i,LOG){
      if(table[i][u] != table[i][v]){
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }
};
