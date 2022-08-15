template<typename T>
vector<vector<T>> warshallFloyd(int n, vector<vector<T>> g, T infty){
  REP(k,n){
    REP(i,n){
      REP(j,n){
        if(g[i][k] == infty || g[k][j] == infty) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  return g;
}
