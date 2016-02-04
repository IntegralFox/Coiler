#include <iostream>

int main(int argc, char* argv[]) {
	int sum = 1000;

	for (int a{3}; a < (sum - 3) / 3; ++a)
		for (int b{a + 1}; b < (sum - a - 1) / 2; ++b) {
			int c{sum - a - b};
			if (a*a + b*b == c*c) {
				std::cout << a*b*c << std::endl;
				return 0;
			}
		}
}
