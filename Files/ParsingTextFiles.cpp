#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void read(ifstream &inputFile)
{
	//cout << "~~~~~~~~read method1~~~~~~~~~~" << endl;
	////read method1
	//char buf[1024] = { 0 };
	//while (inputFile >> buf)
	//{
	//	cout << buf << endl;
	//}

	//cout << "~~~~~~~~read method2~~~~~~~~~~" << endl;
	////read method2
	//char buf1[1024] = { 0 };
	//while (inputFile.getline(buf1, sizeof(buf1)))
	//{
	//	cout << buf1 << endl;
	//}

	////read method3
	cout << "~~~~~~~~read method3~~~~~~~~~~" << endl;
	string buf2;
	while (getline(inputFile, buf2))
	{
		cout << buf2 << endl;
	}


	////read method4
	//cout << "~~~~~~~~read method4~~~~~~~~~~" << endl;
	//char c;
	//while ((c= inputFile.get()) != EOF) //EOF = end of file
	//{
	//	cout << c;
	//}

}


int main()
{
	string inputFileName = "test.txt";
	ifstream inputFile;
	inputFile.open(inputFileName, ios::in);

	if (!inputFile.is_open())
	{
		cout << "Failed to open file" << endl;
		return 1;
	}
	
	read(inputFile);

	//parse txt file
	while (inputFile)
	{
		string line;
		
		getline(inputFile, line, ':');

		int population=0;
		inputFile >> population;

		//inputFile.get();
		inputFile >> ws;
		//if (!inputFile)
		//{
		//	break;
		//}

		cout << "line: " << line <<  "  population: "<<population << endl;

	}

	inputFile.close();

	system("pause");
	return 0;
}