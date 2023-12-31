#include "stdafx.h"
#include "iostream"

using namespace std;

struct listrec
{
	int value;
	listrec *next;
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
	x1.value = 4;
	x2.value = 5;
	x3.value = 3;
	x1.next = &x2;
	x2.next = &x3;
	x3.next = NULL;
	listrec x4;
	x4.value = 6;
	x1.next = &x4;
	x4.next = &x2;

	listrec *head_old, *head_new = NULL;
	head_old = &x1;
	head_new = head_old;

	deepcopy(head_old, head_new);

	cout << "head_old: ";
	while (head_old != NULL)
	{
		cout << head_old->value << " ";
		head_old = head_old->next;
	}
	cout << endl;

	cout << "head_new: ";
	while (head_new != NULL)
	{
		cout << head_new->value << " ";
		head_new = head_new->next;
	}
	cout << endl;

	system("pause");
	return 0;
}