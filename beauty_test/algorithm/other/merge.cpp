/*


#ifndef include___beauty__algorithm__algorithmbase___copy_hpp
	#define include___beauty__algorithm__algorithmbase___copy_hpp
	#include<./beauty/algorithm/algorithmbase/copy.hpp>
#endif

namespace beauty{namespace algorithm{namespace other{
	


template<class InputIter1, class InputIter2, class OutputIter>
OutputIter merge(InputIter1 first1, InputIter1 last1,
InputIter2 first2, InputIter2 last2, OutputIter result){
	while(first1 != last1 && first2 != last2){
		if(*first2 < *first1){
			*result = *first2;
			++first2;
		}else{
			*result = *first1;
			++first1;
		}
		++result;
	}
	return beauty::algorithm::algorithmbase::
		copy(first1, last1,
		 beauty::algorithm::algorithmbase::
	 		copy(first2, last2, result));
}
template<class InputIter1, class InputIter2,
 class OutputIter, class Compare>
OutputIter merge(InputIter1 first1, InputIter1 last1,
InputIter2 first2, InputIter2 last2, OutputIter result,
Compare comp){
	while(first1 != last1 && first2 != last2){
		if(comp(*first2, *first1)){
			*result = *first2;
			++first2;
		}else{
			*result = *first1;
			++first1;
		}
		++result;
	}
	return beauty::algorithm::algorithmbase::
		copy(first1, last1,
	 	beauty::algorithm::algorithmbase::
	 	copy(first2, last2, result));
}

}
}
}*/
#include<./beauty/algorithm/other/merge.hpp>
int main(){
	return 0;
}