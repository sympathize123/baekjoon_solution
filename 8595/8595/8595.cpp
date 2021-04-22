#include <iostream>
#include <string>
using namespace std;

int main()
{
	int times;
	long long int add = 0;
	char c;
	string input, integer = {"0"};
	cin >> times; cin.ignore();
	getline(cin, input);
	for (int i = 0; i < times; i++)
	{
		c = input[i];
		if (c == '0' || c =='1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		{
			integer.push_back(c);
		}
		else
		{
			add += stoi(integer);
			integer = "0";
		}
	}
	add += stoi(integer);
	cout << add;
}