#include <iostream>
using namespace std;

void stop(char street[]);
void go(char street[]);
void delay_me();

int main()
{
	int counter = 0;
	char NS[3] = "NS";
	char EW[3] = "EW";

	while (counter < 10)
	{
		if (counter % 2 == 0)
		{
			stop(NS);
			go(EW);
		}
		else
		{
			stop(EW);
			go(NS);
		}
		counter++;
	}
	return 0;
}

void stop (char street[])
{
	cout << street << " is RED." << endl << endl;
}

void go (char street[])
{
	cout << street << " has RED with GREEN ARROW." << endl;
	delay_me();

	cout << street << " has GREEN." << endl;
	delay_me();

	cout << street << " has YELLOW." << endl << endl << endl << endl << endl;
	delay_me();
}

void delay_me()
{
	for(unsigned long i = 69999999; i > 1; i--);
}
