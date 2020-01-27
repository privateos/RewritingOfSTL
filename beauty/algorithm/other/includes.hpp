
#ifndef beauty__algorithm__other___includes_hpp
#define beauty__algorithm__other___includes_hpp

namespace beauty{namespace algorithm{namespace other{
	


template<class InputIter1, class InputIter2>
bool includes(InputIter1 first1, InputIter1 last1,
InputIter2 first2, InputIter2 last2){
	for( ; first1 != last1 && first2 != last2; ){
		if(*first2 < *first1){
			return false;
		}else{
			if(*first1 < *first2){
				++first1;
			}else{
				++first1;
				++first2;
			}
		}
	}
	return first2 == last2;
}
template<class InputIter1, class InputIter2, class Compare>
bool includes(InputIter1 first1, InputIter1 last1,
InputIter2 first2, InputIter2 last2, Compare comp){
	for( ; first1 != last1 && first2 != last2; ){
		if(comp(*first2, *first1)){
			return false;
		}else{
			if(comp(*first1, *first2)){
				++first1;
			}else{
				++first1;
				++first2;
			}
		}
	}
	return first2 == last2;
}

}
}
}
#endif
