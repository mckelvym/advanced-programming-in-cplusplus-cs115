// Mark McKelvy
// Original Programmer Michael LeBlanc
// August 28, 2002

// This program performs the math necessary for a quadratic equation.

#include <iostream>		// for cin and cout commmands
#include <math.h>			// for the sqrt command

using namespace std;

int main()
{
		// Values for answers and numbers.
		float A;			// A Value
		float B;			// B Value
		float C;			// C Value
		float disc;			// Discriminate
		float X1;			// Positive solution when discriminant is positive.
		float X2;			// Negative solution when discriminant is positive.
		float real;			// First half of equation when disc. is negative.
		float imag;			// Second half of equation when disc. is negative.

		// Now ask user for values

		cout << "What shall be your A value sir? ";
		cin >> A;
		cout << "What shall be your B value sir? ";
		cin >> B;
		cout << "What shall be your C value sir? ";
		cin >> C;

// Now use formula to get the solution

		disc = (B * B) * (-4) * A * C;
		if (disc < 0) {  // Makes negative discriminate positive so it can find
        // the square root.

            disc = -disc;
            real = -B / (2 * A);
            imag = float (sqrt(disc)) / (2 * A);	// float command forces sqrt to be
            // a float and (not double).
            cout << real << "+ " << imag << "i is the pos. solution." << endl;
            cout << real << "- " << imag << "i is the neg. solution." << endl;
        }
        else {
            X1 = (-B + float(sqrt(disc))) / (2.0f * A);
            X2 = (-B - float(sqrt(disc))) / (2.0f * A);
            cout << "The positive solution is " << X1 << " \n";
            cout << "The negative solution is " << X2 << " \n";

        }
        cout << "Press any character + enter to continue. ";
        char ch; // Makes the .exe wait for a char input b4 it closes so that
                 // the answer is visible.

        cin >> ch;
        return 0;
}
