#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

void z_find_sector(long long int n, long long int row, long long int column, long long int* count)
{
	if (n == 1)
	{
		(*count) += 2 * row + column + 1;
		return;
	}
	if ((column >= 0 && row >= 0) && (column <= pow(2, n - 1) -1 && row <= pow(2, n - 1) - 1))
		z_find_sector(n - 1, row, column, count);
	else if ((column >= pow(2, n - 1) && row >= 0) && (column <= pow(2, n) - 1 && row <= pow(2, n - 1) - 1))
	{
		(*count) += pow(2, 2*(n - 1));
		z_find_sector(n - 1, row, column - pow(2, n - 1), count);
	}
	else if ((row >= pow(2, n - 1) && column >= 0) && (row <= pow(2, n) - 1 && column <= pow(2, n - 1) - 1))
	{
		(*count) += 2 * pow(2, 2*n - 2);
		z_find_sector(n - 1, row - pow(2, n - 1), column, count);
	}
	else
	{
		(*count) += 3 * pow(2, 2 * n - 2);
		z_find_sector(n - 1, row - pow(2, n - 1), column - pow(2, n - 1), count);
	}
}

int main()
{
	string input;
	stringstream ss;
	long long int n, row, column;
	long long int* count = new long long int();
	*count = 0;
	getline(cin, input);
	ss.str(input);
	ss >> n; ss >> row; ss >> column;
	z_find_sector(n, row, column, count);
	cout << (*count) - 1;
}