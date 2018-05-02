#include <iostream>

int main() {
	int t[] = {1, 2, 3, 4};
	
	int *ptr;
	for(ptr = t; ptr != t + sizeof(t) / sizeof(t[0]); ++ptr) {
		std::cout << *ptr << std::endl;
	}
}