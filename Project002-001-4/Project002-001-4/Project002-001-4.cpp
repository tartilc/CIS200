#include "stdafx.h"
#include <iostream>
using namespace std;

template<class ItemType>
struct NodeType
{ 
       ItemType info;
       NodeType* next;
};

template<class ItemType>
class Stack
{ 
       private:
  	NodeType<ItemType>* topPtr; // It points to a singly-linked list
  	int length;
       public:
     Stack(){length=0; topPtr=NULL;};  // default constructor: Stack is created and empty
            Stack(const Stack<ItemType> &x);  // copy constructor: implicitly called for a  
             //  deep copy
            void MakeEmpty();    // Stack is made empty; you should deallocate all the 
                                               //  the nodes of the linked list
  	bool IsEmpty();   // test if the stack is empty
  	bool IsFull();   // test if the stack is full; assume MAXITEM=5
  	int lengthOf(){return length;};    // return the number of elements in the stack
  	void Print();   // print the value of all elements in the stack in the sequence 
        // from the top to bottom
  	void Push(ItemType x);   // insert x onto the stack   
            void Pop(ItemType &x);  // delete the top element from the stack
  	// Precondition: the stack is not empty
            ~Stack();  // Destructor:  memory for nodes needs to be deallocated
};

template<class ItemType>
bool Stack<ItemType>::IsEmpty()
{
	if(length==0)
  return true;
	else
  return false;
}

template<class ItemType>
bool Stack<ItemType>::IsFull()
{
	if(length==5)
  return true;
	else
  return false;
}

template<class ItemType>
Stack<ItemType>::~Stack()
{
	NodeType<ItemType> *head = topPtr;
	NodeType<ItemType> *temp = NULL;
	while(head!=NULL)
	{
  temp = head->next;
  delete head;
  head = temp;
	}
	temp = NULL;
	head = NULL;
	cout << "Memory has been deallocated." << endl;
	system("pause");
}

template<class ItemType>
void Stack<ItemType>::Push(ItemType x)
{
	NodeType<ItemType> *head;
    head = new NodeType<ItemType>;
    head->info = x;
    head->next = topPtr;
    topPtr = head;
    length++;
}

template<class ItemType>
void Stack<ItemType>::Pop(ItemType &x)
{
	NodeType<ItemType> *head;
	if(topPtr == NULL)
	{
  return;
	}
	else
	{
  head = topPtr->next;
  x = topPtr->info;
  delete topPtr;
  topPtr=head;
  length--;
	}
}

template<class ItemType>
Stack<ItemType>::Stack(const Stack<ItemType> &x)
{
	NodeType<ItemType>* ptr1;
	NodeType<ItemType>* ptr2;

	if (x.topPtr == NULL) {
		topPtr == NULL;
	}
	else {
		topPtr = new NodeType<ItemType>;
		topPtr->info = x.topPtr->info;
		ptr1 = x.topPtr->next;
		ptr2 = topPtr;
		while (ptr1 != NULL)
		{
			ptr2->next = new NodeType<ItemType>;
			ptr2 = ptr2->next;
			ptr2->info = ptr1->info;
			ptr1 = ptr1->next;
		}
		ptr2->next = NULL;
	}
}

template<class ItemType>
void Stack<ItemType>::Print()  //Return the item to be printed out
{
	NodeType<ItemType> *head = topPtr;
    for(int i=0; i<length;i++)
	{
  cout << head->info << " ";
  head = head->next;
	}
	cout << endl;	
}

template<class ItemType>
void Stack<ItemType>::MakeEmpty()
{
	NodeType<ItemType> *head = topPtr;
	NodeType<ItemType> *temp = NULL;
	while(head!=NULL)
	{
  temp = head->next;
  delete head;
  head = temp;
	}
	temp = NULL;
	head = NULL;
	cout << "Memory has been deallocated." << endl;
}

int main()
{
  Stack <int> IntStack;
  int x;
  IntStack.Pop(x);
  IntStack.Push(11);
  IntStack.Push(22);
  cout << "int length 1 = " << IntStack.lengthOf() << endl;
  IntStack.Pop(x);
  IntStack.Push(33);
  cout << "int length 2 = " << IntStack.lengthOf() << endl;
  cout << "The int stack contains:  " << endl;
  IntStack.Print();
  IntStack.Push(44);
  IntStack.Push(55);
  IntStack.Push(66);
  if(IntStack.IsFull() == false)
     cout << "The int stack is not full !" << endl;
  else
     cout << "The int stack is full !" << endl;
  Stack <int> IntStack2(IntStack);
  cout << "The int stack2 contains:  " << endl;
  IntStack2.Print();
  IntStack2.MakeEmpty();
  cout << "The int stack3 contains:  " << endl;
  IntStack2.Print();
  system("pause");
  return 0;
}