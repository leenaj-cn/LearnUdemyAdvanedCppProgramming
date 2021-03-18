#include "staff.h"

void Staff::setName(string name)
{
	m_Name = name;
}
void Staff::setID(int id)
{
	m_ID = id;
}
void Staff::setDepartment(int depart_id)
{
	m_Department = depart_id;
}
void Staff::setResponbility(string responbility)
{
	m_Responsibility = responbility;
}

string Staff::getName()
{
	return m_Name;
}

int Staff::getID()
{
	return m_ID;
}

int Staff::getDepartment()
{
	return m_Department;
}

string Staff::getResponbility()
{
	return m_Responsibility;
}