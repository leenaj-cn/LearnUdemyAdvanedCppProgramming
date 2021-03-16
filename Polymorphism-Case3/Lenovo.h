#include "cpu.h"

class LenovoCpu :public CPU
{
	virtual void LogicProcessing()
	{
		cout << "Lenovo CPU is doing logic processing" << endl;
	}
};


class LenovoGpu :public GPU
{
	virtual void Computing()
	{
		cout << "Lenovo GPU is Computing" << endl;
	}
};

class LenovoMemory :public Memory
{
	virtual void Storage()
	{
		cout << "Lenovo Memory is Storaging" << endl;
	}
};