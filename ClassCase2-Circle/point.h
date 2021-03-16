#pragma once
#include <iostream>
using namespace std;

class Point
{
public:

	//constructor
	Point()
	{
		cout << "Point Constructor called" << endl;
	}
	void setCoord_x(int x);

	void setCoord_y(int y);

	int getCoord_x();

	int getCoord_y();

	//distructor
	~Point()
	{
		cout << "Point Distructor called" << endl;
	}

private:
	int m_CoordinateX;
	int m_CoordinateY;
};