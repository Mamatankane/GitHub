main: main.o IsDivisible.h IsEvenOdd.h IsGreater.h IsSmaller.h IsPrimeNumber.h ValueDependantTester.h ValueIndependantTester.h NumberTester.h TesterInterface.h IsDivisible.o IsEvenOdd.o IsGreater.o IsSmaller.o IsPrimeNumber.o ValueDependantTester.o ValueIndependantTester.o NumberTester.o TesterInterface.o
	g++ -static IsDivisible.o IsEvenOdd.o IsGreater.o IsSmaller.o IsPrimeNumber.o ValueDependantTester.o ValueIndependantTester.o NumberTester.o TesterInterface.o main.o -o main
	
main.o: main.cpp
	g++ -c main.cpp
	
IsDivisible.o: IsDivisible.h IsDivisible.cpp
	g++ -c IsDivisible.cpp

IsEvenOdd.o: IsEvenOdd.h IsEvenOdd.cpp
	g++ -c IsEvenOdd.cpp

IsGreater.o: IsGreater.h IsGreater.cpp
	g++ -c IsGreater.cpp

IsSmaller.o: IsSmaller.h IsSmaller.cpp
	g++ -c IsSmaller.cpp

IsPrimeNumber.o: IsPrimeNumber.h IsPrimeNumber.cpp
	g++ -c IsPrimeNumber.cpp

ValueDependantTester.o: ValueDependantTester.h ValueDependantTester.cpp
	g++ -c ValueDependantTester.cpp

ValueIndependantTester.o: ValueIndependantTester.h ValueIndependantTester.cpp
	g++ -c ValueIndependantTester.cpp

NumberTester.o: NumberTester.h NumberTester.cpp
	g++ -c NumberTester.cpp

TesterInterface.o: TesterInterface.h TesterInterface.cpp
	g++ -c TesterInterface.cpp
	
run:
	./main
	
clean:
	rm *.o main