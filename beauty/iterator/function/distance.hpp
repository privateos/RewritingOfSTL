
#ifndef beauty__iterator__function___distance_hpp
#define beauty__iterator__function___distance_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#include<./beauty/iterator/iterator_category/random_access_iterator_tag.hpp>
#include<./beauty/iterator/iterator_category/input_iterator_tag.hpp>


namespace beauty{namespace iterator{namespace function{

//////////////////////////input_iterator_tag  __distance()/////////////////////////////////////////////////////////
template<class InputIterator>inline
typename beauty::iterator::iterator_traits::
iterator_traits<InputIterator>::difference_type
__distance(InputIterator first, InputIterator last,
			beauty::iterator::iterator_category::input_iterator_tag){
				
	typename beauty::iterator::iterator_traits::
	iterator_traits<InputIterator>::difference_type n = 0;
	while(first != last){
		++n;
		++first;
	}
	return n;
}
template<class InputIterator, class Distance>inline
void __distance(InputIterator first, InputIterator last, Distance &d,
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
		Distance &d,
		beauty::iterator::iterator_category::random_access_iterator_tag){
			
		d = last - first;
}
///////////////////////////////////////////////////////////////////////////

/////////////////////////distance()///////////////////////////////////////////////
template<class InputIterator>inline
typename beauty::iterator::iterator_traits::
iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last){
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<InputIterator>::iterator_category Category;

	return __distance(first, last, Category());
}
template<class InputIterator>inline
void distance(InputIterator first, InputIterator last,
	typename beauty::iterator::iterator_traits::
	iterator_traits<InputIterator>::difference_type& d){

	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<InputIterator>::iterator_category Category;

	__distance(first, last, d, Category());
}
/////////////////////////////////////////////////////////////////////////////
}
}
}
#endif
