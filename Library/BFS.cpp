void bfs(const Graph &G, int s){
  vector<bool> seen(G.size(), false);
  queue<int> que;
  que.push(s);
  seen[s] = true;

  while(!que.empty()){
    int u = que.front(); que.pop();
    for(auto v: G[u]){
      if(seen[v]) continue;
      seen[v] = true;
      /*
       * TODO *
       */
      que.push(v);
    }
  }
}
