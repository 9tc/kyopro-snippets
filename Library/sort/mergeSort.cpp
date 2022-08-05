void merge(VI &A, int l, int mid, int r){
  int n1 = mid - l;
  int n2 = r - mid;
  VI L(n1+1, INF), R(n2+1, INF);
  REP(i, n1) L[i] = A[l + i];
  REP(i, n2) R[i] = A[mid + i];

  int i = 0, j = 0;
  FOR(k, l, r-1){
    if(L[i] <= R[j]){
      A[k] = L[i];
      ++i;
    }else{
      A[k] = R[j];
      ++j;
    }
  }
}

void mergeSort(VI &A, int l, int r){
  if(l + 1 < r){
    int mid = (l + r) / 2;
    mergeSort(A, l, mid);
    mergeSort(A, mid, r);
    merge(A, l, mid, r);
  }
}
