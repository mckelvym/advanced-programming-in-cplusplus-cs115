#include<iostream.h>
#include<iomanip.h>

void main()
{
	cout.setf(ios::fixed);
	
	for(unsigned long double i = 999999999999999; i >= 1; i = i / 1.01)
	{
		if(i < 511111111111111)
		{
			i = i + 488888888888888;
		}

		cout << setprecision(0) << i << i << i << i << i << endl;	
	}

}