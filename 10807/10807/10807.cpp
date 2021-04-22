#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int times, integer, a, count = 0;
	stringstream ss;
	string input;
	cin >> times; cin.ignore();
	getline(cin, input);
	ss.str(input);
	cin >> integer;
	while (ss >> a)
		if (a == integer)
			count++;
	cout << count;
}