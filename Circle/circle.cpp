// Area of a cirlce program
// Mark McKelvy
//
// Purpose: for credit

// Prog to calculate the area of a cirlce
#include<iostream.h>
int main()
{
	const float pi = 3.1415f;
	int radius;
	float farea;
	cout << "key in an integer that is the radius of a circle ";
	cin >> radius;
	farea = radius * radius * pi;
	cout << "\n The area is "<< farea << '\n';
	return 0;
}