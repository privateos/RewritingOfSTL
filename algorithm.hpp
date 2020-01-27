
#ifndef BEAUTY__OUT__ALGORITHM_HPP
#define BEAUTY__OUT__ALGORITHM_HPP



// ./beauty/
#include<./beauty/types.hpp>
#include<./beauty/config.hpp>
#include<./beauty/exception.hpp>


//   ./beauty/algorithm/algorithmbase/
#include<./beauty/algorithm/algorithmbase/compare.hpp>
#include<./beauty/algorithm/algorithmbase/copy.hpp>	
#include<./beauty/algorithm/algorithmbase/copy_backward.hpp>
#include<./beauty/algorithm/algorithmbase/equal.hpp>
#include<./beauty/algorithm/algorithmbase/fill.hpp>
#include<./beauty/algorithm/algorithmbase/fill_n.hpp>
#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
#include<./beauty/algorithm/algorithmbase/iterator_swap.hpp>
#include<./beauty/algorithm/algorithmbase/lexicographical_compare.hpp>
#include<./beauty/algorithm/algorithmbase/max.hpp>
#include<./beauty/algorithm/algorithmbase/min.hpp>
#include<./beauty/algorithm/algorithmbase/mismatch.hpp>
#include<./beauty/algorithm/algorithmbase/swap.hpp>






// ./beauty/algorithm/heap/
#include<./beauty/algorithm/heap/make_heap.hpp>
#include<./beauty/algorithm/heap/pop_heap.hpp>
#include<./beauty/algorithm/heap/push_heap.hpp>
#include<./beauty/algorithm/heap/sort_heap.hpp>






// ./beauty/algorithm/numeric/
#include<./beauty/algorithm/numeric/accumulate.hpp>
#include<./beauty/algorithm/numeric/adjacent_difference.hpp>
#include<./beauty/algorithm/numeric/inner_product.hpp>
#include<./beauty/algorithm/numeric/iota.hpp>
#include<./beauty/algorithm/numeric/partial_sum.hpp>
#include<./beauty/algorithm/numeric/power.hpp>





// ./beauty/algorithm/other/
#include<./beauty/algorithm/other/adjacent_find.hpp>
#include<./beauty/algorithm/other/binary_search.hpp>
#include<./beauty/algorithm/other/count.hpp>
#include<./beauty/algorithm/other/count_if.hpp>
#include<./beauty/algorithm/other/equal_range.hpp>
#include<./beauty/algorithm/other/find.hpp>
#include<./beauty/algorithm/other/find_end.hpp>
#include<./beauty/algorithm/other/find_first_of.hpp>
#include<./beauty/algorithm/other/find_if.hpp>
#include<./beauty/algorithm/other/for_each.hpp>
#include<./beauty/algorithm/other/gcd.hpp>
#include<./beauty/algorithm/other/generate.hpp>
#include<./beauty/algorithm/other/generate_n.hpp>
#include<./beauty/algorithm/other/includes.hpp>
#include<./beauty/algorithm/other/inplace_merge.hpp>
#include<./beauty/algorithm/other/lcm.hpp>
#include<./beauty/algorithm/other/lower_bound.hpp>
#include<./beauty/algorithm/other/max_element.hpp>
#include<./beauty/algorithm/other/merge.hpp>
#include<./beauty/algorithm/other/min_element.hpp>
#include<./beauty/algorithm/other/next_permutation.hpp>
#include<./beauty/algorithm/other/nth_element.hpp>
#include<./beauty/algorithm/other/partial_sort.hpp>
#include<./beauty/algorithm/other/partial_sort_copy.hpp>
#include<./beauty/algorithm/other/partition.hpp>
#include<./beauty/algorithm/other/prev_permutation.hpp>
#include<./beauty/algorithm/other/random_shuffle.hpp>
#include<./beauty/algorithm/other/remove.hpp>
#include<./beauty/algorithm/other/remove_copy.hpp>
#include<./beauty/algorithm/other/remove_copy_if.hpp>
#include<./beauty/algorithm/other/remove_if.hpp>
#include<./beauty/algorithm/other/replace.hpp>
#include<./beauty/algorithm/other/replace_copy.hpp>
#include<./beauty/algorithm/other/replace_copy_if.hpp>
#include<./beauty/algorithm/other/replace_if.hpp>
#include<./beauty/algorithm/other/reverse.hpp>
#include<./beauty/algorithm/other/reverse_copy.hpp>
#include<./beauty/algorithm/other/rotate.hpp>
#include<./beauty/algorithm/other/rotate_copy.hpp>
#include<./beauty/algorithm/other/search.hpp>
#include<./beauty/algorithm/other/search_n.hpp>
#include<./beauty/algorithm/other/sort.hpp>
#include<./beauty/algorithm/other/swap_ranges.hpp>
#include<./beauty/algorithm/other/transform.hpp>
#include<./beauty/algorithm/other/unique.hpp>
#include<./beauty/algorithm/other/unique_copy.hpp>
#include<./beauty/algorithm/other/upper_bound.hpp>






// ./beauty/algorithm/set/
#include<./beauty/algorithm/set/set_difference.hpp>
#include<./beauty/algorithm/set/set_intersection.hpp>
#include<./beauty/algorithm/set/set_symmetric_difference.hpp>
#include<./beauty/algorithm/set/set_union.hpp>



namespace future{
using namespace beauty;
using namespace beauty::algorithm::algorithmbase;
using namespace beauty::algorithm::heap;
using namespace beauty::algorithm::numeric;
using namespace beauty::algorithm::other;
using namespace beauty::algorithm::set;
}
#endif
