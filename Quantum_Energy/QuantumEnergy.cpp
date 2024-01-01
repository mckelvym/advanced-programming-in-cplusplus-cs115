// Mark McKelvy

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
using namespace std;

// *** function prototypes ***
void q_energy();			// function to calculate quantum energy
void wave_length();			// function to calculate wavelength
int menu();					// what operation will be performed?

int main()
{
	int choice;

	while (true)
	{
		choice = menu();

		switch (choice)
			{
			case 1:
				cout << endl << endl;
				q_energy();
				break;
			case 2:
				cout << endl << endl;
				wave_length();
				break;
			default:
				cout << endl << endl << menu();
				break;
			}
	}
	return 0;
}

int menu()
{
	int choice;

	cout << "Please choose which operation you would like to perform: " << endl << endl;
	cout << "******************************************" << endl;
	cout << "* 1 - Quatum Energy of an Electron       *" << endl;
	cout << "* 2 - Wavelength of an Electron          *" << endl;
	cout << "*                                        *" << endl;
	cout << "* Type '0' to exit                       *" << endl;
	cout << "******************************************" << endl;
	cout << endl;
	cin >> choice;
	if (choice == 0)
		{
			exit(0);
		}
	return (choice);
}

void q_energy()
{
	cout.setf(ios::uppercase);
	cout.setf(ios::scientific);

	const long double planck = pow(10, -34) * 6.62605f;
	const long double lightspeed = 3.000f * pow(10, 8);
	long double wavelength;
	long double quantum_energy;
	long firstpart;
	long power;
	char E;

	cout << "*********************************************************" << endl;
	cout << "*** Please enter wavelength in the form of '3.00 E 8' ***" << endl;
	cout << "*********************************************************" << endl << endl;
	cin >> firstpart >> E >> power;

	wavelength = firstpart * pow(10, power);
	quantum_energy = (planck * lightspeed) / wavelength;

	cout << endl << endl << "Quantum Energy (E) = " << quantum_energy << " Joules" << endl << endl;
}

void wave_length()
{
	cout.setf(ios::uppercase);
	cout.setf(ios::scientific);

	const long double planck = pow(10, -34) * 6.62605f;
	const long double lightspeed = 3.000f * pow(10, 8);
	long double wavelength;
	long double quantum_energy;
	long firstpart;
	long power;
	char E;

	cout << "*****************************************************" << endl;
	cout << "*** Please enter energy in the form of '3.00 E 8' ***" << endl;
	cout << "*****************************************************" << endl << endl;
	cin >> firstpart >> E >> power;

	quantum_energy = firstpart * pow(10, power);
	wavelength = (lightspeed * planck) / quantum_energy;

	cout << endl << endl << "Wavelength (lambda) = " << wavelength << " Meters" << endl << endl;
}
