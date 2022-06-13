template<typename T>
T calcRPoland(string s){
  deque<T> q;
  for(char c: s){
    if(c >= '0' && c <= '9'){
      q.push_back((T)(c - '0'));
    }else{
      T s = q.back(); q.pop_back();
      T t = q.back(); q.pop_back();
      if(c == '+') t += s;
      if(c == '-') t -= s;
      if(c == '*') t *= s;
      if(c == '/') t /= s;
      q.push_back(t);
    }
  }
  return q.front();
}
