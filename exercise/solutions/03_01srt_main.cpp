#include <iostream>

void insertSpace(const char *orig, char *dest) {
	int i = 0, j = 0;
	while (orig[i] != '\0') {
		dest[j] = orig[i];
		++j;
		
		if (orig[i] == 'a') {
			dest[j] = ' ';
			++j;
		}
		++i;
	}
	dest[j] = '\0';
}

int main() {
	const char *str = "Sziamizujs?";
	char buf[256];
	
	insertSpace(str, buf);
	
	std::cout << buf << std::endl;
}