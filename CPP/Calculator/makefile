main: main.o
	g++ main.o -g -o main

main.o: Operator.h Operator.cpp MinusOperator.cpp MinusOperator.h MultiplyOperator.h MultiplyOperator.cpp PlusOperator.h PlusOperator.cpp Stack.h Stack.cpp Calculator.cpp Calculator.h Node.h Node.cpp main.cpp
	g++ main.cpp -g -c main.o

run:
	./main

clean:
	rm *.o main *.zip

tar:
	zip u22524798.zip -main.cpp *.h *.cpp
