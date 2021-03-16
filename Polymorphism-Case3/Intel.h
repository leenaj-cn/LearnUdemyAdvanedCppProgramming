#include "cpu.h"

class IntelCpu :public CPU
{
	virtual void LogicProcessing()
	{
		cout << "Intel CPU is doing logic processing" << endl;
	}
};


class IntelGpu :public GPU
{
	virtual void Computing()
	{
		cout << "Intel GPU is Computing" << endl;
	}
};

class IntelMemory :public Memory
{
	virtual void Storage()
	{
		cout << "Intel Memory is Storaging" << endl;
	}
};