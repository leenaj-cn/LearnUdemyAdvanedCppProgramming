#include "employeeManagerSystem.h"

EmployeeManagerSystem::EmployeeManagerSystem()
{
	ifstream ifs(FILENAME, ios::in);

	//File not exist
	if (!ifs.is_open())
	{
		cout << "File is not exist!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		return;
	}

	//File is empty
	char ch;
	ifs >> ch;
	if (ifs.eof()) //end of file
	{
		cout << "File is empty!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		return;
	}

	//File is not empty
	//cout << "File is not empty!" << endl;
	int number = this->GetEmpNum();
	cout << "Employee number= " << number << endl;
	this->m_EmpNum = number;

	//Init array
	this->m_EmpArray = new Employee * [this->m_EmpNum];
	this->InitEmpArray();

	////test code
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "name=" << this->m_EmpArray[i]->m_Name <<"   "
	//		<< "id=" << this->m_EmpArray[i]->m_EmployeeId << "   "
	//		<< "depart=" << this->m_EmpArray[i]->m_DepartmentId << endl;
	//}


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

void EmployeeManagerSystem::AddEmp()
{
	cout << "Please input the number you want to add:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum <= 0)
	{
		cout << "counter error" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	int newSize = this->m_EmpNum + addNum;
	Employee** newSpace = new Employee * [newSize];

	if (this->m_EmpNum != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
			newSpace[i] = this->m_EmpArray[i];
	}

	for (int i = 0; i < addNum; i++)
	{
		string name;
		int employ_id;
		int depart_id;
		cout << "Please input employee"<<i+1<<"'s id:" << endl;
		cin >> employ_id;

		cout << "Please input employee" << i + 1 << "'s name:" << endl;
		cin >> name;

		cout << "Please input employee" << i + 1 << "'s depart id:" << endl;
		cout << "1. general" << endl;
		cout << "2. manager" << endl;
		cout << "3. boss" << endl;
		cin >> depart_id;

		Employee* emp = NULL;
		switch (depart_id)
		{
		case 1:
			emp = new GeneralEmployee(name, employ_id, depart_id);
			break;
		case 2:
			emp = new Manager(name, employ_id, depart_id);
			break;
		case 3:
			emp = new Boss(name, employ_id, depart_id);
			break;
		default:
			break;
		}

		newSpace[this->m_EmpNum + i] = emp;
	}

	delete [] this->m_EmpArray;
	this->m_EmpArray = newSpace;
	this->m_EmpNum = newSize;
	this->m_FileEmpty = false;

	cout << "Added " << addNum << "new employees!" << endl;

	this->SaveFile();

	system("pause");
	system("cls");
}

void EmployeeManagerSystem::SaveFile()
{
	ofstream ofs(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_EmployeeId << "\t"
			<< this->m_EmpArray[i]->m_DepartmentId << endl;
	}

	ofs.close();

}

int EmployeeManagerSystem::GetEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
		cout << "failed to open file " << FILENAME << endl;

	int employee_id;
	string name;
	int depart_id;

	int num = 0;
	while (ifs >> name && ifs >> employee_id && ifs >> depart_id)
	{
		num++;
	}
	
	ifs.close();
	return num;
}

void EmployeeManagerSystem::InitEmpArray()
{
	ifstream ifs(FILENAME, ios::in);
	int employee_id;
	string name;
	int depart_id;

	int index = 0;
	while (ifs >> name && ifs >> employee_id && ifs >> depart_id)
	{
		Employee* emp = NULL;
		
		if (depart_id == 1)
			emp = new GeneralEmployee(name, employee_id, depart_id);
		else if(depart_id == 2)
			emp = new Manager(name, employee_id, depart_id);
		else
			emp = new Boss(name, employee_id, depart_id);

		this->m_EmpArray[index] = emp;
		index++;	
	}

	ifs.close();


}

void EmployeeManagerSystem::ShowEmp()
{
	ifstream ifs(FILENAME, ios::in);
	
	if (this->m_FileEmpty)
		cout << "File " << "\"" << FILENAME << "\"" << "is empty or not exist" << endl;
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");

}

int EmployeeManagerSystem::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_EmployeeId == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void EmployeeManagerSystem::DeleteEmp()
{
	if (this->m_FileEmpty)
	{
		cout << "File is empry or not exist" << endl;
		system("pause");
		system("cls");
		return;

	}
		
	int id;
	cout << "Input the empoyee id you want to delete:" << endl;
	cin >> id;

	int ret = this->IsExist(id);
	if (ret == -1)
		cout << "the employee not exist" << endl;
	else
	{
		for (int i = ret; i < this->m_EmpNum-1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}

		this->m_EmpNum--;
		this->SaveFile();

		cout << "the employee Deleted" << endl;

	}

	system("pause");
	system("cls");
}

void EmployeeManagerSystem::ModifyEmp()
{
	if (this->m_FileEmpty)
	{
		cout << "File is empty or not exist" << endl;
		system("pause");
		system("cls");
		return;

	}

	int id;
	cout << "Input the empoyee id you want to modify:" << endl;
	cin >> id;

	int ret = this->IsExist(id);
	if (ret == -1)
		cout << "the employee not exist, modify failed" << endl;
	else
	{
		delete this->m_EmpArray[ret];

		int new_empoyee_Id = 0;
		string newName = " ";
		int new_depart_id = 0;

		cout << "Find " << id <<" Employee, Please Input new employee id: " << endl;
		cin >> new_empoyee_Id;
		
		cout << "Input name:" << endl;
		cin >> newName;

		cout << "Input depart id:" << endl;
		cout << "1. general" << endl;
		cout << "2. manager" << endl;
		cout << "3. boss" << endl;
		cin >> new_depart_id;

		Employee* emp = NULL;
		switch (new_depart_id)
		{
		case 1:
			emp = new GeneralEmployee(newName, new_empoyee_Id, new_depart_id);
			break;
		case 2:
			emp = new Manager(newName, new_empoyee_Id, new_depart_id);
			break;
		case 3:
			emp = new Boss(newName, new_empoyee_Id, new_depart_id);
			break;
		default:
			break;
		}
		this->m_EmpArray[ret] = emp;
		this->SaveFile();

		cout << "modify success!" << endl;
	}

	system("pause");
	system("cls");
}

void EmployeeManagerSystem::FindEmp()
{
	if (this->m_FileEmpty)
		cout << "File is not exist or empty" << endl;
	else
	{
		cout << "Input the way you want to find:" << endl;
		cout << "1. Find by employee id:" << endl;
		cout << "2. Find by employee name:" << endl;
		int select;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			cout << "Input employee id:" << endl;
			int id;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret == -1)
				cout << "the employee not exist, modify failed" << endl;
			else
			{
				cout << "the employee found, below is the info:" << endl;

				m_EmpArray[ret]->showInfo();
				break;
	
			}
		}
			break;
		case 2:
		{
			cout << "Input employee name:" << endl;
			string name;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (name == m_EmpArray[i]->m_Name)
				{
					cout << "the employee found, employee id=" << m_EmpArray[i]->m_EmployeeId <<":"<<endl;
					m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
				cout << "Failed to found this people by name" << endl;
		}
			break;
		default:
			cout << "input error" << endl;
			break;
		}
	}


	system("pause");
	system("cls");
}

