#ifndef PRIME_LADDER
#define PRIME_LADDER

#include <algorithm>
#include <cmath>
#include <vector>

class PrimeLadder {
private:
	struct PrimeMultiplePair {
		unsigned long long prime;
		unsigned long long multiple;
	};

	unsigned long long maxLimit{3};
	std::vector<PrimeMultiplePair> primePairs{{2, 4}};

	unsigned long long pi(unsigned long long);

public:
	void generatePrimesLessThan(unsigned long long);
	void generateNPrimes(unsigned long long);
	bool isPrime(unsigned long long);
	unsigned long long nthPrime(unsigned long long);
	unsigned long long primeCount() { return primePairs.size(); }
	std::vector<unsigned long long> getPrimes();
};

unsigned long long PrimeLadder::pi(unsigned long long n) {
	return static_cast<unsigned long long>(n / std::log(n));
}

void PrimeLadder::generatePrimesLessThan(unsigned long long limit) {
	if (limit <= maxLimit)
		return;

	primePairs.reserve(pi(limit));

	// Determine primality of the desired range by forward-computing multiples of primes
	bool candidateIsPrime;
	for (unsigned long long candidate{maxLimit}; candidate < limit; ++candidate) {
		candidateIsPrime = true;

		for (auto& pair : primePairs) {
			if (pair.multiple < candidate)
				pair.multiple += pair.prime;

			if (pair.multiple == candidate)
				candidateIsPrime = false;
		}

		if (candidateIsPrime)
			primePairs.push_back(PrimeMultiplePair {candidate, candidate + candidate});
	}

	maxLimit = limit;
}

void PrimeLadder::generateNPrimes(unsigned long long n) {
	if (n <= primePairs.size())
		return;

	primePairs.reserve(n);

	bool candidateIsPrime;
	unsigned long long candidate = maxLimit;
	while (primePairs.size() < n) {
		candidateIsPrime = true;

		for (auto& pair : primePairs) {
			if (pair.multiple < candidate)
				pair.multiple += pair.prime;

			if (pair.multiple == candidate)
				candidateIsPrime = false;
		}

		if (candidateIsPrime)
			primePairs.push_back(PrimeMultiplePair {candidate, candidate + candidate});

		++candidate;
	}

	maxLimit = candidate;
}

std::vector<unsigned long long> PrimeLadder::getPrimes() {
	std::vector<unsigned long long> primes(primePairs.size());
	std::transform(primePairs.begin(), primePairs.end(), primes.begin(), [](PrimeMultiplePair& pair) { return pair.prime; });
	return primes;
}

bool PrimeLadder::isPrime(unsigned long long n) {
	if (maxLimit < n)
		generatePrimesLessThan(n);

	return (std::count_if(primePairs.begin(), primePairs.end(), [&n](PrimeMultiplePair& pair) { return (pair.prime == n); }) > 0);
}

unsigned long long PrimeLadder::nthPrime(unsigned long long n) {
	if (primePairs.size() < n)
		generateNPrimes(n);

	return primePairs.at(n - 1).prime;
}

#endif
