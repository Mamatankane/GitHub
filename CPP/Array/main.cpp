

#include <iostream>
#include <cstdlib>

#include "Task1.cpp"
#include "Task2.cpp"


using namespace std;

int main()
{

	Phase1::runTest();
	Phase2::runTest();

	return 0;
}


/*
For Task1:
Contents:
0 1 2
3 4 5
6 7 8

Contents of copied array:
0 1 2 
3 4 5 
6 7 8 
*/

/*
For Task2:
Count: 3
Sum: 3
Sorted: 
0 1 2 

Count: 3
Sum: 12
Sorted: 
3 4 5 

Count: 3
Sum: 21
Sorted: 
6 7 8 

*/
