#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input,reverse;
	getline(cin, input);
	while(input != "***")
	{
		reverse.resize(input.size());
		for (int i = 0; i < input.size(); i++)
			reverse[i] = input[input.size()- 1 - i];
		cout << reverse << "\n";
		getline(cin, input);
	}
}