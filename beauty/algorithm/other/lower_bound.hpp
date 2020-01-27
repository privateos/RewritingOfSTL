
#ifndef beauty__algorithm__other___lower_bound_hpp
#define beauty__algorithm__other___lower_bound_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#include<./beauty/iterator/function/distance.hpp>
#include<./beauty/iterator/function/advance.hpp>

namespace beauty{namespace algorithm{namespace other{
	
	
template<class ForwardIter, class T>
ForwardIter lower_bound(ForwardIter first, ForwardIter last, const T &value){
	typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::difference_type
			 half, len = 0;
	ForwardIter i ;
	beauty::iterator::function::distance(first, last, len);

	while(len > 0){
		half = len>>1;
		i = first;
		beauty::iterator::function::advance(i, half);

		if(*i < value){
			len = len - half - 1;
			first = i;
			++first;
		}else{
			len = half;
		}
	}
	return first;
	
}
template<class ForwardIter, class T, class Compare>
ForwardIter lower_bound(ForwardIter first, ForwardIter last,
 const T &value, Compare comp){
	typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::difference_type
	 	half, len = 0;
	ForwardIter i ;
	beauty::iterator::function::distance(first, last, len);
	
	while(len > 0){
		half = len>>1;
		i = first;
		beauty::iterator::function::advance(i, half);
		if(comp(*i, value)){
			len = len - half - 1;
			first = i;
			++first;
		}else{
			len = half;
		}
	}
	return first;
	
}



}
}
}
#endif
