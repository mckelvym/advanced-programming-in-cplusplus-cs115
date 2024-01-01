// Mark McKelvy
/* This Program will show all numbers that are a factor of 2 and 3
   including the number entered. */

#include <iostream>
using namespace std;

int main ()
{
	int i;

	cout << "*** This Program will show all numbers that are a factor of 2 and 3\nincluding the number entered ***" << endl << endl;
	cout << "Please enter a number: ";
	cin >> i;

	for ( ; i > 1; i--)
	{
		if (i % 2 == 0 && i % 3 == 0)
		{
			cout << i << " ";
		}
	}
	cout << endl << endl;
	return 0;
}
