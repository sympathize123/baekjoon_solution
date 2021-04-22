#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class node
{
public:
	int data;
	node* next = nullptr;
	node(){}
	~node(){}
};

class stack
{
private:
	node* head;
	node* tail;
public:
	stack() { head = new node(); tail = nullptr; }
	~stack(){}
	void push(int input)
	{
		node* newstack = new node();
		newstack->data = input;
		if (empty())
		{
			head->next = newstack;
			tail = newstack;
		}
		else
		{
			tail->next = newstack;
			tail = tail->next;
		}
	}
	int pop()
	{
		if (head->next == nullptr)
			return -1;
		else if (size() == 1)
		{
			node* nextptr;
			int return_data;
			nextptr = head->next;
			return_data = nextptr->data;
			head->next = nullptr;
			tail = head;
			delete nextptr;
			return return_data;
		}
		else
		{
			node* nextptr;
			node* before_nextptr = new node();
			int return_data;
			nextptr = head->next;
			while (nextptr->next != nullptr)
			{
				before_nextptr = nextptr;
				nextptr = nextptr->next;
			}
			before_nextptr->next = nullptr;
			return_data = nextptr->data;
			tail = before_nextptr;
			delete nextptr;
			return return_data;
		}
	}
	int size()
	{
		int count = 1;
		if (head->next == nullptr)
			return 0;
		else 
		{
			node* nextptr;
			nextptr = head->next;
			while (nextptr->next != nullptr)
			{
				nextptr = nextptr->next;
				count++;
			}
			return count;
		}
	}
	int empty()
	{
		if (head->next == nullptr)
			return 1;
		else
			return 0;
	}
	int top()
	{
		if (empty())
			return -1;
		else
			return tail->data;
	}
};



int main()
{
	int times;
	string input, a;
	stringstream ss;
	stack stackarray;
	cin >> times; cin.ignore();
	for (int i = 0; i < times; i++)
	{
		getline(cin, input);
		ss.str(input);
		ss >> a;
		if (a == "push")
		{
			int push_int;
			ss >> push_int;
			stackarray.push(push_int);
		}
		else if (a == "pop")
		{
			cout << stackarray.pop() << endl;
		}
		else if (a == "size")
		{
			cout << stackarray.size() << endl;
		}
		else if (a == "empty")
		{
			cout << stackarray.empty() << endl;
		}
		else if (a == "top")
		{
			cout << stackarray.top() << endl;
		}
		ss.str(""); ss.clear();
	}
}