
#ifndef beauty__algorithm__other___nth_element_hpp
#define beauty__algorithm__other___nth_element_hpp

#include<./beauty/algorithm/other/sort.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


namespace beauty{namespace algorithm{namespace other{

template<class RandomAccessIter>inline
void nth_element(RandomAccessIter first,
				RandomAccessIter nth,
				RandomAccessIter last){
					
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::value_type T;

	RandomAccessIter cut;
	while(last - first > 3){
		
		cut = beauty::algorithm::other::
			__unguarded_partition(first, last, T(
				beauty::algorithm::other::__median(*first, *(first +
				(last - first)/2), *(last - 1))));
				
		if(nth < cut){
			last = cut;
		}else{
			first = cut;
		}
	}
	beauty::algorithm::other::__insertion_sort(first, last);
}

template<class RandomAccessIter, class BinaryOper>inline
void nth_element(RandomAccessIter first,
				RandomAccessIter nth,
				RandomAccessIter last,
				BinaryOper op){
					
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::value_type T;

	RandomAccessIter cut;
	while(last - first > 3){

		cut = beauty::algorithm::other::
			__unguarded_partition(first, last,
				T(
				beauty::algorithm::other::__median(*first, *(first +
				(last - first)/2), *(last - 1), op)),
				
				
				op);
				
		if(nth < cut){
			last = cut;
		}else{
			first = cut;
		}
	}
	beauty::algorithm::other::__insertion_sort(first, last, op);
}
}
}
}

#endif
