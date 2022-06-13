bool isPalindrome(const string &v){
  int n = v.length();
  REP(i,n/2){
    if(v[i] != v[n-i-1]) return false;
  }
  return true;
}
