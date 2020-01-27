/*


	

	
namespace beauty{namespace algorithm{namespace set{


template<class InputIter1, class InputIter2, class OutputIter>
OutputIter set_intersection(InputIter1 first1, InputIter1 last1,
InputIter2 first2, InputIter2 last2, OutputIter result){
	while(first1 != last1 && first2 != last2){
		if(*first1 < *first2){
			++first1;
		}else{
			if(*first2 < *first1){
				++first2;
			}else{
				*result = *first1;
				++first1;
				++first2;
				++result;
			}
		}
	}
	return result;
}

template<class InputIter1, class InputIter2, class OutputIter, class Compare>
OutputIter set_intersection(InputIter1 first1, InputIter1 last1,
InputIter2 first2, InputIter2 last2, OutputIter result, Compare comp){
	while( first1 != last1 && first2 != last2){
		if(comp(*first1, *first2)){
			++first1;
		}else{
			if(comp(*first2, *first1)){
				++first2;
			}else{
				*result = *first1;
				++first1;
				++first2;
				++result;
			}
		}
	}
	return result;
}


}
}
}*/
#include<algorithm>
#include<iostream>
#include<./beauty/algorithm/set/set_intersection.hpp>
int main(){
	int b[] = {1,3,5,7,9};
	int a[] = {1,1,2,3,5,8,13};
	int c[10] = {};
	int d[10] = {};

	beauty::algorithm::set::
	set_intersection(b, b + sizeof(b)/sizeof(int), a, a + sizeof(a)/sizeof(int), c);

	std::set_intersection(b, b + sizeof(b)/sizeof(int), a, a + sizeof(a)/sizeof(int), d);
	for(int i = 0; i < 10; ++i){
		if(c[i] != d[i]){
			std::cout<<"error!  "<<c[i]<<"!="<<d[i]<<std::endl;
		}else{
			std::cout<<c[i]<<" ";
		}
	}
	return 0;
}
