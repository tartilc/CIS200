#include "stdafx.h"
#include "iostream"
using namespace std;

#define MAXITEM = 100

struct NodeType
{
	int info;
	NodeType* next;
};

class Stack
{
private:
	int top;
	NodeType * head; // It points to the head of a singly-linked list
public:
	Stack() // default constructor: Stack is created and empty
	{
		head = NULL;
		top = 0;
	}

	Stack(Stack &x) // copy constructor
	{
		NodeType* ptr1;
		NodeType* ptr2;

		if (x.head == NULL) {
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

	void MakeEmpty() // Stack is made empty
	{
		NodeType* tempPtr;

		while (head != NULL)
		{
			tempPtr = head;
			head = head->next;
			delete tempPtr;
		}
	}

	bool IsEmpty() // test if the stack is empty
	{
		return (head = NULL);
	}

	bool IsFull() // test if the stack is full; assume MAXITEM=100
	{
		NodeType* location;
		location = new NodeType;
		if (location == NULL)
			return true;
		else {
			delete location;
			return false;
		}
	}

	int length() // return the number of elements in the stack
	{	
		/*
		int tempLength = 0;
		while (head != NULL)
		{
			tempLength++;
		}
		return tempLength;
		*/
		return top;
	};

	void Print() // print the value of all elements in the stack in the sequence from the top to bottom
	{
		if (IsEmpty()) {
			cout << "List is empty";
			return;
		}

		NodeType* currentPtr = head;
		cout << "The list is: ";
		while (currentPtr != NULL) {
			cout << currentPtr->info << ' ';
			currentPtr = currentPtr->next;
		}
	}

	void Push(int x) // insert x onto the stack
	{
		/*
		if (IsFull())
		{
			cout << "Stack is full";
			return;
		}
		else {
			NodeType* location;
			location = new NodeType;
			location->info = x;
			location->next = head;
			head = location;
		}
		*/
		NodeType* location;
		location = new NodeType;
		location->info = x;
		location->next = head;
		head = location;
		top++;
	};

	void Pop(int &x) // delete the top element from the stack Precondition: the stack is not empty
	{
		
		if (IsEmpty())
		{
			cout << "Stack is empty";
			return;
		}
		else {
			NodeType* tempPtr;
			tempPtr = head;
			head = head->next;
			delete tempPtr;
			top--;
		}
		
		/*
		NodeType* tempPtr;

		x = head->info;
		tempPtr = head;
		head = head->next;
		delete tempPtr;
		top--;
		*/
	};

	~Stack()
	{
		MakeEmpty();
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

	system("pause");
	return 0;
}