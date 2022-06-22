template <class T>
struct ReversableVector{
  bool reversed;
  deque<T> que;

  ReversableVector(){
    reversed = false;
  }

  ReversableVector(const vector<T> &v){
    reversed = false;
    for(T t: v){
      que.push_back(t);
    }
  }

  ReversableVector(const string &v){
    reversed = false;
    for(char t: v){
      que.push_back(t);
    }
  }

  void reverse(){
    reversed = !reversed;
  }

  void push_back(const T& t){
    if(reversed) que.push_front(t);
    else que.push_back(t);
  }

  void push_front(const T& t){
    if(reversed) que.push_back(t);
    else que.push_front(t);
  }

  vector<T> build(){
    vector<T> t;
    for(T item: que) t.push_back(item);
    if(reversed) std::reverse(ALL(t));
    return t;
  }
};
