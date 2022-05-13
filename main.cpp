#include "Business.h"
#include "Employee.h"

struct
{
	vector<IEmployee *> employees;
} company;

int main()
{

#if 1
	company.employees = getEmployee("data/November2021.txt");
	for (auto employee : company.employees)
	{
		cout << employee->toString();
		cout << "Total payment: " << employee->getTotalPayment() << endl<<endl;
	}
	cout << endl;
#endif
	return 0;
}