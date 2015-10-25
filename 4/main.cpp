#include <iostream>
#include <string>

bool isPalindrome(int);

int main (int argc, char** argv)
{
	int maximum = 0;

	for (int smaller = 999; (smaller * 999) > maximum; --smaller)
		for (int larger = 999; (larger * smaller) > maximum; --larger) {
			if (isPalindrome(larger * smaller))
				maximum = larger * smaller;
		}

	std::cout << (maximum) << std::endl;
}

bool isPalindrome(int n)
{
	std::string s = std::to_string(n);

	int a = 0;
	int b = s.length() - 1;

	while (a < b) {
		if (s[a] != s[b])
			return false;
		++a;
		--b;
	}

	return true;
}
