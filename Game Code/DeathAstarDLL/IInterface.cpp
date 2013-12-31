// IInterface.cpp
// compile with: /EHsc /LD
#include "IInterface.h"
#define MAPFLOOR 0x01
#define MAPWALL 0x02
//#define DM_DEBUG //uncoment for debug output
#ifdef DM_DEBUG
#include <iostream>
#endif

using namespace DMLib;

namespace DMAstar
{
	///<summary>
	///Informal constructor.
	///</summary>
	IInterface::IInterface()
	{
		startposx = 0;
		startposy = 0;
		endposx = 0;
		endposy = 0;
	}
	///<summary>
	///Call after the map, start, and endpoint have been inputed to compute the path.
	///</summary>
	void IInterface::computePath()
	{
		Point startpos = Point(startposx,startposy);
		Point endpos = Point(endposx,endposy);
		Node* curentnode;

		//vector of open nodes
		std::vector<Node*> open_nodes;
		//vector of closed nodes
		std::vector<Node*> closed_nodes;
		//make node at curent location;
		Node* newnode = new Node(startpos,startpos,endpos);
		open_nodes.push_back(newnode);
		curentnode = newnode;
		int curentindex = 0;
		//loop
		while (open_nodes.size() > 0)
		{
			curentnode->setvisited();
			std::vector<Node*> temp_nodes;
			Point orginpos = curentnode->getMyPos();
			//generate 8 nodes around,
#ifdef DM_DEBUG
			std::cout << "Creating 8 subnodes from"<< *curentnode << std::endl;//TODO: remove me
#endif
			for(int i = 1;i <= 8;i++)
			{
				Point newpos;
				switch (i)
				{
				case 1:
					newpos.setX(orginpos.getX() -1);
					newpos.setY(orginpos.getY() +1);
					break;
				case 2:
					newpos.setX(orginpos.getX());
					newpos.setY(orginpos.getY() +1);
					break;
				case 3:
					newpos.setX(orginpos.getX() +1);
					newpos.setY(orginpos.getY() +1);
					break;
				case 4:
					newpos.setX(orginpos.getX() +1);
					newpos.setY(orginpos.getY());
					break;
				case 5:
					newpos.setX(orginpos.getX() +1);
					newpos.setY(orginpos.getY() -1);
					break;
				case 6:
					newpos.setX(orginpos.getX());
					newpos.setY(orginpos.getY() -1);
					break;
				case 7:
					newpos.setX(orginpos.getX() -1);
					newpos.setY(orginpos.getY() -1);
					break;
				case 8:
					newpos.setX(orginpos.getX() -1);
					newpos.setY(orginpos.getY());
					break;
				default:
					break;
				}
				Node* newnode = new Node(newpos,orginpos,endpos);
				newnode->SetParent(curentnode);
#ifdef DM_DEBUG
				std::cout << "Created node:" << *newnode <<std::endl; //TODO: removeme
#endif
				temp_nodes.push_back(newnode);
			}
				//loop through new nodes
			bool deletedanode = false;
				for(int i = 0;i < (int)temp_nodes.size();i++)
				{
					deletedanode = false;
					//is one of the nodes the end node?
					if(temp_nodes[i]->getMyPos() == endpos)
					{
#ifdef DM_DEBUG
						std::cout << "Path found" << temp_nodes[i]->getMyPos() << "==" << endpos << std::endl;
#endif
						//put path here
						Node* backtrace = temp_nodes[i];
						while (backtrace != nullptr)
						{
#ifdef DM_DEBUG
						std::cout << backtrace->getMyPos();
#endif
						mypath.push_back(backtrace->getMyPos());
							
							backtrace = backtrace->GetParent();
						}
						
#ifdef DM_DEBUG
						std::cout << "Garbage Cleanup" << std::endl;
#endif
						for(int i =0;i < (int)open_nodes.size();i++)
						{
#ifdef DM_DEBUG
							std::cout << "Delete open node:" << *open_nodes[i] << " " << open_nodes[i] << std::endl;
#endif
							delete open_nodes[i];
							//open_nodes[i] = nullptr;
						}
						open_nodes.clear();
						for(int i =0;i < (int)closed_nodes.size();i++)
						{
#ifdef DM_DEBUG
							std::cout << "Delete closed node:" << *closed_nodes[i] << " " << closed_nodes[i] << std::endl;
#endif
							if(closed_nodes[i] != nullptr && closed_nodes[i]->getWeight() > -2)//HACK: node in open groop isent sent fully to closed group. idk why
							{
								
								delete closed_nodes[i];
							}
						}
						closed_nodes.erase(closed_nodes.begin(), closed_nodes.end());
						for(int i =0;i < (int)temp_nodes.size();i++)
						{
#ifdef DM_DEBUG
							std::cout << "Delete temp node:" << *temp_nodes[i] << " " << temp_nodes[i] << std::endl;
#endif
							if(temp_nodes[i] != nullptr)
							{
								delete temp_nodes[i];
							}
						}
						temp_nodes.erase(temp_nodes.begin(), temp_nodes.end());
#ifdef DM_DEBUG
						std::cout << "Garbage Cleanup -done" << std::endl;
#endif
						return;
					}
					//is it already in open node group?
					if(!deletedanode)
					{
#ifdef DM_DEBUG
						std::cout << "Checking open nodes"<<std::endl;//TODO: remove me
#endif
						for(int ii =0;ii< (int)open_nodes.size();ii++)
						{
							if(temp_nodes[i] != nullptr)
								if(*temp_nodes[i] == *open_nodes[ii])
								{
									//delete.
#ifdef DM_DEBUG
									std::cout << "Deleted node:" << temp_nodes[i]->getMyPos() << " in open node" <<std::endl;//TODO: removemee
#endif
									delete temp_nodes[i];
									temp_nodes.erase(temp_nodes.begin() + i);
									i--;
									deletedanode = true;
									ii = (int)open_nodes.size() + 1;
								}
						}
					}
					//is it in closed node group?
					if(!deletedanode)
					{
#ifdef DM_DEBUG
						std::cout << "Checking closed nodes"<<std::endl;//TODO: remove me
#endif
						for(int ii =0;ii< (int)closed_nodes.size();ii++)
						{
							if(temp_nodes[i] != nullptr)
								if(*temp_nodes[i] == *closed_nodes[ii])
								{
									//delete.
#ifdef DM_DEBUG
									std::cout << "Deleted node:" << temp_nodes[i]->getMyPos() << " in closed group" << std::endl;//TODO: removeme
#endif
									delete temp_nodes[i];
									temp_nodes.erase(temp_nodes.begin() + i);
									i--;
									deletedanode = true;
									ii = (int)closed_nodes.size();
								}
						}
					}
					//is it in the map?
					if(!deletedanode)
					{
#ifdef DM_DEBUG
						std::cout << "Checking map"<<std::endl;//TODO: remove me
#endif
						if(temp_nodes[i]->getMyPos().getX() < 0 
							|| temp_nodes[i]->getMyPos().getY() < 0 
							|| temp_nodes[i]->getMyPos().getX() >= (int)mymap[0].size()
							|| temp_nodes[i]->getMyPos().getY() >= (int)mymap.size())
						{
							
							//not in map
							//delete.
#ifdef DM_DEBUG
							std::cout << "---Closed node:" << temp_nodes[i]->getMyPos() << " out of map"<<std::endl;//TODO: removeme
#endif
							closed_nodes.push_back(temp_nodes[i]);
							temp_nodes.erase(temp_nodes.begin() + i);
							i--;
							deletedanode = true;
						}
					}
					//is it a wall?'
					if(!deletedanode)
					{
#ifdef DM_DEBUG
						std::cout << "Checking walls :"<< *temp_nodes[i] << std::endl; //TODO: Remove me
#endif
						if(mymap[temp_nodes[i]->getMyPos().getY()][temp_nodes[i]->getMyPos().getX()] == MAPWALL)
						{
#ifdef DM_DEBUG
							std::cout << "---Closed node:" << temp_nodes[i]->getMyPos() << " is a wall" <<std::endl; //TODO: Remove me
#endif
							closed_nodes.push_back(temp_nodes[i]);
							temp_nodes.erase(temp_nodes.begin() + i);
							i--;
							//close node
							deletedanode = true;
						}
						else
						{
							temp_nodes[i]->computeweight();
						}
#ifdef DM_DEBUG
						std::cout << "Checking walls -done"<<std::endl; //TODO: Remove me
#endif
					}
				}
				//Is there node in list?
#ifdef DM_DEBUG
				std::cout << "Checks completed"<<std::endl; //TODO: Remove me
#endif
				
				if(temp_nodes.size() == 0)
				{
#ifdef DM_DEBUG
				std::cout << "Tempnodes empty, eraseing and adding node: " << *curentnode << " to closed list"<<std::endl; //TODO: Remove me
#endif
					closed_nodes.push_back(curentnode);
					open_nodes.erase(open_nodes.begin() + curentindex);
#ifdef DM_DEBUG
				std::cout << "-Done"<<std::endl; //TODO: Remove me
#endif
				}
				else
				{
#ifdef DM_DEBUG
				std::cout << "Adding " << temp_nodes.size() << " valid weighted nodes to open node list." <<std::endl; //TODO: Remove me
#endif
					for(int i = 0;i < (int)temp_nodes.size();i++)
					{
						open_nodes.push_back(temp_nodes[i]);
					}
				}
				//find node with lowest weight.
#ifdef DM_DEBUG
				std::cout << "Find node with lowest weight."<<std::endl;//TODO: Remove me
#endif
				Node* lowestcurentnode = nullptr;
				int tempindex;
				for(int i = 0;i < (int)open_nodes.size();i++)
				{
					if(!open_nodes[i]->isvisted())
					{
						if(lowestcurentnode == nullptr)
						{
							lowestcurentnode = open_nodes[i];
							tempindex = i;
						}
						else
						{
							if(open_nodes[i]->getWeight() < lowestcurentnode->getWeight())
							{
								//Set lowest weighted node as new node.
								lowestcurentnode = open_nodes[i];
								tempindex = i;
							}
						}
					}
				}
			if(lowestcurentnode != nullptr)
			{
				curentnode = lowestcurentnode;
				curentindex = tempindex;
			}
			else
			{
#ifdef DM_DEBUG
					std::cout << "@@@@@@@@@@@@@@@@@@@@@@@Couldent find lowest" << std::endl;
					return;
#endif
			}
		}
	}
	/// <summary>
    /// Called to input the map information, 1s walls, 0s floors.
    /// </summary>
    /// <param name="h">Height of the map</param>
    /// <param name="w">Width of the map</param>
	/// <param name="myarray">A vector of char vectors, spessifying the map data.</param>
    void IInterface::setMap(int h, int w,std::vector<std::vector<char>> myarray)
	{
		for(int y = 0;y <h;y++)
		{
			std::vector<byte> temp;
			for( int x = 0;x < w;x++)
			{
				if(myarray[y][x] == '0')
				{
					temp.push_back(MAPFLOOR);
				}
				else
				{
					temp.push_back(MAPWALL);
				}
			}
			mymap.push_back(temp);
		}
	}
	void IInterface::setStart(int x, int y)
	{
		startposx = x;
		startposy = y;
	}
	void IInterface::setEnd(int x, int y)
	{
		endposx = x;
		endposy = y;
	}
	void IInterface::getNextMove()
	{

	}
	std::vector<Point> IInterface::getPath()
	{
		return mypath;
	}
	char IInterface::getDirection(Node n1,Node n2)
	{
		return getDirection(n1.getMyPos(),n2.getMyPos());
	}
	char IInterface::getDirection(Point p1, Point p2)
	{
		//123 -0+ +++
		//8#4 -#+ 0#0
		//765 -0+ ---

		int d1 = p2.getX() - p1.getX();
		int d2 = p2.getY() - p1.getY();
		if(d1 == 0)
		{
			if(d2 == 0)
			{
				return '0';
			}
			else if(d2 > 0)
			{
				return '4';
			}
			else
			{
				return '8';
			}
		}
		else if(d1 > 0)
		{
			if(d2 == 0)
			{
				return '2';
			}
			else if(d2 > 0)
			{
				return '3';
			}
			else
			{
				return '1';
			}
		}
		else
		{
			if(d2 == 0)
			{
				return '6';
			}
			else if(d2 > 0)
			{
				return '5';
			}
			else
			{
				return '7';
			}
		}

		return '0';

	}

	Node::Node()
	{
		parent = nullptr;
		visited = false;
		weight = -1;
	}
	Node::Node(Point mypos,Point orign,Point destination)
	{
		parent = nullptr;
		visited = false;
		pos = mypos;
		char dir = IInterface::getDirection(mypos,orign);
		if(dir == '1' || dir == '3' || dir == '5' || dir == '7')
		{
			costtomove = 14;
		}
		else
		{
			costtomove = 10;
		}
		dirtohome = dir;
		int dist = abs(mypos.getX() - destination.getX()) + abs(mypos.getY() - destination.getY());
		estimateddistance = dist * 10;
		weight = -1;
	}
	void Node::setvisited()
	{
		visited = true;
	}
	bool Node::isvisted()
	{
		return visited;
	}
	void Node::computeweight()
	{
		weight = estimateddistance + costtomove;
	}
	Point Node::getMyPos()
	{
		return pos;
	}
	int Node::getWeight()
	{
		return weight;
	}
	Node* Node::GetParent()
	{
		return parent;
	}
	void Node::SetParent(Node* node)
	{
		parent = node;
	}
	
	Node::~Node()
	{

	}
}