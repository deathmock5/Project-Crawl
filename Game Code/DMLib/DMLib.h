#include <vector>
#include <Windows.h>
#include <iostream>
namespace DMLib
{
	class Point
	{
	public:
		__declspec(dllexport) Point();
		__declspec(dllexport) Point(int x, int y);
		__declspec(dllexport) friend bool operator== (Point &cP1, Point &cP2)
		{
			//std::cout << (cP1.myx) << "=?" << (cP2.myx) << ":" << (cP1.myx == cP2.myx) << " "
			//	<< (cP1.myy) << "=?" << (cP2.myy) << ":" << (cP1.myy == cP2.myy) << std::endl;
			return (cP1.myx == cP2.myx && cP1.myy == cP2.myy);
		}
		__declspec(dllexport) friend bool operator!= (Point &cP1, Point &cP2)
		{
			return !(cP1 == cP2);
		}
		__declspec(dllexport) friend std::ostream& operator<< (std::ostream &out, Point &cPoint)
		{
				out << "{" << cPoint.myx << ", " <<
					cPoint.myy << "}";
			return out;
		}
		__declspec(dllexport) int getX();
		__declspec(dllexport) int getY();
		__declspec(dllexport) void setX(int val);
		__declspec(dllexport) void setY(int val);
	private:
		int myx;
		int myy;
	};
}