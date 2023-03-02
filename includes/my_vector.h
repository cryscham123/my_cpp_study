# pragma once

# include <iostream>

using namespace std;

namespace my_vector
{
	class vector
	{
		string* data;
		int length;
		int capacity;

		public:
			vector(int n = 1);
			~vector();
			
			void push_back(string s);
			void remove(int x);
			int size() const;
			string operator [] (int i) const;
	};
}
