#include <iostream>
#include "Matrix.h"

class School
{
public:
	School();
	School( SS_Node[], Matrix );
	//~School();

private:
	SS_Node[] Scenic_Spot;// store Scenic Spot 
	Matrix School_road;// store School road

};

School::School(  SS_Node[] Scenic, Matrix road ) {
	Scenic_Spot = Scenic;
}

		
int main(int argc, char const *argv[])
{
	School a;                                               
	return 0;
}