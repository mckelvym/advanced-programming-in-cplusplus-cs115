// Mark McKelvy
// This program squares a whole number

#include <iostream.h>

// *** Function Declarations ***
int get_input();
int square(int x);
int output(int y);

int main()
{
	int x;
	int y;
	x = get_input();
	y = square(x);
	output(y);

	return 0;
}

int get_input()
{
	int number;	
	cout << "Please enter a whole number to be squared: ";
	cin >> number;
	return (number);
}

int square(int x)
{
	int sq;
	sq = x * x;
	return (sq);
}

int output(int y)
{
	cout << endl << "The Number Squared is: " << y << endl;
	return 0;
}

