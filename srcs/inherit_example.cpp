#include "inherit_example.h"

using namespace inherit_example;

// employee_list
employee_list::employee_list(int n)
	: capability(n), current_size(0)
{
	data = new employee *[n];
}

void employee_list::add_employee(employee *e)
{
	if (current_size + 2 > capability)
	{
		capability *= 2;
		employee **tmp = new employee *[capability];
		delete[] data;
		data = tmp;
	}
	data[current_size++] = e;
}

int employee_list::size() const
{
	return (current_size);
}

void employee_list::print_total_info() const
{
	int cnt = 0;
	for (int i = 0; i < current_size; i++)
	{
		data[i]->print_info();
		cnt += data[i]->calculate_pay();
	}
	std::cout << "total pay: " << cnt << '\n';
}

employee_list::~employee_list()
{
	for (int i = 0; i < current_size; i++)
		delete data[i];
	delete[] data;
}

// employee
employee::employee(std::string name, int age, std::string position, int rank)
	: name(name), age(age), position(position), rank(rank) {}

employee::employee(const employee &e)
	: name(e.name), age(e.age), position(e.position), rank(e.rank) {}

void employee::print_info() const
{
	std::cout << name << " " << position << '(' << age << ')' << ": " << calculate_pay() << '\n';
}

int employee::calculate_pay() const
{
	return (200 + rank * 50);
}

// manager
manager::manager(std::string name, int age, std::string position, int rank, int year)
	: employee(name, age, position, rank), year(year) {}

manager::manager(const manager &m)
	: employee(m.name, m.age, m.position, m.rank), year(m.year) {}

void manager::print_info() const
{
	std::cout << name << " " << position << '(' << age << ", " << year << ')' << ": " << calculate_pay() << '\n';
}

int manager::calculate_pay() const
{
	return (200 + rank * 50 + 5 * year);
}
