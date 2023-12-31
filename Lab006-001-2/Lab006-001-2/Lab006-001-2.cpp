#include "stdafx.h"
#include<iostream>
using namespace std;

struct listrec
{
	char value;
	struct listrec    *next;
};


void deepcopy(listrec *old_linked_list, listrec *new_linked_list)
{

	while (old_linked_list != NULL)
	{
		new_linked_list->value = old_linked_list->value;
		new_linked_list->next = old_linked_list->next;
		old_linked_list = old_linked_list->next;
		new_linked_list = new_linked_list->next;
	}
}



int main()
{
	listrec x1, x2, x3;
	listrec *head_old, *head_new = NULL;

	x1.value = 'a';
	x1.next = &x2;

	x2.value = 'c';
	x2.next = &x3;

	x3.value = 'w';
	x3.next = NULL;

	head_old = &x1;
	head_new = head_old;

	deepcopy(head_old, head_new);

	//print old list
	cout << "Old List: " << endl;
	while (head_old != NULL)
	{
		cout << head_old->value << endl;
		head_old = head_old->next;
	}

	cout << endl;

	//print copied list
	cout << "Copied list: " << endl;
	while (head_new != NULL)
	{
		cout << head_new->value << endl;
		head_new = head_new->next;
	}


	system("pause");
	return 0;
}