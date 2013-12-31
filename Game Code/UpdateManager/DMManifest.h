#pragma once
#include "ManifistOBJ.h"
#include <vector>
#include <Windows.h>
#include <iostream>
#include <fstream>

class DMManifest
{
public:
	DMManifest(void);
	void addManifistObj(ManifistOBJ);
	std::vector<ManifistOBJ> getManifistList();
	void writeToFile(std::string filename);
	void readFromFile(std::string filename);
	void clearList();
	friend std::ostream& operator<<(std::ostream& os, const DMManifest& obj)
	{
		// write obj to stream
		for each(ManifistOBJ temp in obj.objects)
		{
			os << temp;
		}
	  return os;
	}
	friend std::istream& operator>>(std::istream& is, DMManifest& obj)
	{
	  // read obj from stream
		while(!is.eof())
		{
			ManifistOBJ temp;
			is >> temp;
			obj.objects.push_back(temp);
		}
	  if(false)
		is.setstate(std::ios::failbit);
	  return is;
	}
private:
	std::vector<ManifistOBJ> objects;
};

