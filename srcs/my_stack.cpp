# include "../includes/my_stack.h"

using namespace my_stack;

stack::stack()
:start(NULL, ""), current(&start) {}

stack::~stack()
{
	while (!(*this).empty())
	{
		node *to_delete = current;
		current = current->prev;
		delete to_delete;
	}
}

void stack::push(string s)
{
	current = new node(current, s);
}

void stack::pop()
{
	if ((*this).empty())
		return;
	node *to_delete = current;
	current = current->prev;
	delete to_delete;
}

string stack::top() const
{
	return (current->s);
}

bool stack::empty() const
{
	return (current == &start);
}
