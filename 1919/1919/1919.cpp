#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string input1, input2;
	vector<int> array1,array2;
	array1.resize(26); array2.resize(26);
	int count = 0;
	getline(cin, input1);
	getline(cin, input2);
	for (int i = 0; i < input1.size(); i++)
		array1[input1[i] - 97]++;
	for (int i = 0; i < input2.size(); i++)
		array2[input2[i] - 97]++;
	for (int i = 0; i < 26; i++)
	{
		if (array1[i] > array2[i])
			count += array1[i] - array2[i];
		if (array1[i] < array2[i])
			count += array2[i] - array1[i];
	}
	cout << count;
}