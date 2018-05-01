
#include <iostream>

void changePointer(int **ptr, int *d) {
	*ptr = d;
}

int main() {
	int c = 5, d = 6;
	int *ptr = &c;
	changePointer(&ptr, &d);
	std::cout << ptr << '\n' << &d << std::endl;
}