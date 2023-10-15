#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "stdafx.h"
#include <iostream>
using namespace std;

class Vector
{
public:
	Vector()	// default constructor sets size to 0
	{
		size = 0;
	}

	Vector(int s)	// makes size = s,
					// allocates s space,
					// makes all entries 0
	{
		size = s;
		entries = new int[size];
		for (int i = 0; i < size; i++)
		{
			entries[i] = 0;
		}
	}

	Vector(const Vector & rhs)	// copy constructor
								// makes self a deep copy of rhs
	{
		int i;
		size = rhs.size;
		entries = new int[size];
		for (i = 0; i < size; i++)
		{
			entries[i] = rhs.entries[i];
		}
	}

	Vector operator = (const Vector & rhs)	// makes self a deep copy of rhs
	{
		return *this;
	}

	~Vector()	// default destructor
	{
		for (int i = 0; i < size; i++)
		{
			entries[i] = 0;
		}
	}

	void print()	// Prints out the vector
	{
		cout << "[ ";

		for (int i = 0; i < size; i++)
		{
			cout << entries[i] << " ";
		}

		cout << "]";
	}

	void set(int val, int pos)	// if 0 <=pos<size
								// stores val at pos in entries
	{
		if (0 <= pos && 0 < size)
		{
			for (int i = 0; i < size; i++)
			{
				entries[pos] = val;
			}
		}
	}

private:
	int size; //sets the # of elements used
	int *entries;
};
#endif