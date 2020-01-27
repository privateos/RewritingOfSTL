/*

namespace beauty{namespace algorithm{namespace other{
	


template<class ForwardIter>inline
ForwardIter max_element(ForwardIter first, ForwardIter last){
	if(first == last)return last;
	ForwardIter result = first;
	for( ++first; first != last; ++first){
		if(*result < *first){
			result = first;
		}
	}
	return result;
}
template<class ForwardIter, class Compare>inline
ForwardIter max_element(ForwardIter first, ForwardIter last, Compare comp){
	if(first == last)return last;
	ForwardIter result = first;
	for( ++first; first != last; ++first){
		if(comp(*result, *first)){
			result = first;
		}
	}
	return result;
}

}
}
}*/
#include<./beauty/algorithm/other/max_element.hpp>
int main(){
	return 0;
}