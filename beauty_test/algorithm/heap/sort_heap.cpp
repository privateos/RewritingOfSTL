/*


#ifndef include___beauty__algorithm__heap___pop_heap_hpp
	#define include___beauty__algorithm__heap___pop_heap_hpp
	#include<./beauty/algorithm/heap/pop_heap.hpp>
#endif	

	
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
}*/

#include<algorithm>
#include<iostream>
#include<./beauty/algorithm/heap/make_heap.hpp>
#include<./beauty/algorithm/heap/push_heap.hpp>
#include<./beauty/algorithm/heap/sort_heap.hpp>
bool Compare(int &a, int &b){
	return a < b;
}
int main(){
	int b[] = {1,2,3,5,8,13};
	int a[] = {1,2,3,5,8,13};


/*
	beauty::algorithm::heap::
	make_heap(a, a + sizeof(a)/sizeof(int) - 1);
	beauty::algorithm::heap::
	push_heap(a, a + sizeof(a)/sizeof(int));
	beauty::algorithm::heap::
	sort_heap(a, a + sizeof(a)/sizeof(int));
	
	
	std::make_heap(b, b + sizeof(b)/sizeof(int) - 1);
	std::push_heap(b, b + sizeof(b)/sizeof(int));
	std::sort_heap(b, b + sizeof(b)/sizeof(int));*/
		beauty::algorithm::heap::
	make_heap(a, a + sizeof(a)/sizeof(int) - 1, Compare);
	beauty::algorithm::heap::
	push_heap(a, a + sizeof(a)/sizeof(int), Compare);
	beauty::algorithm::heap::
	sort_heap(a, a + sizeof(a)/sizeof(int), Compare);
	
	
	std::make_heap(b, b + sizeof(b)/sizeof(int) - 1, Compare);
	std::push_heap(b, b + sizeof(b)/sizeof(int), Compare);
	std::sort_heap(b, b + sizeof(b)/sizeof(int), Compare);
	
	for(int i = 0; i < sizeof(a)/sizeof(int); ++i){
		if(a[i] != b[i]){
			std::cout<<"error!  "<<a[i]<<"!="<<b[i]<<std::endl;
		}else{
			std::cout<<b[i]<<" ";
		}
	}
	std::cout<<std::endl;
	return 0;
}
