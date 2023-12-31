#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

struct NodeType
{
	char word;
	NodeType * next;
};

class List
{
private:
	NodeType * headPtr = NULL;

public:
	List()
	{

	}

	void fromstring(const string & word)
	{
		int length = word.length();

		for (int i = length; i >= 0; i--)
		{
			NodeType *temp = new NodeType;

			if (headPtr == NULL)
			{
				temp->word = word[i];

				temp->next = NULL;

				headPtr = temp;
			}
			else {
				temp->word = word[i];

				temp->next = headPtr;

				headPtr = temp;
			}
		}
	}

	string toString()
	{
		string word;

		NodeType * temp = headPtr;

		while (temp != NULL)
		{
			word = word + temp->word;

			temp = temp->next;
		}

		return word;
	}

	string toString(const List & newList)
	{
		string word;

		NodeType *temp = newList.headPtr;

		while (temp != NULL)
		{
			word = word + temp->word;
			temp = temp->next;
		}

		return word;
	}

	List operator+ (const List & rhs)
	{
		string x = toString(*this);
		string y = toString(rhs);
		string z = x + y;

		List com;
		com.fromstring(z);

		return com;
	}

	void deleteList(NodeType * &ptr)
	{
		if (ptr == NULL)
		{

		}
		else {
			deleteList(ptr->next);
			delete ptr;
		}
	}

	friend ostream & operator<<(ostream &  out, const List & rhs)
	{
		NodeType * temp = rhs.headPtr;

		while (temp != NULL)
		{
			out << temp->word;
			temp = temp->next;
		}

		return out;
	}
};

int main()
{
	List list1;
	List list2;
	List list3;

	string word1 = "cat";
	string word2 = "fish";
	string word3 = "";

	list1.fromstring(word1);
	list2.fromstring(word2);
	word3 = list1.toString();
	cout << list1 << " + " << list2 << " = ";
	list3 = list1 + list2;
	cout << list3 << endl;

	system("pause");
	return 0;
}