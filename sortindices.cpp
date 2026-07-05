#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort

using namespace std;

template <typename T>
std::vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  std::vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return *v[i1] > *v[i2];});

  return idx;
}





int main() 
{
    std::vector<double*> v_unsorted{ new double(4.5), new double(1.2), new double(3.4), new double(2.3) };
    
    for (auto i: sort_indexes(v_unsorted)) {
 	 std::cout << *v_unsorted[i] << " : " << i <<  endl;
 	 
 	 //std::cout << i << endl;
    }
    
    std::cout << std::endl;
    return 0;
}
