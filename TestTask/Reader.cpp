#include "Reader.h"

void Reader::readFromFile(std::string const &filename)
{
	std::ifstream fin(filename);
	std::string line;
	if (!fin.is_open())
		throw FileOpenException();
	while (getline(fin, line))
	{
		if (line.find("<low>") != std::string::npos)
			findLow(line);
		else if (line.find("<high>") != std::string::npos)
			findHigh(line);
	}
	fin.close();
	if (lowNum.size() != highNum.size())
		throw LowHighException();
}

void Reader::findLow(std::string const &str)
{
	int pos = 0;
	int start;
	start = str.find("<low", pos);
	start = str.find(">", start);
	start++;
	pos = str.find("</", start);
	std::cout << "Low = " << str.substr(start, pos - start) << std::endl;
	lowNum.push_back(std::stoi(str.substr(start, pos - start)));
}

void Reader::findHigh(std::string const &str)
{
	int pos = 0;
	int start;
	start = str.find("<high", pos);
	start = str.find(">", start);
	start++;
	pos = str.find("</", start);
	std::cout << "High = " << str.substr(start, pos - start) << std::endl;
	highNum.push_back(std::stoi(str.substr(start, pos - start)));

}

const std::vector<int> &Reader::getLowNum() const {
	return lowNum;
}

const std::vector<int> &Reader::getHighNum() const {
	return highNum;
}

const char* Reader::FileOpenException::what() const throw()
{
	return "File can't be opened!";
}

const char* Reader::LowHighException::what() const throw()
{
	return "Wrong number of tag <low> or <high>";
}

