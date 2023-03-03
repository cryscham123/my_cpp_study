#include "my_vector.h"

using namespace my_vector;

vector::vector(int n)
	: capacity(n), length(0), data(new string[n]) {}

vector::~vector()
{
	if (data)
		delete[] data;
}

void vector::push_back(string s)
{
	if (length >= capacity)
	{
		capacity *= 2;
		string *tmp = new string[capacity];
		for (int i = 0; i < length; i++)
			tmp[i] = data[i];
		delete[] data;
		data = tmp;
	}
	data[length++] = s;
}

void vector::remove(int x)
{
	for (int i = x + 1; i < length; i++)
		data[i - 1] = data[i];
	length--;
}

int vector::size() const
{
	return (length);
}
string vector::operator[](int i) const
{
	return (data[i]);
}
