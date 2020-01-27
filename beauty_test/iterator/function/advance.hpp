

#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

namespace beauty{namespace iterator{namespace function{


template<class InputIterator, class Distance>inline
__advance(InputIterator &i, Distance n,
		beauty::iterator::iterator_category::input_iterator_tag){

		while(n){
			++i;
			--n;
		}
}




template<class BidirectionalIterator>inline
__advance(BidirectionalIterator &i, Distance n,
		beauty::iterator::iterator_category::bidirectional_iterator_tag){

		if(n >= 0){
			while(n){
				++i;
				--n;
			}
		}else{
			while(n){
				--i;
				++n;
			}
		}
}


template<class RandomAccessIterator, class Distance>inline
__advance(RandomAccessIterator &i, Distance n,
		beauty::iterator::iterator_category::random_access_iterator_tag){

		i += n;
}

template<class InputIterator, class Distance>inline
void advance(InputIterator &i, Distance n){
	typedef beauty::iterator::iterator_traits::
	iterator_traits<InputIterator>::iterator_category Category;
	__advance(i, n, Category());
}







}
}
}
