#include "my_array.h"

using namespace my_array;

array::array(int N, int *size)
	: N(N), size(size)
{
	top = new list;
	top->level = 0;
	int flag = initialize_list(top);
	if (flag != 0)
	{
		arr_error(flag);
		return;
	}
}

array::array(const array &arr)
	: N(arr.N), size(arr.size)
{
	top = new list;
	top->level = 0;
	initialize_list(top);
	copy_list(top, arr.top);
}

array::~array()
{
	delete_list(top);
	delete top;
}

void array::arr_error(int flag)
{
	switch (flag)
	{
	case 1:
		std::cout << "array size must be more than 1\n";
		break;
	case 2:
		std::cout << "array index must be more than 1\n";
		break;
	case 3:
		std::cout << "array index is not defined\n";
		break;
	}
}
// allocate list recursivly
// if user give proper size, return 0
// or return error flag
int array::initialize_list(list *n)
{
	if (size[n->level] <= 0)
	{
		n->nxt = NULL;
		return (2);
	}
	if (n->level == N - 1)
	{
		n->nxt = new int[size[n->level]];
		return (0);
	}
	n->nxt = new list[size[n->level]];
	for (int i = 0; i < size[n->level]; i++)
	{
		(static_cast<list *>(n->nxt) + i)->level = n->level + 1;
		int flag = initialize_list(static_cast<list *>(n->nxt) + i);
		if (flag != 0)
			return (flag);
	}
	return (0);
}

void array::copy_list(list *dst, list *src)
{
	if (dst->level == N - 1)
	{
		for (int i = 0; i < size[N - 1]; i++)
			static_cast<int *>(dst->nxt)[i] = static_cast<int *>(src->nxt)[i];
		return;
	}
	for (int i = 0; i < size[N - 1]; i++)
		copy_list(static_cast<list *>(dst->nxt) + i, static_cast<list *>(src->nxt) + i);
}

void array::delete_list(list *n)
{
	void *target = n->nxt;
	if (target == NULL)
		return;
	if (n->level == N - 1)
	{
		delete[] static_cast<int *>(target);
		return;
	}
	for (int i = 0; i < size[n->level]; i++)
		delete_list(static_cast<list *>(target) + i);
	delete[] static_cast<list *>(target);
}

INT array::operator[](const int index)
{
	return (INT(N, 1, static_cast<list *>(top->nxt) + index));
}

INT::INT(const int N, int level, void *data)
	: N(N), level(level), data(data)
{
}

INT INT::operator[](const int index)
{
	if (level == N - 1)
		return (INT(N, N, static_cast<int *>(static_cast<array::list *>(data)->nxt) + index));
	else
		return (INT(N, level + 1, static_cast<array::list *>(static_cast<array::list *>(data)->nxt) + index));
}

INT &INT::operator=(const int &a)
{
	*static_cast<int *>(data) = a;
	return (*this);
}

INT::operator int()
{
	return (*static_cast<int *>(data));
}
