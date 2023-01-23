#include "GA.h"

GA::GA(int populationSize, RandomGenerator* rand, int numGenes, int selectionSize)
: populationSize(populationSize), selectionSize(selectionSize){
   this->population=new Chromosome *[populationSize];
   for (int i=0; i<populationSize; i++){
      this->population[i]= new Chromosome(numGenes,rand);
   }


}
GA::GA(GA*geneticAlgorithm){
   if (geneticAlgorithm!=NULL){
         this->population=new Chromosome *[geneticAlgorithm->populationSize];
         this->populationSize= geneticAlgorithm->populationSize;
         this->selectionSize= geneticAlgorithm->selectionSize;
         for (int i=0; i<this->populationSize; i++){
         this->population[i]= new Chromosome(geneticAlgorithm->population[i]) ;

         }
   }
}
GA::~GA(){
   for (int i=0; i<(this->populationSize);i++){
      this->population[i]->~Chromosome();
   }
   delete [] population;
}
Chromosome** GA::selection(FitnessFunction* fitnessFunction) {
   double* ffChromo= new double[this->populationSize];
   Chromosome ** SortedChromo= new Chromosome *[this->populationSize];
  for (int i=0; i<this->populationSize; i++){
     ffChromo[i]= fitnessFunction->calculateFitness(population[i],population[i]->getNumGenes()); }

  for (int i = 0; i < this->populationSize; i++){
      double greatest= -1;
      int index=-1;
      for (int j=0; j< this->populationSize; j++){
         if (ffChromo[j]>greatest){
            index=j;
            greatest= ffChromo[j];
         }
      }
      SortedChromo[i]=new Chromosome(*population[index]);
      ffChromo[index]=-1;
   }  
   delete [] ffChromo; 
   return SortedChromo;

}
Chromosome** GA::inverseSelection(FitnessFunction* fitnessFunction) {
   double* ffChromo= new double[this->populationSize];
   Chromosome ** SortedChromo= new Chromosome *[this->populationSize];
  for (int i=0; i<this->populationSize; i++){
     ffChromo[i]= fitnessFunction->calculateFitness(population[i],population[i]->getNumGenes()); }

  for (int i=0; i< this->populationSize; i++){
      double smallest= 11;
      int index=-1;
      for (int j = this->populationSize-1; j >= 0; j--){
         if (ffChromo[j]<smallest){
            index=j;
            smallest= ffChromo[j];
         }
      }
      SortedChromo[i]=new Chromosome(*population[index]);
      ffChromo[index]=11;
   }  
   delete [] ffChromo; 
   return SortedChromo;
}
Chromosome** GA::crossOver( Chromosome* c1, Chromosome* c2) {
   Chromosome ** arrOfChromo= new Chromosome*[2];
   arrOfChromo[0]=new Chromosome(c1);
   arrOfChromo[1]=new Chromosome(c2);
   arrOfChromo[0]=arrOfChromo[0]->crossOver(c2);
   arrOfChromo[1]= arrOfChromo[1]->crossOver(c1);
   return arrOfChromo;
    
}
Chromosome* GA::mutate( Chromosome* c1){
   Chromosome * mutateChromo= new Chromosome(c1);
   return mutateChromo->mutate();
}
double GA::calculateAvgAccuracy(FitnessFunction* fitnessFunction){
   double total=0;
   for (int i=0; i< this->populationSize; i++){
      total+=fitnessFunction->calculateFitness(this->population[i],this->population[i]->getNumGenes());
   }
   return total/this->populationSize;
}
double GA::calculateStd(FitnessFunction* fitnessFunction){
   double sum=0;

   for (int i=0; i<this->populationSize; i++){
   
      double difference=(fitnessFunction->calculateFitness(this->population[i],this->population[i]->getNumGenes())-this->calculateAvgAccuracy(fitnessFunction));
      sum+= pow(difference,2);
   }
   return sqrt(sum/this->populationSize);

}
double GA::calculateVariance(){
   int unique=0;
   std::string genes="";
   for (int i=0; i<this->populationSize; i++){
         std::string copy= this->population[i]->toString();
        if (genes.find(copy)==-1){
         ++unique;
         genes+=copy+',';
        }
        
    }
   return  (double) unique/this->populationSize;
}
void GA::setPopulation( Chromosome** p){
    for (int i=0; i<this->populationSize; i++){
       this->population[i]= new Chromosome(p[i]);
    }

}
Chromosome** GA::run(FitnessFunction *fitnessFunction){
   Chromosome** winner= this->selection(fitnessFunction);
   Chromosome ** loser= this->inverseSelection(fitnessFunction);
   Chromosome **offspring= new Chromosome *[(this->selectionSize) *3];
   Chromosome ** P=new Chromosome*[this->populationSize];
   for (int i=0; i<((this->selectionSize) *2); i++){
      Chromosome ** nChromosome= this->crossOver(winner[i],winner[i+1]);
      offspring[i]= nChromosome[0];
      offspring[i+1]= nChromosome[1];
      ++i;
   }
   for (int i=0; i<this->selectionSize; i++){
      offspring[i+((this->selectionSize)*2)]= this->mutate(winner[i+((this->selectionSize) *2)]);

       }
   for(int i=0; i<this->populationSize; i++){
         P[i]= this->population[i];
   }
   for (int i=0; i<((this->selectionSize) *3); i++){
      Chromosome * dyingChromosome = loser[i];
      std::string sdeadChromo="";
      sdeadChromo= dyingChromosome->toString();
      std::string sPpop;
      int u=this->populationSize;
      while (sPpop!=sdeadChromo){
         sPpop="";
         u--;
         sPpop=P[u]->toString(); 

      }
      P[u]=offspring[i];
   }
   delete [] offspring;
   return P;
}
double ** GA::run(FitnessFunction *fitnessFunction, int numGenerations){

   double ** results= new double *[numGenerations];
   for (int i=0; i<numGenerations; i++){
      results[i]= new double [3];
      Chromosome **P = this->run(fitnessFunction);
      this->population=P;
      results[i][0]= this->calculateAvgAccuracy(fitnessFunction);
      results[i][1]=this->calculateStd(fitnessFunction);
      results[i][2]= this->calculateVariance();
   }
   return results;


}