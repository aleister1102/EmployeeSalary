#include "Company.h"

Company::Company(string fileName)
{
	vector<string> lines = FileHelper::readTXT(fileName);
	
	for (int i = 0; i < lines.size(); i+=2)
	{
		string name = StringHelper::trim(StringHelper::searchRegex(lines[i], NAME));
		int payment = Converter::parseInt(StringHelper::searchRegex(lines[i + 1], PAYMENT));
		int unit = Converter::parseInt(StringHelper::searchRegex(lines[i + 1], UNIT));

		IEmployee* employee = nullptr;
		if (StringHelper::searchRegex(lines[i], DAILY_EMPLOYEE) != "")
		{
			int employeeType = EmployeeType::DailyEmployee;
			employee = new DailyEmployee(name, payment, unit);
		}
		else if (StringHelper::searchRegex(lines[i], HOURLY_EMPLOYEE) != "") {
			int employeeType = EmployeeType::HourlyEmployee;
			employee = new HourlyEmployee(name, payment, unit);
		}
		else if(StringHelper::searchRegex(lines[i], PRODUCT_EMPLOYEE) != "") {
			int employeeType = EmployeeType::ProductEmployee;
			employee = new ProductEmployee(name, payment, unit);
		}
		else {
			int employeeType = EmployeeType::Manager; // default is manager
			employee = new Manager(name, payment, unit);
		}

		_employees.push_back(employee);
	}
}

string Company::toString()
{
	stringstream builder;

	for (auto employee : _employees)
	{
		builder << employee->toString() << endl;
	}
	
	return builder.str();
}