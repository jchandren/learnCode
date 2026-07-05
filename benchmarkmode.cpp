#include <iostream>
#include <chrono>
#include <cassert>

// Define bitmask values for valid modes
#define MODE_7 (1U << 7)
#define MODE_8 (1U << 8)
#define MODE_9 (1U << 9)
#define MODE_11 (1U << 11)
#define MODE_12 (1U << 12)
#define MODE_13 (1U << 13)
#define MODE_14 (1U << 14)
#define MODE_15 (1U << 15)

// Define VALID_MODES using unsigned int
#define VALID_MODES ((unsigned int)(MODE_7 | MODE_8 | MODE_9 | MODE_11 | MODE_12 | MODE_13 | MODE_14 | MODE_15))

unsigned int valid_modes_direct = VALID_MODES;
unsigned int VALID_MODES_SUBTRACTION = (1U << 0)  // 1
                         | (1U << 1)  // 2
                         | (1U << 2)  // 4
                         | (1U << 4)  // 16
                         | (1U << 5)  // 32
                         | (1U << 6)  // 64
                         | (1U << 7)  // 128
                         | (1U << 8); // 256

void benchmark_direct_check(unsigned char mode) {
    // Direct bitmask check
    
    //bool result = (VALID_MODES & (1U << mode)) != 0;
    bool result = (valid_modes_direct & (1U << mode));
    //assert(result);  // Just for checking if mode is valid; can be removed if unnecessary
}

void benchmark_subtraction_check(unsigned char mode) {
    // Bitmask check with subtraction
    bool result = (VALID_MODES_SUBTRACTION & (1U << (mode - 7))) != 0;
    //assert(result);  // Just for checking if mode is valid; can be removed if unnecessary
}

void benchmark_comparison_check(unsigned char mode) {
    // Bitmask check with comparison
    bool result = (7 <= mode && mode <= 15 && mode != 10);
    //assert(result);  // Just for checking if mode is valid; can be removed if unnecessary
}

int main() {
    unsigned char mode = 10;  // Example mode

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; ++i) {
        benchmark_direct_check(mode);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> direct_duration = end - start;
    std::cout << "Direct check duration: " << direct_duration.count() << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; ++i) {
        benchmark_subtraction_check(mode);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> subtraction_duration = end - start;
    std::cout << "Subtraction check duration: " << subtraction_duration.count() << " seconds\n";
    
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; ++i) {
        benchmark_comparison_check(mode);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> comparison_duration = end - start;
    std::cout << "comparison check duration: " << comparison_duration.count() << " seconds\n";


    return 0;
}

