#include "Chromosome.h"
Chromosome::Chromosome(int numGenes, RandomGenerator* rand){
   if (numGenes<0) {
      this->genes=new bool[0];
      this->numGenes=0;
   }
   else{
      this->genes= new bool[numGenes];
      this->numGenes=numGenes;
      if (rand==NULL){
         for (int i=0; i<numGenes; i++) this->genes[i]=false;
      }
      else{
         for (int i=0; i<numGenes; i++) this->genes[i]=rand->randomBool();
      }
   }

}
Chromosome::Chromosome( Chromosome * chromosome){
    if (chromosome==NULL){
         this->genes=new bool[0];
         this->numGenes=0;
      }
      else{
         this->genes= new bool[chromosome->numGenes];
         this->numGenes=chromosome->numGenes;
         for (int i=0; i<numGenes; i++) this->genes[i]=chromosome->genes[i];
      }
}
Chromosome::Chromosome(bool * genes, int numGenes){
   if (numGenes<0) {
      this->genes=new bool[0];
      this->numGenes=0;
   }
   else{
      this->genes= new bool[numGenes];
      this->numGenes=numGenes;
      if (genes==NULL){
         for (int i=0; i<numGenes; i++) this->genes[i]=false;
      }
      else{
         for (int i=0; i<numGenes; i++) this->genes[i]=genes[i];
      }
   }

}
Chromosome::~Chromosome(){
   delete [] this->genes;
}
double Chromosome::fitness(FitnessFunction* fitnessFunction, Chromosome* chromosome, int numGenes){
   if ((fitnessFunction==NULL)|| (chromosome==NULL) ||(numGenes<=0))
      return 0;
   else 
      return fitnessFunction->calculateFitness(chromosome,numGenes);


}
int Chromosome::getNumGenes(){
   return numGenes;
}
Chromosome* Chromosome::crossOver( Chromosome* c2) {
   Chromosome *newChromosome;
   if (c2==NULL){
      newChromosome= new Chromosome(this);
   }
   else {
      int crossOverPoint= floor((c2-> numGenes)/2);
      bool * nGenes=new bool[c2->numGenes];
      for (int i=0; i<crossOverPoint; i++){
         nGenes[i]=this->genes[i];
      } 
      for (int i=crossOverPoint; i<numGenes; i++){
         nGenes[i]= c2->genes[i];
      }
         newChromosome= new Chromosome(nGenes,this->numGenes);
   delete [] nGenes;
   }

   return newChromosome;
}
Chromosome* Chromosome::mutate(){
   bool * nGenes= new bool[this->numGenes];
   for (int i=0; i<this->numGenes; i++){
      if (genes[i]==1) nGenes[i]=0;
      else nGenes[i]=1;
   }
   Chromosome *newChromosome= new Chromosome(nGenes,this->numGenes);
   delete [] nGenes;
   return newChromosome;
}
std::string Chromosome::toString(){
   std::string String;
    for (int j=0; j<this->numGenes; j++){
           if (this->genes[j]==true) String+='1';
            else String+='0';
        }
   return String;
}
bool* Chromosome::getGenes(){
   return this->genes;
}