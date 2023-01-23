main: main.o chessboard.h chessboard.o chesspiece.h chesspiece.o
	g++ -static chessboard.o chesspiece.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp
	
chessboard.o: chessboard.h chessboard.cpp  
	g++ -c chessboard.cpp
	
GA.o: chesspiece.h chesspiece.cpp  
	g++ -c chesspiece.cpp

run:
	./main
	
clean:
	rm -f *.o main