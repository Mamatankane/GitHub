#include "FitnessFunction.h"

double FitnessFunction::calculateFitness(Chromosome* chromosome, int numGenes){
   int counter=0;
   for (int i=0; i<numGenes; i++){
      if (chromosome->getGenes()[i]==true) ++counter; 
   }
   return (double) counter/numGenes;
}