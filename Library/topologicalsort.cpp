VI topologicalSort(const Graph &g) {
  const int n = g.size();
  VI deg(n);
  REP(i,n){
    for(auto &to: g[i]) ++deg[to];
  }
  stack<int> st;
  REP(i,n){
    if(deg[i] == 0) st.emplace(i);
  }
  VI ord;
  while(!st.empty()) {
    auto p = st.top();
    st.pop();
    ord.emplace_back(p);
    for(auto &to: g[p]) {
      if(--deg[to] == 0) st.emplace(to);
    }
  }
  return ord;
}
