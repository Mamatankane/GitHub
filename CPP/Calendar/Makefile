main: main.o Event.o Calendar.o
	g++ -g -static Calendar.o Event.o main.o -o main

main.o: main.cpp 
	g++ -g -c main.cpp

Event.o: Event.h Event.cpp
	g++ -g -c Event.cpp

Calendar.o: Calendar.h Calendar.cpp
	g++ -g -c Calendar.cpp

run:
	 ./main

clean:
	rm *.o main