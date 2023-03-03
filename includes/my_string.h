#pragma once

#include <iostream>
#include <string.h>

using namespace std;

class my_string
{
	char *str;
	int size;
	int capacity;

public:
	my_string(char c);
	my_string(const char *s);
	explicit my_string(int n);
	my_string(const my_string &s);

	void append(const my_string &s);
	void reserve(int n);
	int length() const;
	int compare(const my_string &s) const;

	char &operator[](const int i) const;

	friend bool operator==(const my_string &a, const my_string &b);
	friend bool operator!=(const my_string &a, const my_string &b);
	friend ostream &operator<<(ostream &o, const my_string &s);
	~my_string();
};

my_string operator+(const my_string &a, const my_string &b);

template <typename T>
my_string concat(const T &s)
{
	return s;
}
template <typename T, typename... TS>
my_string concat(const T &s, TS... ss)
{
	return (s + concat(ss...));
}
