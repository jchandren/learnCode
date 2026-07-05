#include <iostream>

// Define bitmask values for valid modes
#define MODE_7 (1U << 7)
#define MODE_8 (1U << 8)
#define MODE_9 (1U << 9)
#define MODE_11 (1U << 11)
#define MODE_12 (1U << 12)
#define MODE_13 (1U << 13)
#define MODE_14 (1U << 14)
#define MODE_15 (1U << 15)

// Define VALID_MODES by OR-ing the bitmask values
#define VALID_MODES  ((unsigned int) (MODE_7 | MODE_8 | MODE_9 | MODE_11 | MODE_12 | MODE_13 | MODE_14 | MODE_15))

//#define VALID_MODES ((unsigned char)(MODE_7 | MODE_8 | MODE_9 | MODE_11 | MODE_12 | MODE_13 | MODE_14 | MODE_15))

// Create a bitmask for the range 7 to 15, excluding 10
unsigned char createBitmaskExcluding10() {
    unsigned char bitmask = 0;
    for (char value : {7, 8, 9, 11, 12, 13, 14, 15}) {
        bitmask |= (1 << (value - 7)); // Set the bit for each value
    }
    printf("Bitmask created:%u:%X\n", bitmask, bitmask);
    return bitmask;
}

bool checkBitmask_2(unsigned char mode) {
	return    (VALID_MODES & (1U << mode));

}

// Check if a number is in the bitmask
bool isInBitmaskExcluding10(unsigned char number, unsigned int bitmask) {
    // Ensure value is within the expected range (7 to 15)
    if (number < 7 || number > 15) return false;

    // Check if the bit corresponding to the value is set
    return (bitmask & (1 << (number - 7))) != 0;
}

bool rangeChk(unsigned char mode) {
    return ( (7 <= mode) && (10 != mode) && (15 >= mode));
}

bool modeChk(unsigned char mode) {
	    static const unsigned int validModes = 0b1111001111110000; // 7, 8, 9, 11, 12, 13, 14, 15
    return (mode < 16) && (validModes & (1 << mode));
}

int main() {
    unsigned char bitmask = createBitmaskExcluding10();

    unsigned char numbers[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    printf("ValidModes:0x%X\n", VALID_MODES);
    for (unsigned char number : numbers) {
	printf("ValidModeChk:%u:%u\n",number, (VALID_MODES & (1 << number)));
        if (isInBitmaskExcluding10(number, bitmask)) {
            std::cout << "Number " << static_cast<unsigned>(number) << " is in the range 7 to 15, excluding 10.\n";
        } else {
            std::cout << "Number " << static_cast<unsigned>(number) << " is not in the range 7 to 15, or is excluded (10).\n";
        }
        if (rangeChk(number)) {
            std::cout << "Number " << static_cast<unsigned>(number) << " is in the range 7 to 15, excluding 10.\n";
        } else {
            std::cout << "Number " << static_cast<unsigned>(number) << " is not in the range 7 to 15, or is excluded (10).\n";
        }
        if (modeChk((unsigned char)number)) {
            std::cout << "Number " << static_cast<unsigned>(number) << " is in the range 7 to 15, excluding 10.\n";
        } else {
            std::cout << "Number " << static_cast<unsigned>(number) << " is not in the range 7 to 15, or is excluded (10).\n";
        }
    
        if (checkBitmask_2(number)) {
            std::cout << "Checkbitmask_2Number " << static_cast<unsigned>(number) << " is in the range 7 to 15, excluding 10.\n";
        } else {
            std::cout << "Checkbitmask_2Number " << static_cast<unsigned>(number) << " is not in the range 7 to 15, or is excluded (10).\n";
        }
    }

    return 0;
}
