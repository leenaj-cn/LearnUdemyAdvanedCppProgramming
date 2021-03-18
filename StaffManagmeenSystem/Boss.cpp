#include "Boss.h"

Boss::Boss(string name, int employee_id, int depart_id)
{
	this->m_Name = name;
	this->m_EmployeeId = employee_id;
	this->m_DepartmentId = depart_id;
}

string Boss::getDepartmentName()
{
	return string("Boss");
}

void Boss::showInfo()
{
	cout << this->m_Name << "\t";
	cout << this->m_EmployeeId << "\t";
	cout << this->getDepartmentName() << "\t\t";
	cout << "Responsibility: Manage all kinds things of the company" << endl;
}