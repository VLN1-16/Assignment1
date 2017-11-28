# Build the entire program and clean up .o files
all:
	g++ -Wall -c Superhero.cpp main.cpp Heros.cpp
	g++ *.o -o Superhero.out
	rm *.o
bintest:
	g++ -Wall -c main2.cpp Superhero.cpp
	g++ main2.o Superhero.o
	rm *.o
	./a.out
clang:
	clang++ -Wall -c Superhero.cpp main.cpp Heros.cpp -std=c++17
	clang++ *.o -o Superhero.out
	rm *.o
buildwithdebugflags:
	g++ -Wall -c -g Superhero.cpp main.cpp Heros.cpp
	g++ *.o -o SuperheroDebug.out
	rm *.o
