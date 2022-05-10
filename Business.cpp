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

        IEmployee *employee = nullptr;
        if (StringHelper::searchRegex(lines[i], DAILY_EMPLOYEE) != "")
        {
            int employeeType = EmployeeType::DailyEmployee;
            employee = EmployeeFactory ::createEmployee(employeeType, name, payment, unit);
        }
        else if (StringHelper::searchRegex(lines[i], HOURLY_EMPLOYEE) != "")
        {
            int employeeType = EmployeeType::HourlyEmployee;
            employee = EmployeeFactory::createEmployee(employeeType, name, payment, unit);
        }
        else if (StringHelper::searchRegex(lines[i], PRODUCT_EMPLOYEE) != "")
        {
            int employeeType = EmployeeType::ProductEmployee;
            employee = EmployeeFactory::createEmployee(employeeType, name, payment, unit);
        }
        else
        {
            int employeeType = EmployeeType::Manager; // default is manager
            employee = EmployeeFactory::createEmployee(employeeType, name, payment, unit);
        }

        employees.push_back(employee);
    }
    
    return employees;
    
}
