#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

// 階乗(n!)
mint fact(const int n) {
  static vector<mint> v = {1};
  while(v.size() <= n) {
    v.push_back(v.back() * v.size());
  }
  return v[n];
}

// 階乗inverse
mint inv_fact(const int n) {
  static vector<mint> u = {0, 1}, v = {1, 1};
  for (int i = (int)u.size(); i <= n; ++i) {
    u.push_back(-mint(mint::mod() / i) * u[mint::mod() % i]);
    v.push_back(v.back() * u.back());
  }
  return v[n];
}

// 二項係数 nCk <= n! / (k! * (n - k)!)
mint binom(const int n, const int k) {
  return fact(n) * inv_fact(k) * inv_fact(n - k);
}
