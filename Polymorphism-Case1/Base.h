#pragma once
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:

	virtual void Boil() = 0;

	virtual void Brew() = 0;

	virtual void Pour() = 0;

	virtual void PutMaterial() = 0;

	void MakeDrinking()
	{
		Boil();
		Brew();
		Pour();
		PutMaterial();

	}


};
