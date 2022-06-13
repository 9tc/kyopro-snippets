template<typename T>
T digitSum(T n){
  T t = 0;
  while(n){
    t += n % 10;
    n /= 10;
  }
  return t;
}
