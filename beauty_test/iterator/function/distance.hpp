
#ifndef include___beauty__iteator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iteator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#enfif
#ifndef include___beauty__iterator__iterator_category___random_access_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___random_access_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/random_access_iterator_tag.hpp>
#endif
#ifndef include___beauty__iterator__iterator_category___input_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___input_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/input_iterator_tag.hpp>
#endif

namespace beauty{namespace iterator{namespace function{

//////////////////////////input_iterator_tag  __distance()/////////////////////////////////////////////////////////
template<class InputIterator>inline
__distance(InputIterator first, InputIterator last,
			beauty::iterator::iterator_category::input_iterator_tag){
	beauty::iterator::iterator_traits::
	iterator_traits<InputIterator>::difference_type n = 0;
	while(first != last){
		++n;
		++first;
	}
	return n;
}
template<class InputIterator, class Distance>inline
__distance(InputIterator first, InputIterator last, Distance &d
			beauty::iterator::iterator_category::input_iterator_tag){
	d = 0;
	while(first != last){
		++d;
		++first;
	}
}
//////////////////////////////////////////////////////////////////////////////////




/////////////////random_access_iterator_tag    __distance()///////////////////////////////////////////
template<class RandomAccessIterator>inline
typename beauty::iterator::iterator_traits::
iterator_traits<RandomAccessIterator>::difference_type
__distance(RandomAccessIterator first, RandomAccessIterator last,
		beauty::iterator::iterator_category::random_access_iterator_tag){
		return last - first;
}
template<class RandomAccessIterator, class Distance>inline
void __distance(RandomAccessIterator first, RandomAccessIterator last,
		Distance &d
		beauty::iterator::iterator_category::random_access_iterator_tag){
		d = last - first;
}
///////////////////////////////////////////////////////////////////////////

/////////////////////////distance()///////////////////////////////////////////////
template<class InputIterator>inline
typename beauty::iterator::iterator_traits::iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last){
	typedef beauty::iterator::iterator_traits::iterator_traits<InputIterator>::
		iterator_category Category;

	return __distance(first, last, Category());
}
template<class InputIterator>inline
void distance(InputIterator first, InputIterator last,
beauty::iterator::iterator_traits<InputIterator>::difference_type& d){

	typedef beauty::iterator::iterator_traits::iterator_traits<InputIterator>::
		iterator_category Category;

	return __distance(first, last, d, Category());
}
/////////////////////////////////////////////////////////////////////////////
}
}
}
