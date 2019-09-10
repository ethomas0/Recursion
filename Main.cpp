#include <iostream>
#include "Board.h"
#include "Robot.h"

using namespace std;

int main()
{
	// Test case 1
	Board B1(4, 6, {});
	Robot R1(0, 1, 2, 3, 5);
	R1.FindPath(B1);

	// Test case 2
	Board B2(5, 5, { 1,2,2,4,3,3,3,4,4,2,4,4 });
	Robot R2(3, 1, 4, 4, 1);
	R2.FindPath(B2);

	// Test case 3
	Board B3(7, 7, { 1,1,3,1,4,1,1,2,1,6,2,4,3,3,3,5,4,3,4,5,6,2,6,3,6,4,6,5,6,6 });
	Robot R3(3, 6, 1, 2, 6);
	R3.FindPath(B3);

	//Test case 4
	Board B4(4, 6, {2,2});
	Robot R4(0, 1, 2, 4, 2);
	R4.FindPath(B4);

	// Test case 5
	Board B5(4, 6, {1,2,2,3,3,2});
	Robot R5(0, 2, 2, 4, 5);
	R5.FindPath(B5);

	// Test case 6
	Board B6(4, 6, { 1,2,2,3,3,2,2,1 });
	Robot R6(0, 2, 2, 4, 5);
	R6.FindPath(B6);

	// Test case 7
	Board B7(4, 6, { 2,3,3,2,2,1 });
	Robot R7(0, 2, 2, 4, 5);
	R7.FindPath(B7);

	// Test case 8
	Board B8(7, 7, { 2,5,3,4,4,5 });
	Robot R8(0, 3, 5, 3, 2);
	R8.FindPath(B8);


	// Test case 9
	Board B9(7, 7, { 2,5,3,4,4,5 });
	Robot R9(1, 3, 5, 3, 2);
	R9.FindPath(B9);

	// Test case 10
	Board B10(1, 7, {});
	Robot R10(1, 1, 1, 1, 7);
	R10.FindPath(B10);



	return 0;
}