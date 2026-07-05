#include <algorithm>
#include <cstring>
#include <vector>
#include <benchmark/benchmark.h>

const int SIZE = 1000000;

void BM_std_fill(benchmark::State& state) {
    std::vector<int> vec(SIZE);
    for (auto _ : state) {
        std::fill(vec.begin(), vec.end(), 0);
    }
}
BENCHMARK(BM_std_fill);

void BM_memset(benchmark::State& state) {
    int* arr = new int[SIZE];
    for (auto _ : state) {
        std::memset(arr, 0, sizeof(int) * SIZE);
    }
    delete[] arr;
}
BENCHMARK(BM_memset);
