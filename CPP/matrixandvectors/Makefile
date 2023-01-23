main: main.o matrix.o vector.o arithmetic.o
	g++ -g -static main.o matrix.o arithmetic.o vector.o -o main

main.o: main.cpp
	g++ -g -c main.cpp  

matrix.o: matrix.h matrix.cpp
	g++ -g -c matrix.cpp

vector.o: vector.h vector.cpp
	g++ -g -c vector.cpp

arithmetic.: arithmetic.h arithmetic.cpp
	g++ -g -c arithmetic.cpp

run: 
	./main

clean:
	rm *.o main