/*

#ifndef include___beauty__iterator__iterator_category___output_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___output_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/output_iterator_tag.hpp>
#endif
#ifndef include___beauty__iterator__iterator_category___forward_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___forward_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#endif
#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif
#ifndef include___beauty__algorithm__other___adjacent_find_hpp
	#define include___beauty__algorithm__other___adjacent_find_hpp
	#include<./beauty/algorithm/other/adjacent_find.hpp>
#endif

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
}*/
#include<./beauty/algorithm/other/unique.hpp>
int main(){
	return 0;
}