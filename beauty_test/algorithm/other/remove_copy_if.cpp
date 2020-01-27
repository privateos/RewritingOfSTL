/*

namespace beauty{namespace algorithm{namespace other{
	


template<class InputIter, class OutputIter, class Predicate>
OutputIter remove_copy_if(InputIter first, InputIter last,
OutputIter result, Predicate pred){
	for( ; first != last; ++first){
		if(!pred(*first)){
			*result = *first;
			++result;
		}
	}
	return result;
}
template<class InputIter, class OutputIter, class T, class Equal>
OutputIter remove_copy_if(InputIter first, InputIter last,
OutputIter result, const T &value, Equal eq){
	for( ; first != last; ++first){
		if(!eq(*first, value)){
			*result = *first;
			++result;
		}
	}
	return result;
}

}
}
}*/
#include<./beauty/algorithm/other/remove_copy_if.hpp>
int main(){
	return 0;
}