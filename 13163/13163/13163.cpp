#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int times;
	stringstream ss;
	string input, syllable, output;
	cin >> times; cin.ignore();
	for (int i = 0; i < times; i++)
	{
		getline(cin, input);
		ss.str(input);
		ss >> syllable;
		output.append("god");
		while (ss >> syllable)
			output.append(syllable);
		cout << output << "\n";
		output.clear(); ss.str(""); ss.clear();
	}
}