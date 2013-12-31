#include "ManifistOBJ.h"


ManifistOBJ::ManifistOBJ(void)
{
}
void ManifistOBJ::setFilename(char* val)
{
	filename = val;
}
void ManifistOBJ::setVersion(DMVersion val)
{
	myversion = val;
}
char* ManifistOBJ::getFilename()
{
	return filename;
}
DMVersion ManifistOBJ::getVersion()
{
	return myversion;
}
ManifistOBJ::~ManifistOBJ(void)
{

}
