#include "Business.h"

vector<IEmployee*> getEmployee(string fileName)
{
	vector<string> lines = FileHelper::readTXT(fileName);
	vector<IEmployee*> employees;

	for (int i = 0; i < lines.size(); i += 2)
	{
		string name = StringHelper::trim(StringHelper::searchRegex(lines[i], NAME));
		int payment = Converter::parseInt(StringHelper::searchRegex(lines[i + 1], PAYMENT));
		int unit = Converter::parseInt(StringHelper::searchRegex(lines[i + 1], UNIT));
		int fixedPayment = Converter::parseInt(StringHelper::searchRegex(lines[i + 1], PAYMENT, 2));

		IEmployee* employee = nullptr;

		if (StringHelper::searchRegex(lines[i], DAILY_EMPLOYEE) != "0")
		{
			employee = EmployeeFactory::createEmployee(EmployeeType::DailyEmployee);
			auto temp = (DailyEmployee*) employee;

			temp->setName(name);
			temp->setPayment(payment);
			temp->setDays(unit);

			employee = temp;
		}
		else if (StringHelper::searchRegex(lines[i], HOURLY_EMPLOYEE) != "0")
		{
			employee = EmployeeFactory::createEmployee(EmployeeType::HourlyEmployee);
			auto temp = (HourlyEmployee*)employee;

			temp->setName(name);
			temp->setPayment(payment);
			temp->setHours(unit);

			employee = temp;
		}
		else if (StringHelper::searchRegex(lines[i], PRODUCT_EMPLOYEE) != "0")
		{
			employee = EmployeeFactory::createEmployee(EmployeeType::ProductEmployee);
			auto temp = (ProductEmployee*)employee;

			temp->setName(name);
			temp->setPayment(payment);
			temp->setProducts(unit);

			employee = temp;
		}
		else
		{
			employee = EmployeeFactory::createEmployee(EmployeeType::Manager); // default is manager
			auto temp = (Manager*)employee;

			temp->setName(name);
			temp->setPayment(payment);
			temp->setTotalEmployees(unit);
			temp->setFixedPayment(fixedPayment);

			employee = temp;
		}

		employees.push_back(employee);
	}

	return employees;
}
