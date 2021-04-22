#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
	string input;
	double number_of_student, max_capacity, array[12] = { 0 };
	int sex, grade, add = 0;
	stringstream ss;
	getline(cin, input);
	ss.str(input);
	ss >> number_of_student; ss >> max_capacity; 
	ss.str(""); ss.clear();
	for (int i = 0; i < number_of_student; i++)
	{
		getline(cin, input);
		ss.str(input); 
		ss >> sex; ss >> grade;
		if (sex == 0)
			array[grade - 1]++;
		else
			array[sex * 6 + grade - 1]++;
		ss.str(""); ss.clear();
	}
	for (int i = 0; i < 12; i++)
		add += int(ceil(array[i] / max_capacity));
	cout << add;
}