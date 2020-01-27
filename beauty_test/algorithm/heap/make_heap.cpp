/*


	
#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif	
	
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
}*/
#include<algorithm>
#include<iostream>
#include<./beauty/algorithm/heap/make_heap.hpp>
#include<./beauty/algorithm/other/for_each.hpp>
namespace tf = beauty::algorithm::heap;
namespace beauty{

using beauty::algorithm::heap::make_heap;
}
int main(){
	int b[] = {1,2,3,5,8,13};
	int a[] = {1,2,3,5,8,13};


	/*
beauty::algorithm::heap::
	make_heap(a, a + sizeof(a)/sizeof(int));
*/
	beauty::make_heap(a, a + sizeof(a)/sizeof(int));
	
	std::make_heap(b, b + sizeof(b)/sizeof(int));
	for(int i = 0; i < sizeof(a)/sizeof(int); ++i){
		if(a[i] != b[i]){
			std::cout<<"error!  "<<a[i]<<"!="<<b[i]<<std::endl;
		}else{
			std::cout<<b[i]<<" ";
		}
	}
	return 0;
}
