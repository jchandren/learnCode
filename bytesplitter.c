#include <stdio.h>
#include <stdint.h>

void splitBytes(uint16_t i, uint8_t* bytes) {
        // 16 bit system
        bytes[0] =  ((uint16_t)i >> 8) & 0xFF;
        bytes[1] =  ((uint16_t)i >> 0) & 0xFF;  // shift by 0 not needed, of course, just stylistic
}        

int main() {
	uint16_t i = 0x2f8;

	uint8_t bytes[2] = {0,0};
	splitBytes(i,bytes);
	for (int j =0; j < 2; j++) {
		printf("%x:\n",bytes[j]);
	}		

}

