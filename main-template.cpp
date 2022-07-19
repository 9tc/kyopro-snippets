#include<bits/stdc++.h>
using ll = long long;
#define REP(i, n) for(ll i = 0; (i) < ll(n); ++ (i))
#define FOR(i, m, n) for(ll i = (m); (i) <= ll(n); ++ (i))
#define REPR(i, n) for(ll i = ll(n) - 1; (i) >= 0; -- (i))
#define FORR(i, m, n) for(ll i = ll(n) - 1; (i) >= ll(m); -- (i))
#define ALL(x) x.begin(),x.end()

#define INF (int)1e9
#define LLINF (long long)1e18
#define MOD (int)1e9+7
#define MOD9 (int)998244353
#define PI 3.141592653589
#define PB push_back
#define F first
#define S second

#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define Yes(T) {cout<<"Yes"<<endl; if(T) return 0;}
#define No(T) {cout <<"No"<<endl; if(T) return 0;}
#define YES(T) {cout<<"YES"<<endl; if(T) return 0;}
#define NO(T) {cout <<"NO"<<endl; if(T) return 0;}

#define Graph vector<vector<int> >
#define CostGraph vector<vector<pair<int,ll> > >
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>
#define VVI vector<vector<int> >
#define VVL vector<vector<ll> >
#define VPII vector<pair<int,int> >
#define VPLL vector<pair<ll,ll> >

#define DDD fixed<<setprecision(10)
#define PAD setfill('0')<<right<<setw(8)

template <class T>
inline bool chmin(T &a, T b) {
	if(a > b){ a = b; return true;}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if(a < b){a = b; return true;}
	return false;
}
template <class T>
T GCD(T a, T b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
	return (a * b) / GCD(a, b);
}
template <class T>
inline T input(){
  T t; std::cin >> t; return t;
}
template <class T>
inline void printVec(std::vector<T> v){
  REP(i,v.size()) std::cout << v[i] << " " << std::endl[i == v.size()-1];
}

using namespace std;

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

}
