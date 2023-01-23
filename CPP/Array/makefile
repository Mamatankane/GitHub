main: main.o CountArray.h CountArray.o SortArray.h SortArray.o SumArray.h SumArray.o TwoDArray.h TwoDArray.o
	g++ -static CountArray.o SortArray.o SumArray.o TwoDArray.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp
	
CountArray.o: CountArray.h CountArray.cpp  
	g++ -c CountArray.cpp

SortArray.o: SortArray.h SortArray.cpp  
	g++ -c SortArray.cpp

TwoDArray.o: TwoDArray.h TwoDArray.cpp  
	g++ -c TwoDArray.cpp

SumArray.o: SumArray.h SumArray.cpp  
	g++ -c SumArray.cpp

Task1.o: Task1.cpp
	g++ -c Task1.cpp

Task2.o: Task2.cpp
	g++ -c Task2.cpp
	
run:
	./main
	
clean:
	rm *.o main