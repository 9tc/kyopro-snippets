/* 座標圧縮
* usage:
* VI a = {1, 2, 4, 4, 7};
* Compress<int> comp(a);
* comp.build();
* VI b = comp.get(a); -> b = {0,1,2,2,3}
*/

template<typename T>
struct Compress{
  vector<T> xs;

  Compress() = default;

  Compress(const vector<T> &vs){
    add(vs);
  }

  Compress(const initializer_list<vector<T>> &vs) {
    for(auto &p :vs) add(p);
  }

  void add(const vector<T> &vs) {
    copy(begin(vs), end(vs), back_inserter(xs));
  }

  void add(const T &x) {
    xs.emplace_back(x);
  }

  void build() {
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), end(xs));
  }

  vector<int> get(const vector<T> &vs) const{
    vector<int> ret;
    transform(ALL(vs), back_inserter(ret), [&](const T &x) {
      return lower_bound(ALL(xs), x) - begin(xs);
    });
    return ret;
  }

  int get(const T &x) const{
    return lower_bound(ALL(xs), x) - begin(xs);
  }

  const T &operator[](int k) const {
    return xs[k];
  }
};
