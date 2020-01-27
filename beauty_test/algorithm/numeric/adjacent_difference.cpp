/*


#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

namespace beauty{namespace algorithm{namespace numeric{


template<class InputIterator, class OutputIterator>inline
OutputIterator adjacent_difference(InputIterator first, InputIterator last,
 OutputIterator result){
	if(first == last)return result;
	*result = *first;

	 typename beauty::iterator::iterator_traits::iterator_traits<InputIterator>::value_type
	 value = *first, temp;

	 for(++first; first != last; ++first){
 		temp = *first;
 		*++result = temp - value;
 		value = temp;
 	}
 	return ++result;
}

template<class InputIterator, class OutputIterator, class BinaryOperation>inline
OutputIterator adjacent_difference(InputIterator first, InputIterator last,
OutputIterator result, BinaryOperation op){
	if(first == last)return result;
	*result = *first;


	typename beauty::iterator::iterator_traits::iterator_traits<InputIterator>::value_type
	 value = *first, temp;

	for(++first; first != last; ++first){
		temp = *first;
		*++result = op(temp, value);
		value = temp;
	}
	return ++result;
}




}
}
}
*/

#include<numeric>
#include<iostream>
//#include<./beauty/algorithm/numeric/accumulate.hpp>
#include<./beauty/algorithm/numeric/adjacent_difference.hpp>
int Compare(int a, int b){
	return a + b;
}
int main(){
	int b[] = {1,2,3,5,8,13};
	int d[10]={
		
	};
	int a[] = {1,2,3,5,8,13};
	int c[10]={
		
	};
	
	beauty::algorithm::numeric::
	adjacent_difference(a, a + sizeof(a)/sizeof(int), c);
	std::adjacent_difference(b, b + sizeof(b)/sizeof(int), d);
	for(int i = 0; i < sizeof(c)/sizeof(int); ++i){
		if(c[i] != d[i]){
			std::cout<<"error!  "<<c[i]<<"!="<<d[i]<<std::endl;
		}else{
			std::cout<<c[i]<<" ";
		}
	}
	return 0;
}