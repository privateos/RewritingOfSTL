/*


namespace beauty{namespace algorithm{namespace other{
	
template<class InputIter, class OutputIter, class UnaryOper>
OutputIter transform(InputIter first, InputIter last,
OutputIter result, UnaryOper op){
	for( ; first != last; ++first, ++result){
		*result = op(*first);
	}
	return result;
}
template<class InputIter1, class InputIter2, class OutputIter,
class BinaryOper>
OutputIter transform(InputIter1 first1, InputIter1 last1,
InputIter2 first2, OutputIter result, BinaryOper op){
	for( ; first1 != last1; ++first1, ++first2, ++result){
		*result = op(*first1, *first2);
	}
	return result;
}	

}
}
}*/
#include<./beauty/algorithm/other/transform.hpp>
int main(){
	return 0;
}