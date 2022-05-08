#include "Employee.h"
#include "Company.h"


int  main()
{
#if 1
	Employee* employee1 = new DailyEmployee("Quan", 100, 28);
	cout << employee1->toString() << endl;
	cout << "Total Payment: " << employee1->getTotalPayment() << endl << endl;
#endif

#if 1
	Company company("November2021.txt");
	cout << company.toString() << endl;
#endif

	return 0;
}