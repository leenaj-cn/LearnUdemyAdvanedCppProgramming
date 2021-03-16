#include <iostream>
#include <string>
using namespace std;

class Cube
{
private:
	int m_Length;
	int m_Width;
	int m_Height;

public:
	void setLength(int length)
	{
		m_Length = length;
	}

	void setWidth(int width)
	{
		m_Width = width;
	}

	void setHeight(int height)
	{
		m_Height = height;
	}

	int getLength()
	{
		return m_Length;
	}

	int getWidth()
	{
		return m_Width;
	}

	int getHeight()
	{
		return m_Height;
	}

	int getCubeSurface()
	{
		return m_Width * m_Length * 2 + m_Width * m_Height * 2 + m_Length * m_Height * 2;
	}

	int getCubeVolume()
	{
		return m_Width * m_Length * m_Height;
	}
	
	bool isSameCube(Cube c)
	{
		bool ret = false;
		if (m_Width == c.getWidth() && m_Length == c.getHeight() && m_Height == c.getHeight())
			ret = true;

		return ret;
	}

};

bool isSame(Cube& c1, Cube& c2)
{
	return (c1.getWidth() == c2.getWidth() && c1.getLength() == c2.getLength() && c1.getHeight() == c2.getHeight());
}


int main()
{
	Cube c1;
	c1.setWidth(10);
	c1.setLength(10);
	c1.setHeight(10);
	cout << "width="<<c1.getWidth() << "\t";
	cout << "height=" << c1.getLength() << "\t";
	cout << "length=" << c1.getHeight() << endl;
	cout << "Surface:\t" << c1.getCubeSurface() << endl;
	cout << "Volume:\t" << c1.getCubeVolume() << endl;

	Cube c2;
	c2.setWidth(10);
	c2.setLength(10);
	c2.setHeight(20);
	bool ret = c1.isSameCube(c2);
	cout << "is same ret:" << ret << endl;

	if (isSame(c1, c2)) 
		cout << "c1=c2" << endl;
	else 
		cout << "c1 != c2" << endl;

	system("pause");
	return 0;
}