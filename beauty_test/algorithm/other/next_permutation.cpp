/*

#ifndef include___beauty__algorithm__other___reverse_hpp
	#define include___beauty__algorithm__other___reverse_hpp
	#include<./beauty/algorithm/other/reverse.hpp>
#endif
#ifndef include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#define include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
#endif

namespace beauty{namespace algorithm{namespace other{
	
	
template<class BidirectionalIter>
ptype::bool_t next_permutation(BidirectionalIter first,
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
}*/
#include<./beauty/algorithm/other/next_permutation.hpp>
int main(){
	return 0;
}