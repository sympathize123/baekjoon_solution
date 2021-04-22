#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		cin >> input;
		if (i % 2 == 0)
			for (int t = 0; t < 8; t += 2)
				if (input[t] == 'F')
					count++;
				else
					continue;
		else
			for (int t = 0; t < 8; t += 2)
				if (input[t+1] == 'F')
					count++;
				else
					continue;
	}
	cout << count;
}