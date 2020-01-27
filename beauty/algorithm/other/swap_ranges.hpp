
#ifndef beauty__algorithm__other___swap_ranges_hpp
#define beauty__algorithm__other___swap_ranges_hpp

#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>


namespace beauty{namespace algorithm{namespace other{
	
	
template<class ForwardIter1, class ForwardIter2>
ForwardIter2 swap_ranges(ForwardIter1 first1, ForwardIter1 last1,
ForwardIter2 first2){
	while(first1 != last1){
		beauty::algorithm::algorithmbase::
		iter_swap(first1, first2);
		++first1;
		++first2;
	}
	return first2;
}


}
}
}
#endif
