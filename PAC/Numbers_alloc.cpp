#include <stdio.h>
#include<iostream>
using namespace std;



int main() {
	
	cout << "Please Given the input numbers: \n";
	int Max = 0, LMax = 0;
	int tmp;
	cout << "? ";
	cin >> tmp;
	if (tmp != 0)
		Max = tmp;

	while (true)
	{
		
		if (tmp != 0)
		{
			cout << "? ";
			cin >> tmp;
		}

		if (Max == 0 && LMax == 0)
			return -1;
		else
		if (tmp == 0&&LMax!=0)
			break;
		else
		{
			cout << "Not Enough numbers! , at least one more number please! \n";
				return -1;
		}

		if (LMax == 0) {
			if (tmp >= LMax)
				if (tmp > Max) {
					LMax = Max;
					Max = tmp;
				}
				else 
					LMax = tmp;
		}

		else if (tmp >= Max)
		{
			if (Max > LMax)
				LMax = Max;
			Max = tmp;

		}
		else
		if (tmp > LMax)
			LMax = tmp;


	}
	
	cout << "So the Biggest number is " << Max << " and the smaller number is " << LMax<<endl;
}
