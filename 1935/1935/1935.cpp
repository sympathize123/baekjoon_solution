#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int times;
	stack<double> pf_stack;
	double integer[26] = { 0 };
	string input;
	cin >> times; cin.ignore();
	getline(cin, input);
	for (int i = 0; i < times; i++)
	{
		double get_integer; cin >> get_integer;
		integer[i] = get_integer;
	}
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 65 && input[i] <= 90)
			pf_stack.push(integer[input[i] - 'A']);
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			double float1; 
			double float2;
			char op = input[i];
			switch (op)
			{
			case '+':
				float1 = pf_stack.top(); pf_stack.pop(); float2 = pf_stack.top(); pf_stack.pop();
				pf_stack.push(float1 + float2);
				break;
			case '-':
				float1 = pf_stack.top(); pf_stack.pop(); float2 = pf_stack.top(); pf_stack.pop();
				pf_stack.push(float2 - float1);
				break;
			case '/':
				float1 = pf_stack.top(); pf_stack.pop(); float2 = pf_stack.top(); pf_stack.pop();
				pf_stack.push(float2 / float1);
				break;
			case '*':
				float1 = pf_stack.top(); pf_stack.pop(); float2 = pf_stack.top(); pf_stack.pop();
				pf_stack.push(float1 * float2);
				break;
			}
		}
	}
	cout << fixed; cout.precision(2);
	cout << pf_stack.top();
}