// RMQ を init O(n^2), rmq O(1)でできるやつ ただし更新に弱いので，そのときはセグ木

template <typename T>
struct SparseTable{
  vector<vector<T>> st;
  VI lookup;

  SparseTable(const vector<T> &v){
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector<T>(1 << b));
    REP(i,v.size()) st[0][i] = v[i];
    FOR(i,1,b-1) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++){
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    FOR(i, 2, lookup.size() - 1) lookup[i] = lookup[i >> 1] + 1;
  }

  inline T rmq(int l, int r){
    int b = lookup[r - l];
    return min(st[b][l], st[b][r - (1 << b)]);
  }
};
