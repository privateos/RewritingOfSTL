
#ifndef beauty__algorithm__heap___make_heap_hpp
#define beauty__algorithm__heap___make_heap_hpp
	
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>	
	
	
namespace beauty{namespace algorithm{namespace heap{

template<class RandomAccessIter,class Distance>
inline void __make_heap(RandomAccessIter first, Distance parent,
Distance len){
	
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
		value_type Type;
	
	Distance child = 2*parent + 2;
	Type value = *(first + parent);
	
	while(child < len){
		if(*(first + child) < *(first + child - 1)){
			--child;
		}
		if(value < *(first + child)){
			*(first + parent) = *(first + child);
			parent = child;
			child = 2*parent + 2;
		}else{
			break;
		}
	}
	if(child == len){
		--child;
		if(value < *(first + child)){
			*(first + parent) = *(first + child);
			parent = child;
		}
	}
	*(first + parent) = value;
}
template<class RandomAccessIter>
inline void make_heap(RandomAccessIter first, RandomAccessIter last){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
		difference_type	Distance;
	
	Distance len = last - first;
	Distance parent = (len - 2)/2;
	while(parent > 0){
		beauty::algorithm::heap::
		__make_heap(first, parent, len);
		--parent;
	}
	beauty::algorithm::heap::	
	__make_heap(first, parent, len);
}

template<class RandomAccessIter,class Distance, class Compare>
inline void __make_heap(RandomAccessIter first, Distance parent,
Distance len, Compare comp){
	
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
		value_type Type;
	
	Distance child = 2*parent + 2;
	Type value = *(first + parent);
	
	while(child < len){
		if(comp(*(first + child), *(first + child - 1))){
			--child;
		}
		if(comp(value, *(first + child))){
			*(first + parent) = *(first + child);
			parent = child;
			child = 2*parent + 2;
		}else{
			break;
		}
	}
	if(child == len){
		--child;
		if(comp(value, *(first + child))){
			*(first + parent) = *(first + child);
			parent = child;
		}
	}
	*(first + parent) = value;
}
template<class RandomAccessIter, class Compare>
inline void make_heap(RandomAccessIter first, RandomAccessIter last,
Compare comp){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::
		difference_type	Distance;
	
	Distance len = last - first;
	Distance parent = (len - 2)/2;
	while(parent > 0){
		__make_heap(first, parent, len, comp);
		--parent;
	}
	beauty::algorithm::heap::	
	__make_heap(first, parent, len, comp);
}



}
}
}
#endif
