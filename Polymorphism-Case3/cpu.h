#pragma once
#include <iostream>
#include <string>
using namespace std;

class CPU
{
public:
	virtual void LogicProcessing() = 0;
};

class GPU
{
public: 
	virtual void Computing() = 0;
};

class Memory
{
public:
	virtual void Storage() = 0;
};
