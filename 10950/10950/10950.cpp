#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int times; cin >> times;
	int a, b;
	stringstream ss;
	string integer;
	cin.ignore();
	for (int i = 0; i < times; i++)
	{
		getline(cin, integer);
		ss.str(integer);
		while (ss >> a && ss >> b)
			cout <<  a + b << "\n";
		ss.str(""); ss.clear();
	}
}