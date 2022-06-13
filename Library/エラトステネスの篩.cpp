vector<bool> getPrimeNumbers(int n){
  vector<bool> isPrime(n+1, true);
  isPrime[0] = false; // 0は素数ではない
  isPrime[1] = false; // 1は素数ではない
  for(int i = 2; i * i <= n; ++i){
    if(isPrime[i]){
      for(int j = 2; i * j <= max; ++j){
        isPrime[i*j] = false;
      }
    }
  }
  return isPrime;
}
