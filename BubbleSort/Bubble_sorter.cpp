// Mark McKelvy
// Develop C++ code to Bubble sort a 10 int array & search that array for a target value
// return its position in the array.

#include <iostream>
using namespace std;

int main ()
{
	int iarray [10];
	int i;
	int j;
	int flag = 1;
	int lowerbound = 0;
	int upperbound = 10;
	int search_num = iarray[9], search_pos,temp, compare_count;


	for (i = 9; i >= 0; i--)
		iarray[i] = i;

	for (i =0; i<= 9; i++)
	{
		flag = 0;
		for(j = 0; j < 10; j++)
		{
			if (iarray[j + 1] < iarray[j])
			{
				temp = iarray[j + 1] = iarray[j];
				iarray[j] = temp;
				flag = 1;
			}
		}
	}

	search_pos = (lowerbound + upperbound) / 2;
	while((iarray[search_pos] != search_num) && (lowerbound <= upperbound))
	{
		compare_count++;
		if(iarray[search_pos] > search_num)
		{
			upperbound = search_pos - 1;
		}
		else
		{
			lowerbound = search_pos + 1;
		}
		search_pos = (lowerbound + upperbound) / 2;
	}
	if(lowerbound <= upperbound)
	{
		cout << "A binary serach found the number in " << compare_count << " comparisons.\n";
	}
	else
	{
		cout << "Number not found by binary search after " << compare_count << " comparisons.\n";
	}


	return 0;
}
