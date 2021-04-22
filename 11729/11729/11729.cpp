#include <iostream>
using namespace std;

void hanoi_tower(int number_of_plate,int* count)
{
	if (number_of_plate == 1)
		(*count)++;
	else
	{
		(*count)++;
		hanoi_tower(number_of_plate - 1, count);
		hanoi_tower(number_of_plate - 1, count);
	}
}

void move(int start, int dest)
{
	cout << start << " " << dest << endl;
}

void hanoi_tower2(int number_of_plate, int start, int to, int dest)
{
	if (number_of_plate == 1)
		move(start, dest);
	else
	{
		hanoi_tower2(number_of_plate - 1, start, dest, to);
		move(start, dest);
		hanoi_tower2(number_of_plate - 1, to, start, dest);
	}
}


int main()
{
	int number_of;
	int* count = new int();
	*count = 0;
	cin >> number_of;
	hanoi_tower(number_of, count);
	cout << *count << endl;
	hanoi_tower2(number_of, 1, 2, 3);
}