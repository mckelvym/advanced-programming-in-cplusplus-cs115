// mark mckelvy
// simple sizeof program

#include <iostream>
using namespace std;

int main()
{
	int one = 55;
	float two = 99.3f;
	char three = 'Q';
	unsigned long big = 999999999999999;
	int size;

	size = sizeof(one);
	cout << "The int box is: " << size << " bytes in size." << endl;

	size = sizeof(two);
	cout << "The float box is: " << size << " bytes in size." << endl;

	size = sizeof(three);
	cout << "The char box is: " << size << " bytes in size." << endl;

	size = sizeof(big);
	cout << "The unsigned long (big) box is: " << size << " bytes in size." << endl;
	cout << endl;

	return 0;
}
