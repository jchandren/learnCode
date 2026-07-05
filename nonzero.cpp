#include <stdint.h>
#include <stdio.h>
#include <iostream>
int main() {
	uint8_t val = ~0;

	if (val == ~0) {
	  printf("YES!\n");
	} else {
	  printf("NO!\n");
	}
	std::cout << sizeof(0) << std::endl;

	std::cout << sizeof(val) << std::endl;

	std::cout << sizeof(uint32_t) << std::endl;
	val = 0;
	if (val == 0) {
		std::cout << "Equals 0" << std::endl;
	}
	else {

		std::cout << "NOTEquals 0" << std::endl;
	}
}
