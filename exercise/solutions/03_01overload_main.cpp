#include <iostream>

struct IntWrapper {
	int i;
};

int add(int lhs, int rhs) {
	return lhs + rhs;
}

int add(IntWrapper lhs, int rhs) {
	return add(lhs.i, rhs);
}

int add(int lhs, IntWrapper rhs) {
	return add(lhs, rhs.i);
}

int add(IntWrapper lhs, IntWrapper rhs) {
	return add(lhs.i, rhs.i);
}

int main() {
	int i = 10;
	IntWrapper wrap;
	wrap.i = 5;
	
	std::cout << add(i, wrap) << ' '
	           << add(wrap, i) << ' '
	           << add(wrap, wrap) << ' '
	           << add(i, i) << std::endl;
}