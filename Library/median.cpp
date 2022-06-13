template<typename T>
T median(vector<T> a){
  int n = a.size();
  if(n % 2 == 0){
    nth_element(a.begin(), a.begin() + n/2, a.end());
    nth_element(a.begin(), a.begin() + (n-1)/2, a.end());
    return (a[(n-1)/2] + a[n/2]) / 2.0;
  }else{
    nth_element(a.begin(), a.begin() + n/2, a.end());
    return a[n/2];
  }
}
