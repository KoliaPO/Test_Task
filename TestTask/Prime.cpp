#include "Prime.h"

void Prime::findPrimeNumbers(int low, int high, std::mutex &mutex)
{
	mutex.lock();
	try
	{
		if (low > high)
			throw LowHighException();
		for (int i = low; i <= high; i++)
		{
			if (isPrime(i))
				primeNumbers.insert(i);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	mutex.unlock();
}

int Prime::isPrime(int const &num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

const std::set<int> &Prime::getPrimeNumbers() const {
	return primeNumbers;
}

const char* Prime::LowHighException::what() const throw()
{
	return "Low is bigger than High!";
}