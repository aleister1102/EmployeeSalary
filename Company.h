#pragma once
#include "Standard.h"
#include "FileHelper.h"
#include "Converter.h"
#include "Macro.h"
#include "Employee.h"


class EmployeeType {
public:
	inline static int DailyEmployee = 1;
	inline static int HourlyEmployee = 2;
	inline static int ProductEmployee = 3;
	inline static int Manager = 4;
};

class Company {
private:
	vector<IEmployee*> _employees;
	
public:
	Company(string);
	string toString();
};