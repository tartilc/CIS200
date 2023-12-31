#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

struct Date
{
	int day;
	int month;
	int year;

};

template<class T1>
class A
{
private:
	T1 valueA;
public:
	A()
	{

	}

	T1 getvalueA() const
	{
		return valueA;
	}

	void setValueA(T1 x)
	{
		valueA = x;
	}
	
	A(T1 obj)
	{
		valueA = obj.valueA;
	}

	A(T1 &rhs)
	{
		valueA = rhs.valueA;
	}

	struct data {
		int day;
		int month;
		int year;
	};
};

template<class T2>
class B : public A<T2>
{
private:
	T2 valueB;
public:
	B()
	{

	}

	T2 getvalueB() const
	{
		return valueB;
	}

	void setValueB(T2 x)
	{
		valueB = x;
	}

	B(T2 obj)
	{
		valueB = obj.valueB;
	}

	B(T2 &rhs)
	{
		valueB = rhs.valueB;
	}

	struct data {
		int day;
		int month;
		int year;
	};
};


int main()
{
	B<float> inst1;
	inst1.setValueA(1.34);
	inst1.setValueB(3.14);

	cout << inst1.getvalueA() << " " << inst1.getvalueB() << endl;

	B<int> inst2;
	inst2.setValueA(1);
	inst2.setValueB(3);

	cout << inst2.getvalueA() << " " << inst2.getvalueB() << endl;

	B<char> inst3;
	inst3.setValueA('a');
	inst3.setValueB('c');

	cout << inst3.getvalueA() << " " << inst3.getvalueB() << endl;

	B<string> inst4;
	inst4.setValueA("good");
	inst4.setValueB("morning");

	cout << inst4.getvalueA() << " " << inst4.getvalueB() << endl;

	struct Date d1 = { 27,10,2015 };
	struct Date d2 = { 2,11,2015 };
	struct Date d3, d4;

	B<struct Date> inst5;
	inst5.setValueA(d1);
	inst5.setValueB(d2);

	cout << "a: " << d1.day << " " << d1.month << " " << d1.year << " b: " << d2.day << " " << d2.month << " " << d2.year << endl;
	
	system("pause");
	return 0;
}