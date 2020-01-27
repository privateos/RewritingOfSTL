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
}*/
#include<./beauty/algorithm/other/unique_copy.hpp>
int main(){
	return 0;
}