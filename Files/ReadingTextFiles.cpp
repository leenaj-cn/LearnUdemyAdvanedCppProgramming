#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string inputFileName = "test.txt";

	//ifstream inFile;
	//inFile.open(inputFileName);
	fstream inFile;
	inFile.open(inputFileName, ios::in);

	if (inFile.is_open()) {

		char letter;
		string word;
		char arr[100];
		string line;

		while (inFile.good())
		{
			//letter = inFile.get(); //read by letter
			//inFile >> word;  //read by word
			//inFile.getline(arr, 100);  //read by line
			getline(inFile, line); ////read by line
			cout << line << endl;

		}
		inFile.close();

	}
	else {
		cout << "Failed to open file: " << inputFileName << endl;
	}

	return 0;
}