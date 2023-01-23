//Include for Task2 testing
#ifndef T2T_CPP
#define T2T_CPP

#include "CountArray.h"
#include "SumArray.h"
#include "SortArray.h"

using namespace std;

namespace Phase2 {

	void runTest()
	{
		srand(time(0));
		const int Rows = 1+ (rand() % 10);
		const int Cols = 1+ (rand() % 10);

		int** array = new int*[Rows];
		int* sizes = new int[Rows];

		int count = 0;

		//Create array
		for (int i=0;i<Rows;i++)
		{
			sizes[i] = Cols;
			array[i] = new int[Cols];

			for (int k=0;k<sizes[i];k++)
			{
				array[i][k] = count++;
			}
		}

		//Constructor call
		CountArray tester1(array, sizes, Rows);
		SumArray tester2(array, sizes, Rows);
		SortArray tester3(array, sizes, Rows);



		for (int i=0;i<Rows;i++)
		{
			cout<<"Count: "<<*tester1[i]<<endl;
			cout<<"Sum: "<<*tester2[i]<<endl;
			int* arr = tester3[i];

			cout<<"Sorted: "<<endl;
			for (int k=0;k<sizes[i];k++)
				cout<<arr[k]<<" ";
			cout<<endl<<endl;
		}



		for (int i=0;i<Rows;i++)
		{
			delete [] array[i];
		}
		delete [] array;
		delete [] sizes;

	}


}



#endif
