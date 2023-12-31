#include "stdafx.h"
#include <iostream>
using namespace std;

template<class ItemType>

struct NodeType
{
	ItemType info;
	NodeType <ItemType> *next;
};

template<class ItemType>
class Stack
{
private:
	NodeType<ItemType> *topPtr; // It points to a singly-linked list
public:
	Stack() { topPtr = NULL; }  // default constructor: Stack is created and empty
	Stack(const Stack <ItemType> & anotherStack) {
		NodeType<ItemType> *ptr1; NodeType<ItemType> *ptr2;
		if (anotherStack.topPtr == NULL)
			topPtr = NULL;
		else   // allocate memory for first node
		{
			topPtr = new NodeType<ItemType>;
			topPtr->info = anotherStack.topPtr->info;
			ptr1 = anotherStack.topPtr->next;
			ptr2 = topPtr;
			while (ptr1 != NULL)// deep copy other nodes
			{
				ptr2->next = new NodeType<ItemType>;
				ptr2 = ptr2->next;
				ptr2->info = ptr1->info;
				ptr1 = ptr1->next;
			}
			ptr2->next = NULL;
		}
	}

	void MakeEmpty() // Stack is made empty; you should deallocate all the the nodes of the linked list
	{
		NodeType<ItemType> *temp = topPtr;
		while (temp != NULL)
		{
			NodeType<ItemType> * next = temp->next;
			delete temp;
			temp = next;
		}
	}
	bool IsEmpty() { return (topPtr == NULL); }  // test if the stack is empty
	bool IsFull() // test if the stack is full; assume MAXITEM=5
	{
		int MAXITEM = 5, sum = 0;
		while (topPtr != NULL)
		{
			sum++;
			topPtr = topPtr->next;
		}
		return (sum >= MAXITEM);
	}
	int length()  // return the number of elements in the stack
	{
		int sum = 0;
		while (topPtr != NULL)
		{
			sum++;
			topPtr = topPtr->next;
		}
		return sum;
	}
	void Print() // print the value of all elements in the stack in the sequence, from the top to bottom 			
	{
		while (topPtr != NULL)
		{
			cout << topPtr->info << " ";
			topPtr = topPtr->next;
		}
	}
	void Push(ItemType x)   // insert x onto the stack   
	{
		if (IsFull())
			cout << "Is Full" << endl;
		else
		{
			NodeType<ItemType> *newNode;
			newNode = new NodeType<ItemType>;
			newNode->info = x;
			newNode->next = topPtr;
			topPtr = newNode;
			//delete newNode;
		}
	}
	void Pop(ItemType &x) // delete the top element from the stack, Precondition: the stack is not empty
	{
		NodeType <ItemType> *temp;
		if (topPtr != NULL)
		{
			temp = topPtr;
			topPtr = topPtr->next;
			delete temp;
		}
		else
			cout << "Stack is empty" << endl;
	}

	~Stack() // Destructor:  memory for nodes needs to be deallocated
	{
		NodeType<ItemType> *temp = topPtr;
		while (temp != NULL)
		{
			NodeType<ItemType> *next = temp->next;
			delete temp;
			temp = next;
		}
	}
};


int main() {
	Stack <int> IntStack;
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
	Stack <int> IntStack2(IntStack);
	cout << "The int stack2 contains : " << endl;
	IntStack2.Print();
	IntStack2.MakeEmpty();
	cout << "The int stack3 contains : " << endl;
	IntStack2.Print();

	Stack <float> FloatStack;
	float y;
	FloatStack.Pop(y);
	FloatStack.Push(7.1);
	cout << "float length 1 = " << FloatStack.length() << endl;
	FloatStack.Push(2.3);
	FloatStack.Push(3.1);
	cout << "float length 2 = " << FloatStack.length() << endl;
	FloatStack.Pop(y);
	cout << "The float stack contains : " << endl;
	FloatStack.Print();
	Stack <float> FloatStack2 = FloatStack;
	cout << "The float stack 2 contains:  " << endl;
	FloatStack2.Print();
	FloatStack.MakeEmpty();
	cout << "The float stack 3 contains:  " << endl;
	FloatStack2.Print();

	system("pause");
	return 0;
}

