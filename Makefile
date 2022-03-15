machin.out : compte.o mainCompte.o
	g++ -o machin.out compte.o mainCompte.o
mainCompte.0 : mainCompte.cpp
	g++ -c mainCompte.cpp
compte.0 : compte.cpp
	g++ -c compte.cpp