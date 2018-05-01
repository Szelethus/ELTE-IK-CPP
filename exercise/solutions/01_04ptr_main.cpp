#include <iostream>

int findIf(int *t, int size, bool (pred)(int)) {
	for (int i = 0; i < size; ++i) {
		if (pred(t[i]))
			return i;
	}
	return -1;
}

bool isEven(int i) {
	return i % 2 == 0;
}

bool isEqualToSeven(int i) {
	return i == 7;
}

bool isNegative(int i) {
	return i < 0;
}

int main() {
	int t [] = {1, 3, 4, 6, 7, 8, 10};
	
	std::cout << findIf(t, sizeof(t) / sizeof(t[0]), isEven) << ' '
	          << findIf(t, sizeof(t) / sizeof(t[0]), isEqualToSeven) << ' '
	          << findIf(t, sizeof(t) / sizeof(t[0]), isNegative) << std::endl;
}