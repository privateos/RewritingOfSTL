/*

#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif
namespace beauty{namespace algorithm{namespace numeric{

template<class InputIterator, class OutputIterator>inline
OutputIterator partial_sum(InputIterator first, InputIterator last,
OutputIterator result){
	if(first == last)return result;
	*result = *first;

	typename beauty::iterator::iterator_traits::iterator_traits<InputIterator>::value_type
	value = *first;

	for( ++first; first != last; ++first){
		value = value + *first;
		*++result = value;
	}
	return ++result;
}

template<class InputIterator, class OutputIterator, class BinaryOperation>
inline OutputIterator partial_sum(InputIterator first, InputIterator last,
OutputIterator result, BinaryOperation op){
	if(first == last)return result;
	*result = *first;

	typename beauty::iterator::iterator_traits::iterator_traits<InputIterator>::value_type
	value = *first;

	for( ++first; first != last; ++first){
		value = op(value, *first);
		*++result = value;
	}
	return ++result;
}




}
}
}
*/
#include<./beauty/algorithm/numeric/partial_sum.hpp>
int main(){
	return 0;
}