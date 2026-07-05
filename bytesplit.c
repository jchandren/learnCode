#include <stdio.h>
#include <stdint.h>

int main() {
	// 16 bit system  
	uint16_t i = 0x2f8; //0x789A;

	//uint16_t i = 0x0003;
	//
	uint8_t bytes [sizeof(uint16_t)] = 
	{
	  ((uint16_t)i >> 8) & 0xFF,
	  ((uint16_t)i >> 0) & 0xFF,  // shift by 0 not needed, of course, just stylistic
	};
	uint8_t bytes16 [2] = 
	{
		(i >> 8) & 0xFF,
		(i >> 0) & 0xFF,
	};
	for (int j =0; j < 2; j++) {
		printf("%x:\n",bytes[j]);
		printf("bytes16:%x\n",bytes16[j]);
	}		
	printf("SizeofInt:%ld:%ld", sizeof(int),sizeof(uint16_t));
}

