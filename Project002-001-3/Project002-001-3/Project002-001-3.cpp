#include "stdafx.h"
#include "iostream"
using namespace std;

struct NodeType
{
	int info;
	NodeType *next;
};

class Stack
{
private:
	int top;
	NodeType *head;
public:
	Stack()
	{
		head = NULL;
		top = 0;
	}

	Stack(Stack &x)
	{
		NodeType *ptr1;
		NodeType *ptr2;

		if (x.head == NULL)
		{
			head = NULL;
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
	}

	void MakeEmpty()
	{
		NodeType *temp = head;
		while (temp != NULL)
		{
			NodeType * next = temp->next;
			delete temp;
			temp = next;
		}
	}

	bool IsEmpty()
	{
		return (head == NULL);
	}

	bool IsFull()
	{
		int MAXITEM = 100, sum = 0;
		while (head != NULL)
		{
			sum++;
			head = head->next;
		}
		return (sum >= MAXITEM);
	}

	int length()
	{
		int sum = 0;
		while (head != NULL)
		{
			sum++;
			head = head->next;
		}
		return sum;
	}

	void Print()
	{
		while (head != NULL)
		{
			cout << head->info << " ";
			head = head->next;
		}
	}

	void Push(int x)
	{
		if (IsFull())
			cout << "Is Full" << endl;
		else
		{
			NodeType *newNode;
			newNode = new NodeType;
			newNode->info = x;
			newNode->next = head;
			head = newNode;
			//delete newNode;
			top++;
		}
	}

	void Pop(int &x)
	{
		NodeType *temp;
		if (head != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
			top--;
		}
		else
			cout << "Stack is empty" << endl;
	}

	~Stack()
	{
		NodeType *temp = head;
		while (temp != NULL)
		{
			NodeType *next = temp->next;
			delete temp;
			temp = next;
		}
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
	cout << "The int stack contains : " << endl;
	IntStack.Print();
	IntStack.Push(44);
	IntStack.Push(55);
	IntStack.Push(66);
	if (IntStack.IsFull() == false)
		cout << "The int stack is not full !" << endl;
	else
		cout << "The int stack is full !" << endl;
	Stack IntStack2(IntStack);
	cout << "The int stack2 contains : " << endl;
	IntStack2.Print();
	IntStack2.MakeEmpty();
	cout << "The int stack3 contains : " << endl;
	IntStack2.Print();

	
	return 0;
}