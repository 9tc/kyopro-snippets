VL dijkstra(int n, CostGraph& g, int s){
  VL dist(n, LLINF);
  dist[s] = 0;
  priority_queue<pair<int,ll>, vector<pair<int,ll>>, greater<pair<int,ll>>> pq;
  pq.emplace(0, s);
  while(!pq.empty()) {
    auto [nowCost, now] = pq.top(); pq.pop();
    if(dist[now] < nowCost) continue;
    for(auto [to, cost]: g[now]) {
      if(chmin(dist[to], nowCost + cost)) pq.emplace(nowCost + cost, to);
    }
  }
  return dist;
}

VL dijkstra(int n, Graph& g, int s){
  VL dist(n, LLINF);
  dist[s] = 0;
  priority_queue<pair<int,ll>, vector<pair<int,ll>>, greater<pair<int,ll>>> pq;
  pq.emplace(0, s);
  while(!pq.empty()) {
    auto [nowCost, now] = pq.top(); pq.pop();
    if(dist[now] < nowCost) continue;
    for(auto to: g[now]) {
      if(chmin(dist[to], nowCost + 1LL)) pq.emplace(nowCost + 1LL, to);
    }
  }
  return dist;
}
