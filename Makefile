machin.out : main.o
	g++ -o machin.out  main.o
main.0 : main.cpp
	g++ -c main.cpp