// Programmed By Mark McKelvy
// Adds, Subtracts, Multiplies, and Divides Complex Numbers



#include <iostream.h>

main()

{
// Declare all Variables

	float a;
	float b;
	float c;
	float d;
	float real;
	float imag;
	float foilone;
	float foiltwo;
	float denominator;
// And characters...
	char i;					


// Input From User
// Asks for two complex numbers then...

	cout << "Input Complex Number 1, then HIT enter " << '\n' << '\n';
// Store first complex number into parts "a", "b", and "i".
	cin >> a >> b >> i;
	cout << '\n' << "Input Complex Number 2, then HIT enter " << '\n' << '\n';
// Store second complex number into parts "c", "d", and "i".
	cin >> c >> d >> i;

// Adds

	real = a + c;
	imag = b + d;
	cout << '\n' << "The addition " << '\n' << real << "+" << imag << "i\n\n";
	// Print

// Subtracts

	real = a - c;
	imag = b - d;
	cout << "The Subtraction " << '\n' << real << "-" << imag << "i\n\n";
	// Print

// Multiplies

	real = a * c;
	imag = b * d;
	foilone = a * d;
	foiltwo = b * c;
	cout << "The Multiplication " << '\n' << "(" << real << "-" << imag << ")" << "+" << "(" << foilone << "+" << foiltwo << ")" << "i\n\n";
	// Print once again

	// Divides

	denominator = (c * c) + (d * d);
	cout << "The Division \n \n(Numerator) " << '\n' << "(" << real << "+" << imag << ")" << "+" << "(" << foiltwo << "-" << foilone << ")" << "i\n";
	cout << '\n' << "(Denominator) " << '\n' << denominator << '\n' << endl;
	// Again?

	return 0;

	// End Program, Duh!
}