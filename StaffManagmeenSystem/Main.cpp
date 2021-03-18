//#include "staff.h"
//#include "EmployeeSystem.h" 
//#include "utils.h"
#include "employeeManagerSystem.h"
//
//#include "Employee.h"
//#include "GeneralEmployee.h"
//#include "Boss.h"
//#include "Manager.h"
//void testcase()
//{
//	Employee* general = new GeneralEmployee("Tom", 24631, 5);
//	//Employee* general = NULL;
//	//general = new GeneralEmployee("Tom", 24631, 5);
//	general->showInfo();
//	delete general;
//
//	Employee* manager = new Manager("Jerry", 00100, 3);
//	manager->showInfo();
//	delete manager;
//
//	Employee* boss = new Boss("Selina", 00001, 1);
//	boss->showInfo();
//	delete boss;
//}

int main()
{
	//testcase();

	EmployeeManagerSystem ems;
	int select=0;

	while (true)
	{
		ems.ShowMenu();
		cout << "Please Input selection" << endl;
		cin >> select;

		switch (select)
		{
			case 0:
				ems.ExitSystem();
				break;
			case 1:
				ems.AddEmp();
				break;
			case 2:
				ems.ShowEmp();
				break;
			case 3:
				ems.DeleteEmp();
				break;
			case 4:
				ems.ModifyEmp();
				break;
			case 5:
				ems.FindEmp();
				break;
			case 6:
				ems.SortEmp();
				break;
			case 7:
				ems.CleanFile();
				break;
			default:
				//system("pause");
				system("cls");
				break;
		}
	}


	system("pause");
	return 0;
}

