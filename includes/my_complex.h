# ifndef MY_COMPLEX_H
# define MY_COMPLEX_H

# include <iostream>
# include <string.h>
# include <stdlib.h>

class my_complex
{
	double real, img;

	public:
		my_complex(double real, double img);
		my_complex(const char * s);
		my_complex(const my_complex &c);

		my_complex &operator += (const my_complex &c);
		my_complex &operator -= (const my_complex &c);
		my_complex &operator *= (const my_complex &c);
		my_complex &operator /= (const my_complex &c);

		friend my_complex operator + (const my_complex &a, const my_complex &b);
		friend my_complex operator - (const my_complex &a, const my_complex &b);
		friend my_complex operator * (const my_complex &a, const my_complex &b);
		friend my_complex operator / (const my_complex &a, const my_complex &b);
		friend std::ostream &operator << (std::ostream &os, const my_complex &c);
};

# endif
