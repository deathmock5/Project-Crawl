#include <vector>
#include <Windows.h>
#include "DMLib.h"
using namespace DMLib;
namespace DMAstar
{
	class Node
	{
	public:
		Node();
		Node(Point mypos,Point orign,Point destination);
		Point getMyPos();
		void setvisited();
		bool isvisted();
		void computeweight();
		int getWeight();
		Node* GetParent();
		void SetParent(Node*);
		friend bool operator== (Node &cP1, Node &cP2)
		{
			 return (cP1.pos == cP2.pos);
		}
		friend bool operator!= (Node &cP1, Node &cP2)
		{
			return !(cP1.pos == cP2.pos);
		}
		friend std::ostream& operator<< (std::ostream &out, Node &cnode)
		{
				out << "{" << cnode.getMyPos().getX() << ", " << cnode.getMyPos().getY() << "}"
					<< ":" << cnode.weight << " " << cnode.isvisted();
					;
			return out;
		}
		~Node();

	private:
		short costtomove;
		short estimateddistance;
		short weight;
		Point pos;
		char dirtohome;
		bool visited;
		Node *parent;
	};

    class IInterface
    {
    public:

		__declspec(dllexport) IInterface();

        // Sets the map
        __declspec(dllexport) void setMap(int h, int w,std::vector<std::vector<char>> myarray);

		// Sets my startpoint	
		__declspec(dllexport) void setStart(int x, int y);

		// Sets Map endpoint
		__declspec(dllexport) void setEnd(int x, int y);

		// Gets the next move direction
		__declspec(dllexport) void getNextMove();

        // Returns the calculated path
        __declspec(dllexport) std::vector<Point> getPath();

		// Returns a char to the next direction.
		static __declspec(dllexport) char getDirection(Node n1,Node n2);

		// Returns a char to the next direction.
		static __declspec(dllexport) char getDirection(DMLib::Point p1, DMLib::Point p2);

		__declspec(dllexport) void computePath();

	private:
		std::vector<std::vector<byte>> mymap;
		int startposx,startposy;
		int endposx,endposy;
		std::vector<Point> mypath;
		
    };
};