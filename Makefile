machin.out : Point.o
	g++ -o machin.out  Point.o
Point.0 : Point.cpp
	g++ -c Point.cpp