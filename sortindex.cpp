#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
std::vector<size_t> get_indices(std::vector<T> const & v_unsorted, std::vector<T> & v_sorted) 
{
    std::vector<size_t> idx_sorted2unsorted(v_unsorted.size()); 
    std::iota(idx_sorted2unsorted.begin(), idx_sorted2unsorted.end(), 0);

    // Create indices mapping (sorted -> unsorted) sorting in descending order:
    std::stable_sort(idx_sorted2unsorted.begin(), idx_sorted2unsorted.end(),
        [&v_unsorted](size_t i1, size_t i2) 
            { return v_unsorted[i1] > v_unsorted[i2]; }); // You can use '<' for ascending order

    // Create final indices (unsorted -> sorted) and sorted array:
    std::vector<size_t> idx_unsorted2sorted(v_unsorted.size());
    v_sorted.resize(v_unsorted.size());
    for (size_t i = 0; i < v_unsorted.size(); ++i)
    {
        idx_unsorted2sorted[idx_sorted2unsorted[i]] = i;
        v_sorted[i] = v_unsorted[idx_sorted2unsorted[i]];
    }
    return idx_unsorted2sorted;
}

int main() 
{
    std::vector<double> v_unsorted{ 4.5, 1.2, 3.4, 2.3 };
    std::vector<double> v_sorted;
    std::vector<size_t> idx_unsorted2sorted = get_indices(v_unsorted, v_sorted);
    for (auto const & i : idx_unsorted2sorted)
    {
        std::cout << i << ", ";
    }
    return 0;
}
