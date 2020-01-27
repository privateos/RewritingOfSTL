
#ifndef beauty__algorithm__heap___push_heap_hpp
#define beauty__algorithm__heap___push_heap_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
	
namespace beauty{namespace algorithm{namespace heap{


template<class RandomAccessIter>
inline void push_heap(RandomAccessIter first, RandomAccessIter last){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
					difference_type	Distance;
				
	typedef typename beauty::iterator::iterator_traits::
			iterator_traits<RandomAccessIter>::
								value_type Type;
	
	Distance child = last - first - 1;
	Distance parent = (child - 1)/2;
	Type value = *(last - 1);
	while(parent > 0){
		if(*(first + parent) < value){
			*(first + child) = *(first + parent);
			child = parent;
			parent = (child - 1)/2;
		}else{
			break;
		}
	}
	if(parent == 0){
		if(*(first + parent) < value){
			*(first + child) = *(first + parent);
			child = parent;
		}
	}
	*(first + child) = value;	
}
template<class RandomAccessIter, class Compare>
inline void push_heap(RandomAccessIter first, RandomAccessIter last,
Compare comp){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
		difference_type	Distance;
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
		value_type Type;
	
	Distance child = last - first - 1;
	Distance parent = (child - 1)/2;
	Type value = *(last - 1);
	while(parent > 0){
		if(comp(*(first + parent), value)){
			*(first + child) = *(first + parent);
			child = parent;
			parent = (child - 1)/2;
		}else{
			break;
		}
	}
	if(parent == 0){
		if(comp(*(first + parent), value)){
			*(first + child) = *(first + parent);
			child = parent;
		}
	}
	*(first + child) = value;	
}


}
}
}
#endif
