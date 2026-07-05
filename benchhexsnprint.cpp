#include <chrono>
#include <iostream>
#include <iomanip>
#include <fstream>

void benchmarkSnprintf(uint8_t val) {
    char line[4];
    auto start = std::chrono::high_resolution_clock::now();
    snprintf(line, 4, "%02X\n", val);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "snprintf: " << line << " Time: " 
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns\n";
}

void benchmarkStream(uint8_t val) {
    std::ostringstream oss;
    auto start = std::chrono::high_resolution_clock::now();
    oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(val) << "\n";
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Stream: " << oss.str() << " Time: " 
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns\n";
}

int main() {
    uint8_t val = 0xAB; // Example value
    benchmarkStream(val);

    benchmarkSnprintf(val);
    return 0;
}


