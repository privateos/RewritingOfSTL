/*

namespace beauty{namespace algorithm{namespace algorithmbase{



template<class InputIterator1, class InputIterator2>
inline bool equal(InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2){
	for( ; first1 != last1; ++first1, ++first2){
		if(*first1 != *first2)return false;
	}
	return true;
}

template<class InputIterator1, class InputIterator2, class BinaryOperation>
inline bool equal(InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, BinaryOperation op){
	for( ; first1 != last1; ++first1, ++first2){
		if(!op(*first1, *first2))return false;
	}
	return true;
}

}
}
}*/
#include<./beauty/algorithm/algorithmbase/equal.hpp>
int main(){
	return 0;
}