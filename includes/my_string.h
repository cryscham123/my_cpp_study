# ifndef MY_STRING_H
# define MY_STRING_H

# include <iostream>
# include <string.h>

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

		void		reserve(int n);
		int			length()					const;
		void		print()						const;
		int			compare(const my_string& s)		const;

		char		&operator [] (const int i)	const;
		
		friend bool	operator == (const my_string &a, const my_string &b);	
		
		~my_string();
};

# endif
