#include "Employee.h"

// Interface

IEmployee::IEmployee()
{
	_name = "";
	_payment = 0;
}

IEmployee::IEmployee(string name, int payment)
{
	this->_name = name;
	this->_payment = payment;
}


// DailyEmployee

DailyEmployee::DailyEmployee() : IEmployee()
{
	_days = 0;
}

DailyEmployee::DailyEmployee(string name, int payment, int days)
	: IEmployee(name, payment) {
	_days = days;
}

IEmployee* DailyEmployee::Clone(string name, int payment, int days)
{
	return new DailyEmployee(name, payment, days);
}

string DailyEmployee::toString() {
	stringstream builder;

	builder << "---- Daily Employee ----\n";
	builder << "Name: " << Name() << "\n";
	builder << "Daily Payment = " << Payment() << "$\n";
	builder << "Total Days = " << Days() << "\n";

	return builder.str();
}

int DailyEmployee::getTotalPayment()
{
	int totalPayment = Payment() * Days();
	return totalPayment;
}

// Hourly Employee

HourlyEmployee::HourlyEmployee() : IEmployee()
{
	_hours = 0;
}

HourlyEmployee::HourlyEmployee(string name, int payment, int hours)
	: IEmployee(name, payment) {
	_hours = hours;
}

IEmployee* HourlyEmployee::Clone(string name, int payment, int hours)
{
	return new HourlyEmployee(name, payment, hours);
}

string HourlyEmployee::toString() {
	stringstream builder;

	builder << "---- Hourly Employee ----\n";
	builder << "Name: " << Name() << "\n";
	builder << "Hourly Payment = " << Payment() << "$\n";
	builder << "Total Hours = " << Hours() << "\n";

	return builder.str();
}

int HourlyEmployee::getTotalPayment()
{
	int totalPayment = Payment() * Hours();
	return totalPayment;
}

// Product Employee

ProductEmployee::ProductEmployee() : IEmployee()
{
	_products = 0;
}

ProductEmployee::ProductEmployee(string name, int payment, int products)
	: IEmployee(name, payment) {
	_products = products;
}

IEmployee* ProductEmployee::Clone(string name, int payment, int products)
{
	return new ProductEmployee(name, payment, products);
}

string ProductEmployee::toString() {
	stringstream builder;

	builder << "---- Product Employee ----\n";
	builder << "Name: " << Name() << "\n";
	builder << "Payment Per Product = " << Payment() << "$\n";
	builder << "Total Products = " << Products() << "\n";
	
	return builder.str();
}

int ProductEmployee::getTotalPayment()
{
	int totalPayment = Payment() * Products();
	return totalPayment;
}

// Manager

Manager::Manager() : IEmployee()
{
	_totalEmployees = 0;
}

Manager::Manager(string name, int payment, int employees)
	: IEmployee(name, payment) {
	_totalEmployees = employees;
}

IEmployee* Manager::Clone(string name, int payment, int employees)
{
	return new Manager(name, payment, employees);
}

string Manager::toString() {
	stringstream builder;

	builder << "---- Manager ----\n";
	builder << "Name: " << Name() << "\n";
	builder << "Fixed Payment = " << FixedPayment() << "$\n";
	builder << "Payment Per Employee = " << Payment() << "$\n";
	builder << "Total Employees = " << TotalEmployees() << "\n";

	return builder.str();
}

int Manager::getTotalPayment()
{
	int totalPayment = Payment() * TotalEmployees() + FixedPayment();
	return totalPayment;
}

// Employee Factory

IEmployee* EmployeeFactory::createEmployee(int type, string name, int payment, int unit)
{
	IEmployee* employee = nullptr;

	if (type == EmployeeType::DailyEmployee)
	{
		employee = new DailyEmployee(name, payment, unit);
		return employee;
	}
	else if (type == EmployeeType::HourlyEmployee)
	{
		employee = new HourlyEmployee(name, payment, unit);
		return employee;
	}
	else if (type == EmployeeType::ProductEmployee)
	{
		employee = new ProductEmployee(name, payment, unit);
		return employee;
	}
	else if (type == EmployeeType::Manager)
	{
		employee = new Manager(name, payment, unit);
		return employee;
	}

	return employee;
}

// Prototype Factory

vector<IEmployee*> PrototypeFactory::_prototypes = { 
	new DailyEmployee,
	new HourlyEmployee,
	new ProductEmployee,
	new Manager
};

IEmployee* PrototypeFactory::makeEmployee(int type, string name, int payment, int unit)
{
	return _prototypes[--type]->Clone(name, payment, unit);
}
