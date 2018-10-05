#include "Writer.h"

void Writer::writeFile(std::set<int> const &primesNum, std::mutex *mutex)
{
	mutex->lock();
	std::ofstream ofs;
	ofs.open("primes.xml");
	ofs << "<root>\n";
	ofs << "<primes> ";
	std::set<int>::iterator it = primesNum.begin();
	std::set<int>::iterator ite = primesNum.end();
	std::cout << "Prime numbers: ";
	while (it != ite)
	{
		ofs << *it << " ";
		std::cout << *it << " ";
		it++;
	}
	ofs << "</primes>\n";
	ofs << "</root>\n";
	ofs.close();
	mutex->unlock();
	std::cout << "\nFile has been created.\n";

}
