
#ifndef beauty__algorithm__algorithmbase___compare_hpp
#define beauty__algorithm__algorithmbase___compare_hpp

#include<./beauty/types.hpp>

namespace beauty{namespace algorithm{namespace algorithmbase{

template<class InputIter1, class InputIter2>
inline beauty::sbyte compare(InputIter1 first1, InputIter1 last1,
	InputIter2 first2, InputIter2 last2){
	for( ; first1 != last1 && first2 != last2; ++first1, ++first2){
		if(*first1 < *first2)return -1;
		if(*first2 < *first1)return 1;
	}
	if(first1 == last1){
		if(first2 == last2){
			return 0;
		}else{
			return -1;
		}
	}else{
		return 1;
	}
}

template<class InputIter1, class InputIter2, class Compare>
inline beauty::sbyte compare(InputIter1 first1, InputIter1 last1,
	InputIter2 first2, InputIter2 last2, Compare cmp){
	for( ; first1 != last1 && first2 != last2; ++first1, ++first2){
		if(cmp(*first1, *first2))return -1;
		if(cmp(*first2, *first1))return 1;
	}
	if(first1 == last1){
		if(first2 == last2){
			return 0;
		}else{
			return -1;
		}
	}else{
		return 1;
	}
}
}
}
}

#endif
