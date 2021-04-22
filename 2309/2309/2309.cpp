#include <iostream>
using namespace std;

int main()
{
	int input, sum = 0,height[9];
	int temp1, temp2, max, a = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> input;
		sum += input;
		height[i] = input;
	}
	for (int i = 0; i < 9; i++)
	{
		for (int t = i + 1; t < 9; t++)
		{
			if ((sum - height[i] - height[t]) == 100)
			{
				height[i] = 101; height[t] = 101;
				a = 1;
			}
		}
		if (a == 1)
			break;
	}
	for (int i = 0; i < 9; i++)
	{
		max = height[i];
		temp1 = i;
		for (int t = i; t < 9; t++)
		{
			if (max > height[t])
			{
				max = height[t];
				temp1 = t;
			}
		}
		temp2 = height[i];
		height[i] = max;
		height[temp1] = temp2;
	}
	for (int i = 0; i < 7; i++)
		cout << height[i] << endl;
}