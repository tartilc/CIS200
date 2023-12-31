#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;

class Mammal {
public:
	Mammal()
	{
		age = 0;
		weight = 0.0;
	}

	Mammal(Mammal &x)
	{
		age = x.age;
		weight = x.weight;
	}

	~Mammal()
	{
		age = 0;
		weight = 0.0;
	}

	void setAge(int value)
	{
		age = value;
	}

	int getAge()
	{
		return age;
	}

	void setWeight(float value)
	{
		weight = value;
	}

	float getWeight()
	{
		return weight;
	}

	void sound()
	{
		cout << "generic sound" << endl;
	}

private:
	int age;

protected:
	float weight;

};

class Cattle : public Mammal {
public:
	string type;

	Cattle()
	{
		type = "beef";
	}

	Cattle(string x)
	{
		type = x;
	}

	Cattle(Cattle &x)
	{
		type = x.type;
	}

	~Cattle()
	{
		type = "beef";
	}

	void sound()
	{
		cout << "moo" << endl;
	}

	void setType(string x)
	{
		type = x;
	}

	string displayType()
	{
		return type;
	}
};

class Cat : public Mammal {
public:
	string type;

	Cat()
	{
		type = "domestic";
	}

	Cat(string x)
	{
		type = x;
	}

	Cat(Cat &x)
	{
		type = x.type;
	}

	~Cat()
	{
		type = "domestic";
	}

	void sound()
	{
		cout << "mew" << endl;
	}

	void setType(string x)
	{
		type = x;
	}

	string displayType()
	{
		return type;
	}
};

int main()
{
	Mammal x;
	cout << "Initial values for x: " << endl;
	cout << "Age = " << x.getAge() << " Weight = " << x.getWeight() << endl;

	x.setAge(10);
	x.setWeight(123);
	cout << "Modified values for x: " << endl;
	cout << "Age = " << x.getAge() << " Weight = " << x.getWeight() << endl;

	Cattle y("dairy");
	cout << "Initial values for y: " << endl;
	cout << "Age = " << y.getAge() << " Weight = " << y.getWeight() << " Type = " << y.displayType() << endl;

	y.setAge(12);
	y.setWeight(127);
	y.setType("beef");
	cout << "Modified values for y: " << endl;
	cout << "Age = " << y.getAge() << " Weight = " << y.getWeight() << " Type = " << y.displayType() << endl;

	Cat z("wild");
	cout << "Initial values for z: " << endl;
	cout << "Age = " << z.getAge() << " Weight = " << z.getWeight() << " Type = " << z.displayType() << endl;

	z.setAge(13);
	z.setWeight(128);
	z.setType("domestic");
	cout << "Modified values for z: " << endl;
	cout << "Age = " << z.getAge() << " Weight = " << z.getWeight() << " Type = " << z.displayType() << endl;

	Mammal w(x);
	cout << "Modified values for w: " << endl;
	cout << "Age = " << w.getAge() << " Weight = " << w.getWeight() << endl;
	w.sound();

	Cat v(z);
	cout << "Modified values for v: " << endl;
	cout << "Age = " << v.getAge() << " Weight = " << v.getWeight() << " Type = " << v.displayType() << endl;
	v.sound();

	system("pause");
	return 0;
}
