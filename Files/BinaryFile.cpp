#include <iostream>
using namespace std;
#include<fstream>

class Person
{
public:
	char m_Name[64];
	int m_Age;
};


void read()
{
	//read
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "Failed to open file" << endl;
		return;
	}

	Person p;
	ifs.read((char*)&p, sizeof(p));

	cout << p.m_Name << endl;
	cout << p.m_Age << endl;

	ifs.close();
}

void write()
{
	//write to file
	//ofstream ofs;
	//ofs.open("person.txt", ios::out | ios::binary);
	ofstream ofs("person.txt", ios::out | ios::binary);
	Person p = { "Tom", 18 };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();
}

int main()
{
	write();


	system("pause");
	return 0;
}