#include <iostream>
#include <string>
#include <vector>
using namespace std;

class light_switch
{
public:
	int** array;

	void switching_light(int** array, int row, int column)
	{
		if (row > 9 || column > 9 || row < 0 || column < 0)
			return;
		else if (array[row][column] == 0)
			array[row][column] = 1;
		else
			array[row][column] = 0;
	}

	void s_l_2(int** array, int row, int column)
	{
		switching_light(array, row, column);
		switching_light(array, row - 1, column);
		switching_light(array, row, column - 1);
		switching_light(array, row + 1, column);
		switching_light(array, row, column + 1);
	}

	bool check_if_all_off(int** array)
	{
		int count = 0;
		for (int i = 0; i < 10; i++)
			for (int t = 0; t < 10; t++)
				if (array[i][t] == 0)
					count++;
		if (count == 100)
			return true;
		else
			return false;
	}
	
	void combination(vector<int> arr, int k, int r,int* detect)
	{
		if (r == 0)
		{
			int row, column;
			for (int i = 0; i < arr.size(); i++)
			{
				row = arr[i] / 10; column = arr[i] % 10;
				s_l_2(array, row, column);
			}
			if (check_if_all_off(array))
			{
				cout << arr.size();
				*detect = 1;
			}
			else
			{
				for (int i = 0; i < arr.size(); i++)
				{
					row = arr[i] / 10; column = arr[i] % 10;
					s_l_2(array, row, column);
				}
			}
		}
		else if (k == 100)
			return;
		else
		{
			arr.push_back(k);
			combination(arr, k + 1, r - 1,detect);
			arr.pop_back();
			combination(arr, k + 1, r,detect);
		}
	}
};

int main()
{
	string input;
	vector<int> arr;
	light_switch obj;
	obj.array = new int* [10];
	for (int i = 0; i < 10; i++)
		obj.array[i] = new int[10];
	int* detect = new int();
	*detect = 0;
	for (int i = 0; i < 10; i++)
	{
		getline(cin, input);
		for (int t = 0; t < 10; t++)
		{
			if(input[t] == '#')
				obj.array[i][t] = 0;
			else
				obj.array[i][t] = 1;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		obj.combination(arr, 0, i, detect);
		if (*detect == 1)
			break;
	}
	if (*detect == 0)
		cout << -1;
	for(int i = 0;i < 10;i++)
		delete[] obj.array[i];
	delete[] obj.array;
}