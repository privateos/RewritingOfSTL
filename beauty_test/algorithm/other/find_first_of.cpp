/*

namespace beauty{namespace algorithm{namespace other{
	
template<class InputIter, class ForwardIter>
InputIter find_first_of(InputIter first1, InputIter last1,
ForwardIter first2, ForwardIter last2){
	ForwardIter ite;
	for( ; first1 != last1; ++first1){
		for(ite = first2; ite != last2; ++ite){
			if(*ite == *first1){
				return first1;
			}
		}
	}
	return last1;
}
template<class InputIter, class ForwardIter, class BinaryPredicate>
InputIter find_first_of(InputIter first1, InputIter last1,
ForwardIter first2, ForwardIter last2, BinaryPredicate op){
	ForwardIter ite;
	for( ; first1 != last1; ++first1){
		for(ite = first2; ite != last2; ++ite){
			if(op(*ite, *first1)){
				return first1;
			}
		}
	}
	return last1;
}



}
}
}*/
#include<./beauty/algorithm/other/find_first_of.hpp>
int main(){
	return 0;
}