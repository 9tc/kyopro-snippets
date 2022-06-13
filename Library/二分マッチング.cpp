struct BipartiteMatching {
  int N, M;
  MaxFlow<int> mf;
  BipartiteMatching(int n, int m) : N(n), M(m) {
    mf.init(n + m + 2);
  }
  void add_edge(int a, int b) {
    mf.add_edge(a, N + b, 1);
  }
  int match(){
    REP(a, N) mf.add_edge(N + M, a, 1);
    REP(b, M) mf.add_edge(N + b, N + M + 1, 1);
    return mf.maxflow(N + M, N + M + 1);
  }
  // マッチング相手を返す(無いなら-1)
  int whois(int a){
    for(auto e : mf.E[a]) if (e.cap == 0) return e.to - N; return -1;
  }
};
