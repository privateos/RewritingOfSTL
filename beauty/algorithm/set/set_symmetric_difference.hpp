
#ifndef beauty__algorithm__set___set_symmetric_difference_hpp
#define beauty__algorithm__set___set_symmetric_difference_hpp

#include<./beauty/algorithm/algorithmbase/copy.hpp>

	
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
}
#endif
