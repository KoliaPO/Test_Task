#include <iostream>
#include <thread>
#include "Prime.h"
#include "Reader.h"
#include "Writer.h"

std::thread createthread(Prime &p, int const &low, int const &high, std::mutex &mutex)
{
	std::thread th([&]() {
		p.findPrimeNumbers(low, high, mutex);
	});
	return th;
}

int main()
{
	std::string filename;
	Reader reader;
	Prime prime;
	Writer writer;
	std::vector<std::thread> threads;
	std::mutex mutex;

	std::cout << "Enter File name : ";
	std::cin >> filename;
	try
	{
		reader.readFromFile(filename);
		for (size_t i = 0; i < reader.getLowNum().size(); i++)
		{
			threads.push_back(createthread(prime, reader.getLowNum().at(i), reader.getHighNum().at(i), mutex));
		}
		writer.writeFile(prime.getPrimeNumbers());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	for (std::thread &thread : threads)
	{
		if (thread.joinable())
			thread.join();
	}
	system("pause");
 	return 0;
}