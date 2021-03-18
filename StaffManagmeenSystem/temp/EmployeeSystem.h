#include "staff.h"
#include <fstream>

string FileName = "EmployeeList.txt";
ofstream File_W(FileName, ios::out);
ifstream File_R(FileName, ios::in);

class EmployeeSystem: public Staff
{
public:
	EmployeeSystem(string name, int staff_id, int depart_id, string responsibility)
	{
		m_ID = staff_id;
		m_Name = name;
		m_Department = depart_id;
		m_Responsibility = responsibility;

	}
	void ExitSystem()
	{
		cout << "Exited!" << endl;
		system("pause");
		return;
	}

	void AddEmployee(int staff_id, string name, int department_id)
	{
		m_ID = staff_id;
		m_Name = name;
		m_Department = department_id;

		if (!File_W.is_open())	cout << "Could not create file: " << FileName << endl;

		File_W << m_Name << "\t";
		File_W << m_ID << "\t";
		File_W << m_Department << endl;

	}

	void ShowEmpolyeeList()
	{
		if (!File_R.is_open())	cout << "Could not load file: " << FileName << endl;

		//cout << m_Name << "\t";
		//cout << m_ID << "\t";
		//cout << m_Department << "\t";
		//cout << m_Responsibility << endl;

		if (File_R.is_open()) {
			string line;
			while (File_R) {
				getline(File_R, line);
				cout << line << endl;
			}

		}
		else {
			cout << "Cannot open file: " << FileName << endl;
		}
	}

	void DeleteEmployee(int m_ID)
	{

	}

	void ModifyEmployee(int m_ID)
	{

	}

	void FindEmpoyee(int m_ID)
	{

	}

	void SortEmpoyee()
	{

	}

	void ClearAll()
	{

	}

	~EmployeeSystem()
	{
		File_W.close();
		File_R.close();
	}
//private:
	//int m_ID;
	//string m_Name;
	//int m_Department;
	//string m_Responsibility;


};

