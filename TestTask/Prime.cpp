#include "Prime.h"

void Prime::findPrimeNumbers(int const &low, int const &high, std::mutex &mutex)
{
	std::vector<int> vec;
	try
	{
		if (low > high)
			throw LowHighException();
		for (int i = low; i <= high; i++)
		{
			if (isPrime(i))
				vec.push_back(i);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	mutex.lock();
	Prime::saveUniqueNumber(vec);
	mutex.unlock();
}

int Prime::isPrime(int const &num)
{
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

void Prime::saveUniqueNumber(std::vector<int> const & vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		primeNumbers.insert(vec.at(i));
}

const std::set<int> &Prime::getPrimeNumbers() const {
	return primeNumbers;
}

const char* Prime::LowHighException::what() const throw()
{
	return "Low is bigger than High!";
}