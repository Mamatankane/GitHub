main: main.o matrix.h matrix.o
	g++ -static matrix.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp
	
matrix.o: matrix.h matrix.cpp  
	g++ -c matrix.cpp
	
run:
	./main
	
clean:
	rm*.o main
