ll xor0n(ll n){
  if(n % 4 == 0) return n;
  if(n % 4 == 1) return 1;
  if(n % 4 == 2) return n + 1;
  return 0;
}

ll xornm(ll n, ll m){
  if(n > m) swap(n, m);
  if(n == 0) return xor0n(m);
  else return xor0n(n-1) ^ xor0n(m);
}
