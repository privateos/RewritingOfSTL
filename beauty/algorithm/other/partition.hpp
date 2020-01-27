
#ifndef beauty__algorithm__other___partition_hpp
#define beauty__algorithm__other___partition_hpp

#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>


namespace beauty{namespace algorithm{namespace other{
	

template<class BidirectionalIter, class Predicate>
BidirectionalIter partition(BidirectionalIter first,
BidirectionalIter last, Predicate pred){
	while(1){
		while(1){
			if(first == last){
				return first;
			}else{
				if(pred(*first)){
					++first;
				}else{
					break;
				}
			}
		}
		--last;
		while(1){
			if(first == last){
				return first;
			}else{
				if(!pred(*last)){
					--last;
				}else{
					break;
				}
			}
		}
		beauty::algorithm::algorithmbase::
		iter_swap(first, last);
	}
}


}
}
}
#endif
