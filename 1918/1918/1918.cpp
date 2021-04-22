#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool is_operator(char s)
{
	if (s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')')
		return true;
	else
		return false;
}

int op_priority(char s)
{
	switch (s)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}

void postfix_notation(string input)
{
	stack<char> operator_stack;
	string postfix;
	for (int i = 0; i < input.size(); i++)
	{
		if (is_operator(input[i]))
		{
			if (input[i] == ')')
			{
				while (operator_stack.top() != '(')
				{
					postfix.push_back(operator_stack.top());
					operator_stack.pop();
				}
				operator_stack.pop();
			}
			else if (input[i] == '(')
				operator_stack.push(input[i]);
			else
			{
				if (operator_stack.empty())
					operator_stack.push(input[i]);
				else if (op_priority(operator_stack.top()) < op_priority(input[i]))
					operator_stack.push(input[i]);
				else
				{
					while (!operator_stack.empty() && (op_priority(operator_stack.top()) >= op_priority(input[i])))
					{
						postfix.push_back(operator_stack.top());
						operator_stack.pop();
					}
					operator_stack.push(input[i]);
				}
			}
		}
		else
			postfix.push_back(input[i]);
	}
	while (!operator_stack.empty())
	{
		postfix.push_back(operator_stack.top());
		operator_stack.pop();
	}
	for (int i = 0; i < postfix.size(); i++)
		cout << postfix[i];
}

int main()
{
	string input;
	getline(cin, input);
	postfix_notation(input);
}