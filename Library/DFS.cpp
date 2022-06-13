void _dfs(const Graph &G, int v, vector<bool> &seen) {
  seen[v] = true;

  for(auto u: G[v]){
    if(seen[u]) continue;
    /*
    * TODO *
    */
    _dfs(G, u, seen);
  }
}

void dfs(const Graph &G, int s){
  vector<bool> seen(G.size(), false);
  _dfs(G, s, seen);
}
