#ifndef READFILE_H
#define READFILE_H

#include <string>
#include <exception>
#include <vector>
#include <fstream>
#include "Prime.h"

class Reader
{
private:
	std::vector<int> lowNum;
	std::vector<int> highNum;

public:
	void readFromFile(std::string const &filename);
	void findLow(std::string const &str);
	void findHigh(std::string const &str);

	const std::vector<int> &getLowNum() const;
	const std::vector<int> &getHighNum() const;

	class FileOpenException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class LowHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
