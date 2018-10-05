#ifndef WRITEFILE_H
#define WRITEFILE_H

#include <iostream>
#include <set>
#include <fstream>
#include <mutex>

class Writer
{
public:
	void writeFile(std::set<int> const &primesNum, std::mutex *mutex);
};

#endif
