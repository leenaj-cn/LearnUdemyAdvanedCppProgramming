#pragma once
#include <iostream>
#include "point.h"
using namespace std;

class Circle
{
public:
	Circle()
	{
		cout << "Circle Constructor called" << endl;
	}
	void setRadius(float r);

	int getRadius();

	void setCenter(Point center);

	Point getCenter();

	void IsCircle(Circle c, Point p);

	~Circle()
	{
		cout << "Circle Disstructor called" << endl;
	}

private:
	int m_R;
	Point m_Center;
};