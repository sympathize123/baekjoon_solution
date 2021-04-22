#include <iostream>
#include <string>
using namespace std;

int main()
{
	string line;
	while (!getline(cin,line).eof())
		cout << line << "\n";
}