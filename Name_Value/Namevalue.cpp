// Mark McKelvy
// Name value.cpp

#include <iostream.h>

// *** Function Prototypes ***


int main()
{
	char name[] = "";
	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	int value;
	int total;
	for (value = 0; alphabet[value] != '\0'; value++)
	{
		alphabet[value] =  value;
	}
	
	cin >> name;
	value = name[];
	total = value + name[alphabet];

	cout << total;

	return 0;
}
