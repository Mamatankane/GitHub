//Include for Task1 testing

#ifndef T1T_CPP
#define T1T_CPP

#include "TwoDArray.h"
#include <iostream>

using namespace std;


namespace Phase1 {

	void runTest()
	{
		srand(time(0));
		const int Rows = 1+ (rand() % 10);
		const int Cols = 1+ (rand() % 10);
		cout<<Rows<<" , "<<Cols<<endl;

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
		TwoDArray tester(array, sizes, Rows);

		//Test operator<<
		cout<<"Contents:\n"<<tester<<endl;


		//Test conversion overloads
		int** othArray = tester;
		int* othSizes = tester;
		int othSize = tester;

		cout<<"Contents of copied array:"<<endl;
		for (int i=0;i<othSize;i++)
		{
			for (int k=0;k<othSizes[i];k++)
				cout<<othArray[i][k]<<" ";
			cout<<endl;
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
