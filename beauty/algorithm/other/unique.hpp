
#ifndef beauty__algorithm__other___unique_hpp
#define beauty__algorithm__other___unique_hpp

#include<./beauty/iterator/iterator_category/output_iterator_tag.hpp>
#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#include<./beauty/algorithm/other/adjacent_find.hpp>


namespace beauty{namespace algorithm{namespace other{
	
	
template<class InputIter, class OutputIter>inline
OutputIter _unique_copy(InputIter first, InputIter last,
		OutputIter result, 
		beauty::iterator::iterator_category::output_iterator_tag){
	
	typename beauty::iterator::iterator_traits::
	iterator_traits<OutputIter>::value_type type;
	type = *first;
	*result = type;
	while(++first != last){
		if(!(type == *first)){
			type = *first;
			*++result = type;
		}
	}
	return ++result;
}
template<class InputIter, class OutputIter>inline
OutputIter _unique_copy(InputIter first, InputIter last,
	OutputIter result, 
	beauty::iterator::iterator_category::forward_iterator_tag){
	
	*result = *first;
	while(++first != last){
		if(!(*first == *result)){
			*++result = *first;
		}
	}
	return ++result;
}
template<class InputIter, class OutputIter>
OutputIter unique_copy(InputIter first, InputIter last,
 OutputIter result){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<OutputIter>::iterator_category Category;
	
	if(first == last)return result;
	return beauty::algorithm::other::
		_unique_copy(first, last, result, Category());
}
template<class InputIter>
InputIter unique(InputIter first, InputIter last){
	if(first == last)return last;
	
	first = beauty::algorithm::other::adjacent_find(first, last);
	return beauty::algorithm::other::unique_copy(first, last, first);
}

template<class InputIter, class BinaryOper>
InputIter unique(InputIter first, InputIter last, BinaryOper op){
	if(first == last)return last;
	
	first = beauty::algorithm::other::adjacent_find(first, last, op);
	return beauty::algorithm::other::unique_copy(first, last, first);
}


}
}
}
#endif
