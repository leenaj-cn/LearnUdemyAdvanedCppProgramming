#include "GeneralEmployee.h"

GeneralEmployee::GeneralEmployee(string name, int employee_id, int depart_id)
{
	this->m_Name = name;
	this->m_EmployeeId = employee_id;
	this->m_DepartmentId = depart_id;
}

string GeneralEmployee::getDepartmentName()
{
	return string("General");
}
void GeneralEmployee::showInfo()
{
	cout << this->m_Name << "\t";
	cout << this->m_EmployeeId << "\t";
	cout << this->getDepartmentName() << "\t\t";
	cout << "Responsibility: Report to manager" << endl;
}