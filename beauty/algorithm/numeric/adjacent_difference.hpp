
#ifndef beauty__algorithm__numeric___adjacent_difference_hpp
#define beauty__algorithm__numeric___adjacent_difference_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


namespace beauty{namespace algorithm{namespace numeric{


template<class InputIterator, class OutputIterator>inline
OutputIterator adjacent_difference(InputIterator first, InputIterator last,
 OutputIterator result){
	if(first == last)return result;
	*result = *first;

	 typename beauty::iterator::iterator_traits::iterator_traits<InputIterator>::value_type
	 value = *first, temp;

	 for(++first; first != last; ++first){
 		temp = *first;
 		*++result = temp - value;
 		value = temp;
 	}
 	return ++result;
}

template<class InputIterator, class OutputIterator, class BinaryOperation>inline
OutputIterator adjacent_difference(InputIterator first, InputIterator last,
OutputIterator result, BinaryOperation op){
	if(first == last)return result;
	*result = *first;


	typename beauty::iterator::iterator_traits::iterator_traits<InputIterator>::value_type
	 value = *first, temp;

	for(++first; first != last; ++first){
		temp = *first;
		*++result = op(temp, value);
		value = temp;
	}
	return ++result;
}




}
}
}
#endif
