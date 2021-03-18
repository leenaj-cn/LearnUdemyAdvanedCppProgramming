#include "employeeManagerSystem.h"

EmployeeManagerSystem::EmployeeManagerSystem()
{

}

void EmployeeManagerSystem::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "********   0. Exit \t System   **********" << endl;
	cout << "********   1. Add \t Employee   ********" << endl;
	cout << "********   2. Show \t Employee   ********" << endl;
	cout << "********   3. Delete \t Employee   ********" << endl;
	cout << "********   4. Modify \t Employee   ********" << endl;
	cout << "********   5. Find \t Employee   ********" << endl;
	cout << "********   6. Sort \t Employee   ********" << endl;
	cout << "********   7. Clear \t System   **********" << endl;
	cout << "*******************************************" << endl;
}

void EmployeeManagerSystem::ExitSystem()
{
	cout << "Exited!" << endl;
	system("pause");
	exit(0);
}

EmployeeManagerSystem::~EmployeeManagerSystem()
{

}