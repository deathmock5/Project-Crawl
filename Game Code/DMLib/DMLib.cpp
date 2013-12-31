#include "DMLib.h"
#include <io.h>
namespace DMLib
{
	Point::Point()
	{
		
		myx = 0;
		myy = 0;
	}
	Point::Point(int x, int y)
	{
		myx = x;
		myy = y;
	}
	int Point::getX()
	{
		return myx;
	}
	int Point::getY()
	{
		return myy;
	}
	void Point::setX(int val)
	{
		myx = val;
	}
	void Point::setY(int val)
	{
		myy = val;
	}
}

namespace DMLibIO
{
	static bool fileExists(const char* filename)
	{
		if (_access(filename, 0) == -1)
		{
			return false;// File does not exist
		}
		else
		{
			return true;//file was found.
		}
	}
}