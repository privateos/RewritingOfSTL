/*

#ifndef include___beauty__algorithm__algorithmbase___copy_hpp
	#define include___beauty__algorithm__algorithmbase___copy_hpp
	#include<./beauty/algorithm/algorithmbase/copy.hpp>
#endif



namespace beauty{namespace algorithm{namespace set{


template<class InputIter1, class InputIter2, class OutputIter>
OutputIter set_union(InputIter1 first1, InputIter1 last1,
InputIter2 first2, InputIter2 last2, OutputIter result){
	while(first1 != last1 && first2 != last2){
		if(*first1 < *first2){
			*result = *first1;
			++first1;
		}else{
			if(*first2 < *first1){
				*result = *first2;
				++first2;
			}else{
				*result = *first1;
				++first1;
				++first2;
			}
		}
		++result;
	}
	return beauty::algorithm::algorithmbase::copy(first1, last1,
	beauty::algorithm::algorithmbase::copy(first2, last2, result));
}

template<class InputIter1, class InputIter2, class OutputIter, class Compare>
OutputIter set_union(InputIter1 first1, InputIter1 last1,
InputIter2 first2, InputIter2 last2, OutputIter result, Compare comp){
	while( first1 != last1 && first2 != last2){
		if(comp(*first1, *first2)){
			*result = *first1;
			++first1;
		}else{
			if(comp(*first2, *first1)){
				*result = *first2;
				++first2;
			}else{
				*result = *first1;
				++first1;
				++first2;
			}
		}
		++result;
	}
	return beauty::algorithm::algorithmbase::copy(first1, last1, 
	beauty::algorithm::algorithmbase::copy(first2, last2, result));
}


}
}
}*/
#include<algorithm>
#include<iostream>
#include<./beauty/algorithm/set/set_union.hpp>


int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	int b[] = {0,1,3,5,7,9};
	int c[10] = {};
	int d[10] = {};
	
	beauty::algorithm::set::
	set_union(b, b + sizeof(b)/sizeof(int), a, a + sizeof(a)/sizeof(int), c);
	
	std::set_union(b, b + sizeof(b)/sizeof(int), a, a + sizeof(a)/sizeof(int), d);
	for(int i = 0; i < 10; ++i){
		if(c[i] != d[i]){
			std::cout<<"error!  "<<c[i]<<"!="<<d[i]<<std::endl;
		}else{
			std::cout<<c[i]<<" ";
		}
	}
	return 0;
}