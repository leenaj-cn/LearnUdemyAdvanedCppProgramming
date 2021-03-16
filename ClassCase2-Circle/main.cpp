#include "point.h"
#include "circle.h"

//class Point
//{
//private:
//	int m_CoordinateX;
//	int m_CoordinateY;
//public:
//	void setCoord_x(int x)
//	{
//		m_CoordinateX = x;
//	}
//	void setCoord_y(int y)
//	{
//		m_CoordinateY = y;
//	}
//	int getCoord_x()
//	{
//		return m_CoordinateX;
//	}
//	int getCoord_y()
//	{
//		return m_CoordinateY;
//	}
//};
//
//class Circle
//{
//private:
//	int m_R;
//	Point m_Center;
//
//public:
//	void setRadius(float r)
//	{
//		m_R = r;
//	}
//	int getRadius()
//	{
//		return m_R;
//	}
//	void setCenter(Point center)
//	{
//
//		m_Center = center;
//	}
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//	void IsCircle(Circle c, Point p)
//	{
//		int x0 = c.m_Center.getCoord_x();
//		int y0 = c.m_Center.getCoord_y();
//
//		int r = c.getRadius();
//
//		int x1 = p.getCoord_x();
//		int y1 = p.getCoord_y();
//
//		int Distance = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
//		int rDistance = r * r;
//		
//		if (Distance == rDistance)
//			cout << "point is on the circle" << endl;
//		else if (Distance < rDistance)
//			cout << "point is in the circle" << endl;
//		else if (Distance > rDistance)
//			cout << "point is out of the circle" << endl;
//
//	}
//};

int main()
{
	Circle circle;
	Point point;
	Point center;

	center.setCoord_x(10);
	center.setCoord_y(0);

	circle.setCenter(center);
	circle.setRadius(10);

	point.setCoord_x(10);
	point.setCoord_y(10);

	circle.IsCircle(circle, point);

	system("pause");
	return 0;
}

