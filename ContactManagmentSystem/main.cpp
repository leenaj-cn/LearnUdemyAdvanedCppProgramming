#include "Header.h"
#include <typeinfo>


int main()
{
	int menuId = 0;

	Addressbook contact;


	while (true)
	{
		showMenu();

		cin >> menuId;

		switch (menuId)
		{
		case 1:
			addContact(&contact);
			break;
		case 2:
			showContact(&contact);
			break;
		case 3:
			deleteContact(&contact);
			break;
		case 4:
			findContact(&contact);
			break;
		case 5:
			modifyContact(&contact);
			break;
		case 6:
			clearContact(&contact);
			break;
		case 0:
			cout << "See ya!" << endl;
			system("pause");
			return 0;
			break;

		}
	}



	system("pause");
	return 0;
	
}

void showMenu()
{
	cout << "*******************************************" << endl;
	cout << "********   1. Add\t Contact   ********" << endl;
	cout << "********   2. Show\t Contact   ********" << endl;
	cout << "********   3. Delete\t Contact   ********" << endl;
	cout << "********   4. Find\t Contact   ********" << endl;
	cout << "********   5. Modify\t Contact   ********" << endl;
	cout << "********   6. Clear\t Contact   ********" << endl;
	cout << "********   0. Exit\t Contact   ********" << endl;
	cout << "*******************************************" << endl;

}

void addContact(Addressbook * contact)
{
	Person person;
	if (contact->m_Size >= MAX_PERSON)
	{
		cout << "Contact list number is over 1000, failed to add the contact" << endl;
		return;
	}
	else {

		cout << "Please input the person's name" << endl;
		cin >> person.m_Name;
		contact->addressList[contact->m_Size].m_Name = person.m_Name;

		cout << "Please input the person's gender" << endl;
		while (true)
		{
			cin >> person.m_Gender;
			if (person.m_Gender == "male" || person.m_Gender == "Female")
			{
				contact->addressList[contact->m_Size].m_Gender = person.m_Gender;
				break;
			}
			else {
				cout << "Please input correct gender" << endl;
			}

		}

		cout << "Please input the person's age" << endl;
		person.m_Age = 0;
 		while (cin >> person.m_Age)
		{
			if (cin.good()==1)
			{
				contact->addressList[contact->m_Size].m_Age = person.m_Age;
				break;
			}
			else
			{
				cout << "Please input an intger" << endl;
			}

			
		}

		cout << "Please input the person's telephone" << endl;
		cin >> person.m_Phone;
		contact->addressList[contact->m_Size].m_Phone = person.m_Phone;

		cout << "Please input the person's address" << endl;
		cin >> person.m_Address;
		contact->addressList[contact->m_Size].m_Address = person.m_Address;

		contact->m_Size++;
		cout << "Added!" << endl;
		cout << "Your Address Book has: " << contact->m_Size << " people in current" << endl;
		system("pause");
		system("cls");
	}

}

void showContact(Addressbook *contact)
{
	if (contact->m_Size == 0)
	{
		cout << "No body in the address book" << endl;
	}
	else {
		for (int i = 0; i < contact->m_Size; i++)
		{
			string name = contact->addressList[i].m_Name;
			int age = contact->addressList[i].m_Age;
			string gender = contact->addressList[i].m_Gender;
			string phone = contact->addressList[i].m_Phone;
			string address = contact->addressList[i].m_Address;

			cout << name << "\t" << age << "\t" << gender << "\t" << phone << "\t" << address << endl;

		}
	}

	system("pause");
	system("cls");

}

int isExist(Addressbook* contact, string name)
{
	for (int i = 0; i < contact->m_Size; i++)
	{
		if (contact->addressList[i].m_Name.compare(name) == 0)
		{
			cout << "detected!" << endl;
			return i;
		}

	}
	
	return -1;

	system("pause");

}

void removeElement(Addressbook* contact, int ret)
{
	for (int i = ret; i < contact->m_Size-1; i++)
	{
		contact->addressList[ret] = contact->addressList[i + 1];
	}
	contact->m_Size--;
	cout << "Deleted!" << endl;


	
}

void deleteContact(Addressbook* contact)
{

	cout << "Input the name your want to delete" << endl;
	string name;
	cin >> name;

	int ret = isExist(contact, name);

	if (ret == -1)
	{
		cout << "Not exist!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "ret=" << ret << endl;
		removeElement(contact, ret);
	}


	system("pause");
	system("cls");
}

void findContact(Addressbook* contact) 
{
	cout << "Input the name your want to find" << endl;
	string name;
	cin >> name;

	int ret = isExist(contact, name);

	if (ret == -1)
	{
		cout << "Not exist!" << endl;

		system("pause");
		system("cls");
		return;
	}
	else {
		cout << contact->addressList[ret].m_Name << "\t";
		cout << contact->addressList[ret].m_Gender << "\t";
		cout << contact->addressList[ret].m_Age << "\t";
		cout << contact->addressList[ret].m_Phone<< "\t";
		cout << contact->addressList[ret].m_Address << endl;
	}

	system("pause");
	system("cls");

}

void modifyContact(Addressbook* contact)
{
	cout << "Input the name your want to modify" << endl;
	string name;
	cin >> name;

	int ret = isExist(contact, name);

	if (ret == -1)
	{
		cout << "Not exist!" << endl;

	}
	else {
			cout << "Please input the person's name" << endl;
			string name;
			cin >> name;
			contact->addressList[ret].m_Name = name;

			cout << "Please input the person's gender" << endl;
			while (true)
			{
				string gender;
				cin >> gender;
				if (gender == "male" || gender == "female")
				{
					contact->addressList[ret].m_Gender = gender;
					break;
				}
				else {
					cout << "Please input correct gender" << endl;
				}

			}

			cout << "Please input the person's age" << endl;
			int age = 0;
			while (cin >> age)
			{
				if (cin.good() == 1)
				{
					contact->addressList[ret].m_Age = age;
					break;
				}
				else
				{
					cout << "Please input an intger" << endl;
				}


			}

			cout << "Please input the person's telephone" << endl;
			string phone;
			cin >> phone;
			contact->addressList[ret].m_Phone = phone;

			cout << "Please input the person's address" << endl;
			string address;
			cin >> address;
			contact->addressList[ret].m_Address = address;

			cout << "Modified!" << endl;

	}

	system("pause");
	system("cls");
}

void clearContact(Addressbook* contact)
{
	contact->m_Size = 0;
	cout << "address book is cleared" << endl;
	
	system("pause");
	system("cls");
}