
#ifndef beauty__iterator__function___advance_hpp
#define beauty__iterator__function___advance_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


namespace beauty{namespace iterator{namespace function{


template<class InputIterator, class Distance>inline
void __advance(InputIterator &i, Distance n,
		beauty::iterator::iterator_category::input_iterator_tag){

		while(n){
			++i;
			--n;
		}
}




template<class BidirectionalIterator, class Distance>inline
void __advance(BidirectionalIterator &i, Distance n,
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
void __advance(RandomAccessIterator &i, Distance n,
		beauty::iterator::iterator_category::random_access_iterator_tag){

		i += n;
}

template<class InputIterator, class Distance>inline
void advance(InputIterator &i, Distance n){
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<InputIterator>::iterator_category Category;
	__advance(i, n, Category());
}







}
}
}
#endif
