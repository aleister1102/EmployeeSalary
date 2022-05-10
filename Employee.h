#pragma once
#include "Standard.h"

class EmployeeType {
public:
	inline static int DailyEmployee = 1;
	inline static int HourlyEmployee = 2;
	inline static int ProductEmployee = 3;
	inline static int Manager = 4;
};

class IEmployee
{
private:
	string _name;
	int _payment;

public:
	string Name() { return _name; }
	int Payment(){return _payment;}
	void setFullName(string name) { _name = name; }
	void setPayment(int payment) { _payment = payment; }

public:
	IEmployee();
	IEmployee(string, int);

public:
	virtual string toString() = 0;
	virtual int getTotalPayment() = 0;
};

class DailyEmployee : public IEmployee {
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

class HourlyEmployee : public IEmployee {
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

class ProductEmployee : public IEmployee {
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


class Manager : public IEmployee {
private:
	int _totalEmployees;
	int _fixedPayment = 500;

public:
	int TotalEmployees() { return _totalEmployees; }
	int FixedPayment() { return _fixedPayment; }
public:
	Manager();
	Manager(string, int, int);

public:
	string toString();
	int getTotalPayment();
};

