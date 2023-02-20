# include "inherit_example.h"

using namespace inherit_example;

int main()
{
  employee_list emp_list(10);
  emp_list.add_employee(new employee("노홍철", 34, "평사원", 1));
  emp_list.add_employee(new employee("하하", 34, "평사원", 1));

  emp_list.add_employee(new manager("유재석", 41, "부장", 7, 12));
  emp_list.add_employee(new manager("정준하", 43, "과장", 4, 15));
  emp_list.add_employee(new manager("박명수", 43, "차장", 5, 13));
  emp_list.add_employee(new employee("정형돈", 36, "대리", 2));
  emp_list.add_employee(new employee("길", 36, "인턴", -2));
  emp_list.print_total_info();
}
