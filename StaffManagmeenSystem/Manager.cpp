#include "Manager.h"

Manager::Manager(string name, int employee_id, int depart_id)
{
	this->m_Name = name;
	this->m_EmployeeId = employee_id;
	this->m_DepartmentId = depart_id;
}

string Manager::getDepartmentName()
{
	return string("Manager");
}

void Manager::showInfo()
{
	cout << this->m_Name << "\t";
	cout << this->m_EmployeeId << "\t";
	cout << this->getDepartmentName() << "\t\t";
	cout << "Responsibility: Report to Boss and and get report from normal employee" << endl;
}