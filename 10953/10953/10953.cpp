#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);int times = 0, a, b;string integer;cin >> times;
	for (int i = 0; i < times; i++)
	{
		cin >> integer;
		a = integer[integer.find(",") - 1] - 48; b = stoi(integer.substr(integer.find(",") + 1));
		cout << a + b << "\n";
	}
}