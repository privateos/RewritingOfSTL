
#ifndef beauty__algorithm__algorithmbase___mismatch_hpp
#define beauty__algorithm__algorithmbase___mismatch_hpp

#include<./beauty/container/pair/pair.hpp>

namespace beauty{namespace algorithm{namespace algorithmbase{

template<class InputIterator1, class InputIterator2>
inline beauty::container::pair::pair<InputIterator1,InputIterator2>
mismatch(InputIterator1 first1, InputIterator1 last1,
	 InputIterator2 first2){
	
	
	while(first1 != last1 && *first1 == *first2){
		++first1;
		++first2;
	}
	return beauty::container::pair::pair<InputIterator1,InputIterator2>
			(first1, first2);
}

template<class InputIterator1, class InputIterator2,
class BinaryOperation>
inline beauty::container::pair::pair<InputIterator1, InputIterator2>
mismatch(InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, BinaryOperation op){
	
	while( first1 != last1 && op(first1, first2)){
		++first1;
		++first2;
	}
	return beauty::container::pair::pair<InputIterator1,InputIterator2>
			(first1, first2);
}



}
}
}
#endif
