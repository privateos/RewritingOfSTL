
#ifndef beauty__algorithm__other___count_hpp
#define beauty__algorithm__other___count_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


namespace beauty{namespace algorithm{namespace other{
	

template<class InputIter, class T>
typename beauty::iterator::iterator_traits::
iterator_traits<InputIter>::difference_type
count(InputIter first, InputIter last, const T &value){
	typename beauty::iterator::iterator_traits::
		iterator_traits<InputIter>::difference_type n = 0;
	for( ; first != last; ++first){
		if(*first == value){
			++n;
		}
	}
	return n;
}
template<class InputIter, class T, class BinaryOper>
typename beauty::iterator::iterator_traits::
iterator_traits<InputIter>::difference_type
count(InputIter first, InputIter last, const T &value, BinaryOper op){
	
	typename beauty::iterator::iterator_traits::
		iterator_traits<InputIter>::difference_type n = 0;
	for( ; first != last; ++first){
		if(op(*first, value)){
			++n;
		}
	}
	return n;
}


}
}
}
#endif
