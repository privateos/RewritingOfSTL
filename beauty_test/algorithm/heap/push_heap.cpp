/*


#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif	

	
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
}*/

#include<algorithm>
#include<iostream>
#include<./beauty/algorithm/heap/make_heap.hpp>
#include<./beauty/algorithm/heap/push_heap.hpp>
int main(){
	int b[] = {1,2,3,5,8,13};
	int a[] = {1,2,3,5,8,13};


	beauty::algorithm::heap::
	make_heap(a, a + sizeof(a)/sizeof(int) - 1);
	beauty::algorithm::heap::
	push_heap(a, a + sizeof(a)/sizeof(int));

	std::make_heap(b, b + sizeof(b)/sizeof(int) - 1);
	std::push_heap(b, b + sizeof(b)/sizeof(int));

	for(int i = 0; i < sizeof(a)/sizeof(int); ++i){
		if(a[i] != b[i]){
			std::cout<<"error!  "<<a[i]<<"!="<<b[i]<<std::endl;
		}else{
			std::cout<<b[i]<<" ";
		}
	}
	return 0;
}
