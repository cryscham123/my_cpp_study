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

void my_string::reserve(int n)
{
	char *tmp = str;
	str = new char[n];
	for (int i=0; i<size; i++)
		str[i] = tmp[i];
	delete[] tmp;
	capacity = n;
}

void my_string::print() const
{
	for (int i=0; i<size; i++)
		std::cout << str[i];
	std::cout << '\n';
}

int my_string::compare(const my_string& s) const
{
	if (size != s.size)
		return (size - s.size);
	for (int i=0; i<size; i++)
		if (str[i] != s.str[i])
			return (str[i] - s.str[i]);
	return (0);
}

bool operator == (const my_string &a, const my_string &b)
{
	return (a.compare(b) == 0);
}

char &my_string::operator [] (const int i) const
{
	return (str[i]);
}

my_string::~my_string()
{
	if (str)
		delete[] str;
}
