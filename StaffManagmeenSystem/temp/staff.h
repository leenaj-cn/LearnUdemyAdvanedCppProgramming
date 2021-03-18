#pragma once
#include <iostream>
#include <string>
using namespace std;

class Staff
{
public:
	void setName(string name);

	void setID(int id);

	void setDepartment(int depart_id);

	void setResponbility(string responbility);

	string getName();

	int getID();

	int getDepartment();

	string getResponbility();

protected:
	int m_ID;
	string m_Name;
	int m_Department;
	string m_Responsibility;

};
