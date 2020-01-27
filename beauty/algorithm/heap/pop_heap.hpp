
#ifndef beauty__algorithm__heap___pop_heap_hpp
#define beauty__algorithm__heap___pop_heap_hpp
	
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
	
	
namespace beauty{namespace algorithm{namespace heap{



template<class RandomAccessIter>
inline void pop_heap(RandomAccessIter first, RandomAccessIter last){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
		difference_type	Distance;
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
		value_type Type;
	
	--last;
	Type value = *last;
	Distance len = last - first;
	Distance child = 2, parent = 0;
	*last = *first;
	
	while(child < len){
		if(*(first + child) < *(first + child - 1)){
			--child;
		}		
		if(value < *(first + child)){
			*(first + parent) = *(first + child);
			parent = child;
			child = 2*parent + 2;
		}else{
			//*(first + parent) = value;
			break;
		}
	}
	if(child == len){
		--child;
		if(value < *(first + child)){
			*(first + parent) = *(first + child);
			//*(first + child) = value;
			parent = child;
		}
	}

	*(first + parent) = value;
}
template<class RandomAccessIter, class Compare>
inline void pop_heap(RandomAccessIter first, RandomAccessIter last,
Compare comp){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
		difference_type	Distance;
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
		value_type Type;
	
	--last;
	Type value = *last;
	Distance len = last - first;
	Distance child = 2, parent = 0;
	*last = *first;
	
	while(child < len){
		if(comp(*(first + child), *(first + child - 1))){
			--child;
		}		
		if(comp(value, *(first + child))){
			*(first + parent) = *(first + child);
			parent = child;
			child = 2*parent + 2;
		}else{
			//*(first + parent) = value;
			break;
		}
	}
	if(child == len){
		--child;
		if(comp(value, *(first + child))){
			*(first + parent) = *(first + child);
			//*(first + child) = value;
			parent = child;
		}
	}
	
	*(first + parent) = value;
}



}
}
}
#endif
