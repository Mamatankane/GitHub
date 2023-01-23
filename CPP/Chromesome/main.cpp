// Scenerio
// For this assignment, your GA will need to try and get all the chromosomes in the population to only
// contain 1’s. Although this can be easily programmed explicitly the idea is to investigate how the GA
// performs and to gain experience with pointers.
// what is a GA?
// Genetic Algorithms (GA) are a type of evolutionary algorithm developed by John H. Holland in
// the 1960’s. GAs are based on the idea of survival of the fittest where a fitness value is assigned to
// possible solution. This value is an indicator as to how well the possible solution solves the given
// problem. A GA consists out of a population of possible solutions also referred to as chromosomes.
// Each chromosome consists of a set of genes, which is used to encode the actual value of the possible
// solution. Chromosomes are usually encoded as a binary string where each bit represents a gene.

#include <iostream>
#include <ctime>

#include "Chromosome.h"
#include "FitnessFunction.h"
#include "GA.h"
#include "RandomGenerator.h"

using namespace std;

double avg(double** arr, int d, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i][d];
    }
    return sum / size;
}

void benchMark(int numGenerations, int popSize, int selectionSize, int numGenes, long seed, bool generationResults, bool timeResults) {
    RandomGenerator* randomGenerator = new RandomGenerator(seed);
    FitnessFunction* fitnessFunction = new FitnessFunction();
    GA* ga = new GA(popSize, randomGenerator, numGenes, selectionSize);
    clock_t startTime = clock();
    double** results = ga->run(fitnessFunction, numGenerations);
    clock_t endTime = clock();
    cout << "---" << endl;
    if (generationResults) {
        for (int i = 0; i < numGenerations; i++) {
            cout << "Gen " << i << endl;
            cout << "Avg accuracy: " << results[i][0] << endl;
            cout << "Std: " << results[i][1] << endl;
            cout << "Variance: " << results[i][2] << endl;
            cout << "---"<<endl;
        }
    }

    cout << "Run summary: " << endl;
    cout << "Avg avg: " << avg(results, 0, numGenerations) << endl;
    cout << "Avg std: " << avg(results, 1, numGenerations) << endl;
    cout << "Avg var: " << avg(results, 2, numGenerations) << endl;
    if(timeResults)
        cout << "Execution time: " << difftime(endTime, startTime)/1000 << "ms" << endl;

    for (int i = 0; i < numGenerations; i++) {
        delete[] results[i];
    }
    delete[] results;
    delete ga;
    delete fitnessFunction;
    delete randomGenerator;
}

void studentMain() {
    Chromosome** p = new Chromosome * [10];
    for (int i = 0; i < 10; i++) {
        bool* arr = new bool[10];
        for (int j = 0; j < 10; j++) {
            arr[j] = j%2;
            if (j == i) {
                arr[j] = false;
            }
        }
        p[i] = new Chromosome(arr, 10);
        delete[] arr;
    }
    RandomGenerator* rand = new RandomGenerator(12345);
    FitnessFunction* fitnessFunction = new FitnessFunction();
    GA* ga = new GA(10, rand, 10, 1);
    ga->setPopulation(p);

    for (int i = 0; i < 10; i++) {
        delete p[i];
    }
    delete[] p;
    cout << ga->calculateAvgAccuracy(fitnessFunction) << endl;
    cout << ga->calculateStd(fitnessFunction) << endl;
    cout << ga->calculateVariance() << endl;
    p = ga->run(fitnessFunction);
    ga->setPopulation(p);
    cout << ga->calculateAvgAccuracy(fitnessFunction) << endl;
    cout << ga->calculateStd(fitnessFunction) << endl;
    cout << ga->calculateVariance() << endl;
    for (int i = 0; i < 10; i++) {
        delete p[i];
    }
    delete[] p;
    delete ga;
    delete rand;
    delete fitnessFunction;
    benchMark(10, 10, 1, 10, 500, true, false);
}

int main()
{ 
    studentMain();
    return 0;
}