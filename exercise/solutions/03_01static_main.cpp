#include <iostream>

int findIf(int *t, int size, bool (pred)(int)) {
	for (int i = 0; i < size; ++i) {
		if (pred(t[i]))
			return i;
	}
	return -1;
}

bool isSecondEven(int i) {
	static int count = 0;
	if (i % 2 == 0) {
		++count;
	}
	return count == 2 && i % 2 == 0;
}

int main() {
	int t [] = {1, 3, 4, 6, 7, 8, 10};
	
	std::cout << findIf(t, sizeof(t) / sizeof(t[0]), isSecondEven) << std::endl;
	// 1. Ha többször hívjuk meg a függvényt, a statikus változó értéke nem áll vissza 0ra.
	std::cout << findIf(t, sizeof(t) / sizeof(t[0]), isSecondEven) << std::endl;
	// 2. Párhuzamos programok esetén előfordulhat, hogy `count`-ot egyszerre több folyamat
	// is akarja módosítani, ami nem definiált viselkedés.
}