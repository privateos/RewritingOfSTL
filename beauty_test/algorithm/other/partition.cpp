/*


#ifndef include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#define include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
#endif

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
}*/
#include<./beauty/algorithm/other/partition.hpp>
int main(){
	return 0;
}