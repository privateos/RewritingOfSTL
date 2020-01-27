/*



namespace beauty{namespace algorithm{namespace numeric{

template<class InputIterator1, class InputIterator2, class T>inline
T inner_product(InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, T init){
	for( ; first1 != last1; ++first1, ++first2){
		init = init + (*first1)*(*first2);
	}
	return init;
}

template<class InputIterator1, class InputIterator2, class T,
class BinaryOperation>inline
T inner_product(InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, T init, BinaryOperation op){
	for( ; first1 != last1; ++first1, ++first2){
		init = init + op(*first1, *first2);
	}
	return init;
}




}
}
}
*/

#include<numeric>
#include<iostream>

#include<./beauty/algorithm/numeric/inner_product.hpp>
int Compare(int a, int b){
	return a * b;
}
int add1(int a, int b){
	return a + b;
}
int main(){
	int b[] = {1,2,3,5,8,13};
	int d[]={2,3,4,5,6,7,8,9
		
	};
	int a[] = {1,2,3,5,8,13};
	int c[]={2,3,4,5,6,7,8,9
		
	};
	int ap = -1;
	int bp = -2;
/*
	ap = beauty::algorithm::numeric::
	inner_product(a, a + sizeof(a)/sizeof(int), c, 0);
	
	bp = std::inner_product(b, b + sizeof(b)/sizeof(int), d, 0);*/
		ap = beauty::algorithm::numeric::
	inner_product(a, a + sizeof(a)/sizeof(int), c, 0, Compare);
	
	bp = std::inner_product(b, b + sizeof(b)/sizeof(int), d, 0, add1, Compare);
	if(ap != bp){
		std::cout<<"error! ";
	}else{
		std::cout<<ap<<std::endl;
	}
	return 0;
}