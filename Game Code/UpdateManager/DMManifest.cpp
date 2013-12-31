#include "DMManifest.h"


DMManifest::DMManifest(void)
{
}
void DMManifest::addManifistObj(ManifistOBJ val)
{
	objects.push_back(val);
}
std::vector<ManifistOBJ> DMManifest::getManifistList()
{
	return objects;
}
void DMManifest::writeToFile(std::string filename)
{
	std::ofstream fout;
	fout.open(filename, std::ios::out | std::ios::trunc);
    if(fout.fail())
    {

    }
	else
	{
		fout << *this;
	}
	fout.close();
}
void DMManifest::readFromFile(std::string filename)
{
	std::ifstream fin;
	fin.open(filename);
    if(fin.fail())
    {

    }
	else
	{
		fin >> *this;
	}
	fin.close();
}
void DMManifest::clearList()
{
	objects.clear();
}