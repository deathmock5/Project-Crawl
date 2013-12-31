#include "DMVersion.h"


DMVersion::DMVersion(void)
{
	majorversion = 0;
	minorversion = 0;
	bugfixes = 0;
	buildnumber = 0;
}
void DMVersion::setMajorVersion(int val)
{
	majorversion = val;
}
void DMVersion::setMinorVersion(int val)
{
	minorversion = val;
}
void DMVersion::setBugFixes(int val)
{
	bugfixes = val;
}
void DMVersion::setBuildNumber(int val)
{
	buildnumber = val;
}
int DMVersion::getMajotVersion()
{
	return majorversion;
}
int DMVersion::getMinorVersion()
{
	return minorversion;
}
int DMVersion::getBugFixes()
{
	return bugfixes;
}
int DMVersion::getBuildNumber()
{
	return buildnumber;
}