template<typename T>
void warshall_floyd(T n, vector<vector<T>> &g, T INF) {
  REP(k,n){
    REP(i,n){
      REP(j,n){
        if(g[i][k] == INF || g[k][j] == INF) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}
