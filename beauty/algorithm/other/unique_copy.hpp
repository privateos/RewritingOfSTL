
#ifndef beauty__algorithm__other___unique_copy_hpp
#define beauty__algorithm__other___unique_copy_hpp

#include<./beauty/iterator/iterator_category/output_iterator_tag.hpp>
#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>

namespace beauty{namespace algorithm{namespace other{
	
	
template<class InputIter, class OutputIter, class BinaryOper>inline
OutputIter _unique_copy(InputIter first, InputIter last,
	OutputIter result, BinaryOper op ,
	beauty::iterator::iterator_category::output_iterator_tag){
	
	typename beauty::iterator::iterator_traits::
		iterator_traits<OutputIter>::value_type type;
	
	type = *first;
	*result = type;
	while(++first != last){
		if(!op(type, *first)){
			type = *first;
			*++result = type;
		}
	}
	return ++result;
}
template<class InputIter, class OutputIter, class BinaryOper>inline
OutputIter _unique_copy(InputIter first, InputIter last,
	OutputIter result, BinaryOper op,
	beauty::iterator::iterator_category::forward_iterator_tag){
	
	*result = *first;
	while(++first != last){
		if(!op(*first,*result)){
			*++result = *first;
		}
	}
	return ++result;
}
template<class InputIter, class OutputIter, class BinaryOper>
OutputIter unique_copy(InputIter first, InputIter last,
 OutputIter result, BinaryOper op){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<OutputIter>	::iterator_category Category;
	
	if(first == last)return result;
	return beauty::algorithm::other::
		_unique_copy(first, last, result, op, Category());
}


}
}
}
#endif
