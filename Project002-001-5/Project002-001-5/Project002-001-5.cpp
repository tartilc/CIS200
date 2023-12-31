#include "stdafx.h"
#include "iostream"
using namespace std;

struct NodeType
{
	int info;
	NodeType* next;
};


class Stack
{
private:
	int top;
	NodeType * head;

public:
	Stack()
	{
		top = 0;
		head = NULL;
	}

	Stack(Stack &x)
	{
		/*
		NodeType* ptr1;
		NodeType* ptr2;

		if (x.head == NULL) {
			head == NULL;
		}
		else {
			head = new NodeType;
			head->info = x.head->info;
			ptr1 = x.head->next;
			ptr2 = head;
			while (ptr1 != NULL)
			{
				ptr2->next = new NodeType;
				ptr2 = ptr2->next;
				ptr2->info = ptr1->info;
				ptr1 = ptr1->next;
			}
			ptr2->next = NULL;
		}
		*/
		head = NULL;
		NodeType *temp = x.head;
		while (temp != NULL)
		{
			Push(temp->info);
			temp = temp->next;
		}
	}

	void MakeEmpty()
	{
		NodeType *start = head;
		NodeType *temp = NULL;
		while (start != NULL)
		{
			temp = start->next;
			delete start;
			start = temp;
		}
		temp = NULL;
		start = NULL;
	}

	bool IsEmpty()
	{
		if (top == 0)
			return true;
		else
			return false;
	}

	bool IsFull()
	{
		if (top == 100)
			return true;
		else
			return false;
	}

	int length()
	{
		return top;
	}

	void Print()
	{
		NodeType *start = head;
		//for (int i = 0; i<top; i++)
		while (start != NULL)
		{
			cout << start->info << " ";
			start = start->next;
		}
		cout << endl;
	}

	void Push(int x)
	{
		NodeType *start;
		start = new NodeType;
		start->info = x;
		start->next = head;
		head = start;
		top++;
	}

	void Pop(int &x)
	{
		NodeType *start;
		if (head == NULL)
		{
			return;
		}
		else
		{
			start = head->next;
			x = head->info;
			delete head;
			head = start;
			top--;
		}
	}

	~Stack()
	{
		NodeType *start = head;
		NodeType *temp = NULL;
		while (start != NULL)
		{
			temp = start->next;
			delete start;
			start = temp;
		}
		temp = NULL;
		start = NULL;
	}
};

int main()
{
	Stack IntStack;
	int x;
	IntStack.Pop(x);
	IntStack.Push(11);
	IntStack.Push(22);
	cout << "int length 1 = " << IntStack.length() << endl;
	IntStack.Pop(x);
	IntStack.Push(33);
	cout << "int length 2 = " << IntStack.length() << endl;
	cout << "The int stack contains:  " << endl;
	IntStack.Print();
	IntStack.Push(44);
	IntStack.Push(55);
	IntStack.Push(66);
	if (IntStack.IsFull() == false)
		cout << "The int stack is not full !" << endl;
	else
		cout << "The int stack is full !" << endl;
	Stack IntStack2(IntStack);
	cout << "The int stack2 contains:  " << endl;
	IntStack2.Print();
	IntStack2.MakeEmpty();
	cout << "The int stack3 contains:  " << endl;
	IntStack2.Print();
	system("pause");
	return 0;
}