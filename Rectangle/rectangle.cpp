// Area of a rectangle program
// Mark McKelvy
//
// Purpose: for credit

// Prog to calculate the area of a rectangle
#include<iostream.h>
int main()
{
	int side1;
	int side2;
	int area;
	cout << "key in an integer for side 1 of a rectangle ";
	cin >> side1;
	cout << "key in an integer for side 2 of a rectangle ";
	cin >> side2;
	area = side1 * side2;
	cout << "\n The area is "<< area << '\n';
	return 0;
}
