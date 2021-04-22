#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
int main()
{
	long long unsigned int times;
	stack<int> histogram;
	stringstream ss;
	string get_input;
	int height[100000];
	while (1)
	{
		getline(cin, get_input);
		ss.str(get_input);
		ss >> times;
		if (times == 0)
			break;
		for (int i = 0; i < times; i++)
			ss >> height[i];
		long long max = 0;
		for (int i = 0; i < times; i++) 
		{
			while (!histogram.empty() && height[histogram.top()] > height[i])
			{
				long long max_height = height[histogram.top()];
				histogram.pop();
				long long unsigned int width = i;
				if (!histogram.empty()) 
					width = i - histogram.top() - 1;
				if (max < max_height * width)
					max = max_height * width;
			}
			histogram.push(i);
		}
		while (!histogram.empty())
		{
			long long unsigned int max_height = height[histogram.top()];
			histogram.pop();
			long long unsigned int width = times;
			if (!histogram.empty())
				width = times - histogram.top() - 1;
			if (max < max_height * width)
				max = max_height * width;
		}
		std::cout << max << "\n";
		ss.str(""); ss.clear();
	}
}