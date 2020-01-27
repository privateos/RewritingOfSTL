/*


	

#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif	
	
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
}*/

#include<algorithm>
#include<iostream>
#include<./beauty/algorithm/heap/make_heap.hpp>
#include<./beauty/algorithm/heap/pop_heap.hpp>

int main(){
	int b[] = {1,2,3,5,8,13};
	int a[] = {1,2,3,5,8,13};


	beauty::algorithm::heap::
	make_heap(a, a + sizeof(a)/sizeof(int));
	beauty::algorithm::heap::
	pop_heap(a, a + sizeof(a)/sizeof(int));
	
	std::make_heap(b, b + sizeof(b)/sizeof(int));
	std::pop_heap(b, b + sizeof(b)/sizeof(int));
	
	for(int i = 0; i < sizeof(a)/sizeof(int); ++i){
		if(a[i] != b[i]){
			std::cout<<"error!  "<<a[i]<<"!="<<b[i]<<std::endl;
		}else{
			std::cout<<b[i]<<" ";
		}
	}
	return 0;
}
