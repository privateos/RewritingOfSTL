
#ifndef beauty__algorithm__other___pre_permutation_hpp
#define beauty__algorithm__other___pre_permutation_hpp

#include<./beauty/algorithm/other/reverse.hpp>
#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>


namespace beauty{namespace algorithm{namespace other{
	
	
template<class BidirectionalIter>
bool prev_permutation(BidirectionalIter first,
BidirectionalIter last){
	if(first == last)return false;
	BidirectionalIter i = first;
	if(++i == last)return false;
	
	i = last;
	--i;
	BidirectionalIter ii, j;
	for( ; ; ){
		ii = i;
		--i;
		if(*ii < *i){
			j = last;
			while(!(*--j < *i));
			beauty::algorithm::algorithmbase::iter_swap(i, j);
			beauty::algorithm::other::reverse(ii, last);
			return true;
		}
		if(i == first){
			beauty::algorithm::other::reverse(first, last);
			return false;
		}
	}
}
template<class BidirectionalIter, class Compare>
bool prev_permutation(BidirectionalIter first,
BidirectionalIter last, Compare comp){
	if(first == last)return false;
	BidirectionalIter i = first;
	if(++i == last)return false;
	
	i = last;
	--i;
	BidirectionalIter ii, j;
	for( ; ; ){
		ii = i;
		--i;
		if(comp(*ii, *i)){
			j = last;
			while(!comp(*--j, *i));
			beauty::algorithm::algorithmbase::iter_swap(i, j);
			beauty::algorithm::other::reverse(ii, last);
			return true;
		}
		if(i == first){
			beauty::algorithm::other::reverse(first, last);
			return false;
		}
	}
}


}
}
}
#endif
