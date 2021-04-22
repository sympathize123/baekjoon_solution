#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string input;
	vector<int> array;
	array.resize(26);
	getline(cin, input);
	for (int i = 0;i < input.size(); i++)
		array[input[i] - 97]++;
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
}