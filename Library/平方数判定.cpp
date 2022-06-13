bool isSquareNumber(ll i){
	ll j = 0;
	while(j * j < i) ++j;
	return j * j == i;
}
