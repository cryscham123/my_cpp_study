#pragma once

#include <iostream>
#include <fstream>
#include <string.h>

#define MAX(A, B) ((A) > (B) ? (A) : (B))

using namespace std;

namespace my_excel
{
	class cell;
	class table;

	class cell
	{
	protected:
		int x, y;
		table *t;
		string data;

	public:
		virtual string stringify();
		virtual int to_numeric();

		cell(string data, int x, int y, table *t);
	};

	class table
	{
	protected:
		int max_row, max_col;

		cell ***data;

	public:
		table(int max_row, int max_col);
		~table();

		void reg_cell(cell *c, int row, int col);
		int to_numeric(const string &s);
		int to_numeric(int row, int col);
		string stringify(const string &s);
		string stringify(int row, int col);

		virtual string print_table() = 0;
	};

	class txt_table : public table
	{
		string repeat_char(int n, char c);
		string col_num_to_str(int n);

	public:
		txt_table(int row, int col);
		string print_table();
	};
	ostream &operator<<(ostream &o, table &table);
};
