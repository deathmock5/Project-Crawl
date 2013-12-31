#pragma once
#include <iostream>
class DMVersion
{
public:
	DMVersion(void);
	void setMajorVersion(int);
	void setMinorVersion(int);
	void setBugFixes(int);
	void setBuildNumber(int);
	int getMajotVersion();
	int getMinorVersion();
	int getBugFixes();
	int getBuildNumber();
	friend std::ostream& operator<<(std::ostream& os, const DMVersion& obj)
	{
		// write obj to stream
		os << obj.majorversion << " " << obj.minorversion << " " << obj.bugfixes << " " << obj.buildnumber << " ";
	  return os;
	}
	friend std::istream& operator>>(std::istream& is, DMVersion& obj)
	{
	  is >> obj.majorversion;
	  is >> obj.minorversion;
	  is >> obj.bugfixes;
	  is >> obj.buildnumber;
	  if(false)
		is.setstate(std::ios::failbit);
	  return is;
	}
	friend bool operator==(const DMVersion& lhs, const DMVersion& rhs)
	{
		if (lhs.majorversion != rhs.majorversion || 
			lhs.minorversion != rhs.minorversion || 
			lhs.bugfixes != rhs.bugfixes || 
			lhs.buildnumber != rhs.buildnumber)
		{
			return false;
		}
		else
		{
			return true;
		}
		/* do actual comparison */ 
	}
	friend bool operator!=(const DMVersion& lhs, const DMVersion& rhs)
	{
		return !operator==(lhs,rhs);
	}
	friend bool operator< (const DMVersion& lhs, const DMVersion& rhs)
	{
		if(lhs.buildnumber < rhs.buildnumber)
		{
			return true;
		}
		else
		{
			return false;
		}
		/* do actual comparison */ 
	}
	friend bool operator> (const DMVersion& lhs, const DMVersion& rhs)
	{
		return  operator< (rhs,lhs);
	}
	friend bool operator<=(const DMVersion& lhs, const DMVersion& rhs)
	{
		return !operator> (lhs,rhs);
	}
	friend bool operator>=(const DMVersion& lhs, const DMVersion& rhs)
	{
		return !operator< (lhs,rhs);
	}
	DMVersion& operator++()
	{
		buildnumber++;
		return *this;
	}
	DMVersion operator++(int)
	  {
		DMVersion tmp(*this);
		operator++();
		return tmp;
	  }
	DMVersion& operator+=(const DMVersion& rhs)
	{
		// actual addition of rhs to *this
		majorversion += rhs.majorversion;
		minorversion += rhs.minorversion;
		bugfixes += rhs.bugfixes;
		buildnumber += rhs.buildnumber;
		return *this;
	}
	friend DMVersion operator+(DMVersion lhs, const DMVersion& rhs)
	{
	  lhs += rhs;
	  return lhs;
	}
private:
	int majorversion;
	int minorversion;
	int bugfixes;
	int buildnumber;
};

