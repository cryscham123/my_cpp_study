#include "my_excel.h"

using namespace my_excel;

cell::cell(string data, int x, int y, table *t)
	: data(data), x(x), y(y), t(t) {}

string cell::stringify()
{
	return (data);
}

int cell::to_numeric()
{
	return (0);
}

table::table(int max_row, int max_col)
	: max_row(max_row), max_col(max_col)
{
	data = new cell **[max_row];
	for (int i = 0; i < max_row; i++)
	{
		data[i] = new cell *[max_col];
		for (int j = 0; j < max_col; j++)
			data[i][j] = NULL;
	}
}

table::~table()
{
	for (int i = 0; i < max_row; i++)
	{
		for (int j = 0; j < max_col; j++)
			if (data[i][j] != NULL)
				delete data[i][j];
		delete[] data[i];
	}
	delete[] data;
}

void table::reg_cell(cell *c, int row, int col)
{
	if (row >= max_row || col >= max_col)
		return;
	if (data[row][col] != NULL)
		delete data[row][col];
	data[row][col] = c;
}

int table::to_numeric(const string &s)
{
	int col = s[0] - 'A';
	int row = atoi(s.c_str() + 1) - 1;

	if (row < max_row && col < max_col && data[row][col] != NULL)
		return (data[row][col]->to_numeric());
	return (0);
}

int table::to_numeric(int row, int col)
{
	if (row < max_row && col < max_col && data[row][col] != NULL)
		return (data[row][col]->to_numeric());
	return (0);
}

string table::stringify(const string &s)
{
	int col = s[0] - 'A';
	int row = atoi(s.c_str() + 1) - 1;

	if (row < max_row && col < max_col && data[row][col] != NULL)
		return (data[row][col]->stringify());
	return ("");
}

string table::stringify(int row, int col)
{
	if (row < max_row && col < max_col && data[row][col] != NULL)
		return (data[row][col]->stringify());
	return ("");
}

ostream &my_excel::operator<<(ostream &o, table &t)
{
	o << t.print_table();
	return (o);
}

txt_table::txt_table(int row, int col)
	: table(row, col) {}

string txt_table::repeat_char(int n, char c)
{
	string s = "";
	for (int i = 0; i < n; i++)
		s += c;
	return (s);
}

string txt_table::col_num_to_str(int n)
{
	string s = "";
	if (n < 26)
		s += (n + 'A');
	else
	{
		s += n / 26 + 'A' - 1;
		s += n % 26 + 'A';
	}
	return (s);
}

string txt_table::print_table()
{
	string target;

	int *col_wide = new int[max_col];
	int total_wide = 4;
	target += repeat_char(4, ' ');
	for (int i = 0; i < max_col; i++)
	{
		target += " | ";
		int tmp = 0;
		for (int j = 0; j < max_row; j++)
			if (data[i][j] != NULL)
				tmp = MAX(tmp, data[i][j]->stringify().length());
		string col_num = col_num_to_str(i);
		col_wide[i] = MAX(col_num.length(), tmp);
		total_wide += col_wide[i] + 3;
		target += col_num;
		target += repeat_char(tmp - col_num.length(), ' ');
	}
	target += '\n';
	for (int i = 0; i < max_row; i++)
	{
		target += repeat_char(total_wide, '-');
		target += '\n';
		string row_num = to_string(i + 1);
		target += row_num;
		target += repeat_char(4 - row_num.length(), ' ');
		for (int j = 0; j < max_col; j++)
		{
			target += " | ";
			if (data[i][j] == NULL)
			{
				target += repeat_char(col_wide[j], ' ');
				continue;
			}
			target += data[i][j]->stringify();
			target += repeat_char(col_wide[j] - data[i][j]->stringify().length(), ' ');
		}
		target += '\n';
	}
	delete[] col_wide;
	return (target);
}
