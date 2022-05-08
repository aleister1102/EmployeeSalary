#include "Employee.h"

// Interface

Employee::Employee()
{
	_name = "";
	_payment = 0;
}

Employee::Employee(string name, int payment)
{
	this->_name = name;
	this->_payment = payment;
}


// DailyEmployee

DailyEmployee::DailyEmployee() : Employee()
{
	_days = 0;
}

DailyEmployee::DailyEmployee(string name, int payment, int days)
	: Employee(name, payment) {
	_days = days;
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

HourlyEmployee::HourlyEmployee() : Employee()
{
	_hours = 0;
}

HourlyEmployee::HourlyEmployee(string name, int payment, int hours)
	: Employee(name, payment) {
	_hours = hours;
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

ProductEmployee::ProductEmployee() : Employee()
{
	_products = 0;
}

ProductEmployee::ProductEmployee(string name, int payment, int products)
	: Employee(name, payment) {
	_products = products;
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

Manager::Manager() : Employee()
{
	_totalEmployees = 0;
}

Manager::Manager(string name, int payment, int employees)
	: Employee(name, payment) {
	_totalEmployees = employees;
}

string Manager::toString() {
	stringstream builder;

	builder << "---- Manager ----\n";
	builder << "Name: " << Name() << "\n";
	builder << "Fixed Payment = " << FixedPayment() << "$\n";
	builder << "Payment Per Employee = " << Payment() << "$\n";
	builder << "Total Employees = " << Employees() << "\n";

	return builder.str();
}

int Manager::getTotalPayment()
{
	int totalPayment = Payment() * Employees() + FixedPayment();
	return totalPayment;
}

