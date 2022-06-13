void _dfs(const Graph &G, int v, vector<bool> &seen) {
  seen[v] = true; // v を訪問済にする

  // v から行ける各頂点 next_v について
  for (auto u : G[v]) {
    if (seen[u]) continue;
    /*
    * TODO *
    */
    _dfs(G, u, seen); // 再帰的に探索
  }
}

void dfs(const Graph &G, int s){
  vector<bool> seen(G.size(), false);
  _dfs(G, s, seen);
}
