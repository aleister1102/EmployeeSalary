#include "Business.h"
#include "Employee.h"

struct
{
	vector<IEmployee *> employees;
} company;

int main()
{
#if 0
	IEmployee* employee1 = new DailyEmployee("Quan", 100, 28);
	cout << employee1->toString() << endl;
	cout << "Total Payment: " << employee1->getTotalPayment() << endl << endl;
#endif

#if 1
	company.employees = getEmployee("November2021.txt");
	for (auto employee : company.employees)
	{
		cout << employee->toString();
		cout << "Total payment: " << employee->getTotalPayment() << endl<<endl;
	}
	cout << endl;
#endif

	return 0;
}