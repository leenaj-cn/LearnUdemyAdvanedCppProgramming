#include "circle.h"

void Circle::setRadius(float r)
{
	m_R = r;
}
int Circle::getRadius()
{
	return m_R;
}
void Circle::setCenter(Point center)
{

	m_Center = center;
}
Point Circle::getCenter()
{
	return m_Center;
}

void Circle::IsCircle(Circle c, Point p)
{
	int x0 = c.m_Center.getCoord_x();
	int y0 = c.m_Center.getCoord_y();

	int r = c.getRadius();

	int x1 = p.getCoord_x();
	int y1 = p.getCoord_y();

	int Distance = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
	int rDistance = r * r;

	if (Distance == rDistance)
		cout << "point is on the circle" << endl;
	else if (Distance < rDistance)
		cout << "point is in the circle" << endl;
	else if (Distance > rDistance)
		cout << "point is out of the circle" << endl;

}