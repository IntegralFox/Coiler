#include <iostream>
#include "../lib/PrimeLadder.hpp"

int main(int argc, char* argv[]) {
	PrimeLadder ladder;
	ladder.generatePrimesLessThan(2000000);

	unsigned long long sum{0};
	for (auto prime : ladder.getPrimes())
		sum += prime;

	std::cout << sum << std::endl;
}
