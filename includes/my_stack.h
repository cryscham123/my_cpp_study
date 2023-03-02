# pragma once
# include <iostream>

using namespace std;

namespace my_stack
{
	class stack
	{
		struct node
		{
			node *prev;
			string s;

			node(node* prev, string s)
			:prev(prev), s(s) {}
		};

		node* current;
		node start;

		public:
			stack();
			~stack();
			void push(string s);
			void pop();
			string top() const;
			bool empty() const;
	};
};
