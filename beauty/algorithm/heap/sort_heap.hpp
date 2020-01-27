
#ifndef beauty__algorithm__heap___sort_heap_hpp
#define beauty__algorithm__heap___sort_heap_hpp

#include<./beauty/algorithm/heap/pop_heap.hpp>
	
namespace beauty{namespace algorithm{namespace heap{


template<class RandomAccessIter>
void sort_heap(RandomAccessIter first, RandomAccessIter last){
	while(last - first > 1){
		beauty::algorithm::heap::
		pop_heap(first, last);
		--last;
	}
}
template<class RandomAccessIter, class Compare>
void sort_heap(RandomAccessIter first, RandomAccessIter last,
Compare comp){
	while(last - first > 1){
		beauty::algorithm::heap::
		pop_heap(first, last, comp);
		--last;
	}
}


}
}
}
#endif
