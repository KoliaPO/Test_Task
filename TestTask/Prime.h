#ifndef PRIME_H
#define PRIME_H

#include <iostream>
#include <vector>
#include <set>
#include <mutex>

class Prime
{
private:
	std::set<int> primeNumbers;
public:
	void findPrimeNumbers(int const &low, int const &high, std::mutex &mutex);
	int isPrime(int const &num);
	const std::set<int> &getPrimeNumbers() const;

	class LowHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
