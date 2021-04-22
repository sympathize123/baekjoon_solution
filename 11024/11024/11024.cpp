#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int times, add = 0,integer;
	string line;
	stringstream ss;
	cin >> times;
	cin.ignore();
	for (int i = 0; i < times; i++)
	{
		getline(cin, line);
		ss.str(line);
		while (ss >> integer)
		{
			add += integer;
		}
		ss.str("");
		ss.clear();
		cout << add << "\n";
		add = 0;
	}
}