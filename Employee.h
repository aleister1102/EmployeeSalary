#pragma once
#include "Standard.h"

class Employee
{
private:
	string _name;
	int _payment;

public:
	string Name() { return _name; }
	int Payment(){return _payment;}
	void setFullName(string fullName) { _name = fullName; }
	void setPayment(int payment) { _payment = payment; }

public:
	Employee();
	Employee(string, int);

public:
	virtual string toString() = 0;
	virtual int getTotalPayment() = 0;
};

class DailyEmployee : public Employee {
private:
	int _days;

public:
	int Days() { return _days; }

public:
	DailyEmployee();
	DailyEmployee(string, int, int);
	
public:
	string toString();
	int getTotalPayment();
};

class HourlyEmployee : public Employee {
private:
	int _hours;

public:
	int Hours() { return _hours; }

public:
	HourlyEmployee();
	HourlyEmployee(string, int, int);

public:
	string toString();
	int getTotalPayment();
};

class ProductEmployee : public Employee {
private:
	int _products;

public:
	int Products() { return _products; }

public:
	ProductEmployee();
	ProductEmployee(string, int, int);

public:
	string toString();
	int getTotalPayment();
};


class Manager : public Employee {
private:
	int _totalEmployees;
	int _fixedPayment = 500;

public:
	int Employees() { return _totalEmployees; }
	int FixedPayment() { return _fixedPayment; }
public:
	Manager();
	Manager(string, int, int);

public:
	string toString();
	int getTotalPayment();
};

