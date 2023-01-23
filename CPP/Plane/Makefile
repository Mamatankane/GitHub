main: main.o Cargo.o Passenger.o SecretCargo.o
	g++ -static Cargo.o Passenger.o SecretCargo.o main.o -o main

Cargo.o: Cargo.cpp Cargo.h
	g++ -c Cargo.cpp

SecretCargo.o: SecretCargo.cpp SecretCargo.h
	g++ -c SecretCargo.cpp

Passenger.o: Passenger.cpp Passenger.h
	g++ -c Passenger.cpp

main.o: main.cpp Plane.cpp Exceptions.cpp Controller.cpp
	g++ -c main.cpp

run:
	./main
clean:
	rm *.o main