void EmployeeManagerSystem::SortEmp()
{
	if (this->m_FileEmpty)
	{
		cout << "File is not exist or empty" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "Input the way you want to sort:" << endl;
		cout << "1. sort by ¡ü" << endl;
		cout << "2. sort by ¡ý" << endl;
		int select;
		cin >> select;


		for (int i = 0; i < this->m_EmpNum - 1; i++)
		{
			for (int j =0; j < this->m_EmpNum - 1-i; j++)
			{
				if (select==1)
				{
					if (this->m_EmpArray[j]->m_EmployeeId > this->m_EmpArray[j+1]->m_EmployeeId)
					{
						Employee* temp = m_EmpArray[j];
						m_EmpArray[j] = m_EmpArray[j + 1];
						m_EmpArray[j + 1] = temp;
					}
				}
				else
				{
					if (this->m_EmpArray[j]->m_EmployeeId < this->m_EmpArray[j + 1]->m_EmployeeId)
					{
						Employee* temp = m_EmpArray[j];
						m_EmpArray[j] = m_EmpArray[j + 1];
						m_EmpArray[j + 1] = temp;
					}
				}
			}
		}

		cout << "sort done: " << endl;
		this->SaveFile();
		this->ShowEmp();

	}

}




void EmployeeManagerSystem::CleanFile()
{
	cout << "Are you sure to clear?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc); //delete file and recreate it
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileEmpty = true;
		}
		cout << "Clean file done!" << endl;

	}
	else {
		cout << "Turn Back!" << endl;
	}

	system("pause");
	system("cls");
}

EmployeeManagerSystem::~EmployeeManagerSystem()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}