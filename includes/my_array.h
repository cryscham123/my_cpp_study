# ifndef MY_ARRAY_H
# define MY_ARRAY_H

# include <iostream>

namespace my_array
{
	class array;
	class INT;

	class array
	{
		friend INT;
		struct list
		{
			int		level;
			void	*nxt;
		};
		const int	N;
		int			*size;
		list		*top;

		public:
			explicit array(int N, int *size);
			array(const array &arr);
			~array();
			
			int initialize_list(list *n);
			void copy_list(list *dst, list *src);
			void delete_list(list *n);
			void arr_error(int flag);

			INT operator [](const int index);
	};

	class INT
	{
		const int	N;
		void		*data;
		int			level;

		public:
			INT(const int N, int _level = 0, void *_data = NULL);
			
			INT operator [] (const int index);
			INT &operator = (const int& a);
			operator int();
	};
}

# endif
