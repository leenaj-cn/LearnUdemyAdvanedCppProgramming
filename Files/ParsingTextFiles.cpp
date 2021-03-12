#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string inputFileName = "test.txt";
	ifstream inputFile;
	inputFile.open(inputFileName);

	if (!inputFile.is_open())
		return 1;

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

	return 0;
}