main: main.o RandomGenerator.h RandomGenerator.o GA.h GA.o FitnessFunction.h FitnessFunction.o Chromosome.h Chromosome.o
	g++ -static RandomGenerator.o GA.o FitnessFunction.o Chromosome.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp
	
RandomGenerator.o: RandomGenerator.h RandomGenerator.cpp  
	g++ -c RandomGenerator.cpp
	
GA.o: GA.h GA.cpp  
	g++ -c GA.cpp

FitnessFunction.o: FitnessFunction.h FitnessFunction.cpp  
	g++ -c FitnessFunction.cpp

Chromosome.o: Chromosome.h Chromosome.cpp  
	g++ -c Chromosome.cpp

run:
	./main
	
clean:
	rm -f *.o main
