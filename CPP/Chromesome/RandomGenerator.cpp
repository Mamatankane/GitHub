#include "RandomGenerator.h"
#include <cmath>

RandomGenerator::RandomGenerator(int seed) : seed(seed) {
   srand(seed);
}
bool RandomGenerator::randomBool(){
   int rand_num=rand();
   if (rand_num%2==0) return false;
   else return true;
}