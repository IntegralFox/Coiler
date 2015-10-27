#include <iostream>

int main(int argc, char** argv)
{
	int primeFactors[21] = {};

	for (int number = 2; number <= 20; ++number) {
		int n = number;
		int divisor = 2;

		while (n > 1) {
			int dividedCount = 0;

			while (n % divisor == 0) {
				++dividedCount;
				n /= divisor;
			}

			if (primeFactors[divisor] < dividedCount)
				primeFactors[divisor] = dividedCount;

			++divisor;
		}
	}

	int multiple = 1;

	for (int prime = 2; prime < 21; ++prime) {
		if (primeFactors[prime] > 0) {
			for (int i = 0; i < primeFactors[prime]; ++i) {
				multiple *= prime;
			}
		}
	}

	std::cout << multiple << std::endl;
}
