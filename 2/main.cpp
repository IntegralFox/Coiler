#include <iostream>

int main (int argc, char** argv)
{
	long long smaller, larger, fibonacci, sum;
	smaller = 0;
	larger = 1;
	fibonacci = 1;
	sum = 0;

	while (fibonacci <= 4000000) {
		if (!(fibonacci & 0x0001))
			sum += fibonacci;

		fibonacci = smaller + larger;
		smaller = larger;
		larger = fibonacci;
	}

	std::cout << sum << std::endl;
}
