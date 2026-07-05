#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
std::vector<size_t> get_indices(std::vector<T> const & v_unsorted, std::vector<T> & v_sorted) 
{
    std::vector<size_t> idx_sorted2unsorted(v_unsorted.size()); 
    std::iota(idx_sorted2unsorted.begin(), idx_sorted2unsorted.end(), 0);
    std::cout << "iota:idx_sorted2unsorted: ";
    for (auto const & i : idx_sorted2unsorted)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;



    // Create indices mapping (sorted -> unsorted) sorting in descending order:
    std::stable_sort(idx_sorted2unsorted.begin(), idx_sorted2unsorted.end(),
        [&v_unsorted](size_t i1, size_t i2) 
            { 	
            	std::cout << "Checking :i1:" << i1 << ":i2:" << i2 << ":val1:" << *v_unsorted[i1] << ":val2:" << *v_unsorted[i1] << ":Res:" << (*v_unsorted[i1] > *v_unsorted[i2]) << std::endl;
            	return *v_unsorted[i1] > *v_unsorted[i2]; }); // You can use '<' for ascending order



    // Create final indices (unsorted -> sorted) and sorted array:
    //std::vector<size_t> idx_unsorted2sorted(v_unsorted.size());
    v_sorted.resize(v_unsorted.size());
    
  

/*
    std::cout << "unsorted2sorted vector:" ;
    for (auto const & i : idx_unsorted2sorted)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
*/
    
    for (size_t i = 0; i < v_unsorted.size(); ++i)
    {
        //idx_unsorted2sorted[idx_sorted2unsorted[i]] = i;
        v_sorted[i] = v_unsorted[idx_sorted2unsorted[i]];
    }
    /*
    std::cout << "sorted vector: v_sorted:" ;
    for (auto const & i : idx_unsorted2sorted)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    */

      std::cout << "v_sorted: ";
    for (auto const & i : v_sorted)
    {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;

    
    
    std::cout << "idx_sorted2unsorted:" ;
    for (auto const & i : idx_sorted2unsorted)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    
    
    
    //return idx_unsorted2sorted;
    return idx_sorted2unsorted;
}
// 0, 2, 3, 1 : 0:0, 2:1, 3:2, 1:3, c

//0, 3, 1,2
int main() 
{
    std::vector<double*> v_unsorted{ new double(4.5), new double(1.2), new double(3.4), new double(2.3) };
    std::vector<double*> v_sorted;
    std::vector<size_t> idx_unsorted2sorted = get_indices(v_unsorted, v_sorted);
    for (auto const & i : idx_unsorted2sorted)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    return 0;
}
