# include "my_excel.h"

using namespace my_excel;

int main()
{
  txt_table table(5, 5);
  ofstream out("test.txt");
  table.reg_cell(new cell("Hello~", 0, 0, &table), 0, 0);
  table.reg_cell(new cell("C++", 0, 1, &table), 0, 1);

  table.reg_cell(new cell("Programming", 1, 1, &table), 1, 1);
  cout << table;
  out << table;
}
