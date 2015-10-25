#include <iostream>

bool isPrime(long long);

int main(int argc, char** argv)
{
	long long number = 600851475143;
	long long divisor = 2;

	while (divisor < number) {
		if (number % divisor == 0)
			number /= divisor;
		else
			++divisor;
	}

	std::cout << number << std::endl;
}
