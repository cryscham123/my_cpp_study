# include "my_complex.h"

my_complex::my_complex(double real, double img)
: real(real), img(img) {}

my_complex::my_complex(const char *s)
{
	real = atof(s);
	int i = 0;
	while (i < strlen(s) && s[i] != 'i')
		i++;
	if (s[i] == 'i' && (s[i-1] == '+' || s[i-1] == '-'))
		img = s[i-1] == '+' ? atof(s + i + 1) : -atof(s + i + 1);
	else
		img = 0;
}

my_complex::my_complex(const my_complex &c)
: real(c.real), img(c.img) {}

std::ostream &operator << (std::ostream &os, const my_complex &c)
{
	os << '(' << c.real << " , " << c.img << ")\n";
	return (os);
}

my_complex operator + (const my_complex &a, const my_complex &b)
{
	my_complex tmp(a.real + b.real, a.img + b.img);
	return (tmp);
}

my_complex operator - (const my_complex &a, const my_complex &b)
{
	my_complex tmp(a.real - a.real, b.img - b.img);
	return (tmp);
}

my_complex operator * (const my_complex &a, const my_complex &b)
{
	my_complex tmp(
			a.real * b.real - a.img * b.img,
			a.real * b.img + a.img * b.real);
	return (tmp);
}

my_complex operator / (const my_complex &a, const my_complex &b)
{
	my_complex tmp(
			(a.real * b.real + a.img * b.img) / (b.real * b.real + b.img * b.img),
			(a.img * b.real - a.real * b.img) / (b.real * b.real + b.img * b.img));
	return (tmp);
}

my_complex &my_complex::operator += (const my_complex &c)
{
	(*this) = (*this) + c;
	return (*this);
}

my_complex &my_complex::operator -= (const my_complex &c)
{
	(*this) = (*this) - c;
	return (*this);
}

my_complex &my_complex::operator *= (const my_complex &c)
{
	(*this) = (*this) * c;
	return (*this);
}

my_complex &my_complex::operator /= (const my_complex &c)
{
	(*this) = (*this) / c;
	return (*this);
}
