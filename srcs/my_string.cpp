#include "my_string.h"

my_string::my_string(char c)
	: size(1), capacity(1)
{
	str = new char;
	str[0] = c;
}

my_string::my_string(const char *s)
	: size(strlen(s)), capacity(strlen(s))
{
	str = new char[size];
	strcpy(str, s);
}

my_string::my_string(const my_string &s)
	: size(s.size), capacity(s.capacity)
{
	str = new char[capacity];
	strcpy(str, s.str);
}

my_string::my_string(int n)
	: size(0), capacity(n)
{
	str = new char[n];
}

int my_string::length() const
{
	return (size);
}

void my_string::append(const my_string &s)
{
	if (capacity <= size + s.size)
	{
		capacity = 2 * (size + s.size);
		char *tmp = new char[capacity];
		for (int i = 0; i < size; i++)
			tmp[i] = str[i];
		delete[] str;
		str = tmp;
	}
	for (int i = 0; i < s.size; i++)
		str[size++] = s.str[i];
}

void my_string::reserve(int n)
{
	char *tmp = str;
	str = new char[n];
	for (int i = 0; i < size; i++)
		str[i] = tmp[i];
	delete[] tmp;
	capacity = n;
}

int my_string::compare(const my_string &s) const
{
	if (size != s.size)
		return (size - s.size);
	for (int i = 0; i < size; i++)
		if (str[i] != s.str[i])
			return (str[i] - s.str[i]);
	return (0);
}

bool operator==(const my_string &a, const my_string &b)
{
	return (a.compare(b) == 0);
}

bool operator!=(const my_string &a, const my_string &b)
{
	return (!(a == b));
}

my_string operator+(const my_string &a, const my_string &b)
{
	my_string tmp(a);
	tmp.append(b);
	return (tmp);
}

char &my_string::operator[](const int i) const
{
	return (str[i]);
}

ostream &operator<<(ostream &o, const my_string &s)
{
	for (int i = 0; i < s.size; i++)
		o << s.str[i];
	return (o);
}

my_string::~my_string()
{
	if (str)
		delete[] str;
}
