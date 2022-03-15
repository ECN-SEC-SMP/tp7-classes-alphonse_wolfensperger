machin.out : main.o thispoint.o
	g++ -o machin.out  main.o thispoint.o
main.0 : main.cpp
	g++ -c main.cpp
thispoint.0 : thispoint.cpp
	g++ -c thispoint.cpp