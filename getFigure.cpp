#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

Matrix getFigure() {
	int nodeNumber = 0;
	cout << "How many node in the figure ?" << endl
		 << "Number? ";// enter the number of the Scenic Spot
	cin >> nodeNumber;	

	Matrix newFigure(nodeNumber,nodeNumber);// A new figure to store the road

	int flag = 0;// using in "while", judging whether input or not
	while(flag == 0) {
		char temp[5];// Store node data
		int length = 0;// Store road length
		cout << "Enter the two node, example(<1,2>)" << endl 
			 << "?";// enter the two node (if two node linked)
		cin >> temp;

		cout << "Enter the road length: " << endl
			 << "?";
		cin  >> length;

		int temp1 = (int)(temp[1] - '0');
		int temp2 = (int)(temp[3] - '0');

		newFigure[temp1][temp2] = length;		

		cout << "Do you want enter new? (enter 0 for next, enter 1 for exit)" << endl 
		     << "?";
		cin >> flag;
	}
	
	for (int i = 0; i < nodeNumber; ++i) {
		newFigure[i][i] = 1;
	}

	// for (int i = 0; i < nodeNumber; ++i) {
	// 	for(int j = 0; j < nodeNumber; ++j) {
	// 		if (newFigure[i][j] > 1)
	// 			newFigure[i][j] = 1;
	// 	}
	// }

	return newFigure;
}

int main(int argc, char const *argv[])
{
	Matrix road( 3, 3 ); 
	road = getFigure();
	
	for (int i = 0; i < 3; ++i)
	 {
	 	for (int j = 0; j < 3; ++j)
	 	{
	 		cout << road[i][j] << " ";
	 	}
	 	cout << endl;
	 } 
	return 0;
}