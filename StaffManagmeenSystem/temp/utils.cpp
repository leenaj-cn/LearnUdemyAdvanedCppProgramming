#include "utils.h"

void showMenu()
{
	cout << "*******************************************" << endl;
	cout << "********   1. Exit \t System   ********" << endl;
	cout << "********   2. Add \t Employee   ********" << endl;
	cout << "********   3. Show \t Employee   ********" << endl;
	cout << "********   4. Delete \t Employee   ********" << endl;
	cout << "********   5. Modify \t Employee   ********" << endl;
	cout << "********   6. Find \t Employee   ********" << endl;
	cout << "********   7. Sort \t Employee   ********" << endl;
	cout << "********   8. Clear \t System   ********" << endl;
	cout << "*******************************************" << endl;

}

void Add()
{
	int count;
	cout << "How many employees you want to add?" << endl;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		string name;
		int empoyee_id;
		int depart_id;

		cout << "Please Input the id of Employee:" << i + 1 << endl;
		cin >> empoyee_id;

		cout << "Please Input the name of Employee:" << i + 1 << endl;
		cin >> name;

		cout << "Please Input the department of Employee:" << i + 1 << endl;
		cin >> depart_id;



	}

}