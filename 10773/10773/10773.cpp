#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int times, input, sum = 0;
	cin >> times; cin.ignore();
	stack<int> array;
	for (int i = 0; i < times; i++)
	{
		cin >> input;
		if (input == 0)
			array.pop();
		else
			array.push(input);
	}
	while (array.empty() == false)
	{
		sum += array.top();
		array.pop();
	}
	cout << sum;
}