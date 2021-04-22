#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int times;
	string input, output, syllable;
	stringstream ss;
	cin >> times; cin.ignore();
	for (int i = 0; i < times; i++)
	{
		getline(cin, input);
		ss.str(input);
		while (ss >> syllable)
		{
			for (int t = 0; t < syllable.size() / 2; t++)
			{
				char temp;
				temp = syllable[t];
				syllable[t] = syllable[syllable.size() - 1 - t];
				syllable[syllable.size() - 1 - t] = temp;
			}
			output.append(syllable);
			output.append(" ");
		}
		cout << output << "\n";
		output.clear(); ss.str(""); ss.clear();
	}
}