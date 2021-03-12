#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string outputFileName = "test.txt";
	ofstream OutFile;

	const char* text = { "abcdefg" };
	
	OutFile.open(outputFileName);
	if (OutFile.is_open())
	{
		OutFile << "below is the content of text:" << endl;
		for(int i=0;i<7;i++)
			OutFile << text[i]<< endl;

		OutFile.close();
	}
	else
	{
		cout << "Failed to create file: " << outputFileName << endl;
	}
}