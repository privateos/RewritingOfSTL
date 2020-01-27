/*

namespace beauty{namespace algorithm{namespace other{
	

template<class InputIter, class OutputIter, class T>
OutputIter remove_copy(InputIter first, InputIter last,
OutputIter result, const T &value){
	for( ; first != last; ++first){
		if(*first != value){
			*result = *first;
			++result;
		}
	}
	return result;
}


}
}
}*/
#include<./beauty/algorithm/other/remove_copy.hpp>
int main(){
	return 0;
}