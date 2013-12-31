#pragma once
#ifndef _MANIFISTOBJ_H_
#define _MANIFISTOBJ_H_
#include <iostream>
#include "DMVersion.h"
#include <string>
class ManifistOBJ
{
public:
	ManifistOBJ(void);
	void setFilename(char*);
	void setVersion(DMVersion);
	char* getFilename();
	DMVersion getVersion();
	friend std::ostream& operator<<(std::ostream& os, const ManifistOBJ& obj)
	{
		os << obj.filename << " " << obj.myversion;
	  // write obj to stream
	  return os;
	}
	friend std::istream& operator>>(std::istream& is, ManifistOBJ& obj)
	{
		std::string temp;
		is >> temp;
		is >> obj.myversion;
		char * writable = new char[temp.size() + 1];
		std::copy(temp.begin(), temp.end(), writable);
		writable[temp.size()] = '\0'; // don't forget the terminating 0
		obj.filename = writable;
	  if(false)
		is.setstate(std::ios::failbit);
	  return is;
	}
	~ManifistOBJ(void);
private:
	char* filename;
	DMVersion myversion;
};
#endif
