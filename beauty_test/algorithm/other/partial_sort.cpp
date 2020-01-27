/*

#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif
#ifndef include___beauty__algorithm__heap___make_heap_hpp
	#define include___beauty__algorithm__heap___make_heap_hpp
	#include<./beauty/algorithm/heap/make_heap.hpp>
#endif
#ifndef include___beauty__algorithm__heap___sort_heap_hpp
	#define include___beauty__algorithm__heap___sort_heap_hpp
	#include<./beauty/algorithm/heap/sort_heap.hpp>
#endif
namespace beauty{namespace algorithm{namespace other{
	
template<class RandomAccessIter>
inline void partial_sort(RandomAccessIter first,
RandomAccessIter middle, RandomAccessIter last){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::value_type Type;
	
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::difference_type Distance;
	
	Distance len = middle - first;
	Distance child, parent;
	beauty::algorithm::heap::make_heap(first, middle);
	Type value;
	for(RandomAccessIter i = middle; i < last; ++i){
		if(*i < *first){
			value = *i;
			*i = *first;
			
			child = 2;
			parent = 0;
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
	}
	beauty::algorithm::heap::sort_heap(first, middle);	
}

template<class RandomAccessIter, class Compare>
inline void partial_sort(RandomAccessIter first,
RandomAccessIter middle, RandomAccessIter last, Compare comp){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::value_type Type;
		
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>::difference_type Distance;
	
	Distance len = middle - first;
	Distance child, parent;
	beauty::algorithm::heap::make_heap(first, middle, comp);	
	
	Type value;
	for(RandomAccessIter i = middle; i < last; ++i){
		if(comp(*i, *first)){
			value = *i;
			*i = *first;
			
			child = 2;
			parent = 0;
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
	}
	beauty::algorithm::heap::sort_heap(first, middle, comp);
}
	

}
}
}*/
#include<./beauty/algorithm/other/partial_sort.hpp>
int main(){
	return 0;
}