
#ifndef beauty__algorithm__other___random_shuffle_hpp
#define beauty__algorithm__other___random_shuffle_hpp

#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#include<./beauty/header.hpp>

namespace beauty{namespace algorithm{namespace other{


template<class RandomAccessIter>
void random_shuffle(RandomAccessIter first, RandomAccessIter last){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>
		::difference_type Distance;
	
	for(RandomAccessIter i = first + 1; i != last; ++i){
		beauty::algorithm::algorithmbase::
		iter_swap(i , first + Distance(std::rand()%(i - first + 1)));
	}
}
template<class RandomAccessIter, class RandomAccessGenerator>
void random_shuffle(RandomAccessIter first, RandomAccessIter last,
RandomAccessGenerator &Random){
	
	for(RandomAccessIter i = first + 1; i != last; ++i){
		beauty::algorithm::algorithmbase::
		iter_swap(i , first + Random(i - first + 1));
	}
}


}
}
}
#endif
