#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Employee.h"
#include "GeneralEmployee.h"
#include "Boss.h"
#include "Manager.h"

#include <fstream>
#define FILENAME  "EmployeeList.txt"


class EmployeeManagerSystem
{
public:
	EmployeeManagerSystem();
	void ShowMenu();
	void ExitSystem();
	void AddEmp();
	void SaveFile();
	int GetEmpNum();
	void InitEmpArray();
	void ShowEmp();
	int IsExist(int id);
	void DeleteEmp();
	void ModifyEmp();
	void FindEmp();
	void SortEmp();
	void CleanFile();

	~EmployeeManagerSystem();


	int m_EmpNum;
	Employee** m_EmpArray;
	bool m_FileEmpty;
};