main: studentmain.o chessboard.h chessboard.o chesspiece.h chesspiece.o
	g++ -static chessboard.o chesspiece.o studentmain.o -o main

studentmain.o: studentmain.cpp
	g++ -c studentmain.cpp
	
chessboard.o: chessboard.h chessboard.cpp  
	g++ -c chessboard.cpp
	
GA.o: chesspiece.h chesspiece.cpp  
	g++ -c chesspiece.cpp

run:
	./main
	
clean:
	rm -f *.o main