#include <iostream>
#include <thread>
#include "Prime.h"
#include "Reader.h"
#include "Writer.h"

std::thread createThread(Prime &p, int const &low, int const &high)
{
	std::thread th([&]() {
		p.findPrimeNumbers(low, high);
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

	std::cout << "Enter File name : ";
	std::cin >> filename;
	try
	{
		reader.readFromFile(filename);
		for (size_t i = 0; i < reader.getLowNum().size(); i++)
		{
			threads.push_back(createThread(prime, reader.getLowNum().at(i), reader.getHighNum().at(i)));
		}
		for (std::thread &thread : threads)
		{
			if (thread.joinable())
				thread.join();
		}
		writer.writeFile(prime.getPrimeNumbers());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	system("pause");
 	return 0;
}