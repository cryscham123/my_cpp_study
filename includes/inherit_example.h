# pragma once

# include <iostream>

namespace inherit_example
{
	class employee_list;
	class employee;
	class manager;
	
	class employee_list
	{
		int capability;
		int current_size;
		employee **data;

		public:
			explicit employee_list(int n);

			void add_employee(employee* e);
			int size() const;
			void print_total_info() const;

			~employee_list();
	};

	class employee
	{
		protected:
			std::string name;
			int age;

			std::string position;
			int rank;

		public:
			employee(std::string name, int age, std::string position, int rank);
			employee(const employee &e);
			
			virtual void print_info() const;
			virtual int calculate_pay() const;
	};

	class manager: public employee
	{
		int year;

		public:
			manager(std::string name, int age, std::string position, int rank, int year);
			manager(const manager &m);
			
			void print_info() const override;
			int calculate_pay() const override;
	};
}
