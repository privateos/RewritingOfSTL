/*


	
#ifndef include___beauty__algorithm__algorithmbase___copy_hpp
	#define include___beauty__algorithm__algorithmbase___copy_hpp
	#include<./beauty/algorithm/algorithmbase/copy.hpp>
#endif
	
namespace beauty{namespace algorithm{namespace set{



template<class InputIter1, class InputIter2, class OutputIter>
OutputIter set_symmetric_difference(InputIter1 first1, InputIter1 last1,
InputIter2 first2, InputIter2 last2, OutputIter result){
	while(first1 != last1 && first2 != last2){
		if(*first1 < *first2){
			*result = *first1;
			++first1;
			++result;
		}else{
			if(*first2 < *first1){
				*result = *first2;
				++first2;
				++result;
			}else{
				++first1;
				++first2;
			}
		}
	}
	return beauty::algorithm::algorithmbase::
		copy(first1, last1, 
			beauty::algorithm::algorithmbase::
			copy(first2, last2, result));
}

template<class InputIter1, class InputIter2, class OutputIter, class Compare>
OutputIter set_symmetric_difference(InputIter1 first1, InputIter1 last1,
InputIter2 first2, InputIter2 last2, OutputIter result, Compare comp){
	while(first1 != last1 && first2 != last2){
		if(comp(*first1, *first2)){
			*result = *first1;
			++first1;
			++result;
		}else{
			if(comp(*first2, *first1)){
				*result = *first2;
				++first2;
				++result;
			}else{
				++first1;
				++first2;
			}
		}
	}
	return beauty::algorithm::algorithmbase::
			copy(first1, last1, 
			beauty::algorithm::algorithmbase::copy(first2, last2, result));
}

}
}
}*/
#include<algorithm>
#include<iostream>
#include<./beauty/algorithm/set/set_symmetric_difference.hpp>
int main(){
	int b[] = {1,3,5,7,9};
	int a[] = {1,1,2,3,5,8,13};
	int c[10] = {};
	int d[10] = {};

	beauty::algorithm::set::
	set_symmetric_difference(b, b + sizeof(b)/sizeof(int), a, a + sizeof(a)/sizeof(int), c);

	std::set_symmetric_difference(b, b + sizeof(b)/sizeof(int), a, a + sizeof(a)/sizeof(int), d);
	for(int i = 0; i < 10; ++i){
		if(c[i] != d[i]){
			std::cout<<"error!  "<<c[i]<<"!="<<d[i]<<std::endl;
		}else{
			std::cout<<c[i]<<" ";
		}
	}
	return 0;
}
