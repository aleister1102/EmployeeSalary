#pragma once
#include "Standard.h"

class EmployeeType {
public:
	inline static int DailyEmployee = 0;
	inline static int HourlyEmployee = 1;
	inline static int ProductEmployee = 2;
	inline static int Manager = 3;
};

class IEmployee
{
protected:
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
	virtual IEmployee* Clone() = 0;
};

class DailyEmployee : public IEmployee {
private:
	int _days;

public:
	int Days() { return _days; }
	void setDays(int days) { _days = days; }

public:
	DailyEmployee();
	DailyEmployee(string, int, int);
	DailyEmployee(const DailyEmployee& other);
	
public:
	string toString();
	int getTotalPayment();
	IEmployee* Clone();
};

class HourlyEmployee : public IEmployee {
private:
	int _hours;

public:
	int Hours() { return _hours; }
	void setHours(int hours) { _hours = hours; }

public:
	HourlyEmployee();
	HourlyEmployee(string, int, int);
	HourlyEmployee(const HourlyEmployee& other);

public:
	string toString();
	int getTotalPayment();
	IEmployee* Clone();
};

class ProductEmployee : public IEmployee {
private:
	int _products;

public:
	int Products() { return _products; }
	void setProducts(int products) { _products = products; }

public:
	ProductEmployee();
	ProductEmployee(string, int, int);
	ProductEmployee(const ProductEmployee& other);
public:
	string toString();
	int getTotalPayment();
	IEmployee* Clone();
};


class Manager : public IEmployee {
private:
	int _totalEmployees;
	int _fixedPayment = 500;

public:
	int TotalEmployees() { return _totalEmployees; }
	int FixedPayment() { return _fixedPayment; }
	void setTotalEmployees(int totalEmployees) { _totalEmployees = totalEmployees; }

public:
	Manager();
	Manager(string, int, int);
	Manager(const Manager& other);

public:
	string toString();
	int getTotalPayment();
	IEmployee* Clone();
};

class EmployeeFactory {
private:
	static vector<IEmployee*> _prototypes;
public:
	static IEmployee* createEmployee(int type);
};


