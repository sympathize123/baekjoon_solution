#include <iostream>
#include <stack>
using namespace std;
int main()
{
	long long unsigned int times, input, max = 0;
	stack<long long unsigned int> histogram;
	cin >> times; cin.ignore();
	for (long long unsigned int i = 0; i < times; i++)
	{
		cin >> input;
		if (histogram.empty())
		{
			histogram.push(input);
		}
		else if (histogram.top() <= input)
		{
			histogram.push(input);
		}
		else
		{
			while (histogram.top() > input)
			{
				long long unsigned int max_height = histogram.top(); long long unsigned int count = 0; long long unsigned int area = 0, a = 0;
				while (max_height == histogram.top())
				{
					histogram.pop();
					count++;
					if (histogram.empty())
					{
						for (long long unsigned int i = 0; i < count; i++)
							histogram.push(input);
						histogram.push(input);
						area = max_height * count;
						if (area > max)
							max = area;
						a = 1;
						break;
					}
				}
				area = max_height * count;
				if (input < histogram.top() && a != 1)
				{
					max_height = histogram.top();
					for (long long unsigned int i = 0; i < count; i++)
						histogram.push(max_height);
				}
				else if (a != 1 && input >= histogram.top())
				{
					for (long long unsigned int i = 0; i < count; i++)
						histogram.push(input);
					histogram.push(input);
				}
				if (area > max && a != 1)
					max = area;
				max_height = histogram.top(); count = 0; area = 0; a = 0;
			}
		}
	}
	long long unsigned int max_height = histogram.top(); long long unsigned int count = 0, area = 0, a = 0;
	while (!histogram.empty())
	{
		while (max_height == histogram.top())
		{
			histogram.pop();
			count++;
			if (histogram.empty())
			{
				area = max_height * count;
				if (area > max)
					max = area;
				a = 1;
				break;
			}
		}
		area = max_height * count;
		if (a != 1 && max_height > histogram.top())
		{
			max_height = histogram.top();
			for (long long unsigned int i = 0; i < count; i++)
				histogram.push(max_height);
		}
		if (area > max && a != 1)
			max = area;
		count = 0; area = 0; a = 0;
	}
	cout << max;
}