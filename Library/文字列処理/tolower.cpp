string tolower(string s) {
  transform(ALL(s), s.begin(),
  [](unsigned char c){ return tolower(c); }
  );
  return s;
}
