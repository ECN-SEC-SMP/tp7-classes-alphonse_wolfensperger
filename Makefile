machin.out : mainCompte.o
	g++ -o machin.out  mainCompte.o
mainCompte.0 : mainCompte.cpp
	g++ -c mainCompte.cpp