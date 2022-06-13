run: a.out
	./a.out

a.out: main.cpp
	g++ main.cpp -O3 -std=c++1y -I .
