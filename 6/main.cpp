#include <iostream>

int main() {
	long long sumSquares = 0;
	long long squaredSum = 0;

	for (int i = 1; i <= 100; ++i) {
		sumSquares += i * i;
		squaredSum += i;
	}

	squaredSum *= squaredSum;

	std::cout << (squaredSum - sumSquares) << std::endl;
}
