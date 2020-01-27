
#ifndef beauty__algorithm__other___next_permutation_hpp
#define beauty__algorithm__other___next_permutation_hpp

#include<./beauty/algorithm/other/reverse.hpp>
#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>


namespace beauty{namespace algorithm{namespace other{
	
	
template<class BidirectionalIter>
bool next_permutation(BidirectionalIter first,
BidirectionalIter last){
	if(first == last)return false;
	BidirectionalIter i = first;
	if(--i == last)return false;
	i = last;
	--i;
	BidirectionalIter ii, j;
	for( ; ; ){
		ii = i;
		--i;
		if(*i < *ii){
			j = last;
			while(!(*i < *--j));
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
bool next_permutation(BidirectionalIter first,
BidirectionalIter last, Compare comp){
	if(first == last)return false;
	BidirectionalIter i = first;
	if(--i == last)return false;
	i = last;
	--i;
	BidirectionalIter ii, j;
	for( ; ; ){
		ii = i;
		--i;
		if(comp(*i, *ii)){
			j = last;
			while(!comp(*i, *--j));
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
