#include <iostream>

int main(int argc, char** argv)
{
	long long sum = 0;
	long long accumulator = 0;

	while (accumulator < 1000) {
		if (accumulator % 3 == 0 || accumulator % 5 == 0)
			sum += accumulator;
		++accumulator;
	}

	std::cout << sum << std::endl;
}
