template <typename T>
bool isSquareNumber(T i){
	T j = 0;
	while(j * j < i) ++j;
	return j * j == i;
}
