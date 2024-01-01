// Mark McKelvy
/* This Program will take a phrase and reverse the characters */

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int count;
	char swapchar;
	char text[127];

	cout << "Hey you, enter some random text to be reversed: ";
	cin.get(text, 127);
	count = strlen(text);
	for(int i = 0; i < count / 2; i++)
	{
		swapchar = text[i];
		text[i] = text[count-1-i];
		text[count-1-i] = swapchar;
	}

	cout << text << endl << endl;
	return 0;
}
