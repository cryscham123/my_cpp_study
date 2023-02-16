# ifndef MY_ARRAY_H
# define MY_ARRAY_H

# include <iostream>

class my_array
{
	struct list
	{
		int		level;
		void	*nxt;
	};
	const int	N;
	int			*size;
	list		*top;

	public:
		explicit my_array(int N, int *size);
		my_array(const my_array &arr);
		~my_array();
		
		int initialize_list(list *n);
		void copy_list(list *dst, list *src);
		void delete_list(list *n);
		void arr_error(int flag);
};

# endif
