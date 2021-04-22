#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string input;
	stringstream integer;
	int add = 0,a;
	getline(cin,input);
	integer.str(input);
	for (;!integer.eof();)
	{
		integer >> a;
		add += a;
	}
	cout << add << endl;
}