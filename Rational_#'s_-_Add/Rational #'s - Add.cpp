// Mark McKelvy
// CS 1:00 MWF
// October 11, 2002

// *** Preprocessor Directives ***
#include <iostream.h>

// *** Programmer Defined Data Types ***
struct rational
{
	int numerator;
	int denominator;
};

// *** Function Prototypes ***
rational Add (rational r1, rational r2);
void Enter (rational &r1, rational &r2);
void Print (rational r);

int main() 
{
	rational r1;
	rational r2;
	rational result;
	
	Enter (r1, r2);
	result = Add (r1, r2);
	Print (result);
	cout << endl;

	return 0;
}

rational Add (rational r1, rational r2)
{
	r2.numerator = r1.numerator * r2.denominator + r2.denominator * r1.numerator;
	r2.denominator = (r2.denominator * r1.denominator);
	return (r1, r2);
}

void Enter (rational &r1, rational &r2)
{
	cout << "Please enter a rational number one, separated by spaces: ";
	cin >> r1.numerator >> r1.denominator;
	cout << "Please enter a rational number two, separated by spaces: ";
	cin >> r2.numerator >> r2.denominator;
}

void Print (rational r)
{
	cout << "The number is: " << r.numerator << "/" << r.denominator << endl;
}

