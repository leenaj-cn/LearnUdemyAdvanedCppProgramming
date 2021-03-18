#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
	virtual string getDepartmentName() = 0;
	virtual void showInfo() = 0;

	string m_Name;
	int m_EmployeeId;
	int m_DepartmentId;
};