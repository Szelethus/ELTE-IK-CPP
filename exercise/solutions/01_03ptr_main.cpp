
#include <iostream>

void changePointer(const int **ptr, const int *d) {
	*ptr = d;
}

int main() {
	const int c = 5, d = 6;
	const int *ptr = &c;
	changePointer(&ptr, &d);
	std::cout << ptr << '\n' << &d << std::endl;
}