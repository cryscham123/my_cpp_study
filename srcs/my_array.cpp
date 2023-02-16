//#include "../includes/my_array.h"
#include "my_array.h"

my_array::my_array(int N, int *size)
:N(N), size(size)
{
	if (N < 1)
	{
		arr_error(1);
		top = NULL;
		return ;
	}
	top = new list;
	top->level = 0;
	int flag = initialize_list(top);
	if (flag != 0)
	{
		arr_error(flag);
		delete_list(top);
		delete top;
		top = NULL;
		return ;
	}
}

my_array::my_array(const my_array &arr)
:N(arr.N), size(arr.size)
{
	top = new list;
	top->level = 0;
	initialize_list(top);
	copy_list(top, arr.top);
}

my_array::~my_array()
{
	if (top != NULL)
	{
		delete_list(top);
		delete top;
	}
}

void my_array::arr_error(int flag)
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
int my_array::initialize_list(list *n)
{
	if (size[n->level] <= 0)
		return (2);
	if(n->level == N - 1)
	{
		n->nxt = new int[size[n->level]];
		return (0);
	}
	n->nxt = new list[size[n->level]];
	for (int i=0; i<size[n->level]; i++)
	{
		(static_cast<list *>(n->nxt) + i)->level = n->level + 1;
		int flag = initialize_list(static_cast<list *>(n->nxt) + i);
		if (flag != 0)
			return (flag);
	}
	return (0);
}

void my_array::copy_list(list *dst, list *src)
{
	if(dst->level == N-1)
	{
		for (int i=0; i < size[N-1]; i++)
			static_cast<int *>(dst->nxt)[i] = static_cast<int *>(src->nxt)[i];
		return ;
	}
	for (int i=0; i < size[N-1]; i++)
		copy_list(static_cast<list *>(dst->nxt) + i, static_cast<list *>(src->nxt) + i);
}

void my_array::delete_list(list *n)
{
	if (n->level == N-1)
	{
		delete[] static_cast<int *>(n->nxt);
		return ;
	}
	list *target = static_cast<list *>(n->nxt);
	if (target == NULL)
		return ;
	for (int i=0; i < size[n->level]; i++)
		delete_list(target + i);
	delete[] target;
}
