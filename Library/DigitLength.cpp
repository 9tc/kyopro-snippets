template<typename T>
T digitLength(T n){
  if(n == 0) return 0;
  return 1 + digitLength(n / 10);
}
