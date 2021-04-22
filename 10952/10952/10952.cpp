#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int a, b;
	stringstream ss;
	string integer; getline(cin, integer); ss.str(integer);
	for (; ss >> a && ss >> b;)
	{
		if (a == 0 && b == 0)
			break;
		else
			cout << a + b << "\n";
		ss.str(""); ss.clear();
		getline(cin, integer); ss.str(integer);
	}
}