#ifndef WRITEFILE_H
#define WRITEFILE_H

#include <iostream>
#include <set>
#include <fstream>

class Writer
{
public:
	void writeFile(std::set<int> const &primesNum);
};

#endif
