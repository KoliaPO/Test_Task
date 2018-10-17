#include "Prime.h"

void Prime::findPrimeNumbers(int const &low, int const &high, std::mutex &mutex)
{
	try
	{
		if (low > high)
			throw LowHighException();
		for (int i = low; i <= high; i++)
		{
			//std::cout << "Thread id = " << std::this_thread::get_id() << "\n";
			if (isPrime(i))
			{
				mutex.lock();
				primeNumbers.insert(i);
				mutex.unlock();
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
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

const std::set<int> &Prime::getPrimeNumbers() const {
	return primeNumbers;
}

const char* Prime::LowHighException::what() const throw()
{
	return "Low is bigger than High!";
}