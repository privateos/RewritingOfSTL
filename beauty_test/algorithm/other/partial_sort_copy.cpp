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

template<class InputIter, class RandomAccessIter>
inline void partial_sort_copy(InputIter first, InputIter last,
RandomAccessIter result_first, RandomAccessIter result_last){
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<RandomAccessIter>::value_type Type;
	
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<RandomAccessIter>::difference_type Distance;
	
	RandomAccessIter tresult_first = result_first;
	while(first != last && tresult_first != result_last){
		*tresult_first = *first;
		++tresult_first;
		++first;
	}
	
	
	Distance len = result_last - result_first;
	Distance child, parent;
	beauty::algorithm::heap::make_heap(result_first, result_last);
	
	for( ; first < last; ++first){
		if(*first < *result_first){
			
			child = 2;
			parent = 0;
			while(child < len){
				if(*(result_first + child) < *(result_first + child - 1)){
					--child;
				}
				if(*first < *(result_first + child)){
					*(result_first + parent) = *(result_first + child);
					parent = child;
					child = 2*parent + 2;
				}else{
					break;
				}
			}
			if(child == len){
				--child;
				if(*first < *(result_first + child)){
					*(result_first + parent) = *(result_first + child);
					parent = child;
				}
			}
			*(result_first + parent) = *first;
		}
	}
	beauty::algorithm::heap::sort_heap(result_first, result_last);
}
template<class InputIter, class RandomAccessIter, class Compare>
inline void partial_sort_copy(InputIter first, InputIter last,
RandomAccessIter result_first, RandomAccessIter result_last,
Compare comp){
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<RandomAccessIter>::value_type Type;
	
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<RandomAccessIter>::difference_type Distance;
	
	RandomAccessIter tresult_first = result_first;
	while(first != last && tresult_first != result_last){
		*tresult_first = *first;
		++tresult_first;
		++first;
	}
	
	
	Distance len = result_last - result_first;
	Distance child, parent;
	beauty::algorithm::heap::make_heap(result_first, result_last, comp);
	
	for( ; first < last; ++first){
		if(comp(*first,*result_first)){
			
			child = 2;
			parent = 0;
			while(child < len){
				if(comp(*(result_first + child), *(result_first + child - 1))){
					--child;
				}
				if(comp(*first, *(result_first + child))){
					*(result_first + parent) = *(result_first + child);
					parent = child;
					child = 2*parent + 2;
				}else{
					break;
				}
			}
			if(child == len){
				--child;
				if(comp(*first, *(result_first + child))){
					*(result_first + parent) = *(result_first + child);
					parent = child;
				}
			}
			*(result_first + parent) = *first;
		}
	}
	beauty::algorithm::heap::sort_heap(result_first, result_last, comp);
}

}
}
}*/
#include<./beauty/algorithm/other/partial_sort_copy.hpp>
int main(){
	return 0;
}