#include <iostream>

#define SEIVE_SIZE 500000

int main(int argc, char** argv)
{
	bool isPrime[SEIVE_SIZE];

	for (int i = 0; i < SEIVE_SIZE; ++i) {
		isPrime[i] = true;
	}

	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i < (SEIVE_SIZE / 2); ++i) {
		if (isPrime[i]) {
			int multiple = i + i;
			while (multiple < SEIVE_SIZE) {
				isPrime[multiple] = false;
				multiple += i;
			}
		}
	}

	int nthPrime = 0;
	int n = 0;

	for (int i = 0; i < SEIVE_SIZE && n < 10001; ++i) {
		if (isPrime[i]) {
			++n;
			nthPrime = i;
		}
	}

	std::cout << nthPrime << std::endl;
}
