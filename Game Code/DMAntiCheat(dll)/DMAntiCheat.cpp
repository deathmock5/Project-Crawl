// DMAntiCheat.cpp
// compile with: /EHsc /LD

#include "DMAntiCheat.h"

#include <stdexcept>

using namespace std;

namespace DMAntiCheat
{
    /*double MyMathFuncs::Add(double a, double b)
    {
        return a + b;
    }*/
	void DMPint::set(int val)
	{
		myvalue = val;
		obfuscate();
	}
	void DMPint::set(DMPbyte val)
	{
		myvalue = val.getint();
		obfuscate();
	}
	void DMPint::set(DMPint val)
	{
		myvalue = val.getint();
		obfuscate();
	}
	void DMPint::set(DMPdouble val)
	{
		myvalue = val.getint();
		obfuscate();
	}
	void DMPint::set(DMPstring val)
	{
		myvalue = val.getint();
		obfuscate();
	}
	

	int DMPint::getint()
	{
		return deobfuscate();
	}


	int DMPint::deobfuscate()
	{
		return myvalue / -5;
	}
	void DMPint::obfuscate()
	{
		if (!obfusicated)
		{
			myvalue = myvalue * -5;
		}
	}
}