/*

#ifndef include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#define include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
#endif

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
}*/
#include<./beauty/algorithm/other/swap_ranges.hpp>
int main(){
	return 0;
}