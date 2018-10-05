#include <iostream>
#include <thread>
#include "Prime.h"
#include "Reader.h"
#include "Writer.h"

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
			threads.push_back(std::move(std::thread([&]() {
				prime.findPrimeNumbers(reader.getLowNum().at(i), reader.getHighNum().at(i), ref(mutex));
			})));
		}
		writer.writeFile(prime.getPrimeNumbers(), &mutex);
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