# include "my_array.h"

int main()
{
	int a[2] = {2,2};
	int b[2] = {2,-1};
	int d[3] = {4,2,3};
	std:: cout << "A test\n";
	my_array A(-1, a);
	std:: cout << "B test\n";
	my_array B(2, b);
	std:: cout << "D test\n";
	my_array D(3, d);
}
