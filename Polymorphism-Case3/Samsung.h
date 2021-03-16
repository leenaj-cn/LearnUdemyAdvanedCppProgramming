#include "cpu.h"

class SamsungCpu :public CPU
{
	virtual void LogicProcessing()
	{
		cout << "Samsung CPU is doing logic processing" << endl;
	}
};


class SamsungGpu :public GPU
{
	virtual void Computing()
	{
		cout << "Samsung GPU is Computing" << endl;
	}
};

class SamsungMemory :public Memory
{
	virtual void Storage()
	{
		cout << "Samsung Memory is Storaging" << endl;
	}
};