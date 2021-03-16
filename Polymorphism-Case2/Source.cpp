//make a calculator 
//according to C++'s Polymorphism

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Calculator
{
public:
	virtual int Compute()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;
};


class AddCalculator : public Calculator
{
public:
	int Compute()
	{
		return m_Num1 + m_Num2;
	}

};


class SubCalculator : public Calculator
{
public:
	int Compute()
	{
		return m_Num1 - m_Num2;
	}

};


class MulCalculator : public Calculator
{
public:
	int Compute()
	{
		return m_Num1 * m_Num2;
	}
};

int main()
{
	//add
	Calculator* cal = new AddCalculator;
	cal->m_Num1 = 10;
	cal->m_Num2 = 20;
	int result = cal->Compute();
	cout << cal->m_Num1 << "+" << cal->m_Num2 << "=" << result << endl;
	delete cal;

	//sub
	cal = new SubCalculator;
	cal->m_Num1 = 10;
	cal->m_Num2 = 20;
	result = cal->Compute();
	cout << cal->m_Num1 << "-" << cal->m_Num2 << "=" << result << endl;
	delete cal;
	
	//multiple
	cal = new MulCalculator;
	cal->m_Num1 = 10;
	cal->m_Num2 = 20;
	result = cal->Compute();
	cout << cal->m_Num1 << "*" << cal->m_Num2 << "=" << result << endl;
	delete cal;


	system("pause");
	return 0;
}