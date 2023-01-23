// Scenerio
// You will create a wrapper class for a 2D integer array called TwoDArray. Overloading some operators will provide output for usage outside the class.
// For this use case once the 2D array is contained by an object of this class, we don’t want it to be
// modified again. Thus, all the operations performed by the child classes will be read-only.
// In Task 2, you will create the actual derived classes that each perform specific operations on the data
// contained in the 2-dimensional array. These classes will have access to the 2D array of the parent
// class, but will use the data in different ways despite the fact that the same function call is used ([ ]).
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
